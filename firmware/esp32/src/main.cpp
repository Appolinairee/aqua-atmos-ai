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
  
  // 2. Traitement & Calculs
  domain::DerivedFrame derived;
  derived.dew_point_c = domain::compute_dew_point_c(sensors.temp_air_c, sensors.hr_pct);
  derived.humidity_ratio_gkg = domain::compute_humidity_ratio_gkg(sensors.temp_air_c, sensors.hr_pct);
  derived.delta_hr_sorbent = domain::compute_delta_hr_sorbent(sensors.hr_in_pct, sensors.hr_out_pct);
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
  
  domain::OutputFrame requested_outputs = control::build_outputs(vcrc_decision, sorb_decision);
  domain::OutputFrame outputs = control::apply_output_guard(requested_outputs, output_guard_state, millis(), hard_block);
  
  // 6. Actionnement
  actuator_hub.apply(outputs, hard_block);

  // 7. IHM & Communication
  display_hub.update(sensors, vcrc_decision, sorb_decision);
  wifi_hub.handle(sensors, vcrc_decision, sorb_decision);
  
  static unsigned long last_log = 0;
  if (millis() - last_log > 2000) {
    last_log = millis();
    Serial.printf("T:%.1f HR:%.1f | VCRC:%d SORB:%d\n", 
      sensors.temp_air_c, sensors.hr_pct, 
      outputs.vcrc_relay_on, (int)sorb_decision.mode);
  }

  delay(50);
}
