#include <Arduino.h>
#include <Wire.h>

#if defined(AQUA_APP_TEST_DHT11) || defined(AQUA_APP_TEST_DHT22) || defined(AQUA_APP_TEST_DHT22_OLED)
#include <DHT.h>
#endif

#if defined(AQUA_APP_TEST_DHT22_OLED) || defined(AQUA_APP_TEST_LCD_ONLY)
#include <LiquidCrystal_I2C.h>
#endif

#if defined(AQUA_APP_TEST_SENSOR_1) || defined(AQUA_APP_TEST_SENSOR_2) || \
    defined(AQUA_APP_TEST_ALL_SENSORS) || defined(AQUA_APP_RULES_V1)
#include <Adafruit_SHT31.h>
#endif

#include "app/test_modes.h"
#include "config/pins.h"
#include "config/sensor_addresses.h"
#include "control/rule_engine.h"
#include "domain/metrics.h"
#include "sensors/sensor_math.h"

namespace {

constexpr unsigned long kLoopPeriodMs = 2000UL;

#if defined(AQUA_APP_TEST_DHT11)
constexpr int kDht11Pin = 5;
constexpr int kDht11Type = DHT11;
DHT dht11(kDht11Pin, kDht11Type);
#endif

#if defined(AQUA_APP_TEST_DHT22) || defined(AQUA_APP_TEST_DHT22_OLED)
constexpr int kDht22Pin = 5;
constexpr int kDht22Type = DHT22;
DHT dht22(kDht22Pin, kDht22Type);
#endif

#if defined(AQUA_APP_TEST_DHT22_OLED)
// LCD 1602A à l'adresse 0x27 (16 colonnes, 2 lignes)
LiquidCrystal_I2C lcd(0x27, 16, 2);
#endif

#if defined(AQUA_APP_TEST_LCD_ONLY)
LiquidCrystal_I2C lcd(0x27, 16, 2);
#endif

#if defined(AQUA_APP_TEST_SENSOR_1) || defined(AQUA_APP_TEST_SENSOR_2) || \
    defined(AQUA_APP_TEST_ALL_SENSORS) || defined(AQUA_APP_RULES_V1)
Adafruit_SHT31 ambient_sht31 = Adafruit_SHT31();
Adafruit_SHT31 sorbent_sht31 = Adafruit_SHT31();
#endif

void print_banner(const char* title) {
  Serial.println();
  Serial.println("========================================");
  Serial.println(title);
  Serial.println("========================================");
}

void setup_i2c() {
  Wire.begin(aqua_atmos::config::I2C_SDA_PIN, aqua_atmos::config::I2C_SCL_PIN);
}

#if defined(AQUA_APP_TEST_SENSOR_1) || defined(AQUA_APP_TEST_SENSOR_2) || \
    defined(AQUA_APP_TEST_ALL_SENSORS) || defined(AQUA_APP_RULES_V1)
bool begin_sht31(Adafruit_SHT31& sensor, uint8_t address) {
  return sensor.begin(address);
}

void print_sht31_reading(const char* label, Adafruit_SHT31& sensor) {
  const float temp_c = sensor.readTemperature();
  const float hr_pct = sensor.readHumidity();

  Serial.print(label);
  Serial.print(" temp_c=");
  Serial.print(temp_c);
  Serial.print(", hr_pct=");
  Serial.println(hr_pct);
}

void setup_single_sht31(const char* title, Adafruit_SHT31& sensor, uint8_t address) {
  print_banner(title);
  setup_i2c();

  if (!begin_sht31(sensor, address)) {
    Serial.println("Erreur: capteur SHT31 non detecte.");
    while (true) {
      delay(1000);
    }
  }
}

void setup_dual_sht31() {
  print_banner("TEST 2 CAPTEURS T/H");
  setup_i2c();

  const bool ambient_ok =
      begin_sht31(ambient_sht31, aqua_atmos::config::SHT31_AIR_AMBIENT_I2C_ADDRESS);
  const bool sorbent_ok =
      begin_sht31(sorbent_sht31, aqua_atmos::config::SHT31_SORBENT_I2C_ADDRESS);

  if (!ambient_ok || !sorbent_ok) {
    Serial.println("Erreur: un ou deux capteurs SHT31 non detectes.");
    while (true) {
      delay(1000);
    }
  }
}
#endif

#if defined(AQUA_APP_TEST_RESERVOIR) || defined(AQUA_APP_TEST_ALL_SENSORS) || defined(AQUA_APP_RULES_V1)
void print_reservoir_reading() {
  const int raw = analogRead(aqua_atmos::config::RESERVOIR_LEVEL_ADC_PIN);
  const float pct = aqua_atmos::sensors::reservoir_percent_from_adc(raw);

  Serial.print("reservoir_raw=");
  Serial.print(raw);
  Serial.print(", reservoir_pct=");
  Serial.println(pct);
}

void setup_reservoir() {
  print_banner("TEST RESERVOIR ANALOGIQUE");
  pinMode(aqua_atmos::config::RESERVOIR_LEVEL_ADC_PIN, INPUT);
}

void loop_reservoir_only() {
  print_reservoir_reading();
  delay(kLoopPeriodMs);
}
#endif

#if defined(AQUA_APP_TEST_RESERVOIR_CONTACT) || defined(AQUA_APP_TEST_ALL_SENSORS) || defined(AQUA_APP_RULES_V1)
void setup_reservoir_contact() {
  print_banner("TEST RESERVOIR CONTACT 2 FILS");
  pinMode(aqua_atmos::config::RESERVOIR_CONTACT_PIN, INPUT_PULLUP);
}

void loop_reservoir_contact() {
  const int state = digitalRead(aqua_atmos::config::RESERVOIR_CONTACT_PIN);

  Serial.print("reservoir_contact_state=");
  Serial.print(state);
  Serial.print(", interpretation=");
  if (state == LOW) {
    Serial.println("contact_detected");
  } else {
    Serial.println("open_or_dry");
  }

  delay(kLoopPeriodMs);
}
#endif

#if defined(AQUA_APP_TEST_ALL_SENSORS) || defined(AQUA_APP_RULES_V1)
void setup_all_sensors() {
  print_banner("TEST ENSEMBLE CAPTEURS");
  setup_i2c();
  pinMode(aqua_atmos::config::RESERVOIR_LEVEL_ADC_PIN, INPUT);

  const bool ambient_ok =
      begin_sht31(ambient_sht31, aqua_atmos::config::SHT31_AIR_AMBIENT_I2C_ADDRESS);
  const bool sorbent_ok =
      begin_sht31(sorbent_sht31, aqua_atmos::config::SHT31_SORBENT_I2C_ADDRESS);

  if (!ambient_ok || !sorbent_ok) {
    Serial.println("Erreur: impossible d'initialiser tous les capteurs.");
    while (true) {
      delay(1000);
    }
  }
}

void setup_rules() {
  setup_all_sensors();
  print_banner("TEST CAPTEURS + REGLES");
}

void loop_all_sensors() {
  const float ambient_temp_c = ambient_sht31.readTemperature();
  const float ambient_hr_pct = ambient_sht31.readHumidity();
  const float sorbent_temp_c = sorbent_sht31.readTemperature();
  const float sorbent_hr_pct = sorbent_sht31.readHumidity();
  const int reservoir_raw = analogRead(aqua_atmos::config::RESERVOIR_LEVEL_ADC_PIN);
  const float reservoir_pct = aqua_atmos::sensors::reservoir_percent_from_adc(reservoir_raw);

  Serial.print("ambient_temp_c=");
  Serial.print(ambient_temp_c);
  Serial.print(", ambient_hr_pct=");
  Serial.print(ambient_hr_pct);
  Serial.print(", sorbent_temp_c=");
  Serial.print(sorbent_temp_c);
  Serial.print(", sorbent_hr_pct=");
  Serial.print(sorbent_hr_pct);
  Serial.print(", reservoir_raw=");
  Serial.print(reservoir_raw);
  Serial.print(", reservoir_pct=");
  Serial.println(reservoir_pct);

  delay(kLoopPeriodMs);
}

void loop_rules() {
  aqua_atmos::domain::SensorFrame sensors;
  sensors.temp_air_c = ambient_sht31.readTemperature();
  sensors.hr_pct = ambient_sht31.readHumidity();
  sensors.hr_in_pct = ambient_sht31.readHumidity();
  sensors.hr_out_pct = sorbent_sht31.readHumidity();
  sensors.temp_cond_c = sensors.temp_air_c - 4.0F;
  sensors.temp_collector_c = sensors.temp_air_c + 10.0F;
  sensors.pv_voltage = 15.0F;
  sensors.solar_wm2 = 500.0F;
  sensors.soc_battery_pct = 60.0F;
  sensors.reservoir_level_pct = aqua_atmos::sensors::reservoir_percent_from_adc(
      analogRead(aqua_atmos::config::RESERVOIR_LEVEL_ADC_PIN));
  sensors.hour_of_day = 14;

  aqua_atmos::domain::DerivedFrame derived;
  derived.dew_point_c = aqua_atmos::domain::compute_dew_point_c(sensors.temp_air_c, sensors.hr_pct);
  derived.humidity_ratio_gkg =
      aqua_atmos::domain::compute_humidity_ratio_gkg(sensors.temp_air_c, sensors.hr_pct);
  derived.delta_hr_sorbent =
      aqua_atmos::domain::compute_delta_hr_sorbent(sensors.hr_in_pct, sensors.hr_out_pct);

  const auto vcrc = aqua_atmos::control::decide_vcrc(sensors, derived);
  const auto sorbent = aqua_atmos::control::decide_sorbent(sensors, derived);

  Serial.print("temp_air_c=");
  Serial.print(sensors.temp_air_c);
  Serial.print(", hr_pct=");
  Serial.print(sensors.hr_pct);
  Serial.print(", dew_point_c=");
  Serial.print(derived.dew_point_c);
  Serial.print(", humidity_ratio_gkg=");
  Serial.print(derived.humidity_ratio_gkg);
  Serial.print(", delta_hr_sorbent=");
  Serial.print(derived.delta_hr_sorbent);
  Serial.print(", reservoir_pct=");
  Serial.print(sensors.reservoir_level_pct);
  Serial.print(", vcrc_state=");
  Serial.print(vcrc.state ? 1 : 0);
  Serial.print(", sorbent_mode=");
  Serial.print(static_cast<int>(sorbent.mode));
  Serial.print(", heater_on=");
  Serial.println(sorbent.heater_on ? 1 : 0);

  delay(kLoopPeriodMs);
}
#endif

#if defined(AQUA_APP_TEST_DHT11)
void setup_dht11() {
  print_banner("TEST DHT11");
  dht11.begin();
}

void loop_dht11() {
  const float hr_pct = dht11.readHumidity();
  const float temp_c = dht11.readTemperature();

  if (isnan(hr_pct) || isnan(temp_c)) {
    Serial.println("Erreur lecture DHT11");
    delay(kLoopPeriodMs);
    return;
  }

  Serial.print("dht11_temp_c=");
  Serial.print(temp_c);
  Serial.print(", dht11_hr_pct=");
  Serial.println(hr_pct);

  delay(kLoopPeriodMs);
}
#endif

#if defined(AQUA_APP_TEST_LCD_ONLY)
void setup_lcd_only() {
  print_banner("TEST LCD SEUL");
  setup_i2c();
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LCD SEUL OK !");
}

void loop_lcd_only() {
  delay(kLoopPeriodMs);
}
#endif

#if defined(AQUA_APP_TEST_DHT22_OLED)
void setup_dht22_oled() {
  print_banner("TEST DHT22 + LCD 1602");
  setup_i2c();
  dht22.begin();

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("AQUA-ATMOS");
  lcd.setCursor(0, 1);
  lcd.print("INITIALISATION...");
  delay(2000);
}

void loop_dht22_oled() {
  static unsigned long last_read_time = 0;
  static float last_temp = 0.0;
  static float last_hr = 0.0;

  // Lecture toutes les 5 secondes pour stabiliser
  if (millis() - last_read_time > 5000) {
    noInterrupts();
    last_hr = dht22.readHumidity();
    last_temp = dht22.readTemperature();
    interrupts();
    last_read_time = millis();
    
    Serial.print("T: "); Serial.print(last_temp); Serial.print(" C, ");
    Serial.print("H: "); Serial.print(last_hr); Serial.println(" %");
  }

  lcd.setCursor(0, 0);
  if (isnan(last_temp)) {
    lcd.print("Temp: Erreur    ");
  } else {
    lcd.print("Temp: "); lcd.print(last_temp, 1); lcd.print(" C   ");
  }

  lcd.setCursor(0, 1);
  if (isnan(last_hr)) {
    lcd.print("Hum : Erreur    ");
  } else {
    lcd.print("Hum : "); lcd.print(last_hr, 1); lcd.print(" %    ");
  }
  
  delay(100);
}
#endif

}  // namespace

namespace aqua_atmos::app {

void setup_selected_mode() {
#if defined(AQUA_APP_TEST_DHT11)
  setup_dht11();
#elif defined(AQUA_APP_TEST_DHT22)
  setup_dht22();
#elif defined(AQUA_APP_TEST_DHT22_OLED)
  setup_dht22_oled();
#elif defined(AQUA_APP_TEST_LCD_ONLY)
  setup_lcd_only();
#elif defined(AQUA_APP_TEST_SENSOR_1)
  setup_single_sht31(
      "TEST CAPTEUR 1 T/H",
      ambient_sht31,
      aqua_atmos::config::SHT31_AIR_AMBIENT_I2C_ADDRESS);
#elif defined(AQUA_APP_TEST_SENSOR_2)
  setup_single_sht31(
      "TEST CAPTEUR 2 T/H",
      sorbent_sht31,
      aqua_atmos::config::SHT31_SORBENT_I2C_ADDRESS);
#elif defined(AQUA_APP_TEST_RESERVOIR_CONTACT)
  setup_reservoir_contact();
#elif defined(AQUA_APP_TEST_RESERVOIR)
  setup_reservoir();
#elif defined(AQUA_APP_TEST_ALL_SENSORS)
  setup_all_sensors();
#else
  setup_rules();
#endif
}

void loop_selected_mode() {
#if defined(AQUA_APP_TEST_DHT11)
  loop_dht11();
#elif defined(AQUA_APP_TEST_DHT22)
  loop_dht22();
#elif defined(AQUA_APP_TEST_DHT22_OLED)
  loop_dht22_oled();
#elif defined(AQUA_APP_TEST_LCD_ONLY)
  loop_lcd_only();
#elif defined(AQUA_APP_TEST_SENSOR_1)
  loop_single_sht31("sensor_1", ambient_sht31);
#elif defined(AQUA_APP_TEST_SENSOR_2)
  loop_single_sht31("sensor_2", sorbent_sht31);
#elif defined(AQUA_APP_TEST_RESERVOIR_CONTACT)
  loop_reservoir_contact();
#elif defined(AQUA_APP_TEST_RESERVOIR)
  loop_reservoir_only();
#elif defined(AQUA_APP_TEST_ALL_SENSORS)
  loop_all_sensors();
#else
  loop_rules();
#endif
}

}  // namespace aqua_atmos::app
