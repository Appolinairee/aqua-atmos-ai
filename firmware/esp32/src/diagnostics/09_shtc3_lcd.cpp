#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SHTC3.h>
#include <LiquidCrystal_I2C.h>
#include "config/pins.h"

Adafruit_SHTC3 shtc3;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  Wire.begin(aqua_atmos::config::I2C_SDA_PIN, aqua_atmos::config::I2C_SCL_PIN);
  delay(500);
  lcd.init(); delay(200); lcd.clear(); lcd.backlight();

  if (!shtc3.begin()) {
    Serial.println("SHTC3 non detecte!");
    lcd.setCursor(0, 0); lcd.print("SHTC3 ABSENT!   ");
    lcd.setCursor(0, 1); lcd.print("Verif câblage   ");
  } else {
    Serial.println("SHTC3 OK");
    lcd.setCursor(0, 0); lcd.print("SHTC3 OK        ");
  }
}

void loop() {
  sensors_event_t hum, tmp;
  shtc3.getEvent(&hum, &tmp);

  Serial.printf("T:%.1f C  HR:%.1f%%\n", tmp.temperature, hum.relative_humidity);

  char buf[17];
  lcd.setCursor(0, 0);
  snprintf(buf, sizeof(buf), "T: %.1f C       ", tmp.temperature);
  lcd.print(buf);
  lcd.setCursor(0, 1);
  snprintf(buf, sizeof(buf), "HR: %.1f %%      ", hum.relative_humidity);
  lcd.print(buf);

  delay(1000);
}
