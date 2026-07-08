#pragma once

#include "config/timing.h"
#include "domain/types.h"

namespace aqua_atmos::control {

struct OutputGuardState {
  bool vcrc_relay_on = false;
  bool pump_relay_on = false;
  unsigned long last_vcrc_on_ms = 0;
  unsigned long last_vcrc_off_ms = 0;
  unsigned long last_pump_off_ms = 0;
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

  // 1. Sécurité prioritaire : On coupe TOUT
  if (hard_block) {
    guarded = domain::OutputFrame();
    state.vcrc_relay_on = false;
    state.pump_relay_on = false;
    return guarded;
  }

  // 2. Gestion du VCRC
  if (guarded.vcrc_relay_on && !state.vcrc_relay_on) {
    // Demande d'ALLUMAGE
    if (state.last_vcrc_off_ms > 0UL && !has_waited(now_ms, state.last_vcrc_off_ms, config::VCRC_MIN_OFF_MS)) {
      guarded.vcrc_relay_on = false; 
    } else {
      state.last_vcrc_on_ms = now_ms;
    }
  } 
  else if (!guarded.vcrc_relay_on && state.vcrc_relay_on) {
    // Demande d'EXTINCTION
    if (!has_waited(now_ms, state.last_vcrc_on_ms, config::VCRC_MIN_RUN_MS)) {
      guarded.vcrc_relay_on = true; // Forçage maintien (MRT)
    } else {
      state.last_vcrc_off_ms = now_ms;
    }
  }

  // Si le VCRC est maintenu ON par le MRT, les ventilos doivent rester ON si on est en mode absorption
  if (guarded.vcrc_relay_on) {
      // Note: fans_relay_on suit normalement sorb.mode dans build_outputs
  }

  // 3. Gestion de la Pompe / Chauffage (MOT)
  if (guarded.pump_relay_on && !state.pump_relay_on &&
      state.last_pump_off_ms > 0UL &&
      !has_waited(now_ms, state.last_pump_off_ms, config::HEATER_MIN_OFF_MS)) {
    guarded.pump_relay_on = false;
  }
  if (state.pump_relay_on && !guarded.pump_relay_on) {
    state.last_pump_off_ms = now_ms;
  }

  state.vcrc_relay_on = guarded.vcrc_relay_on;
  state.pump_relay_on = guarded.pump_relay_on;
  return guarded;
}

}  // namespace aqua_atmos::control
