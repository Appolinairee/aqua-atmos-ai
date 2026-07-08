#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
#include "config/pins.h"

using namespace aqua_atmos::config;

RTC_DS3231 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);

bool parseSetCommand(const String& line, DateTime& dt) {
  int year, month, day, hour, minute, second;
  int parsed = sscanf(line.c_str(), "SET %d-%d-%d %d:%d:%d",
                      &year, &month, &day, &hour, &minute, &second);

  if (parsed != 6) return false;
  if (year < 2024 || month < 1 || month > 12 || day < 1 || day > 31) return false;
  if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59) return false;

  dt = DateTime(year, month, day, hour, minute, second);
  return true;
}

void printRtcTime() {
  DateTime now = rtc.now();
  Serial.printf("RTC: %04d-%02d-%02d %02d:%02d:%02d\n",
                now.year(), now.month(), now.day(),
                now.hour(), now.minute(), now.second());
}

void printRtcOnLcd() {
  char buf[17];
  DateTime now = rtc.now();
  lcd.setCursor(0, 0);
  snprintf(buf, sizeof(buf), "RTC %02d:%02d:%02d  ", now.hour(), now.minute(), now.second());
  lcd.print(buf);
  lcd.setCursor(0, 1);
  snprintf(buf, sizeof(buf), "%04d-%02d-%02d    ", now.year(), now.month(), now.day());
  lcd.print(buf);
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("RTC DIAG");
  Serial.println("\n--- DIAGNOSTIC 05 : RTC SET/CHECK ---");
  Serial.println("RTC attendu: DS3231/DS1307 a l'adresse I2C 0x68");

  if (!rtc.begin()) {
    Serial.println("ERREUR: RTC introuvable sur le bus I2C.");
    while (true) delay(1000);
  }

  if (rtc.lostPower()) {
    Serial.println("INFO: RTC a perdu l'alimentation, reglage avec l'heure de compilation.");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  printRtcTime();
  printRtcOnLcd();
  Serial.println("Pour regler precisement: SET YYYY-MM-DD HH:MM:SS");
  Serial.println("Exemple: SET 2026-06-18 18:25:00");
}

void loop() {
  if (Serial.available()) {
    String line = Serial.readStringUntil('\n');
    line.trim();

    DateTime requested;
    if (parseSetCommand(line, requested)) {
      rtc.adjust(requested);
      Serial.println("OK: RTC regle.");
      printRtcTime();
      printRtcOnLcd();
    } else if (line.length() > 0) {
      Serial.println("Commande invalide. Format: SET YYYY-MM-DD HH:MM:SS");
    }
  }

  static unsigned long lastPrint = 0;
  if (millis() - lastPrint >= 5000) {
    lastPrint = millis();
    printRtcTime();
    printRtcOnLcd();
  }
}
