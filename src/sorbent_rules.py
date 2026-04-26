from __future__ import annotations

from dataclasses import dataclass

from constants import (
    HEATER_SOC_THRESHOLD_PCT,
    SOLAR_RADIATION_THRESHOLD_WM2,
    SORBENT_HR_THRESHOLD_PCT,
    SORBENT_SATURATION_DELTA_HR_EPSILON,
)
from safety_rules import is_battery_low, is_reservoir_full


@dataclass(frozen=True)
class SorbentDecision:
    mode: str
    heater_on: bool
    saturated: bool


def is_sorbent_saturated(delta_hr: float) -> bool:
    return abs(delta_hr) <= SORBENT_SATURATION_DELTA_HR_EPSILON


def has_extraction_energy(solar_wm2: float, soc_battery_pct: float) -> bool:
    has_solar = solar_wm2 >= SOLAR_RADIATION_THRESHOLD_WM2
    has_heater_energy = soc_battery_pct >= HEATER_SOC_THRESHOLD_PCT
    return has_solar or has_heater_energy


def decide_sorbent_mode(
    hr_pct: float,
    delta_hr: float,
    solar_wm2: float,
    reservoir_level_pct: float,
    soc_battery_pct: float,
) -> SorbentDecision:
    """Return sorbent mode using retained logic with saturation for regeneration only."""
    if is_reservoir_full(reservoir_level_pct) or is_battery_low(soc_battery_pct):
        return SorbentDecision(mode="veille", heater_on=False, saturated=False)

    saturated = is_sorbent_saturated(delta_hr)
    extraction_possible = has_extraction_energy(solar_wm2, soc_battery_pct)

    if saturated and extraction_possible:
        heater_on = solar_wm2 < SOLAR_RADIATION_THRESHOLD_WM2 and soc_battery_pct >= HEATER_SOC_THRESHOLD_PCT
        return SorbentDecision(mode="regeneration", heater_on=heater_on, saturated=True)

    if hr_pct >= SORBENT_HR_THRESHOLD_PCT:
        return SorbentDecision(mode="absorption", heater_on=False, saturated=saturated)

    return SorbentDecision(mode="veille", heater_on=False, saturated=saturated)
