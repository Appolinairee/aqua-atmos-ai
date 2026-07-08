from __future__ import annotations

from dataclasses import asdict, dataclass


@dataclass(frozen=True)
class CycleRecord:
    profile_name: str
    day_index: int
    hour: int
    temp_air_c: float
    hr_pct: float
    solar_wm2: float
    pv_voltage: float
    temp_collector_c: float
    temp_cond_c: float
    delta_hr_sorbent: float
    reservoir_level_pct: float
    soc_battery_pct: float
    dew_point_c: float
    humidity_ratio_gkg: float
    vcrc_state: int
    vcrc_reason: str
    sorbent_mode: str
    heater_on: bool
    sorbent_saturated: bool

    def to_dict(self) -> dict[str, object]:
        return asdict(self)
