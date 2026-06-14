#pragma once

namespace aqua_atmos::config {

constexpr int I2C_SDA_PIN = 18;
constexpr int I2C_SCL_PIN = 19;
constexpr int ONEWIRE_PIN = 4;

constexpr int RESERVOIR_LEVEL_ADC_PIN = 34;
constexpr int BATTERY_VOLTAGE_ADC_PIN = 35;
constexpr int RESERVOIR_CONTACT_PIN = 21;

constexpr int VCRC_RELAY_PIN = 26;
constexpr int HEATER_RELAY_PIN = 27;

constexpr int VCRC_FAN_PWM_PIN = 22;
constexpr int SORBENT_FAN_1_PWM_PIN = 25;
constexpr int SORBENT_FAN_2_PWM_PIN = 15;
constexpr int SORBENT_SERVO_PIN = 23;

constexpr int LED_ALARM_RED_PIN = 32;
constexpr int LED_VCRC_YELLOW_PIN = 33;
constexpr int LED_OK_GREEN_PIN = 14;
constexpr int LED_SORBENT_BLUE_PIN = 12;

}
