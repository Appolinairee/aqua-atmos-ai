#pragma once

#include "domain/types.h"
#include <ESP32Servo.h>

namespace aqua_atmos::actuators {

class ActuatorHub {
 public:
  void begin();
  void apply(const domain::OutputFrame& outputs, bool has_error = false);

 private:
  Servo sorbent_servo_;
  
  const int ch_vcrc = 0;
  const int ch_sorb1 = 1;
  const int ch_sorb2 = 2;
};

}
