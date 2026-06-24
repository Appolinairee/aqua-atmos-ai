#include <Arduino.h>
#include "config/pins.h"

using namespace aqua_atmos::config;

void setRelay(const char* label, int pin, bool on) {
  int level = on ? LOW : HIGH; // relais actifs LOW
  digitalWrite(pin, level);
  delay(20);
  Serial.printf("%s GPIO%d sortie=%d attendu=%s\n",
                label, pin, digitalRead(pin), on ? "ON" : "OFF");
}

/**
 * DIAGNOSTIC 01 : RELAIS ET LEDS
 * Objectif : Verifier la puissance et le retour visuel.
 */
void setup() {
  Serial.begin(115200);
  pinMode(VCRC_RELAY_PIN, OUTPUT);      digitalWrite(VCRC_RELAY_PIN, HIGH);
  pinMode(HEATER_RELAY_PIN, OUTPUT);    digitalWrite(HEATER_RELAY_PIN, HIGH);
  pinMode(SORBENT_FAN_1_PWM_PIN, OUTPUT); digitalWrite(SORBENT_FAN_1_PWM_PIN, HIGH);
  pinMode(LED_ALARM_RED_PIN, OUTPUT);
  pinMode(LED_OK_GREEN_PIN, OUTPUT);
  pinMode(LED_VCRC_YELLOW_PIN, OUTPUT);
  pinMode(LED_SORBENT_BLUE_PIN, OUTPUT);
}

void loop() {
  Serial.println("Test: VCRC (Relais 1 + LED Jaune)");
  setRelay("VCRC", VCRC_RELAY_PIN, true); digitalWrite(LED_VCRC_YELLOW_PIN, HIGH);
  delay(2000);
  setRelay("VCRC", VCRC_RELAY_PIN, false); digitalWrite(LED_VCRC_YELLOW_PIN, LOW);
  delay(500);

  Serial.println("Test: Pompe (Relais 2 + LED Bleue)");
  setRelay("POMPE", HEATER_RELAY_PIN, true); digitalWrite(LED_SORBENT_BLUE_PIN, HIGH);
  delay(2000);
  setRelay("POMPE", HEATER_RELAY_PIN, false); digitalWrite(LED_SORBENT_BLUE_PIN, LOW);
  delay(500);

  Serial.println("Test: Ventilos (Relais 3 + LED Verte)");
  setRelay("VENTILO", SORBENT_FAN_1_PWM_PIN, true); digitalWrite(LED_OK_GREEN_PIN, HIGH);
  delay(2000);
  setRelay("VENTILO", SORBENT_FAN_1_PWM_PIN, false); digitalWrite(LED_OK_GREEN_PIN, LOW);
  delay(500);

  Serial.println("Test: Alarme (LED Rouge)");
  digitalWrite(LED_ALARM_RED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_ALARM_RED_PIN, LOW);
  delay(2000);
}
