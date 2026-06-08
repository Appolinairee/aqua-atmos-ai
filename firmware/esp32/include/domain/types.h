#pragma once

namespace aqua_atmos::domain {

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

struct DerivedFrame {
  float dew_point_c = 0.0F;
  float humidity_ratio_gkg = 0.0F;
  float delta_hr_sorbent = 0.0F;
  
  // Missing features for ML models
  float hour_sin = 0.0F;
  float hour_cos = 0.0F;
  float day_sin = 0.0F;
  float day_cos = 0.0F;
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
  enum class Mode {
    Veille,
    Absorption,
    Regeneration,
  };

  Mode mode = Mode::Veille;
  bool heater_on = false;
};

struct OutputFrame {
  bool vcrc_relay_on = false;
  bool heater_relay_on = false;
  int vcrc_fan_pwm = 0;
  int sorbent_fan_pwm = 0;
  int servo_angle_deg = 0;
};

}  // namespace aqua_atmos::domain
