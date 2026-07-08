from __future__ import annotations

from dataclasses import dataclass

from dew_point import magnus_dew_point
from metrics import humidity_ratio_gkg
from sorbent_rules import decide_sorbent_mode
from vcrc_rules import decide_vcrc_state


@dataclass(frozen=True)
class RuleLabels:
    dew_point_c: float
    humidity_ratio_gkg: float
    vcrc_state: int
    vcrc_reason: str
    sorbent_mode: str
    heater_on: bool
    sorbent_saturated: bool


def label_cycle(
    *,
    hr_pct: float,
    temp_air_c: float,
    delta_hr_sorbent: float,
    solar_wm2: float,
    reservoir_level_pct: float,
    soc_battery_pct: float,
) -> RuleLabels:
    dew_point_c = magnus_dew_point(temp_air_c, hr_pct)
    humidity_ratio = humidity_ratio_gkg(temp_air_c, hr_pct)

    vcrc = decide_vcrc_state(
        hr_pct=hr_pct,
        temp_air_c=temp_air_c,
        reservoir_level_pct=reservoir_level_pct,
        soc_battery_pct=soc_battery_pct,
    )
    sorbent = decide_sorbent_mode(
        hr_pct=hr_pct,
        delta_hr=delta_hr_sorbent,
        solar_wm2=solar_wm2,
        reservoir_level_pct=reservoir_level_pct,
        soc_battery_pct=soc_battery_pct,
    )
    return RuleLabels(
        dew_point_c=dew_point_c,
        humidity_ratio_gkg=humidity_ratio,
        vcrc_state=vcrc.state,
        vcrc_reason=vcrc.reason,
        sorbent_mode=sorbent.mode,
        heater_on=sorbent.heater_on,
        sorbent_saturated=sorbent.saturated,
    )
