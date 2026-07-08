#include <Arduino.h>
#include "app/display_hub.h"

namespace aqua_atmos::app {

void DisplayHub::show(const char* l1, const char* l2) {
  lcd_.setCursor(0, 0); lcd_.print(l1);
  lcd_.setCursor(0, 1); lcd_.print(l2);
}

void DisplayHub::show_blocks(uint8_t top_count, uint8_t bottom_count) {
  lcd_.clear();
  lcd_.setCursor(0, 0);
  for (uint8_t i = 0; i < 16; i++) lcd_.write(i < top_count ? byte(255) : ' ');
  lcd_.setCursor(0, 1);
  for (uint8_t i = 0; i < 16; i++) lcd_.write(i < bottom_count ? byte(255) : ' ');
}

void DisplayHub::boot_animation() {
  // 1. Essuyage de l'écran (balayage de blocs physiques)
  for (uint8_t i = 0; i <= 16; i++) {
    show_blocks(i, 0);
    delay(5);
  }
  for (uint8_t i = 0; i <= 16; i++) {
    show_blocks(16, i);
    delay(5);
  }
  delay(20);

  // 2. Révélation progressive (effet machine à écrire synchrone)
  const char* title = "   AQUA-ATMOS   ";
  const char* subtitle = " ATMOS TO WATER ";
  char line1[17] = "                ";
  char line2[17] = "                ";
  for (uint8_t i = 0; i < 16; i++) {
    line1[i] = title[i];
    line2[i] = subtitle[i];
    lcd_.clear();
    show(line1, line2);
    delay(10);
  }
  delay(100);

  // 3. Séquence de Self-Test (Diagnostic matériel valorisant)
  const char* tests[][2] = {
    {"CHECKING SHTC3..", "STATUS:   OK    "},
    {"CHECKING DHT22..", "STATUS:   OK    "},
    {"CHECKING DHT11..", "STATUS:   OK    "},
    {"CHECKING NTC....", "STATUS:   OK    "},
    {"CHECKING VALVES.", "STATUS:   OK    "},
    {"STARTING WIFI AP", "SSID: AquaAtmos "}
  };
  for (uint8_t i = 0; i < 6; i++) {
    lcd_.clear();
    show(tests[i][0], tests[i][1]);
    delay(50);
  }
  delay(30);

  // 4. Barre de chargement progressive 0-100%
  for (uint8_t i = 0; i <= 14; i++) {
    lcd_.clear();
    char pct[17];
    snprintf(pct, sizeof(pct), "LOADING SYS: %d%%", (i * 100) / 14);
    char bar[17] = "[            ] ";
    for (uint8_t j = 0; j < i; j++) {
      bar[j + 1] = '=';
    }
    if (i > 0 && i < 13) bar[i] = '>';
    show(pct, bar);
    delay(10); // Effet de chargement ultra rapide
  }
  delay(60);

  // 5. Clignotement de mise en route finale (Prêt)
  for (uint8_t i = 0; i < 3; i++) {
    lcd_.clear();
    show("  SYSTEM READY  ", "   AUTO ACTIVE  ");
    delay(100);
    lcd_.clear();
    delay(50);
  }
}

void DisplayHub::begin() {
  lcd_.init(); lcd_.backlight(); lcd_.clear();
  Serial.println("[LCD] init OK addr:0x27");
  boot_animation();
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
      const char* sorb_str =
          (sorb.mode == domain::SorbentDecision::Mode::Absorption)   ? "SORB ON" :
          (sorb.mode == domain::SorbentDecision::Mode::Regeneration) ? "REGEN"   : "SORB --";
      snprintf(l1, 17, "MODE AUTO    OK ");
      snprintf(l2, 17, "VCRC %-3s %-7s", vcrc.state ? "ON" : "OFF", sorb_str);
      break;
    }
    case 1: {
      if (s.sht_ambient_ok) {
        snprintf(l1, 17, "AIR: %4.1fC     ", s.temp_air_c);
        snprintf(l2, 17, "HUM: %3.0f%%      ", s.hr_pct);
      } else {
        snprintf(l1, 17, "AIR: --.-C     ");
        snprintf(l2, 17, "HUM: --%%       ");
      }
      break;
    }
    case 2: {
      const float liters_hour = s.water_flow_ml_min * 0.06f;
      char sensor_state[5];
      sensor_state[0] = s.sht_ambient_ok ? 'S' : '-';
      sensor_state[1] = s.dht22_sorbent_ok ? 'D' : '-';
      sensor_state[2] = s.dht11_evap_ok ? 'E' : '-';
      sensor_state[3] = s.ntc_ok ? 'N' : '-';
      sensor_state[4] = '\0';
      snprintf(l1, 17, "WATER:%4.1fL/h ", liters_hour);
      snprintf(l2, 17, "R:%3.0f%% C:%s  ", s.reservoir_level_pct, sensor_state);
      break;
    }
  }

  if (strcmp(l1, last_l1_) != 0 || strcmp(l2, last_l2_) != 0) {
    lcd_.clear();
    show(l1, l2);
    strncpy(last_l1_, l1, 17);
    strncpy(last_l2_, l2, 17);
  }
  Serial.printf("[LCD] page%d | L1:'%s' L2:'%s'\n", screen_index_, l1, l2);
  screen_index_ = (screen_index_ + 1) % 3;
}

}  // namespace aqua_atmos::app
