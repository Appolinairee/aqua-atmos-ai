#include <Arduino.h>
#include <Wire.h>
#include "sensors/sensor_hub.h"
#include "sensors/sensor_math.h"
#include "config/pins.h"
#include "config/sensor_addresses.h"
#include "config/constants.h"

namespace aqua_atmos::sensors {

void SensorHub::begin() {
  Wire.begin(config::I2C_SDA_PIN, config::I2C_SCL_PIN);
  has_sht_ambient_ = sht_ambient_.begin(config::SHT31_AIR_AMBIENT_I2C_ADDRESS);
  has_sht_sorbent_ = sht_sorbent_.begin(config::SHT31_SORBENT_I2C_ADDRESS);
  dht_condenser_.begin();

  pinMode(config::RESERVOIR_LEVEL_ADC_PIN, INPUT);
  pinMode(config::BATTERY_VOLTAGE_ADC_PIN, INPUT);
}

domain::SensorFrame SensorHub::read() {
  domain::SensorFrame frame;

  // 1. Lecture physique
  float t_sht = has_sht_ambient_ ? sht_ambient_.readTemperature() : NAN;
  float h_sht = has_sht_ambient_ ? sht_ambient_.readHumidity() : NAN;
  float t_dht = dht_condenser_.readTemperature();
  float h_dht = dht_condenser_.readHumidity();
  
  float res_adc = static_cast<float>(analogRead(config::RESERVOIR_LEVEL_ADC_PIN));
  float bat_adc = static_cast<float>(analogRead(config::BATTERY_VOLTAGE_ADC_PIN));

  // 2. Application des Fallbacks (uniquement si lecture invalide ou proche de zéro)
  
  // Ambiance
  if (!isnan(t_sht)) {
    frame.temp_air_c = t_sht;
    frame.hr_pct = h_sht;
  } else if (!isnan(t_dht)) {
    frame.temp_air_c = t_dht;
    frame.hr_pct = h_dht;
  } else {
    frame.temp_air_c = config::FALLBACK_TEMP_AIR_C;
    frame.hr_pct = config::FALLBACK_HR_PCT;
  }

  // Condenseur
  frame.temp_cond_c = (!isnan(t_dht)) ? t_dht : config::FALLBACK_TEMP_COND_C;

  // Sorbant
  frame.hr_in_pct = frame.hr_pct;
  frame.hr_out_pct = (has_sht_sorbent_) ? sht_sorbent_.readHumidity() : (frame.hr_pct - 2.0F);

  // Énergie & Niveaux
  frame.reservoir_level_pct = reservoir_percent_from_adc(static_cast<int>(res_adc));
  if (frame.reservoir_level_pct < 0.1F) frame.reservoir_level_pct = config::FALLBACK_RESERVOIR_LEVEL_PCT;

  float bat_volt = (bat_adc / config::ADC_MAX_VALUE) * config::ADC_VREF * config::BATTERY_DIVIDER_RATIO;
  frame.soc_battery_pct = estimate_soc_from_battery_voltage(bat_volt);
  
  if (frame.soc_battery_pct < 1.0F) {
    frame.soc_battery_pct = config::FALLBACK_SOC_BATTERY_PCT;
    frame.pv_voltage = config::FALLBACK_PV_VOLTAGE;
  } else {
    frame.pv_voltage = bat_volt;
  }

  // Autres constantes
  frame.temp_collector_c = frame.temp_air_c + 10.0F; 
  frame.solar_wm2 = config::FALLBACK_SOLAR_WM2;
  frame.hour_of_day = config::FALLBACK_HOUR_OF_DAY;

  return frame;
}

float SensorHub::estimate_soc_from_battery_voltage(float v) const {
  if (v >= config::BATTERY_MAX_VOLTAGE) return 100.0F;
  if (v <= config::BATTERY_MIN_VOLTAGE) return 0.0F;
  return (v - config::BATTERY_MIN_VOLTAGE) / (config::BATTERY_MAX_VOLTAGE - config::BATTERY_MIN_VOLTAGE) * 100.0F;
}

}
