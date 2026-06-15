#pragma once

#include "config/timing.h"
#include "domain/types.h"

namespace aqua_atmos::control {

struct OutputGuardState {
  bool vcrc_relay_on = false;
  bool heater_relay_on = false;
  unsigned long last_vcrc_on_ms = 0;  // Moment du dernier allumage
  unsigned long last_vcrc_off_ms = 0; // Moment de la dernière extinction
  unsigned long last_heater_off_ms = 0;
};

inline bool has_waited(unsigned long now_ms, unsigned long since_ms, unsigned long wait_ms) {
  return (now_ms - since_ms) >= wait_ms;
}

inline domain::OutputFrame apply_output_guard(
    const domain::OutputFrame& requested,
    OutputGuardState& state,
    unsigned long now_ms,
    bool hard_block = false) {
  domain::OutputFrame guarded = requested;

  // 1. Sécurité prioritaire (Hard Block) : On coupe TOUT sans délai
  if (hard_block) {
    guarded = domain::OutputFrame();
    state.vcrc_relay_on = false;
    state.heater_relay_on = false;
    return guarded;
  }

  // 2. Gestion du VCRC
  if (guarded.vcrc_relay_on && !state.vcrc_relay_on) {
    // Demande d'ALLUMAGE
    if (state.last_vcrc_off_ms > 0UL && !has_waited(now_ms, state.last_vcrc_off_ms, config::VCRC_MIN_OFF_MS)) {
      guarded.vcrc_relay_on = false; // Trop tôt, on refuse
      guarded.vcrc_fan_pwm = 0;
    } else {
      state.last_vcrc_on_ms = now_ms; // On autorise et on note l'heure
    }
  } 
  else if (!guarded.vcrc_relay_on && state.vcrc_relay_on) {
    // Demande d'EXTINCTION
    if (!has_waited(now_ms, state.last_vcrc_on_ms, config::VCRC_MIN_RUN_MS)) {
      guarded.vcrc_relay_on = true; // Trop tôt, on force le maintien ON (MRT)
      guarded.vcrc_fan_pwm = requested.vcrc_fan_pwm > 0 ? requested.vcrc_fan_pwm : 200;
    } else {
      state.last_vcrc_off_ms = now_ms; // On autorise l'extinction
    }
  }

  // 3. Gestion du Chauffage (uniquement MOT pour l'instant)
  if (guarded.heater_relay_on && !state.heater_relay_on &&
      state.last_heater_off_ms > 0UL &&
      !has_waited(now_ms, state.last_heater_off_ms, config::HEATER_MIN_OFF_MS)) {
    guarded.heater_relay_on = false;
  }
  if (state.heater_relay_on && !guarded.heater_relay_on) {
    state.last_heater_off_ms = now_ms;
  }

  state.vcrc_relay_on = guarded.vcrc_relay_on;
  state.heater_relay_on = guarded.heater_relay_on;
  return guarded;
}

}  // namespace aqua_atmos::control
