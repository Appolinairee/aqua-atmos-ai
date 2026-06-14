#include <Arduino.h>
#include "sensors/sensor_hub.h"
#include "app/display_hub.h"
#include "control/rule_engine.h"
#include "control/inference_engine.h"
#include "domain/metrics.h"

using namespace aqua_atmos;

sensors::SensorHub sensor_hub;
app::DisplayHub display_hub;

void setup() {
  Serial.begin(115200);
  Serial.println("[DIAG] Inference Check Starting...");

  sensor_hub.begin();
  display_hub.begin();

  Serial.println("[DIAG] Hardware initialized. Monitoring AI Decisions...");
}

void loop() {
  // 1. Acquisition réelle via HAL de production
  domain::SensorFrame sensors = sensor_hub.read();

  // 2. Préparation des données dérivées
  domain::DerivedFrame derived;
  derived.dew_point_c = domain::compute_dew_point_c(sensors.temp_air_c, sensors.hr_pct);
  derived.humidity_ratio_gkg = domain::compute_humidity_ratio_gkg(sensors.temp_air_c, sensors.hr_pct);
  derived.delta_hr_sorbent = domain::compute_delta_hr_sorbent(sensors.hr_in_pct, sensors.hr_out_pct);
  domain::enrich_derived_frame(sensors, derived);

  // 3. Calcul par les règles métier
  domain::VcrcDecision vcrc_rule = control::decide_vcrc(sensors, derived);
  domain::SorbentDecision sorb_rule = control::decide_sorbent(sensors, derived);

  // 4. Calcul par l'IA (Inférence temps réel)
  domain::VcrcDecision vcrc_ml;
  domain::SorbentDecision sorb_ml;
  control::run_inference(sensors, derived, vcrc_ml, sorb_ml);

  // 5. Affichage spécialisé Diagnostic sur l'écran LCD
  // On n'utilise pas display_hub.update() ici car on veut un affichage de test spécifique
  static unsigned long last_disp = 0;
  if (millis() - last_disp > 2000) {
    last_disp = millis();
    
    Serial.printf("IA vs RULE | VCRC: %d/%d | SORB: %d/%d | HEAT: %d/%d\n",
                  vcrc_ml.state, vcrc_rule.state,
                  (int)sorb_ml.mode, (int)sorb_rule.mode,
                  sorb_ml.heater_on, sorb_rule.heater_on);
  }

  // On peut réutiliser la structure de l'écran pour afficher la comparaison
  display_hub.update(sensors, vcrc_ml, sorb_ml); // Affiche ce que l'IA propose

  delay(200); 
}
