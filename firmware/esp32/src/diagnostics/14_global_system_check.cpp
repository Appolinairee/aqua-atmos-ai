#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_SHTC3.h>
#include <DHT.h>
#include <RTClib.h>
#include <ESP32Servo.h>
#include "config/pins.h"

using namespace aqua_atmos::config;

LiquidCrystal_I2C lcd(0x27, 16, 2);
Adafruit_SHTC3 shtc3;
DHT dht22(DHT22_SORBENT_PIN, DHT22);
DHT dht11(DHT11_EVAPORATOR_PIN, DHT11);
RTC_DS3231 rtc;
Servo servo;

bool has_sht = false, has_rtc = false;

void setup() {
  Serial.begin(115200);
  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
  delay(500);

  lcd.init(); delay(200); lcd.clear(); lcd.backlight();
  lcd.setCursor(0, 0); lcd.print("AQUA DIAG v1.0");
  lcd.setCursor(0, 1); lcd.print("Init...");

  delay(200);
  for (int i = 0; i < 3 && !has_sht; i++) {
    has_sht = shtc3.begin(); delay(100);
  }
  has_rtc = rtc.begin();

  dht22.begin(); delay(2000); dht11.begin(); delay(1000);

  analogSetAttenuation(ADC_11db);
  pinMode(FLOAT_SWITCH_PIN, INPUT_PULLUP);
  pinMode(FLOW_METER_PIN, INPUT_PULLUP);

  pinMode(LED_ALARM_RED_PIN, OUTPUT);
  pinMode(LED_OK_GREEN_PIN, OUTPUT);
  pinMode(LED_VCRC_YELLOW_PIN, OUTPUT);
  pinMode(LED_SORBENT_BLUE_PIN, OUTPUT);
  pinMode(VCRC_RELAY_PIN, OUTPUT);

  servo.attach(SORBENT_SERVO_PIN);
  servo.write(0);

  Serial.printf("SHTC3: %s | RTC: %s\n", has_sht ? "OK" : "ABSENT", has_rtc ? "OK" : "ABSENT");
  lcd.setCursor(0, 1); lcd.print(has_sht ? "SHT:OK " : "SHT:-- ");
}

void loop() {
  static unsigned long last_sensor = 0, last_actuator = 0;
  unsigned long now = millis();

  // Capteurs toutes les 5s
  if (now - last_sensor > 5000) {
    last_sensor = now;

    // DHT en premier (timing critique)
    static bool read_sorb = true;
    float t22 = NAN, h22 = NAN, t11 = NAN, h11 = NAN;
    if (read_sorb) {
      t22 = dht22.readTemperature(); h22 = dht22.readHumidity();
    } else {
      t11 = dht11.readTemperature(); h11 = dht11.readHumidity();
    }
    read_sorb = !read_sorb;

    // SHTC3 — begin() peut échouer mais les lectures fonctionnent quand même
    if (!has_sht) shtc3.begin();
    float t_air = NAN, hr_air = NAN;
    sensors_event_t hev, tev;
    if (shtc3.getEvent(&hev, &tev)) {
      t_air = tev.temperature; hr_air = hev.relative_humidity;
      has_sht = true;
    }

    // NTC avec garde contre bruit
    long sum = 0;
    for (int i = 0; i < 32; i++) { sum += analogRead(NTC_10K_ANALOG_PIN); delay(5); }
    float v = (sum / 32) * 3.3f / 4095.0f;
    float t_ntc = NAN;
    if (v > 0.1f && v < 3.2f) {
      float r_ntc = 1000.0f * (3.3f - v) / v;
      t_ntc = 1.0f / (1.0f / 298.15f + log(r_ntc / 10000.0f) / 3950.0f) - 273.15f;
    }

    // Float
    bool full = (digitalRead(FLOAT_SWITCH_PIN) == LOW);

    // RTC
    String time_str = "--:--:--";
    if (has_rtc) {
      DateTime now_dt = rtc.now();
      char buf[9];
      snprintf(buf, 9, "%02d:%02d:%02d", now_dt.hour(), now_dt.minute(), now_dt.second());
      time_str = String(buf);
    }

    // LCD
    char buf[17];
    lcd.setCursor(0, 0);
    if (!isnan(t_air))
      snprintf(buf, 17, "T:%.1f HR:%.0f%%  ", t_air, hr_air);
    else
      snprintf(buf, 17, "SHT:---         ");
    lcd.print(buf);
    lcd.setCursor(0, 1);
    snprintf(buf, 17, "%s %s", time_str.c_str(), full ? "PLEIN" : "VIDE ");
    lcd.print(buf);

    // Serial
    Serial.printf("SHT:%.1f/%.0f%% | S:%.1f/%.0f%% | E:%.1f/%.0f%% | NTC:%.1f | Float:%s | %s\n",
      t_air, hr_air, t22, h22, t11, h11, t_ntc, full ? "PLEIN" : "VIDE", time_str.c_str());
  }

  // Actionneurs toutes les 15s
  if (now - last_actuator > 15000) {
    last_actuator = now;

    // LEDs cycle
    digitalWrite(LED_ALARM_RED_PIN, HIGH);  delay(300); digitalWrite(LED_ALARM_RED_PIN, LOW);
    digitalWrite(LED_OK_GREEN_PIN, HIGH);   delay(300); digitalWrite(LED_OK_GREEN_PIN, LOW);
    digitalWrite(LED_VCRC_YELLOW_PIN, HIGH);delay(300); digitalWrite(LED_VCRC_YELLOW_PIN, LOW);
    digitalWrite(LED_SORBENT_BLUE_PIN, HIGH);delay(300);digitalWrite(LED_SORBENT_BLUE_PIN, LOW);

    // Relais VCRC
    digitalWrite(VCRC_RELAY_PIN, HIGH); delay(500); digitalWrite(VCRC_RELAY_PIN, LOW);

    // Servo
    servo.write(90); delay(1000); servo.write(0);

    Serial.println(">> Cycle actionneurs OK");
  }
}
