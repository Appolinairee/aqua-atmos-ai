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

  // 1. Ambiance (SHT31 Primaire)
  if (has_sht_ambient_) {
    frame.temp_air_c = sht_ambient_.readTemperature();
    frame.hr_pct = sht_ambient_.readHumidity();
  }

  // 2. Condenseur (DHT22 dédié)
  frame.temp_cond_c = dht_condenser_.readTemperature();

  // 3. Sorbant (SHT31 Secondaire pour calcul Delta HR)
  frame.hr_in_pct = frame.hr_pct;
  if (has_sht_sorbent_) {
    frame.hr_out_pct = sht_sorbent_.readHumidity();
  } else {
    frame.hr_out_pct = frame.hr_pct; // Pas de gain si capteur absent
  }

  // Niveaux et Énergie
  frame.reservoir_level_pct = reservoir_percent_from_adc(analogRead(config::RESERVOIR_LEVEL_ADC_PIN));

  float bat_raw = static_cast<float>(analogRead(config::BATTERY_VOLTAGE_ADC_PIN));
  float bat_volt = (bat_raw / config::ADC_MAX_VALUE) * config::ADC_VREF * config::BATTERY_DIVIDER_RATIO;
  frame.pv_voltage = bat_volt; 
  frame.soc_battery_pct = estimate_soc_from_battery_voltage(bat_volt);

  // Valeurs par défaut pour les entrées non équipées
  frame.temp_collector_c = frame.temp_air_c + 5.0F;
  frame.solar_wm2 = (bat_volt > 13.0F) ? config::SOLAR_PRODUCTION_THRESHOLD : 0.0F;
  frame.hour_of_day = 12;

  return frame;
  }

  float SensorHub::estimate_soc_from_battery_voltage(float v) const {
  if (v >= config::BATTERY_MAX_VOLTAGE) return 100.0F;
  if (v <= config::BATTERY_MIN_VOLTAGE) return 0.0F;
  return (v - config::BATTERY_MIN_VOLTAGE) / (config::BATTERY_MAX_VOLTAGE - config::BATTERY_MIN_VOLTAGE) * 100.0F;
  }

}
