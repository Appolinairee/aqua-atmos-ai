#include "domain/metrics.h"
#include "config/constants.h"
#include <cmath>

namespace aqua_atmos::domain {

void enrich_derived_frame(const SensorFrame& sensors, DerivedFrame& derived) {
    constexpr float kPi = 3.14159265F;
    
    derived.hour_sin = std::sin(2.0F * kPi * static_cast<float>(sensors.hour_of_day) / 24.0F);
    derived.hour_cos = std::cos(2.0F * kPi * static_cast<float>(sensors.hour_of_day) / 24.0F);
    
    derived.thermal_lift_c = sensors.temp_air_c - sensors.temp_cond_c;
    derived.collector_gain_c = sensors.temp_collector_c - sensors.temp_air_c;
    
    derived.is_daylight = (sensors.solar_wm2 > config::SOLAR_DAYLIGHT_THRESHOLD) ? 1 : 0;
    derived.high_humidity_flag = (sensors.hr_pct >= config::VCRC_MIN_HR_PCT) ? 1 : 0;
    derived.battery_stress_flag = (sensors.soc_battery_pct <= config::BATTERY_CRITICAL_SOC + 5.0F) ? 1 : 0;
    derived.reservoir_high_flag = (sensors.reservoir_level_pct >= config::RESERVOIR_HIGH_THRESHOLD) ? 1 : 0;
}

}  // namespace aqua_atmos::domain
