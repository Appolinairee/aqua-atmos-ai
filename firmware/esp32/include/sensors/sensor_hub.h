#pragma once

#include "domain/types.h"
#include "config/pins.h"
#include <Adafruit_SHTC3.h>
#include <DHT.h>

namespace aqua_atmos::sensors {

class SensorHub {
 public:
  void begin();
  domain::SensorFrame read();
  bool hasSht() const { return has_sht_ambient_; }

 private:
  float estimate_soc_from_battery_voltage(float battery_voltage) const;

  Adafruit_SHTC3 sht_ambient_ = Adafruit_SHTC3();

  DHT dht22_sorbent_  = DHT(config::DHT22_SORBENT_PIN,    DHT22);
  DHT dht11_evap_     = DHT(config::DHT11_EVAPORATOR_PIN, DHT11);

  bool has_sht_ambient_ = false;
};

}
