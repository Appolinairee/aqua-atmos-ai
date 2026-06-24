#pragma once

#include "control/safety.h"
#include "domain/types.h"
#include "config/constants.h"

namespace aqua_atmos::control {

inline domain::VcrcDecision decide_vcrc(
    const domain::SensorFrame& s,
    const domain::DerivedFrame& d,
    bool hard_block,
    bool current_state) {
  domain::VcrcDecision decision;
  if (hard_block) return decision;

  float hr_threshold = current_state ? (config::VCRC_MIN_HR_PCT - config::VCRC_HYSTERESIS_PCT) 
                                     : config::VCRC_MIN_HR_PCT;

  decision.state = (s.hr_pct >= hr_threshold && 
                    d.dew_point_c > config::VCRC_MIN_DEW_POINT_C && 
                    d.humidity_ratio_gkg >= config::VCRC_MIN_HUM_RATIO_GKG);
  return decision;
}

inline domain::SorbentDecision decide_sorbent(
    const domain::SensorFrame& s,
    const domain::DerivedFrame& d,
    bool hard_block) {
  domain::SorbentDecision decision;
  if (hard_block) return decision;

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
    const domain::VcrcDecision& rule_v,
    const domain::SorbentDecision& rule_s,
    const domain::VcrcDecision& ml_v,
    const domain::SorbentDecision& ml_s,
    bool hard_block,
    domain::VcrcDecision& fused_v,
    domain::SorbentDecision& fused_s) {
  
  if (hard_block) {
    fused_v.state = false;
    fused_s.mode = domain::SorbentDecision::Mode::Veille;
    fused_s.heater_on = false;
    return;
  }

  fused_v.state = rule_v.state && ml_v.state;
  fused_s.mode = rule_s.mode;
  fused_s.heater_on = rule_s.heater_on && ml_s.heater_on;
}

inline domain::OutputFrame build_outputs(const domain::VcrcDecision& vcrc, const domain::SorbentDecision& sorb) {
  domain::OutputFrame out;
  out.vcrc_relay_on = vcrc.state;
  out.heater_relay_on = sorb.heater_on;
  
  // Les ventilateurs ne tournent qu'en mode Absorption
  out.fans_relay_on = (sorb.mode == domain::SorbentDecision::Mode::Absorption);

  switch (sorb.mode) {
    case domain::SorbentDecision::Mode::Absorption:
      out.servo_angle_deg = 90;
      out.sorbent_fan_1_pwm = 220;
      out.sorbent_fan_2_pwm = 220;
      break;
    case domain::SorbentDecision::Mode::Regeneration:
      out.servo_angle_deg = 0;
      out.sorbent_fan_1_pwm = 160;
      out.sorbent_fan_2_pwm = 160;
      break;
    default:
      out.servo_angle_deg = 0;
      out.sorbent_fan_1_pwm = 0;
      out.sorbent_fan_2_pwm = 0;
      break;
  }
  return out;
}

}  // namespace aqua_atmos::control
