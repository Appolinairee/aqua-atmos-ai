#pragma once

namespace aqua_atmos::sensors {

inline float reservoir_percent_from_adc(int raw_adc) {
  const int clamped = raw_adc < 0 ? 0 : (raw_adc > 4095 ? 4095 : raw_adc);
  return (static_cast<float>(clamped) / 4095.0F) * 100.0F;
}

}  // namespace aqua_atmos::sensors
