#include <Arduino.h>
#include "actuators/actuator_hub.h"
#include "config/pins.h"

namespace aqua_atmos::actuators {

void ActuatorHub::begin() {
  pinMode(config::VCRC_RELAY_PIN, OUTPUT);
  pinMode(config::HEATER_RELAY_PIN, OUTPUT);
  digitalWrite(config::VCRC_RELAY_PIN, LOW);
  digitalWrite(config::HEATER_RELAY_PIN, LOW);

  ledcSetup(ch_vcrc, 5000, 8);
  ledcAttachPin(config::VCRC_FAN_PWM_PIN, ch_vcrc);
  ledcSetup(ch_sorb1, 5000, 8);
  ledcAttachPin(config::SORBENT_FAN_1_PWM_PIN, ch_sorb1);
  ledcSetup(ch_sorb2, 5000, 8);
  ledcAttachPin(config::SORBENT_FAN_2_PWM_PIN, ch_sorb2);

  sorbent_servo_.attach(config::SORBENT_SERVO_PIN);
  sorbent_servo_.write(0);

  pinMode(config::LED_ALARM_RED_PIN, OUTPUT);
  pinMode(config::LED_VCRC_YELLOW_PIN, OUTPUT);
  pinMode(config::LED_OK_GREEN_PIN, OUTPUT);
  pinMode(config::LED_SORBENT_BLUE_PIN, OUTPUT);
}

void ActuatorHub::apply(const domain::OutputFrame& outputs, bool has_error) {
  digitalWrite(config::VCRC_RELAY_PIN, outputs.vcrc_relay_on ? HIGH : LOW);
  digitalWrite(config::HEATER_RELAY_PIN, outputs.heater_relay_on ? HIGH : LOW);

  ledcWrite(ch_vcrc, outputs.vcrc_fan_pwm);
  ledcWrite(ch_sorb1, outputs.sorbent_fan_pwm);
  ledcWrite(ch_sorb2, outputs.sorbent_fan_pwm);

  sorbent_servo_.write(outputs.servo_angle_deg);

  digitalWrite(config::LED_ALARM_RED_PIN, has_error ? HIGH : LOW);
  digitalWrite(config::LED_VCRC_YELLOW_PIN, outputs.vcrc_relay_on ? HIGH : LOW);
  const bool sorbent_active = outputs.sorbent_fan_pwm > 0;
  digitalWrite(config::LED_SORBENT_BLUE_PIN, sorbent_active ? HIGH : LOW);

  bool active = outputs.vcrc_relay_on || sorbent_active;
  digitalWrite(config::LED_OK_GREEN_PIN, (!has_error && active) ? HIGH : LOW);
}

}
