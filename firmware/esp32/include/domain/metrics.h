#pragma once

#include <cmath>

namespace aqua_atmos::domain {

inline float compute_dew_point_c(float temp_c, float rel_humidity_pct) {
  constexpr float kA = 17.625F;
  constexpr float kB = 243.04F;
  const float humidity_ratio = rel_humidity_pct / 100.0F;
  if (humidity_ratio <= 0.0F) {
    return -50.0F;
  }
  const float gamma = std::log(humidity_ratio) + ((kA * temp_c) / (kB + temp_c));
  return (kB * gamma) / (kA - gamma);
}

inline float compute_humidity_ratio_gkg(float temp_c, float rel_humidity_pct) {
  constexpr float kPressureHpa = 1013.25F;
  const float saturation_hpa = 6.112F * std::exp((17.67F * temp_c) / (temp_c + 243.5F));
  const float vapor_hpa = (rel_humidity_pct / 100.0F) * saturation_hpa;
  return 1000.0F * 0.62198F * vapor_hpa / (kPressureHpa - vapor_hpa);
}

inline float compute_delta_hr_sorbent(float hr_in_pct, float hr_out_pct) {
  return hr_in_pct - hr_out_pct;
}

inline void enrich_derived_frame(const SensorFrame& sensors, DerivedFrame& derived) {
  constexpr float kPi = 3.14159265F;
  
  derived.hour_sin = std::sin(2.0F * kPi * static_cast<float>(sensors.hour_of_day) / 24.0F);
  derived.hour_cos = std::cos(2.0F * kPi * static_cast<float>(sensors.hour_of_day) / 24.0F);
  
  // Note: assuming day 0 for now as we don't have day of year in SensorFrame
  derived.day_sin = 0.0F; 
  derived.day_cos = 1.0F;
  
  derived.thermal_lift_c = sensors.temp_air_c - sensors.temp_cond_c;
  derived.collector_gain_c = sensors.temp_collector_c - sensors.temp_air_c;
  derived.is_daylight = (sensors.solar_wm2 > 0) ? 1 : 0;
  derived.high_humidity_flag = (sensors.hr_pct >= 70.0F) ? 1 : 0;
  derived.battery_stress_flag = (sensors.soc_battery_pct <= 25.0F) ? 1 : 0;
  derived.reservoir_high_flag = (sensors.reservoir_level_pct >= 80.0F) ? 1 : 0;
}

}  // namespace aqua_atmos::domain
