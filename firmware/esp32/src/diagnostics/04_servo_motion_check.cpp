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
  myservo.attach(aqua_atmos::config::SORBENT_SERVO_PIN);
  Serial.println("Test des 2 Servomoteurs (Broche 13 en parallèle)");
  Serial.println("Mouvement : 0 (Fermé) -> 90 (Ouvert) -> 140 (Régénération)");
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
