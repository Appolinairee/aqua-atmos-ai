#include <Arduino.h>
#include <Wire.h>
#include <math.h>
#include "sensors/sensor_hub.h"
#include "sensors/sensor_math.h"
#include "config/pins.h"
#include "config/sensor_addresses.h"
#include "config/constants.h"
#include "config/fallbacks.h"

namespace aqua_atmos::sensors {

static volatile uint32_t s_flow_pulses = 0;

void IRAM_ATTR flow_isr() { s_flow_pulses++; }

void SensorHub::begin() {
  Wire.begin(config::I2C_SDA_PIN, config::I2C_SCL_PIN);
  Wire.setTimeOut(200);
  delay(300);

  has_rtc_ = rtc_.begin();
  delay(100);

  Wire.setTimeOut(200);  // après rtc_.begin() qui reset Wire

  for (int i = 0; i < 5 && !has_sht_ambient_; i++) {
    has_sht_ambient_ = sht_ambient_.begin();
    delay(100);
  }

  dht22_sorbent_.begin();
  dht11_evap_.begin();

  analogSetAttenuation(ADC_11db);
  pinMode(config::FLOAT_SWITCH_PIN,        INPUT_PULLUP);
  pinMode(config::RESERVOIR_LEVEL_ADC_PIN, INPUT);
  pinMode(config::BATTERY_VOLTAGE_ADC_PIN, INPUT);
  pinMode(config::FLOW_METER_PIN,          INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(config::FLOW_METER_PIN), flow_isr, FALLING);

  Serial.printf("[SensorHub] SHTC3:%s RTC:%s\n",
    has_sht_ambient_ ? "OK" : "fallback",
    has_rtc_         ? "OK" : "fallback");
}

float SensorHub::read_ntc_temp_c() {
  long sum = 0;
  for (int i = 0; i < 32; i++) { sum += analogRead(config::NTC_10K_ANALOG_PIN); delay(2); }
  float v = (sum / 32) * 3.3f / 4095.0f;
  if (v < 0.1f || v > 3.2f) {
    last_ntc_ok_ = false;
    return config::FALLBACK_TEMP_COND_C;
  }
  float r_ntc = 1000.0f * (3.3f - v) / v;
  float t = 1.0f / (1.0f / 298.15f + log(r_ntc / 10000.0f) / 3950.0f) - 273.15f;
  if (t < -10.0f || t > 100.0f) {
    last_ntc_ok_ = false;
    return config::FALLBACK_TEMP_COND_C;
  }
  last_ntc_ok_ = true;
  return t;
}

float SensorHub::read_flow_lpm() {
  uint32_t pulses = s_flow_pulses;
  s_flow_pulses = 0;
  return pulses / 7.5f;
}

domain::SensorFrame SensorHub::read() {
  domain::SensorFrame frame;

  // --- 1. SHTC3 ---
  static uint8_t sht_fail_streak = 0;
  static unsigned long sht_retry_at = 0;

  if (!has_sht_ambient_ && millis() > sht_retry_at) {
    has_sht_ambient_ = sht_ambient_.begin(&Wire);
    if (!has_sht_ambient_) sht_retry_at = millis() + 5000;
  }

  if (has_sht_ambient_) {
    sensors_event_t hum_ev, tmp_ev;
    if (sht_ambient_.getEvent(&hum_ev, &tmp_ev)) {
      frame.temp_air_c = tmp_ev.temperature;
      frame.hr_pct     = hum_ev.relative_humidity;
      sht_fail_streak  = 0;
    } else {
      sht_fail_streak++;
      if (sht_fail_streak > 5) { has_sht_ambient_ = false; sht_retry_at = millis() + 5000; }
      frame.temp_air_c = config::FALLBACK_TEMP_AIR_C;
      frame.hr_pct     = config::FALLBACK_HR_PCT;
    }
  } else {
    frame.temp_air_c = config::FALLBACK_TEMP_AIR_C;
    frame.hr_pct     = config::FALLBACK_HR_PCT;
  }

  // --- 2. DHT22 sorbant ---
  float t_sorb = dht22_sorbent_.readTemperature();
  float h_sorb = dht22_sorbent_.readHumidity();
  last_dht22_ok_ = !isnan(t_sorb) && !isnan(h_sorb);
  frame.temp_sorbent_internal_c = last_dht22_ok_ ? t_sorb : frame.temp_air_c;
  frame.hr_in_pct               = last_dht22_ok_ ? h_sorb : frame.hr_pct;

  // --- 3. DHT11 évaporateur ---
  float t_evap = dht11_evap_.readTemperature();
  float h_evap = dht11_evap_.readHumidity();
  last_dht11_ok_ = !isnan(t_evap) && !isnan(h_evap);
  frame.hr_out_pct = last_dht11_ok_ ? h_evap : (frame.hr_pct - 2.0f);

  // --- 4. NTC condenseur ---
  frame.temp_cond_c = read_ntc_temp_c();

  // --- 5. Débitmètre ---
  frame.water_flow_ml_min = read_flow_lpm() * 1000.0f;

  // --- 6. Float switch (fixé jusqu'à validation câblage) ---
  frame.float_switch_active = false;

  // --- 7. Réservoir (fixé jusqu'à validation capteur) ---
  frame.reservoir_level_pct = config::FALLBACK_RESERVOIR_LEVEL_PCT;

  // --- 8. Batterie ---
  float bat_adc  = static_cast<float>(analogRead(config::BATTERY_VOLTAGE_ADC_PIN));
  float bat_volt = (bat_adc / config::ADC_MAX_VALUE) * config::ADC_VREF * config::BATTERY_DIVIDER_RATIO;
  frame.soc_battery_pct = estimate_soc_from_battery_voltage(bat_volt);
  if (frame.soc_battery_pct < 1.0f) {
    frame.soc_battery_pct = config::FALLBACK_SOC_BATTERY_PCT;
    frame.pv_voltage      = config::FALLBACK_PV_VOLTAGE;
  } else {
    frame.pv_voltage = bat_volt;
  }

  // --- 9. RTC ---
  if (has_rtc_) {
    frame.hour_of_day = rtc_.now().hour();
  } else {
    frame.hour_of_day = config::FALLBACK_HOUR_OF_DAY;
  }

  frame.temp_collector_c = frame.temp_air_c + 10.0f;
  frame.solar_wm2        = config::FALLBACK_SOLAR_WM2;

  return frame;
}

float SensorHub::estimate_soc_from_battery_voltage(float v) const {
  if (v >= config::BATTERY_MAX_VOLTAGE) return 100.0f;
  if (v <= config::BATTERY_MIN_VOLTAGE) return 0.0f;
  return (v - config::BATTERY_MIN_VOLTAGE) /
         (config::BATTERY_MAX_VOLTAGE - config::BATTERY_MIN_VOLTAGE) * 100.0f;
}

}
