#include <Arduino.h>
#include "app/display_hub.h"

namespace aqua_atmos::app {

void DisplayHub::show(const char* l1, const char* l2) {
  lcd_.setCursor(0, 0); lcd_.print(l1);
  lcd_.setCursor(0, 1); lcd_.print(l2);
}

void DisplayHub::begin() {
  lcd_.init(); lcd_.backlight(); lcd_.clear();
  show("  AQUA WATER AI ", "  Initialisant..");
  delay(2000);
  lcd_.clear();
  show("  AQUA WATER AI ", "  Systeme Pret! ");
  delay(1000);
  lcd_.clear();
}

void DisplayHub::update(
    const domain::SensorFrame& s,
    const domain::DerivedFrame& d,
    const domain::VcrcDecision& vcrc,
    const domain::SorbentDecision& sorb) {

  if (millis() - last_update_ms_ < 4000) return;
  last_update_ms_ = millis();

  char l1[17], l2[17];

  switch (screen_index_) {
    case 0: {
      snprintf(l1, 17, "T:%.1fC  HR:%.0f%% ", s.temp_air_c, s.hr_pct);
      snprintf(l2, 17, "Rosee: %.1fC     ", d.dew_point_c);
      break;
    }
    case 1: {
      const char* vcrc_str = vcrc.state ? "ACTIF" : "ARRETE";
      const char* sorb_str =
          (sorb.mode == domain::SorbentDecision::Mode::Absorption)  ? "ABSORP" :
          (sorb.mode == domain::SorbentDecision::Mode::Regeneration) ? "REGEN"  : "VEILLE";
      snprintf(l1, 17, "VCRC  : %-8s", vcrc_str);
      snprintf(l2, 17, "Sorb  : %-8s", sorb_str);
      break;
    }
  }

  lcd_.clear();
  show(l1, l2);
  screen_index_ = (screen_index_ + 1) % 2;
}

}  // namespace aqua_atmos::app
