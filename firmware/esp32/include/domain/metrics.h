#pragma once

#include <cmath>
#include "domain/types.h"

namespace aqua_atmos::domain {

/**
 * @brief Calcul du point de rosée via la formule de Magnus-Tetens.
 * @return Température de rosée en °C.
 */
inline float compute_dew_point_c(float temp_c, float hr_pct) {
  constexpr float kA = 17.625F;
  constexpr float kB = 243.04F;
  const float rh_ratio = hr_pct / 100.0F;
  
  if (rh_ratio <= 0.0F) return -50.0F;

  const float gamma = std::log(rh_ratio) + ((kA * temp_c) / (kB + temp_c));
  return (kB * gamma) / (kA - gamma);
}

/**
 * @brief Calcul du rapport d'humidité (w) en grammes de vapeur par kg d'air sec.
 */
inline float compute_humidity_ratio_gkg(float temp_c, float hr_pct) {
  constexpr float kPressureHpa = 1013.25F;
  const float saturation_hpa = 6.112F * std::exp((17.67F * temp_c) / (temp_c + 243.5F));
  const float vapor_hpa = (hr_pct / 100.0F) * saturation_hpa;
  return 1000.0F * 0.62198F * vapor_hpa / (kPressureHpa - vapor_hpa);
}

inline float compute_delta_hr_sorbent(float hr_in_pct, float hr_out_pct) {
  return hr_in_pct - hr_out_pct;
}

/**
 * @brief Enrichit la structure DerivedFrame pour le moteur de règles et l'IA.
 */
void enrich_derived_frame(const SensorFrame& sensors, DerivedFrame& derived);

}  // namespace aqua_atmos::domain
