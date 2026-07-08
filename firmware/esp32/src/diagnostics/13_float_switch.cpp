#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "config/pins.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  delay(500);
  lcd.init(); delay(200); lcd.clear(); lcd.backlight();
  pinMode(aqua_atmos::config::FLOAT_SWITCH_PIN, INPUT_PULLUP);
  Serial.println("Float switch GPIO32 - active LOW");
}

void loop() {
  bool active = (digitalRead(aqua_atmos::config::FLOAT_SWITCH_PIN) == LOW);
  Serial.printf("Float: %s\n", active ? "ACTIVE (reservoir plein)" : "INACTIF");

  char buf[17];
  lcd.setCursor(0, 0); lcd.print("Float Switch    ");
  lcd.setCursor(0, 1);
  snprintf(buf, 17, "%s", active ? "PLEIN           " : "VIDE            ");
  lcd.print(buf);

  delay(500);
}
