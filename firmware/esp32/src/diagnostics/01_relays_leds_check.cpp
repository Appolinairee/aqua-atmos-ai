#include <Arduino.h>
#include "config/pins.h"

using namespace aqua_atmos::config;

/**
 * DIAGNOSTIC 01 : RELAIS ET LEDS
 * Objectif : Verifier la puissance et le retour visuel.
 */
void setup() {
  Serial.begin(115200);
  pinMode(VCRC_RELAY_PIN, OUTPUT);
  pinMode(PUMP_RELAY_PIN, OUTPUT);
  pinMode(FANS_RELAY_PIN, OUTPUT);
  pinMode(LED_ALARM_RED_PIN, OUTPUT);
  pinMode(LED_OK_GREEN_PIN, OUTPUT);
  pinMode(LED_VCRC_BLUE_PIN, OUTPUT);
  pinMode(LED_SORBENT_YELLOW_PIN, OUTPUT);
}

void loop() {
  Serial.println("Test: VCRC (Relais 1 + LED Bleue)");
  digitalWrite(VCRC_RELAY_PIN, HIGH); digitalWrite(LED_VCRC_BLUE_PIN, HIGH);
  delay(2000);
  digitalWrite(VCRC_RELAY_PIN, LOW); digitalWrite(LED_VCRC_BLUE_PIN, LOW);
  delay(500);

  Serial.println("Test: Pompe (Relais 2 + LED Jaune)");
  digitalWrite(PUMP_RELAY_PIN, HIGH); digitalWrite(LED_SORBENT_YELLOW_PIN, HIGH);
  delay(2000);
  digitalWrite(PUMP_RELAY_PIN, LOW); digitalWrite(LED_SORBENT_YELLOW_PIN, LOW);
  delay(500);

  Serial.println("Test: Ventilos (Relais 3 + LED Verte)");
  digitalWrite(FANS_RELAY_PIN, HIGH); digitalWrite(LED_OK_GREEN_PIN, HIGH);
  delay(2000);
  digitalWrite(FANS_RELAY_PIN, LOW); digitalWrite(LED_OK_GREEN_PIN, LOW);
  delay(500);

  Serial.println("Test: Alarme (LED Rouge)");
  digitalWrite(LED_ALARM_RED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_ALARM_RED_PIN, LOW);
  delay(2000);
}
