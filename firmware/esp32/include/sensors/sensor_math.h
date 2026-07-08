#pragma once

namespace aqua_atmos::sensors {

/**
 * @brief Convertit les données brutes ADC en pourcentage (0-100%).
 */
inline float reservoir_percent_from_adc(int raw_adc) {
  const int clamped = raw_adc < 0 ? 0 : (raw_adc > 4095 ? 4095 : raw_adc);
  return (static_cast<float>(clamped) / 4095.0F) * 100.0F;
}

/**
 * @brief Convertit la fréquence du débitmètre YF-S201 en mL/min.
 * Formule constructeur : F (Hz) = 7.5 * Q (L/min)
 */
inline float flow_pulses_to_ml_min(float frequency_hz) {
    if (frequency_hz <= 0.0F) return 0.0F;
    return (frequency_hz / 7.5F) * 1000.0F;
}

}  // namespace aqua_atmos::sensors
