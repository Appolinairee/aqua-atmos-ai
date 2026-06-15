#pragma once

#include "control/safety.h"
#include "domain/types.h"
#include "config/constants.h"

namespace aqua_atmos::control {

inline domain::VcrcDecision decide_vcrc(const domain::SensorFrame& s, const domain::DerivedFrame& d) {
  domain::VcrcDecision decision;
  if (is_hard_block(s)) return decision;

  decision.state = (s.hr_pct >= config::VCRC_MIN_HR_PCT && 
                    d.dew_point_c > config::VCRC_MIN_DEW_POINT_C && 
                    d.humidity_ratio_gkg >= config::VCRC_MIN_HUM_RATIO_GKG);
  return decision;
}

inline domain::SorbentDecision decide_sorbent(const domain::SensorFrame& s, const domain::DerivedFrame& d) {
  domain::SorbentDecision decision;
  if (is_hard_block(s)) return decision;

  const bool is_saturated = d.delta_hr_sorbent <= config::SORBENT_SATURATION_DELTA;
  const bool has_solar = s.solar_wm2 >= config::SOLAR_PRODUCTION_THRESHOLD;
  const bool has_energy_for_heat = s.soc_battery_pct >= config::HEATER_MIN_SOC_PCT;

  if (is_saturated && (has_solar || has_energy_for_heat)) {
    decision.mode = domain::SorbentDecision::Mode::Regeneration;
    decision.heater_on = !has_solar && has_energy_for_heat;
  } else if (s.hr_pct >= config::SORBENT_MIN_HR_PCT) {
    decision.mode = domain::SorbentDecision::Mode::Absorption;
  }

  return decision;
}

inline void fuse_decisions(
    const domain::VcrcDecision& rule_vcrc,
    const domain::SorbentDecision& rule_sorbent,
    const domain::VcrcDecision& inference_vcrc,
    const domain::SorbentDecision& inference_sorbent,
    bool hard_block,
    domain::VcrcDecision& fused_vcrc,
    domain::SorbentDecision& fused_sorbent) {
  fused_vcrc = domain::VcrcDecision();
  fused_sorbent = domain::SorbentDecision();

  if (hard_block) return;

  fused_vcrc.state = rule_vcrc.state && inference_vcrc.state;
  fused_sorbent.mode = rule_sorbent.mode;
  fused_sorbent.heater_on = rule_sorbent.heater_on &&
                            inference_sorbent.heater_on &&
                            rule_sorbent.mode == domain::SorbentDecision::Mode::Regeneration &&
                            inference_sorbent.mode == domain::SorbentDecision::Mode::Regeneration;
}

/**
 * @brief Traduit les décisions logiques en consignes physiques (PWM, angles).
 */
inline domain::OutputFrame build_outputs(const domain::VcrcDecision& vcrc, const domain::SorbentDecision& sorb) {
  domain::OutputFrame out;
  out.vcrc_relay_on = vcrc.state;
  out.heater_relay_on = sorb.heater_on;
  out.vcrc_fan_pwm = vcrc.state ? 200 : 0;

  switch (sorb.mode) {
    case domain::SorbentDecision::Mode::Absorption:
      out.sorbent_fan_pwm = 160;
      out.servo_angle_deg = 90;
      break;
    case domain::SorbentDecision::Mode::Regeneration:
      out.sorbent_fan_pwm = 220;
      out.servo_angle_deg = 140;
      break;
    default:
      out.sorbent_fan_pwm = 0;
      out.servo_angle_deg = 0;
      break;
  }
  return out;
}

}  // namespace aqua_atmos::control
