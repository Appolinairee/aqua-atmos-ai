#pragma once

namespace aqua_atmos::config {

// Bus I2C (SHT31 Ambiant, LCD)
constexpr int I2C_SDA_PIN = 21;
constexpr int I2C_SCL_PIN = 22;

// Capteurs T/H Unifilaires
constexpr int DHT22_SORBENT_PIN = 19;
constexpr int DHT11_EVAPORATOR_PIN = 18;
constexpr int NTC_10K_ANALOG_PIN = 35;

// Mesure de Production
constexpr int FLOW_METER_PIN = 14;

// Gestion de l'Eau
constexpr int FLOAT_SWITCH_PIN = 32;
constexpr int WATER_LEVEL_ANALOG_PIN = 33;

// Actionneurs
constexpr int VCRC_RELAY_PIN = 26;
constexpr int HEATER_RELAY_PIN = 27;
constexpr int VCRC_FAN_PWM_PIN = 25;
constexpr int SORBENT_FAN_1_PWM_PIN = 12;
constexpr int SORBENT_FAN_2_PWM_PIN = 13;
constexpr int SORBENT_SERVO_PIN = 2; // Not conflicting with 14

// LEDs de Diagnostic
constexpr int LED_ALARM_RED_PIN = 15;
constexpr int LED_OK_GREEN_PIN = 16;
constexpr int LED_VCRC_YELLOW_PIN = 17;
constexpr int LED_SORBENT_BLUE_PIN = 23;

}
