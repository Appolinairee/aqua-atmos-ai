#include <Arduino.h>
#include <DHT.h>
#include "config/pins.h"

using namespace aqua_atmos::config;

DHT dht22_sorb(DHT22_SORBENT_PIN, DHT22);
DHT dht11_evap(DHT11_EVAPORATOR_PIN, DHT11);

/**
 * DIAGNOSTIC 03 : CAPTEURS DIGITAUX
 * Objectif : Lire les DHT, le Flotteur et le Debitmetre.
 */
void setup() {
  Serial.begin(115200);
  dht22_sorb.begin();
  dht11_evap.begin();
  pinMode(FLOAT_SWITCH_PIN, INPUT_PULLUP);
  pinMode(FLOW_METER_PIN, INPUT_PULLUP);
}

void loop() {
  float h22 = dht22_sorb.readHumidity();
  float t11 = dht11_evap.readTemperature();
  bool fl = digitalRead(FLOAT_SWITCH_PIN);
  
  Serial.printf("DHT22 (Sorb): %.1f%% | DHT11 (Evap): %.1fC | Float: %s\n", 
                h22, t11, fl ? "LEVE (ALERTE)" : "OK");

  // Note : pour le debitmetre, on compte les impulsions brutes ici
  static long pulses = 0;
  if (digitalRead(FLOW_METER_PIN) == LOW) {
      pulses++;
      Serial.printf("Flow pulse detected! Total: %ld\n", pulses);
      delay(10); // debounce sommaire pour test
  }

  delay(500);
}
