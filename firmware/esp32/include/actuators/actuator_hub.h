#pragma once

#include "domain/types.h"

namespace aqua_atmos::actuators {

class ActuatorHub {
 public:
  void begin();
  void apply(const domain::OutputFrame& outputs);
};

}  // namespace aqua_atmos::actuators
