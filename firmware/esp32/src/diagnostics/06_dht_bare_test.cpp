#include <Arduino.h>
#include <DHT.h>

// Branchement sur 2e ESP32 :
//   VCC  -> 3.3V
//   GND  -> GND
//   DATA -> GPIO4
// Changer le type ci-dessous selon le capteur teste : DHT11 ou DHT22

#define TEST_PIN  4
#define TEST_TYPE DHT22   // <-- changer en DHT11 si besoin

DHT dht(TEST_PIN, TEST_TYPE);

void setup() {
    Serial.begin(115200);
    pinMode(TEST_PIN, INPUT_PULLUP);
    delayMicroseconds(100);
    int idle = digitalRead(TEST_PIN);
    Serial.printf("\n=== TEST DHT BARE - GPIO%d ===\n", TEST_PIN);
    Serial.printf("Type declare : %s\n", TEST_TYPE == DHT22 ? "DHT22" : "DHT11");
    Serial.printf("Etat idle pin : %s%s\n",
                  idle ? "HIGH (OK)" : "LOW (!!)",
                  idle ? "" : " -> verif VCC/GND/DATA");
    dht.begin();
    Serial.println("Warmup 2s...");
    delay(2000);
}

void loop() {
    float t = dht.readTemperature();
    float h = dht.readHumidity();
    if (isnan(t) || isnan(h)) {
        Serial.println("ECHEC -> nan  (pas de reponse capteur)");
    } else {
        Serial.printf("OK  %.1f C  %.1f %%\n", t, h);
    }
    delay(2500);
}
