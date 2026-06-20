#include <Arduino.h>
#include "config/pins.h"

using namespace aqua_atmos::config;

// Diviseur de tension : 3.3V -> [NTC 10K] -> GPIO35 -> [1K fixe] -> GND
constexpr float R_REF  = 1000.0f;
constexpr float R_NOM  = 10000.0f; // NTC 10K a 25C
constexpr float BETA   = 3950.0f;
constexpr float T_NOM  = 298.15f;  // 25C en Kelvin

void setup() {
    Serial.begin(115200);
    analogSetAttenuation(ADC_11db); // plage 0-3.3V
    Serial.println("\n=== TEST NTC 10K - GPIO35 ===");
    Serial.println("Format: ADC | V | R_ntc | Temp");
}

void loop() {
    long sum = 0;
    for (int i = 0; i < 32; i++) { sum += analogRead(NTC_10K_ANALOG_PIN); delay(5); }
    int raw = sum / 32;
    float voltage = raw * 3.3f / 4095.0f;

    if (voltage <= 0.05f || voltage >= 3.25f) {
        Serial.printf("ADC: %4d | %.3fV | NTC non connecte ou court-circuit\n", raw, voltage);
        delay(2000);
        return;
    }

    float r_ntc = R_REF * (3.3f - voltage) / voltage;
    float tempK = 1.0f / (1.0f / T_NOM + log(r_ntc / R_NOM) / BETA);
    float tempC = tempK - 273.15f;

    Serial.printf("ADC: %4d | %.3fV | R: %.0f ohm | %.1f C\n", raw, voltage, r_ntc, tempC);
    delay(2000);
}
