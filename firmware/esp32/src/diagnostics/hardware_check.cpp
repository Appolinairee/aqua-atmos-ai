#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SHTC3.h>
#include <DHT.h>
#include <ESP32Servo.h>
#include <LiquidCrystal_I2C.h>
#include "config/pins.h"

using namespace aqua_atmos::config;

Adafruit_SHTC3 sht = Adafruit_SHTC3();
DHT dht22_sorb(DHT22_SORBENT_PIN, DHT22);
DHT dht11_evap(DHT11_EVAPORATOR_PIN, DHT11);
Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  Serial.println("\n--- HARDWARE DIAGNOSTIC START ---");

  // 1. LCD & I2C
  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
  lcd.init();
  lcd.backlight();
  lcd.print("DIAGNOSTIC MODE");

  // 2. Capteurs
  bool sht_ok = sht.begin();
  dht22_sorb.begin();
  dht11_evap.begin();
  pinMode(FLOAT_SWITCH_PIN, INPUT_PULLUP);
  pinMode(FLOW_METER_PIN, INPUT_PULLUP);

  // 3. Relais
  pinMode(VCRC_RELAY_PIN, OUTPUT);
  pinMode(HEATER_RELAY_PIN, OUTPUT);
  pinMode(SORBENT_FAN_1_PWM_PIN, OUTPUT);

  // 4. LEDs
  pinMode(LED_ALARM_RED_PIN, OUTPUT);
  pinMode(LED_OK_GREEN_PIN, OUTPUT);
  pinMode(LED_VCRC_YELLOW_PIN, OUTPUT);
  pinMode(LED_SORBENT_BLUE_PIN, OUTPUT);

  // 5. Servo
  servo.attach(SORBENT_SERVO_PIN);

  Serial.printf("SHTC3: %s\n", sht_ok ? "OK" : "MISSING");
  delay(1000);
}

void loop() {
  Serial.println("\n--- New Cycle ---");

  // Test des Capteurs
  sensors_event_t humidity, temp;
  sht.getEvent(&humidity, &temp);
  float t = temp.temperature;
  float h = dht22_sorb.readHumidity();
  bool float_st = digitalRead(FLOAT_SWITCH_PIN);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.printf("T:%.1f H:%.0f", t, h);
  lcd.setCursor(0,1);
  lcd.printf("Float:%d", float_st);

  // Test Séquentiel des Actionneurs
  Serial.println("Relais 1 (VCRC)...");
  digitalWrite(VCRC_RELAY_PIN, HIGH); digitalWrite(LED_VCRC_YELLOW_PIN, HIGH);
  delay(1000);
  digitalWrite(VCRC_RELAY_PIN, LOW); digitalWrite(LED_VCRC_YELLOW_PIN, LOW);

  Serial.println("Relais 2 (Heater)...");
  digitalWrite(HEATER_RELAY_PIN, HIGH); digitalWrite(LED_SORBENT_BLUE_PIN, HIGH);
  delay(1000);
  digitalWrite(HEATER_RELAY_PIN, LOW); digitalWrite(LED_SORBENT_BLUE_PIN, LOW);

  Serial.println("Relais 3 (Ventilos)...");
  digitalWrite(SORBENT_FAN_1_PWM_PIN, HIGH); digitalWrite(LED_OK_GREEN_PIN, HIGH);
  delay(1000);
  digitalWrite(SORBENT_FAN_1_PWM_PIN, LOW); digitalWrite(LED_OK_GREEN_PIN, LOW);

  Serial.println("Servo Move...");
  servo.write(90); delay(1000);
  servo.write(0); delay(1000);

  // Alerte si erreur
  if (isnan(t)) {
    digitalWrite(LED_ALARM_RED_PIN, HIGH);
    Serial.println("ALERT: SHTC3 Data Error!");
  } else {
    digitalWrite(LED_ALARM_RED_PIN, LOW);
  }

  delay(2000);
}
