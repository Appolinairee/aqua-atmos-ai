#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  pinMode(5, OUTPUT);
  Serial.println("GPIO5 test - ON/OFF toutes les secondes");
}

void loop() {
  digitalWrite(5, HIGH);
  Serial.println("GPIO27 HIGH");
  delay(1000);
  digitalWrite(5, LOW);
  Serial.println("GPIO27 LOW");
  delay(1000);
}
