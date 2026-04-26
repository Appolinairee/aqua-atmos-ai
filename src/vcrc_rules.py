from __future__ import annotations

from dataclasses import dataclass

from constants import VCRC_DEW_POINT_MIN_C, VCRC_HR_MIN_PCT, VCRC_HUMIDITY_RATIO_MIN_GKG
from dew_point import magnus_dew_point
from metrics import humidity_ratio_gkg
from safety_rules import is_battery_low, is_reservoir_full


@dataclass(frozen=True)
class VcrcDecision:
    state: int
    reason: str


def decide_vcrc_state(
    hr_pct: float,
    temp_air_c: float,
    reservoir_level_pct: float,
    soc_battery_pct: float,
) -> VcrcDecision:
    """Return VCRC ON/OFF using retained rule set and hard safety constraints."""
    if is_reservoir_full(reservoir_level_pct):
        return VcrcDecision(state=0, reason="reservoir_full")

    if is_battery_low(soc_battery_pct):
        return VcrcDecision(state=0, reason="battery_low")

    if hr_pct < VCRC_HR_MIN_PCT:
        return VcrcDecision(state=0, reason="low_hr")

    dew_point_c = magnus_dew_point(temp_air_c, hr_pct)
    if dew_point_c <= VCRC_DEW_POINT_MIN_C:
        return VcrcDecision(state=0, reason="anti_frost")

    w_gkg = humidity_ratio_gkg(temp_air_c, hr_pct)
    if w_gkg < VCRC_HUMIDITY_RATIO_MIN_GKG:
        return VcrcDecision(state=0, reason="low_humidity_ratio")

    return VcrcDecision(state=1, reason="eligible")
