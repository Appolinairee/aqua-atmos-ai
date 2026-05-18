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

}  // namespace aqua_atmos::domain
