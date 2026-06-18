#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "config/pins.h"

/**
 * DIAGNOSTIC 02 : SCAN BUS I2C
 * Objectif : Detecter le LCD (0x27) et le SHT31 (0x44).
 */
void setup() {
  Serial.begin(115200);
  Wire.begin(aqua_atmos::config::I2C_SDA_PIN, aqua_atmos::config::I2C_SCL_PIN);
  Serial.println("\nI2C Scanner Starting...");
}

void loop() {
  byte error, address;
  int devices = 0;

  for(address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.printf("Device found at 0x%02X ", address);
      if (address == 0x27) Serial.print("(LCD)");
      if (address == 0x70) Serial.print("(SHTC3 Ambiant)");
      Serial.println();
      devices++;
    }
  }

  if (devices == 0) Serial.println("No I2C devices found\n");
  else Serial.printf("Scan complete. %d devices found.\n", devices);

  delay(5000);
}
