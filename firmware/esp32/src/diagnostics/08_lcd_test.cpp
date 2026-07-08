#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "config/pins.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  Wire.begin(aqua_atmos::config::I2C_SDA_PIN, aqua_atmos::config::I2C_SCL_PIN);
  delay(500);
  lcd.init();
  delay(200);
  lcd.clear();
  lcd.backlight();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("  AQUA WATER AI ");
  lcd.setCursor(0, 1);
  lcd.print("   OK - v1.0    ");
  delay(2000);
  lcd.setCursor(0, 0);
  lcd.print("  TEST LCD OK   ");
  lcd.setCursor(0, 1);
  lcd.print(" Bonjour Monde! ");
  delay(2000);
}
