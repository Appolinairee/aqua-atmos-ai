#pragma once

namespace aqua_atmos::config {

// Bus I2C (SHT31 Ambiant, LCD)
constexpr int I2C_SDA_PIN = 21;
constexpr int I2C_SCL_PIN = 22;

// Capteurs T/H Unifilaires
constexpr int DHT22_SORBENT_PIN = 5;
constexpr int DHT11_EVAPORATOR_PIN = 18;
constexpr int NTC_10K_ANALOG_PIN = 36;

// Mesure de Production
constexpr int FLOW_METER_PIN = 14;

// Gestion de l'Eau
constexpr int FLOAT_SWITCH_PIN = 32;
constexpr int RESERVOIR_LEVEL_ADC_PIN = 33;
constexpr int BATTERY_VOLTAGE_ADC_PIN = 34;

// Actionneurs
constexpr int VCRC_RELAY_PIN = 26;
constexpr int HEATER_RELAY_PIN = 27;
constexpr int SORBENT_FAN_1_PWM_PIN = 25;
// constexpr int SORBENT_FAN_2_PWM_PIN = 13; // (Mise en parallele ou desactivee)
constexpr int SORBENT_SERVO_PIN = 13; // 2 servos branches en parallele sur GPIO 13

// LEDs de Diagnostic
constexpr int LED_ALARM_RED_PIN = 15;
constexpr int LED_OK_GREEN_PIN = 16;
constexpr int LED_VCRC_YELLOW_PIN = 17;
constexpr int LED_SORBENT_BLUE_PIN = 23;

}
