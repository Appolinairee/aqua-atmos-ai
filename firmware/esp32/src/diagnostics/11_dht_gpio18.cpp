#include <Arduino.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

DHT dht(5, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  delay(500);
  lcd.init(); delay(200); lcd.clear(); lcd.backlight();
  dht.begin();
  delay(2000);
  Serial.println("DHT11 GPIO5 test");
}

void loop() {
  delay(3000);
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (isnan(t)) {
    Serial.println("GPIO5: ECHEC");
    lcd.setCursor(0, 0); lcd.print("GPIO5: ECHEC   ");
    lcd.setCursor(0, 1); lcd.print("Verif cablage   ");
  } else {
    Serial.printf("GPIO5: %.1fC  %.1f%%\n", t, h);
    char buf[17];
    lcd.setCursor(0, 0);
    snprintf(buf, 17, "T: %.1f C        ", t);
    lcd.print(buf);
    lcd.setCursor(0, 1);
    snprintf(buf, 17, "HR: %.1f %%       ", h);
    lcd.print(buf);
  }
}
