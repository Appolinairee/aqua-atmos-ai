#pragma once

namespace aqua_atmos::config {

// Spécifications Hardware
constexpr float ADC_VREF = 3.3F;
constexpr float ADC_MAX_VALUE = 4095.0F;
constexpr float BATTERY_DIVIDER_RATIO = 11.0F; // Rapport du pont diviseur (R1+R2)/R2

// Seuils Batterie (LiFePO4 ou Plomb 12V)
constexpr float BATTERY_MAX_VOLTAGE = 12.7F;
constexpr float BATTERY_MIN_VOLTAGE = 11.5F;
constexpr float BATTERY_CRITICAL_SOC = 20.0F;

// Thermodynamique
constexpr float MAGNUS_A = 17.625F;
constexpr float MAGNUS_B = 243.04F;
constexpr float MOLAR_MASS_RATIO_WATER_AIR = 0.62198F;
constexpr float STANDARD_PRESSURE_HPA = 1013.25F;

// Seuils Thermiques
constexpr float CONDENSER_MAX_TEMP_C = 60.0F;

// Seuils Réservoir
constexpr float RESERVOIR_FULL_THRESHOLD = 95.0F;
constexpr float RESERVOIR_HIGH_THRESHOLD = 85.0F;

// Seuils Environnementaux (Production)
constexpr float VCRC_MIN_HR_PCT = 40.0F;
constexpr float VCRC_HYSTERESIS_PCT = 3.0F; // Marge pour l'extinction
constexpr float VCRC_MIN_DEW_POINT_C = 2.0F;
constexpr float VCRC_MIN_HUM_RATIO_GKG = 6.0F;

// Seuils Sorbant
constexpr float SORBENT_MIN_HR_PCT = 40.0F;
constexpr float SORBENT_SATURATION_DELTA = 1.0F;
constexpr float SOLAR_DAYLIGHT_THRESHOLD = 50.0F;  // W/m2 pour considérer qu'il fait jour
constexpr float SOLAR_PRODUCTION_THRESHOLD = 500.0F; // W/m2 pour régénération sans appoint
constexpr float HEATER_MIN_SOC_PCT = 35.0F;

}
