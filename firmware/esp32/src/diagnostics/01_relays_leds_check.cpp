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
  pinMode(HEATER_RELAY_PIN, OUTPUT);
  pinMode(SORBENT_FAN_1_PWM_PIN, OUTPUT);
  pinMode(LED_ALARM_RED_PIN, OUTPUT);
  pinMode(LED_OK_GREEN_PIN, OUTPUT);
  pinMode(LED_VCRC_YELLOW_PIN, OUTPUT);
  pinMode(LED_SORBENT_BLUE_PIN, OUTPUT);
}

void loop() {
  Serial.println("Test: VCRC (Relais 1 + LED Jaune)");
  digitalWrite(VCRC_RELAY_PIN, HIGH); digitalWrite(LED_VCRC_YELLOW_PIN, HIGH);
  delay(2000);
  digitalWrite(VCRC_RELAY_PIN, LOW); digitalWrite(LED_VCRC_YELLOW_PIN, LOW);
  delay(500);

  Serial.println("Test: Pompe (Relais 2 + LED Bleue)");
  digitalWrite(HEATER_RELAY_PIN, HIGH); digitalWrite(LED_SORBENT_BLUE_PIN, HIGH);
  delay(2000);
  digitalWrite(HEATER_RELAY_PIN, LOW); digitalWrite(LED_SORBENT_BLUE_PIN, LOW);
  delay(500);

  Serial.println("Test: Ventilos (Relais 3 + LED Verte)");
  digitalWrite(SORBENT_FAN_1_PWM_PIN, HIGH); digitalWrite(LED_OK_GREEN_PIN, HIGH);
  delay(2000);
  digitalWrite(SORBENT_FAN_1_PWM_PIN, LOW); digitalWrite(LED_OK_GREEN_PIN, LOW);
  delay(500);

  Serial.println("Test: Alarme (LED Rouge)");
  digitalWrite(LED_ALARM_RED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_ALARM_RED_PIN, LOW);
  delay(2000);
}
