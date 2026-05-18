#pragma once

#include "domain/types.h"

namespace aqua_atmos::control {

constexpr float kReservoirFullPct = 95.0F;
constexpr float kBatteryLowPct = 20.0F;

inline bool is_reservoir_full(float reservoir_level_pct) {
  return reservoir_level_pct > kReservoirFullPct;
}

inline bool is_battery_low(float soc_battery_pct) {
  return soc_battery_pct < kBatteryLowPct;
}

inline bool is_hard_block(const domain::SensorFrame& sensors) {
  return is_reservoir_full(sensors.reservoir_level_pct) || is_battery_low(sensors.soc_battery_pct);
}

}  // namespace aqua_atmos::control
