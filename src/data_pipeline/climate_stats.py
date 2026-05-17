from __future__ import annotations

import csv
import math
from dataclasses import asdict, dataclass
from pathlib import Path

from .city_catalog import get_city_definition


DEFAULT_STATS_DIR = Path("data/climate/stats")


@dataclass(frozen=True)
class ClimateStat:
    city_id: str
    month: int
    hour: int
    sample_count: int
    temp_mean_c: float
    temp_std_c: float
    temp_p01_c: float
    temp_p05_c: float
    temp_p50_c: float
    temp_p95_c: float
    temp_p99_c: float
    hr_mean_pct: float
    hr_std_pct: float
    hr_p01_pct: float
    hr_p05_pct: float
    hr_p50_pct: float
    hr_p95_pct: float
    hr_p99_pct: float
    solar_mean_wm2: float
    solar_std_wm2: float
    solar_p01_wm2: float
    solar_p05_wm2: float
    solar_p50_wm2: float
    solar_p95_wm2: float
    solar_p99_wm2: float
    cloud_mean_pct: float
    cloud_std_pct: float
    cloud_p01_pct: float
    cloud_p05_pct: float
    cloud_p50_pct: float
    cloud_p95_pct: float
    cloud_p99_pct: float

    def to_dict(self) -> dict[str, object]:
        return asdict(self)


def stats_path_for_city(city_id: str, base_dir: Path | None = None) -> Path:
    return (base_dir or DEFAULT_STATS_DIR) / f"{city_id}_hourly_stats.csv"


def load_climate_stats(city_name: str, *, base_dir: Path | None = None) -> dict[tuple[int, int], ClimateStat]:
    city = get_city_definition(city_name)
    path = stats_path_for_city(city.city_id, base_dir=base_dir)
    if not path.exists():
        raise FileNotFoundError(
            f"Missing climate stats for '{city.city_id}' at {path}. "
            "Run scripts/ingest_open_meteo.py first."
        )

    stats: dict[tuple[int, int], ClimateStat] = {}
    with path.open("r", encoding="utf-8", newline="") as handle:
        reader = csv.DictReader(handle)
        for row in reader:
            stat = ClimateStat(
                city_id=row["city_id"],
                month=int(row["month"]),
                hour=int(row["hour"]),
                sample_count=int(row["sample_count"]),
                temp_mean_c=float(row["temp_mean_c"]),
                temp_std_c=float(row["temp_std_c"]),
                temp_p01_c=float(row["temp_p01_c"]),
                temp_p05_c=float(row["temp_p05_c"]),
                temp_p50_c=float(row["temp_p50_c"]),
                temp_p95_c=float(row["temp_p95_c"]),
                temp_p99_c=float(row["temp_p99_c"]),
                hr_mean_pct=float(row["hr_mean_pct"]),
                hr_std_pct=float(row["hr_std_pct"]),
                hr_p01_pct=float(row["hr_p01_pct"]),
                hr_p05_pct=float(row["hr_p05_pct"]),
                hr_p50_pct=float(row["hr_p50_pct"]),
                hr_p95_pct=float(row["hr_p95_pct"]),
                hr_p99_pct=float(row["hr_p99_pct"]),
                solar_mean_wm2=float(row["solar_mean_wm2"]),
                solar_std_wm2=float(row["solar_std_wm2"]),
                solar_p01_wm2=float(row["solar_p01_wm2"]),
                solar_p05_wm2=float(row["solar_p05_wm2"]),
                solar_p50_wm2=float(row["solar_p50_wm2"]),
                solar_p95_wm2=float(row["solar_p95_wm2"]),
                solar_p99_wm2=float(row["solar_p99_wm2"]),
                cloud_mean_pct=float(row["cloud_mean_pct"]),
                cloud_std_pct=float(row["cloud_std_pct"]),
                cloud_p01_pct=float(row["cloud_p01_pct"]),
                cloud_p05_pct=float(row["cloud_p05_pct"]),
                cloud_p50_pct=float(row["cloud_p50_pct"]),
                cloud_p95_pct=float(row["cloud_p95_pct"]),
                cloud_p99_pct=float(row["cloud_p99_pct"]),
            )
            stats[(stat.month, stat.hour)] = stat
    return stats


def write_climate_stats(path: Path, stats: list[ClimateStat]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    fieldnames = list(stats[0].to_dict().keys())
    with path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=fieldnames)
        writer.writeheader()
        for stat in stats:
            writer.writerow(stat.to_dict())


def build_climate_stats_from_rows(city_id: str, rows: list[dict[str, str]]) -> list[ClimateStat]:
    grouped: dict[tuple[int, int], dict[str, list[float]]] = {}

    for row in rows:
        month = int(row["month"])
        hour = int(row["hour"])
        bucket = grouped.setdefault(
            (month, hour),
            {"temp": [], "hr": [], "solar": [], "cloud": []},
        )
        bucket["temp"].append(float(row["temp_air_c"]))
        bucket["hr"].append(float(row["hr_pct"]))
        bucket["solar"].append(float(row["solar_wm2"]))
        bucket["cloud"].append(float(row["cloud_cover_pct"]))

    stats: list[ClimateStat] = []
    for (month, hour), values in sorted(grouped.items()):
        temp = values["temp"]
        hr = values["hr"]
        solar = values["solar"]
        cloud = values["cloud"]
        stats.append(
            ClimateStat(
                city_id=city_id,
                month=month,
                hour=hour,
                sample_count=len(temp),
                temp_mean_c=_mean(temp),
                temp_std_c=_stddev(temp),
                temp_p01_c=_quantile(temp, 0.01),
                temp_p05_c=_quantile(temp, 0.05),
                temp_p50_c=_quantile(temp, 0.50),
                temp_p95_c=_quantile(temp, 0.95),
                temp_p99_c=_quantile(temp, 0.99),
                hr_mean_pct=_mean(hr),
                hr_std_pct=_stddev(hr),
                hr_p01_pct=_quantile(hr, 0.01),
                hr_p05_pct=_quantile(hr, 0.05),
                hr_p50_pct=_quantile(hr, 0.50),
                hr_p95_pct=_quantile(hr, 0.95),
                hr_p99_pct=_quantile(hr, 0.99),
                solar_mean_wm2=_mean(solar),
                solar_std_wm2=_stddev(solar),
                solar_p01_wm2=_quantile(solar, 0.01),
                solar_p05_wm2=_quantile(solar, 0.05),
                solar_p50_wm2=_quantile(solar, 0.50),
                solar_p95_wm2=_quantile(solar, 0.95),
                solar_p99_wm2=_quantile(solar, 0.99),
                cloud_mean_pct=_mean(cloud),
                cloud_std_pct=_stddev(cloud),
                cloud_p01_pct=_quantile(cloud, 0.01),
                cloud_p05_pct=_quantile(cloud, 0.05),
                cloud_p50_pct=_quantile(cloud, 0.50),
                cloud_p95_pct=_quantile(cloud, 0.95),
                cloud_p99_pct=_quantile(cloud, 0.99),
            )
        )
    return stats


def _mean(values: list[float]) -> float:
    return sum(values) / len(values)


def _stddev(values: list[float]) -> float:
    if len(values) < 2:
        return 0.0
    mean = _mean(values)
    variance = sum((value - mean) ** 2 for value in values) / len(values)
    return math.sqrt(variance)


def _quantile(values: list[float], q: float) -> float:
    ordered = sorted(values)
    if len(ordered) == 1:
        return ordered[0]
    position = (len(ordered) - 1) * q
    lower_index = int(math.floor(position))
    upper_index = int(math.ceil(position))
    lower = ordered[lower_index]
    upper = ordered[upper_index]
    if lower_index == upper_index:
        return lower
    weight = position - lower_index
    return lower + (upper - lower) * weight
