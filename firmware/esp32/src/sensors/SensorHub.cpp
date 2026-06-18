#include <Arduino.h>
#include <Wire.h>
#include "sensors/sensor_hub.h"
#include "sensors/sensor_math.h"
#include "config/pins.h"
#include "config/sensor_addresses.h"
#include "config/constants.h"
#include "config/fallbacks.h"

namespace aqua_atmos::sensors {

void SensorHub::begin() {
  Wire.begin(config::I2C_SDA_PIN, config::I2C_SCL_PIN);
  has_sht_ambient_ = sht_ambient_.begin();
  has_sht_sorbent_ = sht_sorbent_.begin();
  dht_condenser_.begin();

  pinMode(config::RESERVOIR_LEVEL_ADC_PIN, INPUT);
  pinMode(config::BATTERY_VOLTAGE_ADC_PIN, INPUT);
}

domain::SensorFrame SensorHub::read() {
  domain::SensorFrame frame;

  // 1. Lecture physique
  float t_sht = NAN;
  float h_sht = NAN;
  if (has_sht_ambient_) {
    sensors_event_t humidity, temp;
    sht_ambient_.getEvent(&humidity, &temp);
    t_sht = temp.temperature;
    h_sht = humidity.relative_humidity;
  }
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
  float h_out = frame.hr_pct - 2.0F;
  if (has_sht_sorbent_) {
    sensors_event_t h_event, t_event;
    sht_sorbent_.getEvent(&h_event, &t_event);
    h_out = h_event.relative_humidity;
  }
  frame.hr_out_pct = h_out;

  // Énergie & Niveaux
  // Réservoir : lecture brute, avec fallback si capteur débranché (lit 0)
  frame.reservoir_level_pct = reservoir_percent_from_adc(static_cast<int>(res_adc));
  if (frame.reservoir_level_pct < 0.1F) frame.reservoir_level_pct = config::FALLBACK_RESERVOIR_LEVEL_PCT;

  // Batterie : calcul du SOC basé sur la tension
  float bat_volt = (bat_adc / config::ADC_MAX_VALUE) * config::ADC_VREF * config::BATTERY_DIVIDER_RATIO;
  frame.soc_battery_pct = estimate_soc_from_battery_voltage(bat_volt);
  
  // Fallback si la batterie est indétectable (secteur direct sans capteur)
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
