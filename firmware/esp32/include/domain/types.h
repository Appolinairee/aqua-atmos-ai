#pragma once

/**
 * @file types.h
 * @brief Définitions des structures de données transverses.
 */

namespace aqua_atmos::domain {

/**
 * @struct SensorFrame
 * @brief Données brutes issues des capteurs.
 */
struct SensorFrame {
  float temp_air_c = 0.0F;
  float hr_pct = 0.0F;
  float hr_in_pct = 0.0F;
  float hr_out_pct = 0.0F;
  float temp_cond_c = 0.0F;
  float temp_collector_c = 0.0F;
  float solar_wm2 = 0.0F;
  float pv_voltage = 0.0F;
  float soc_battery_pct = 0.0F;
  float reservoir_level_pct = 0.0F;
  int hour_of_day = 0;
};

/**
 * @struct DerivedFrame
 * @brief Variables calculées pour la décision IA/Règles.
 */
struct DerivedFrame {
  float dew_point_c = 0.0F;
  float humidity_ratio_gkg = 0.0F;
  float delta_hr_sorbent = 0.0F;
  
  float hour_sin = 0.0F;
  float hour_cos = 0.0F;
  float day_sin = 0.0F;
  float day_cos = 1.0F;
  float thermal_lift_c = 0.0F;
  float collector_gain_c = 0.0F;
  int is_daylight = 0;
  int high_humidity_flag = 0;
  int battery_stress_flag = 0;
  int reservoir_high_flag = 0;
};

struct VcrcDecision {
  bool state = false;
};

struct SorbentDecision {
  enum class Mode { Veille, Absorption, Regeneration };
  Mode mode = Mode::Veille;
  bool heater_on = false;
};

/**
 * @struct OutputFrame
 * @brief Consignes unifiées pour les actionneurs.
 */
struct OutputFrame {
  bool vcrc_relay_on = false;
  bool heater_relay_on = false;
  int vcrc_fan_pwm = 0;    // 0-255
  int sorbent_fan_pwm = 0; // 0-255, applied to both sorbent fans
  int servo_angle_deg = 0; // 0-180
};

}  // namespace aqua_atmos::domain
