from __future__ import annotations

import csv
import random
from pathlib import Path

from .city_catalog import get_city_definition
from .climate_stats import ClimateStat, load_climate_stats
from .labeler import RuleLabels, label_cycle
from .schema import CycleRecord


DEFAULT_OUTPUT_PATH = Path("data/synthetic/synthetic_cycles.csv")
DEFAULT_YEAR_OUTPUT_PATH = Path("data/synthetic/synthetic_year.csv")

def generate_synthetic_dataset(
    *,
    profile_name: str,
    days: int,
    month: int,
    seed: int = 0,
    output_path: Path | None = None,
    stats_dir: Path | None = None,
) -> list[CycleRecord]:
    if days <= 0:
        raise ValueError("days must be positive.")
    if not 1 <= month <= 12:
        raise ValueError("month must be in 1..12.")

    city = get_city_definition(profile_name)
    climate_stats = load_climate_stats(city.city_id, base_dir=stats_dir)
    rng = random.Random(seed)
    records = _generate_records(city_id=city.city_id, climate_stats=climate_stats, days=days, month=month, rng=rng)

    destination = output_path or DEFAULT_OUTPUT_PATH
    _write_records(destination, records)
    return records


def generate_synthetic_year(
    *,
    profile_name: str,
    seed: int = 0,
    output_path: Path | None = None,
    stats_dir: Path | None = None,
) -> list[CycleRecord]:
    rng = random.Random(seed)
    city = get_city_definition(profile_name)
    climate_stats = load_climate_stats(city.city_id, base_dir=stats_dir)
    records: list[CycleRecord] = []
    day_offset = 0

    for month in range(1, 13):
        month_records = _generate_records(
            city_id=city.city_id,
            climate_stats=climate_stats,
            days=_days_in_month(month),
            month=month,
            rng=rng,
            day_offset=day_offset,
        )
        records.extend(month_records)
        day_offset += _days_in_month(month)

    destination = output_path or DEFAULT_YEAR_OUTPUT_PATH
    _write_records(destination, records)
    return records


def _generate_records(
    *,
    city_id: str,
    climate_stats: dict[tuple[int, int], ClimateStat],
    days: int,
    month: int,
    rng: random.Random,
    day_offset: int = 0,
) -> list[CycleRecord]:
    month_index = month - 1
    battery_soc = rng.uniform(45.0, 85.0)
    reservoir_level = rng.uniform(10.0, 55.0)
    sorbent_load = rng.uniform(0.15, 0.50)
    records: list[CycleRecord] = []

    for day_index in range(days):
        day_bias_c = rng.uniform(-1.5, 1.5)
        day_bias_hr = rng.uniform(-6.0, 6.0)
        rare_event = _pick_rare_event(rng)
        cloud_factor = _cloud_factor(rare_event=rare_event, rng=rng)

        for hour in range(24):
            env = _build_hourly_environment(
                stat=climate_stats[(month, hour)],
                hour=hour,
                day_bias_c=day_bias_c,
                day_bias_hr=day_bias_hr,
                cloud_factor=cloud_factor,
                sorbent_load=sorbent_load,
                battery_soc=battery_soc,
                rare_event=rare_event,
                rng=rng,
            )
            labels = label_cycle(
                hr_pct=env["hr_pct"],
                temp_air_c=env["temp_air_c"],
                delta_hr_sorbent=env["delta_hr_sorbent"],
                solar_wm2=env["solar_wm2"],
                reservoir_level_pct=reservoir_level,
                soc_battery_pct=battery_soc,
            )
            record = CycleRecord(
                profile_name=city_id,
                day_index=day_offset + day_index,
                hour=hour,
                temp_air_c=env["temp_air_c"],
                hr_pct=env["hr_pct"],
                solar_wm2=env["solar_wm2"],
                pv_voltage=env["pv_voltage"],
                temp_collector_c=env["temp_collector_c"],
                temp_cond_c=env["temp_cond_c"],
                delta_hr_sorbent=env["delta_hr_sorbent"],
                reservoir_level_pct=reservoir_level,
                soc_battery_pct=battery_soc,
                dew_point_c=labels.dew_point_c,
                humidity_ratio_gkg=labels.humidity_ratio_gkg,
                vcrc_state=labels.vcrc_state,
                vcrc_reason=labels.vcrc_reason,
                sorbent_mode=labels.sorbent_mode,
                heater_on=labels.heater_on,
                sorbent_saturated=labels.sorbent_saturated,
            )
            records.append(record)
            battery_soc, reservoir_level, sorbent_load = _update_hidden_state(
                battery_soc=battery_soc,
                reservoir_level=reservoir_level,
                sorbent_load=sorbent_load,
                solar_wm2=env["solar_wm2"],
                hr_pct=env["hr_pct"],
                labels=labels,
                rng=rng,
            )
    return records


def _build_hourly_environment(
    *,
    stat: ClimateStat,
    hour: int,
    day_bias_c: float,
    day_bias_hr: float,
    cloud_factor: float,
    sorbent_load: float,
    battery_soc: float,
    rare_event: str,
    rng: random.Random,
) -> dict[str, float]:
    temp_air_c = _sample_observed_range(
        mean=stat.temp_mean_c + day_bias_c + _rare_temp_shift(rare_event),
        std=max(0.6, stat.temp_std_c * 0.55),
        lower=stat.temp_p01_c - 1.5,
        upper=stat.temp_p99_c + 1.5,
        rng=rng,
    )
    hr_pct = _sample_observed_range(
        mean=stat.hr_mean_pct + day_bias_hr + _rare_hr_shift(rare_event),
        std=max(2.5, stat.hr_std_pct * 0.65),
        lower=max(25.0, stat.hr_p01_pct - 4.0),
        upper=min(99.0, stat.hr_p99_pct + 3.0),
        rng=rng,
    )
    solar_wm2 = _sample_observed_range(
        mean=max(0.0, stat.solar_mean_wm2 * cloud_factor * _rare_solar_factor(rare_event)),
        std=max(0.0, stat.solar_std_wm2 * 0.7),
        lower=max(0.0, stat.solar_p01_wm2 * 0.6),
        upper=max(stat.solar_p99_wm2 * 1.05, stat.solar_p50_wm2 + 25.0),
        rng=rng,
    )
    cloud_cover_pct = _sample_observed_range(
        mean=_clamp(stat.cloud_mean_pct * (2.0 - cloud_factor) + _rare_cloud_shift(rare_event), 0.0, 100.0),
        std=max(4.0, stat.cloud_std_pct * 0.65),
        lower=0.0,
        upper=100.0,
        rng=rng,
    )
    solar_wm2 = 0.0 if solar_wm2 < 5.0 else solar_wm2
    pv_voltage = 5.5 + (solar_wm2 / 900.0) * 14.0 if solar_wm2 > 0 else 0.0

    collector_gain = (solar_wm2 / 900.0) * 28.0
    temp_collector_c = temp_air_c + collector_gain + rng.uniform(-1.0, 1.0)

    cooling_margin = 2.0 + (min(100.0, battery_soc) / 100.0) * 2.5 + (solar_wm2 / 900.0) * 1.5
    temp_cond_c = temp_air_c - cooling_margin + rng.uniform(-0.8, 0.8)

    absorption_potential = max(0.0, (hr_pct - 35.0) / 8.0)
    solar_penalty = (solar_wm2 / 900.0) * 1.8
    saturation_penalty = sorbent_load * 6.0
    delta_hr_sorbent = max(
        0.0,
        absorption_potential - solar_penalty - saturation_penalty + rng.uniform(-0.4, 0.4),
    )

    return {
        "temp_air_c": round(temp_air_c, 2),
        "hr_pct": round(hr_pct, 2),
        "solar_wm2": round(solar_wm2, 2),
        "pv_voltage": round(pv_voltage, 2),
        "temp_collector_c": round(temp_collector_c, 2),
        "temp_cond_c": round(temp_cond_c, 2),
        "delta_hr_sorbent": round(delta_hr_sorbent, 2),
        "cloud_cover_pct": round(cloud_cover_pct, 2),
    }


def _update_hidden_state(
    *,
    battery_soc: float,
    reservoir_level: float,
    sorbent_load: float,
    solar_wm2: float,
    hr_pct: float,
    labels: RuleLabels,
    rng: random.Random,
) -> tuple[float, float, float]:
    solar_charge = (solar_wm2 / 900.0) * 7.5
    vcrc_drain = 5.5 if labels.vcrc_state else 0.5
    heater_drain = 4.0 if labels.heater_on else 0.0
    auxiliary_drain = 1.2 if labels.sorbent_mode != "veille" else 0.2
    battery_soc = _clamp(
        battery_soc + solar_charge - vcrc_drain - heater_drain - auxiliary_drain + rng.uniform(-0.5, 0.5),
        5.0,
        100.0,
    )

    water_gain = 1.4 if labels.vcrc_state else 0.0
    passive_use = rng.uniform(0.0, 0.25)
    reservoir_level = _clamp(reservoir_level + water_gain - passive_use, 0.0, 100.0)

    if labels.sorbent_mode == "regeneration":
        sorbent_load -= 0.22 + rng.uniform(-0.03, 0.03)
    elif labels.sorbent_mode == "absorption" and hr_pct >= 40.0:
        sorbent_load += 0.12 + rng.uniform(-0.03, 0.03)
    else:
        sorbent_load += rng.uniform(-0.02, 0.02)

    sorbent_load = _clamp(sorbent_load, 0.0, 1.0)
    return battery_soc, reservoir_level, sorbent_load


def _solar_shape(hour: int) -> float:
    return 0.0


def _pick_rare_event(rng: random.Random) -> str:
    roll = rng.random()
    if roll < 0.04:
        return "heatwave"
    if roll < 0.08:
        return "humid_night"
    if roll < 0.12:
        return "dust"
    if roll < 0.15:
        return "fog"
    return "nominal"


def _cloud_factor(*, rare_event: str, rng: random.Random) -> float:
    baseline = rng.uniform(0.78, 1.08)
    if rare_event == "dust":
        baseline -= 0.18
    if rare_event == "fog":
        baseline -= 0.10
    return _clamp(baseline, 0.45, 1.12)


def _rare_temp_shift(rare_event: str) -> float:
    if rare_event == "heatwave":
        return 3.5
    if rare_event == "fog":
        return -1.0
    return 0.0


def _rare_hr_shift(rare_event: str) -> float:
    if rare_event == "humid_night":
        return 8.0
    if rare_event == "fog":
        return 10.0
    if rare_event == "heatwave":
        return -6.0
    return 0.0


def _rare_solar_factor(rare_event: str) -> float:
    if rare_event == "dust":
        return 0.72
    if rare_event == "fog":
        return 0.82
    return 1.0


def _rare_cloud_shift(rare_event: str) -> float:
    if rare_event == "fog":
        return 12.0
    if rare_event == "dust":
        return 8.0
    return 0.0


def _sample_observed_range(
    *,
    mean: float,
    std: float,
    lower: float,
    upper: float,
    rng: random.Random,
) -> float:
    if std <= 0.0:
        return _clamp(mean, lower, upper)
    for _ in range(8):
        value = rng.gauss(mean, std)
        if lower <= value <= upper:
            return value
    return _clamp(mean, lower, upper)


def _write_records(path: Path, records: list[CycleRecord]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    fieldnames = list(records[0].to_dict().keys())
    with path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=fieldnames)
        writer.writeheader()
        for record in records:
            writer.writerow(record.to_dict())


def _clamp(value: float, lower: float, upper: float) -> float:
    return max(lower, min(upper, value))


def _days_in_month(month: int) -> int:
    if month == 2:
        return 28
    if month in {4, 6, 9, 11}:
        return 30
    return 31
