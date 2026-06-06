#pragma once

namespace aqua_atmos::config {

constexpr int I2C_SDA_PIN = 18;
constexpr int I2C_SCL_PIN = 19;

constexpr int ONEWIRE_PIN = 4;

constexpr int RESERVOIR_LEVEL_ADC_PIN = 34;
constexpr int RESERVOIR_CONTACT_PIN = 21;
constexpr int BATTERY_VOLTAGE_ADC_PIN = 35;

constexpr int VCRC_RELAY_PIN = 26;
constexpr int HEATER_RELAY_PIN = 27;

constexpr int VCRC_FAN_PWM_PIN = 22;
constexpr int SORBENT_FAN_PWM_PIN = 19;
constexpr int SORBENT_SERVO_PIN = 23;

constexpr int STATUS_LED_PIN = 2;

}  // namespace aqua_atmos::config
