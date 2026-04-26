from __future__ import annotations

from constants import BATTERY_LOW_PCT, RESERVOIR_FULL_PCT


def is_reservoir_full(reservoir_level_pct: float) -> bool:
    return reservoir_level_pct > RESERVOIR_FULL_PCT


def is_battery_low(soc_battery_pct: float) -> bool:
    return soc_battery_pct < BATTERY_LOW_PCT
