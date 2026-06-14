#pragma once

#include "domain/types.h"
#include <LiquidCrystal_I2C.h>

namespace aqua_atmos::app {

class DisplayHub {
 public:
  void begin();
  void update(const domain::SensorFrame& sensors, const domain::VcrcDecision& vcrc, const domain::SorbentDecision& sorbent);

 private:
  LiquidCrystal_I2C lcd_ = LiquidCrystal_I2C(0x27, 16, 2);
  unsigned long last_update_ms_ = 0;
  int screen_index_ = 0;
};

}  // namespace aqua_atmos::app
