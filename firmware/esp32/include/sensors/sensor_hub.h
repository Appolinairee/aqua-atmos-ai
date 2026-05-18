#pragma once

#include "domain/types.h"

namespace aqua_atmos::sensors {

class SensorHub {
 public:
  void begin();
  domain::SensorFrame read();

 private:
  float estimate_solar_from_pv_voltage(float pv_voltage) const;
  float estimate_soc_from_battery_voltage(float battery_voltage) const;
};

}  // namespace aqua_atmos::sensors
