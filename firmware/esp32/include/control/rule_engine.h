#pragma once

#include "control/safety.h"
#include "domain/types.h"

namespace aqua_atmos::control {

constexpr float kVcrcHrMinPct = 40.0F;
constexpr float kVcrcDewPointMinC = 2.0F;
constexpr float kVcrcHumidityRatioMinGkg = 6.0F;

constexpr float kSorbentHrMinPct = 40.0F;
constexpr float kSorbentDeltaHrSaturatedPct = 1.0F;
constexpr float kSolarThresholdWm2 = 500.0F;
constexpr float kHeaterSocThresholdPct = 35.0F;

inline domain::VcrcDecision decide_vcrc(
    const domain::SensorFrame& sensors,
    const domain::DerivedFrame& derived) {
  domain::VcrcDecision decision;
  if (is_hard_block(sensors)) {
    decision.state = false;
    return decision;
  }
  if (sensors.hr_pct < kVcrcHrMinPct) {
    decision.state = false;
    return decision;
  }
  if (derived.dew_point_c <= kVcrcDewPointMinC) {
    decision.state = false;
    return decision;
  }
  if (derived.humidity_ratio_gkg < kVcrcHumidityRatioMinGkg) {
    decision.state = false;
    return decision;
  }
  decision.state = true;
  return decision;
}

inline domain::SorbentDecision decide_sorbent(
    const domain::SensorFrame& sensors,
    const domain::DerivedFrame& derived) {
  domain::SorbentDecision decision;
  if (is_hard_block(sensors)) {
    decision.mode = domain::SorbentDecision::Mode::Veille;
    decision.heater_on = false;
    return decision;
  }

  const bool saturated = derived.delta_hr_sorbent <= kSorbentDeltaHrSaturatedPct;
  const bool solar_ok = sensors.solar_wm2 >= kSolarThresholdWm2;
  const bool heater_energy_ok = sensors.soc_battery_pct >= kHeaterSocThresholdPct;

  if (saturated && (solar_ok || heater_energy_ok)) {
    decision.mode = domain::SorbentDecision::Mode::Regeneration;
    decision.heater_on = !solar_ok && heater_energy_ok;
    return decision;
  }

  if (sensors.hr_pct >= kSorbentHrMinPct) {
    decision.mode = domain::SorbentDecision::Mode::Absorption;
    decision.heater_on = false;
    return decision;
  }

  decision.mode = domain::SorbentDecision::Mode::Veille;
  decision.heater_on = false;
  return decision;
}

inline domain::OutputFrame build_outputs(
    const domain::VcrcDecision& vcrc,
    const domain::SorbentDecision& sorbent) {
  domain::OutputFrame outputs;
  outputs.vcrc_relay_on = vcrc.state;
  outputs.heater_relay_on = sorbent.heater_on;
  outputs.vcrc_fan_pwm = vcrc.state ? 200 : 0;

  switch (sorbent.mode) {
    case domain::SorbentDecision::Mode::Veille:
      outputs.sorbent_fan_pwm = 0;
      outputs.servo_angle_deg = 0;
      break;
    case domain::SorbentDecision::Mode::Absorption:
      outputs.sorbent_fan_pwm = 160;
      outputs.servo_angle_deg = 90;
      break;
    case domain::SorbentDecision::Mode::Regeneration:
      outputs.sorbent_fan_pwm = 220;
      outputs.servo_angle_deg = 140;
      break;
  }

  return outputs;
}

}  // namespace aqua_atmos::control
