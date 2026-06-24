#pragma once

#include "domain/types.h"
#include "config/pins.h"
#include <Adafruit_SHTC3.h>
#include <DHT.h>
#include <RTClib.h>

namespace aqua_atmos::sensors {

class SensorHub {
 public:
  void begin();
  domain::SensorFrame read();
  bool hasSht() const { return has_sht_ambient_; }
  bool lastDht22Ok() const { return last_dht22_ok_; }
  bool lastDht11Ok() const { return last_dht11_ok_; }
  bool lastNtcOk() const { return last_ntc_ok_; }

 private:
  float estimate_soc_from_battery_voltage(float battery_voltage) const;

  Adafruit_SHTC3 sht_ambient_ = Adafruit_SHTC3();

  DHT dht22_sorbent_  = DHT(config::DHT22_SORBENT_PIN,    DHT22);
  DHT dht11_evap_     = DHT(config::DHT11_EVAPORATOR_PIN, DHT11);

  bool has_sht_ambient_ = false;
  bool has_rtc_         = false;
  bool last_dht22_ok_   = false;
  bool last_dht11_ok_   = false;
  bool last_ntc_ok_     = false;
  RTC_DS3231 rtc_;

  static constexpr int   FLOAT_DEBOUNCE_COUNT = 5;
  int float_low_count_ = 0;

  float read_ntc_temp_c();
  float read_flow_lpm();

};

}
