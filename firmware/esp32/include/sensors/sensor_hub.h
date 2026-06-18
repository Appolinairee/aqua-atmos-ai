#pragma once

#include "domain/types.h"
#include <Adafruit_SHTC3.h>
#include <DHT.h>

namespace aqua_atmos::sensors {

class SensorHub {
 public:
  void begin();
  domain::SensorFrame read();

 private:
  float estimate_soc_from_battery_voltage(float battery_voltage) const;

  Adafruit_SHTC3 sht_ambient_ = Adafruit_SHTC3();
  Adafruit_SHTC3 sht_sorbent_ = Adafruit_SHTC3();
  DHT dht_condenser_ = DHT(5, DHT22); // DHT22 placé sur le condenseur

  bool has_sht_ambient_ = false;
  bool has_sht_sorbent_ = false;
};

}
