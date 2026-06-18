#include <Arduino.h>
#include <ESP32Servo.h>
#include "config/pins.h"

Servo myservo;

/**
 * DIAGNOSTIC 04 : SERVO MECANIQUE
 * Objectif : Verifier la course des volets.
 */
void setup() {
  Serial.begin(115200);
  myservo.attach(aqua_atmos::config::LED_SORBENT_YELLOW_PIN); // Utilise la pin 23 du tableau
  Serial.println("Servo test starting (0 -> 90 -> 140)");
}

void loop() {
  Serial.println("Position: 0 (Ferme)");
  myservo.write(0);
  delay(2000);

  Serial.println("Position: 90 (Ouvert)");
  myservo.write(90);
  delay(2000);

  Serial.println("Position: 140 (Regen)");
  myservo.write(140);
  delay(2000);
}
