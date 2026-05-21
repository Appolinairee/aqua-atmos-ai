#include <Arduino.h>
#include "app/test_modes.h"

void setup() {
  Serial.begin(115200);
  delay(800);
  aqua_atmos::app::setup_selected_mode();
}

void loop() {
  aqua_atmos::app::loop_selected_mode();
}
