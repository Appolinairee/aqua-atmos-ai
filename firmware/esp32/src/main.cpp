#include <Arduino.h>
#include "sensors/sensor_hub.h"
#include "actuators/actuator_hub.h"
#include "app/display_hub.h"
#include "control/rule_engine.h"
#include "control/inference_engine.h"
#include "domain/metrics.h"

using namespace aqua_atmos;

sensors::SensorHub sensor_hub;
actuators::ActuatorHub actuator_hub;
app::DisplayHub display_hub;

void setup() {
  Serial.begin(115200);
  sensor_hub.begin();
  actuator_hub.begin();
  display_hub.begin();
  Serial.println("[AQUA-ATMOS] Ready");
}

void loop() {
  domain::SensorFrame sensors = sensor_hub.read();
  
  domain::DerivedFrame derived;
  derived.dew_point_c = domain::compute_dew_point_c(sensors.temp_air_c, sensors.hr_pct);
  derived.humidity_ratio_gkg = domain::compute_humidity_ratio_gkg(sensors.temp_air_c, sensors.hr_pct);
  derived.delta_hr_sorbent = domain::compute_delta_hr_sorbent(sensors.hr_in_pct, sensors.hr_out_pct);
  domain::enrich_derived_frame(sensors, derived);

  domain::VcrcDecision vcrc_rule = control::decide_vcrc(sensors, derived);
  domain::SorbentDecision sorb_rule = control::decide_sorbent(sensors, derived);
  
  domain::OutputFrame outputs = control::build_outputs(vcrc_rule, sorb_rule);
  actuator_hub.apply(outputs, control::is_hard_block(sensors));

  display_hub.update(sensors, vcrc_rule, sorb_rule);
  
  static unsigned long last_log = 0;
  if (millis() - last_log > 2000) {
    last_log = millis();
    Serial.printf("T:%.1f HR:%.1f | VCRC:%d SORB:%d HEAT:%d\n", 
      sensors.temp_air_c, sensors.hr_pct, 
      outputs.vcrc_relay_on, (int)sorb_rule.mode, outputs.heater_relay_on);
  }

  delay(100);
}
