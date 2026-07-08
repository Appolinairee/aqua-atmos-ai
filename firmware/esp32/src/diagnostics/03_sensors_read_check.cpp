#include <Arduino.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "config/pins.h"

using namespace aqua_atmos::config;

LiquidCrystal_I2C lcd(0x27, 16, 2);

// DHT22 GPIO5 (sorbant), DHT11 GPIO18 (evaporateur)
DHT dht22(DHT22_SORBENT_PIN,    DHT22); // GPIO5
DHT dht11(DHT11_EVAPORATOR_PIN, DHT11); // GPIO18

/**
 * DIAGNOSTIC 03 : DHT RAW + LECTURE
 * Etape 1 : etat brut GPIO (idle doit etre HIGH avec pull-up)
 * Etape 2 : lecture DHT avec la librairie
 */
void checkRawPin(const char* label, int pin) {
    // Mode input sans pull-up interne : pin flotte si rien ne la tire
    pinMode(pin, INPUT);
    int raw_no_pull = digitalRead(pin);

    // Mode input avec pull-up interne
    pinMode(pin, INPUT_PULLUP);
    delayMicroseconds(100);
    int raw_pullup = digitalRead(pin);

    Serial.printf("[%s GPIO%d] Sans pull-up: %s | Avec pull-up interne: %s\n",
                  label, pin,
                  raw_no_pull ? "HIGH" : "LOW",
                  raw_pullup  ? "HIGH" : "LOW");

    if (raw_pullup == LOW) {
        Serial.printf("  !! GPIO%d reste LOW meme avec pull-up -> court-circuit ou DATA/GND inverses!\n", pin);
    } else {
        Serial.printf("  OK GPIO%d idle HIGH avec pull-up -> pin libre, pas de court-circuit\n", pin);
    }
}

void printDht(const char* label, DHT& sensor) {
    float t = sensor.readTemperature();
    float h = sensor.readHumidity();
    if (isnan(t) || isnan(h)) {
        Serial.printf("[%s] ECHEC lecture (nan) -> capteur absent, mauvais type, ou pas de pull-up\n", label);
    } else {
        Serial.printf("[%s] OK  %.1f C  %.1f %%\n", label, t, h);
    }
}

void setup() {
    Serial.begin(115200);
    Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
    delay(500);
    lcd.init(); delay(200); lcd.clear(); lcd.backlight();

    dht22.begin();
    delay(3000);
    float t22 = dht22.readTemperature(), h22 = dht22.readHumidity();
    Serial.printf("S GPIO5: %.1fC %.1f%%\n", t22, h22);

    dht11.begin();
    delay(3000);
    float t11 = dht11.readTemperature(), h11 = dht11.readHumidity();
    Serial.printf("E GPIO18: %.1fC %.1f%%\n", t11, h11);

    char buf[17];
    lcd.setCursor(0, 0);
    snprintf(buf, 17, !isnan(t22) ? "S:%.1fC %.1f%%   " : "S: ECHEC        ", t22, h22);
    lcd.print(buf);
    lcd.setCursor(0, 1);
    snprintf(buf, 17, !isnan(t11) ? "E:%.1fC %.1f%%   " : "E: ECHEC        ", t11, h11);
    lcd.print(buf);
}

void loop() {
    static bool read_sorb = true;
    static float t22 = NAN, h22 = NAN, t11 = NAN, h11 = NAN;
    char buf[17];

    delay(2500);

    if (read_sorb) {
        t22 = dht22.readTemperature(); h22 = dht22.readHumidity();
        Serial.printf("S: %.1fC %.1f%%\n", t22, h22);
    } else {
        t11 = dht11.readTemperature(); h11 = dht11.readHumidity();
        Serial.printf("E: %.1fC %.1f%%\n", t11, h11);
    }
    read_sorb = !read_sorb;

    lcd.setCursor(0, 0);
    snprintf(buf, 17, !isnan(t22) ? "S:%.1fC %.1f%%    " : "S: ---          ", t22, h22);
    lcd.print(buf);

    lcd.setCursor(0, 1);
    snprintf(buf, 17, !isnan(t11) ? "E:%.1fC %.1f%%    " : "E: ---          ", t11, h11);
    lcd.print(buf);
}
