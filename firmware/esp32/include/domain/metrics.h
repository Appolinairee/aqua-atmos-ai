#pragma once

#include <cmath>
#include <algorithm>
#include "domain/types.h"
#include "config/constants.h"

namespace aqua_atmos::domain {

/**
 * @brief Calcul du point de rosée via la formule de Magnus-Tetens.
 * @return Température de rosée en °C.
 */
inline float compute_dew_point_c(float temp_c, float hr_pct) {
  const float rh_ratio = hr_pct / 100.0F;
  
  const float safe_rh_ratio = std::max(0.001F, rh_ratio);

  const float gamma = std::log(safe_rh_ratio) + ((config::MAGNUS_A * temp_c) / (config::MAGNUS_B + temp_c));
  const float dp = (config::MAGNUS_B * gamma) / (config::MAGNUS_A - gamma);
  return (dp < -50.0F) ? -50.0F : dp;
}

/**
 * @brief Calcul du rapport d'humidité (w) en grammes de vapeur par kg d'air sec.
 */
inline float compute_humidity_ratio_gkg(float temp_c, float hr_pct) {
  const float exponent = (config::MAGNUS_A * temp_c) / (temp_c + config::MAGNUS_B);
  const float saturation_hpa = 6.112F * std::exp(exponent);
  const float vapor_hpa = (hr_pct / 100.0F) * saturation_hpa;
  return 1000.0F * config::MOLAR_MASS_RATIO_WATER_AIR * vapor_hpa / (config::STANDARD_PRESSURE_HPA - vapor_hpa);
}

inline float compute_delta_hr_sorbent(float hr_in_pct, float hr_out_pct) {
  return hr_in_pct - hr_out_pct;
}

/**
 * @brief Enrichit la structure DerivedFrame pour le moteur de règles et l'IA.
 */
void enrich_derived_frame(const SensorFrame& sensors, DerivedFrame& derived);

}  // namespace aqua_atmos::domain
