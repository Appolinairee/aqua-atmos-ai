#include <Arduino.h>
#include "app/display_hub.h"

namespace aqua_atmos::app {

void DisplayHub::begin() {
  lcd_.init();
  lcd_.backlight();
  lcd_.clear();
  lcd_.setCursor(0, 0);
  lcd_.print("AQUA-ATMOS V1.0");
  delay(1000);
}

void DisplayHub::update(const domain::SensorFrame& sensors, const domain::VcrcDecision& vcrc, const domain::SorbentDecision& sorbent) {
  if (millis() - last_update_ms_ < 3000) return;
  last_update_ms_ = millis();

  lcd_.clear();
  lcd_.setCursor(0, 0);

  switch (screen_index_) {
    case 0: // Ambiance
      lcd_.print("T:"); lcd_.print(sensors.temp_air_c, 1); lcd_.print("C ");
      lcd_.print("HR:"); lcd_.print(sensors.hr_pct, 0); lcd_.print("%");
      lcd_.setCursor(0, 1);
      lcd_.print("Bat:"); lcd_.print(sensors.soc_battery_pct, 0); lcd_.print("% ");
      lcd_.print("Res:"); lcd_.print(sensors.reservoir_level_pct, 0); lcd_.print("%");
      break;

    case 1: // Etats
      lcd_.print("VCRC:"); lcd_.print(vcrc.state ? "ON " : "OFF");
      lcd_.setCursor(0, 1);
      lcd_.print("Sorb:"); 
      if (sorbent.mode == domain::SorbentDecision::Mode::Absorption) lcd_.print("ABS");
      else if (sorbent.mode == domain::SorbentDecision::Mode::Regeneration) lcd_.print("REG");
      else lcd_.print("OFF");
      lcd_.print(" Heat:"); lcd_.print(sorbent.heater_on ? "ON" : "OFF");
      break;
  }

  screen_index_ = (screen_index_ + 1) % 2;
}

}  // namespace aqua_atmos::app
