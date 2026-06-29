#include <Arduino.h>
#include "sensors/sensor_hub.h"
#include "actuators/actuator_hub.h"
#include "app/display_hub.h"
#include "comm/wifi_hub.h"
#include "control/rule_engine.h"
#include "control/inference_engine.h"
#include "control/output_guard.h"
#include "domain/metrics.h"

using namespace aqua_atmos;

sensors::SensorHub sensor_hub;
actuators::ActuatorHub actuator_hub;
app::DisplayHub display_hub;
comm::WifiHub wifi_hub;
control::OutputGuardState output_guard_state;

void setup() {
  Serial.begin(115200);
  sensor_hub.begin();
  actuator_hub.begin();
  display_hub.begin();
  wifi_hub.begin();
  Serial.println("[AQUA-ATMOS] Ready");
}

void loop() {
  // 1. Acquisition Hardware
  domain::SensorFrame sensors = sensor_hub.read();

  const auto& mock = wifi_hub.mock_sensors();
  if (mock.active) {
    sensors.temp_air_c = mock.temp_air_c;
    sensors.hr_pct = mock.hr_pct;
    sensors.hr_in_pct = mock.hr_pct;
    sensors.soc_battery_pct = mock.soc_battery_pct;
    sensors.reservoir_level_pct = mock.reservoir_level_pct;
    sensors.temp_cond_c = mock.temp_cond_c;
    sensors.solar_wm2 = mock.solar_wm2;
    sensors.float_switch_active = (mock.reservoir_level_pct >= 95.0f);
  }
  
  // 2. Traitement & Calculs
  domain::DerivedFrame derived;
  derived.dew_point_c = domain::compute_dew_point_c(sensors.temp_air_c, sensors.hr_pct);
  derived.humidity_ratio_gkg = domain::compute_humidity_ratio_gkg(sensors.temp_air_c, sensors.hr_pct);
  derived.delta_hr_sorbent = domain::compute_delta_hr_sorbent(sensors.hr_in_pct, sensors.hr_out_pct);
  if (mock.active) {
    derived.delta_hr_sorbent = mock.delta_hr_sorbent;
  }
  domain::enrich_derived_frame(sensors, derived);

  const bool hard_block = control::is_hard_block(sensors);

  // 3. Logique de Décision (Règles)
  domain::VcrcDecision vcrc_rule = control::decide_vcrc(sensors, derived, hard_block, output_guard_state.vcrc_relay_on);
  domain::SorbentDecision sorb_rule = control::decide_sorbent(sensors, derived, hard_block);

  // 4. Inférence IA
  domain::VcrcDecision vcrc_inference;
  domain::SorbentDecision sorb_inference;
  if (!hard_block) {
    control::run_inference(sensors, derived, vcrc_inference, sorb_inference);
  }

  // 5. Fusion & Sécurité
  domain::VcrcDecision vcrc_decision;
  domain::SorbentDecision sorb_decision;
  control::fuse_decisions(vcrc_rule, sorb_rule, vcrc_inference, sorb_inference, hard_block, vcrc_decision, sorb_decision);

  // 5b. Overrides manuels (Pi → ESP32)
  const auto& ov = wifi_hub.overrides();
  if (!hard_block) {
    if (ov.vcrc_enabled)   vcrc_decision.state  = ov.vcrc_value;
    if (ov.sorb_enabled)   sorb_decision.mode   = ov.sorb_value;
    if (ov.heater_enabled) sorb_decision.heater_on = ov.heater_value;
  }
  
  domain::OutputFrame requested_outputs = control::build_outputs(vcrc_decision, sorb_decision);
  domain::OutputFrame outputs = control::apply_output_guard(requested_outputs, output_guard_state, millis(), hard_block);
  
  // 6. Actionnement
  actuator_hub.apply(outputs, hard_block);

  // 7. IHM & Communication
  display_hub.update(sensors, derived, vcrc_decision, sorb_decision);
  wifi_hub.handle(sensors, derived, vcrc_decision, sorb_decision);
  
  static unsigned long last_log = 0;
  if (millis() - last_log > 2000) {
    last_log = millis();

    // [1] Capteurs bruts
    Serial.printf("[SENS] SHT:%s T:%.1f HR:%.1f | DHT22:%s Tin:%.1f Hin:%.1f | DHT11:%s Hout:%.1f | NTC:%s Tcond:%.1f\n",
      sensor_hub.hasSht() ? "OK" : "FB",
      sensors.temp_air_c, sensors.hr_pct,
      sensor_hub.lastDht22Ok() ? "OK" : "FB",
      sensors.temp_sorbent_internal_c, sensors.hr_in_pct,
      sensor_hub.lastDht11Ok() ? "OK" : "FB",
      sensors.hr_out_pct,
      sensor_hub.lastNtcOk() ? "OK" : "FB",
      sensors.temp_cond_c);

    // [2] Sécurité
    Serial.printf("[SAFE] BLOCK:%d | reserv:%.0f%% batt:%.0f%% float:%d Tcond:%.1f\n",
      hard_block,
      sensors.reservoir_level_pct, sensors.soc_battery_pct,
      sensors.float_switch_active, sensors.temp_cond_c);

    // [3] Dérivés
    Serial.printf("[DERIV] Tdp:%.1f w:%.2fg/kg dHR:%.1f daylight:%d\n",
      derived.dew_point_c, derived.humidity_ratio_gkg,
      derived.delta_hr_sorbent, derived.is_daylight);

    // [4] Règles
    Serial.printf("[RULE] VCRC:%d SORB:%d heat:%d\n",
      vcrc_rule.state, (int)sorb_rule.mode, sorb_rule.heater_on);

    // [5] IA
    Serial.printf("[ML  ] VCRC:%d SORB:%d heat:%d\n",
      vcrc_inference.state, (int)sorb_inference.mode, sorb_inference.heater_on);

    // [6] Sorties finales
    Serial.printf("[OUT ] VCRC:%d FAN:%d SERV:%d HEAT:%d\n---\n",
      outputs.vcrc_relay_on, outputs.fans_relay_on,
      outputs.servo_angle_deg, outputs.heater_relay_on);
  }

  delay(50);
}
