#pragma once

namespace aqua_atmos::config {

constexpr float FALLBACK_TEMP_AIR_C = 25.0F;
constexpr float FALLBACK_HR_PCT = 60.0F;
constexpr float FALLBACK_TEMP_COND_C = 20.0F;
constexpr float FALLBACK_RESERVOIR_LEVEL_PCT = 30.0F;
constexpr float FALLBACK_SOC_BATTERY_PCT = 100.0F; // Modifié pour le secteur direct
constexpr float FALLBACK_PV_VOLTAGE = 12.5F;
constexpr float FALLBACK_SOLAR_WM2 = 0.0F;  // pas de capteur solaire -> soleil considéré absent
constexpr int FALLBACK_HOUR_OF_DAY = 12;

}  // namespace aqua_atmos::config
