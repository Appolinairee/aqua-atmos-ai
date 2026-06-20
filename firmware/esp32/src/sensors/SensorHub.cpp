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
  delay(100); // stabilisation bus I2C

  // Capteur principal ambiance — 3 tentatives
  for (int i = 0; i < 3 && !has_sht_ambient_; i++) {
    has_sht_ambient_ = sht_ambient_.begin();
    if (!has_sht_ambient_) delay(50);
  }

  // Capteurs secondaires T/HR
  dht22_sorbent_.begin();   // GPIO5  : sorbant
  dht11_evap_.begin();      // GPIO18 : évaporateur

  pinMode(config::FLOAT_SWITCH_PIN,        INPUT_PULLUP);
  pinMode(config::RESERVOIR_LEVEL_ADC_PIN, INPUT);
  pinMode(config::BATTERY_VOLTAGE_ADC_PIN, INPUT);

  Serial.printf("[SensorHub] SHTC3 ambiant: %s\n", has_sht_ambient_ ? "OK" : "absent -> fallback");
}

domain::SensorFrame SensorHub::read() {
  domain::SensorFrame frame;

  // --- 1. Ambiance : SHTC3 (principal) ---
  if (!has_sht_ambient_) sht_ambient_.begin(&Wire);

  sensors_event_t hum_ev, tmp_ev;
  if (sht_ambient_.getEvent(&hum_ev, &tmp_ev)) {
    frame.temp_air_c = tmp_ev.temperature;
    frame.hr_pct     = hum_ev.relative_humidity;
    has_sht_ambient_ = true;
  } else {
    frame.temp_air_c = config::FALLBACK_TEMP_AIR_C;
    frame.hr_pct     = config::FALLBACK_HR_PCT;
  }

  // --- 2. Sorbant : DHT22 GPIO19 ---
  float t_sorb = dht22_sorbent_.readTemperature();
  float h_sorb = dht22_sorbent_.readHumidity();
  frame.temp_sorbent_internal_c = !isnan(t_sorb) ? t_sorb : frame.temp_air_c;
  frame.hr_in_pct               = !isnan(h_sorb) ? h_sorb : frame.hr_pct;

  // --- 3. Évaporateur : DHT11 GPIO18 ---
  float t_evap = dht11_evap_.readTemperature();
  float h_evap = dht11_evap_.readHumidity();
  frame.temp_cond_c = !isnan(t_evap) ? t_evap : config::FALLBACK_TEMP_COND_C;
  frame.hr_out_pct  = !isnan(h_evap) ? h_evap : (frame.hr_pct - 2.0F);

  // --- 4. Float switch ---
  frame.float_switch_active = (digitalRead(config::FLOAT_SWITCH_PIN) == LOW);

  // --- 5. ADC Réservoir ---
  int res_adc = analogRead(config::RESERVOIR_LEVEL_ADC_PIN);
  frame.reservoir_level_pct = reservoir_percent_from_adc(res_adc);
  if (frame.reservoir_level_pct < 0.1F)
    frame.reservoir_level_pct = config::FALLBACK_RESERVOIR_LEVEL_PCT;

  // --- 6. ADC Batterie ---
  float bat_adc  = static_cast<float>(analogRead(config::BATTERY_VOLTAGE_ADC_PIN));
  float bat_volt = (bat_adc / config::ADC_MAX_VALUE) * config::ADC_VREF * config::BATTERY_DIVIDER_RATIO;
  frame.soc_battery_pct = estimate_soc_from_battery_voltage(bat_volt);
  if (frame.soc_battery_pct < 1.0F) {
    frame.soc_battery_pct = config::FALLBACK_SOC_BATTERY_PCT;
    frame.pv_voltage      = config::FALLBACK_PV_VOLTAGE;
  } else {
    frame.pv_voltage = bat_volt;
  }

  // --- 7. Contexte estimé ---
  frame.temp_collector_c = frame.temp_air_c + 10.0F;
  frame.solar_wm2        = config::FALLBACK_SOLAR_WM2;
  frame.hour_of_day      = config::FALLBACK_HOUR_OF_DAY;

  return frame;
}

float SensorHub::estimate_soc_from_battery_voltage(float v) const {
  if (v >= config::BATTERY_MAX_VOLTAGE) return 100.0F;
  if (v <= config::BATTERY_MIN_VOLTAGE) return 0.0F;
  return (v - config::BATTERY_MIN_VOLTAGE) /
         (config::BATTERY_MAX_VOLTAGE - config::BATTERY_MIN_VOLTAGE) * 100.0F;
}

}
