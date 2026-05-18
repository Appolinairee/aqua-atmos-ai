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
