#pragma once

#include "domain/types.h"
#include "config/constants.h"

namespace aqua_atmos::control {

inline bool is_reservoir_full(float reservoir_level_pct) {
  return reservoir_level_pct > config::RESERVOIR_FULL_THRESHOLD;
}

inline bool is_battery_low(float soc_battery_pct) {
  return soc_battery_pct < config::BATTERY_CRITICAL_SOC;
}

inline bool is_thermal_hazard(float condenser_temp_c) {
  return condenser_temp_c > config::CONDENSER_MAX_TEMP_C;
}

inline bool is_hard_block(const domain::SensorFrame& sensors) {
  return is_reservoir_full(sensors.reservoir_level_pct) || 
         is_battery_low(sensors.soc_battery_pct) ||
         is_thermal_hazard(sensors.temp_cond_c);
}

}  // namespace aqua_atmos::control
