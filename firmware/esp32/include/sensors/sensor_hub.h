#pragma once

#include "domain/types.h"
#include <Adafruit_SHT31.h>
#include <DHT.h>

namespace aqua_atmos::sensors {

class SensorHub {
 public:
  void begin();
  domain::SensorFrame read();

 private:
  float estimate_soc_from_battery_voltage(float battery_voltage) const;

  Adafruit_SHT31 sht_ambient_ = Adafruit_SHT31();
  Adafruit_SHT31 sht_sorbent_ = Adafruit_SHT31();
  DHT dht_condenser_ = DHT(5, DHT22); // DHT22 placé sur le condenseur

  bool has_sht_ambient_ = false;
  bool has_sht_sorbent_ = false;
};

}
