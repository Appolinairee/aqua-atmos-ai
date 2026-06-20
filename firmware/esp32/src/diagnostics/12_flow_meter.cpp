#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "config/pins.h"

volatile uint32_t pulse_count = 0;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void IRAM_ATTR onPulse() { pulse_count++; }

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  delay(500);
  lcd.init(); delay(200); lcd.clear(); lcd.backlight();
  lcd.print("Debitmetre GPIO14");

  pinMode(aqua_atmos::config::FLOW_METER_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(aqua_atmos::config::FLOW_METER_PIN), onPulse, FALLING);
  Serial.println("Debitmetre pret - fais couler de l'eau");
}

void loop() {
  delay(1000);
  uint32_t pulses = pulse_count;
  pulse_count = 0;

  float flow_lpm = pulses / 7.5f;  // K=7.5 pulses/L/min

  Serial.printf("Pulses: %u | Debit: %.2f L/min\n", pulses, flow_lpm);

  char buf[17];
  lcd.setCursor(0, 0);
  snprintf(buf, 17, "Pulses: %u       ", pulses);
  lcd.print(buf);
  lcd.setCursor(0, 1);
  snprintf(buf, 17, "%.2f L/min      ", flow_lpm);
  lcd.print(buf);
}
