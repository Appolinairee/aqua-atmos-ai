from __future__ import annotations

import argparse
import csv
import json
from pathlib import Path
from typing import Any
from urllib.parse import urlencode
from urllib.request import urlopen


ROOT = Path(__file__).resolve().parents[1]
SRC = ROOT / "src"
import sys

if str(SRC) not in sys.path:
    sys.path.insert(0, str(SRC))

from data_pipeline.city_catalog import get_city_definition, list_city_ids
from data_pipeline.climate_stats import build_climate_stats_from_rows, stats_path_for_city, write_climate_stats


OPEN_METEO_ARCHIVE_URL = "https://archive-api.open-meteo.com/v1/archive"
HOURLY_VARIABLES = [
    "temperature_2m",
    "relative_humidity_2m",
    "dew_point_2m",
    "cloud_cover",
    "shortwave_radiation",
]


def main() -> None:
    parser = argparse.ArgumentParser(description="Ingest historical hourly weather data from Open-Meteo.")
    parser.add_argument("--cities", default="all", help="Comma-separated city ids or 'all'.")
    parser.add_argument("--start-date", default="2019-01-01")
    parser.add_argument("--end-date", default="2024-12-31")
    parser.add_argument("--output-dir", default=str(ROOT / "data" / "climate"))
    args = parser.parse_args()

    city_ids = list_city_ids() if args.cities == "all" else [item.strip() for item in args.cities.split(",") if item.strip()]
    output_dir = Path(args.output_dir)
    raw_dir = output_dir / "raw"
    normalized_dir = output_dir / "normalized"
    stats_dir = output_dir / "stats"

    for city_id in city_ids:
        city = get_city_definition(city_id)
        payload, url = fetch_open_meteo_archive(
            latitude=city.latitude_deg,
            longitude=city.longitude_deg,
            start_date=args.start_date,
            end_date=args.end_date,
        )
        raw_path = raw_dir / f"{city.city_id}_{args.start_date}_{args.end_date}.json"
        normalized_path = normalized_dir / f"{city.city_id}_hourly.csv"
        metadata_path = raw_dir / f"{city.city_id}_{args.start_date}_{args.end_date}.meta.json"

        write_json(raw_path, payload)
        write_json(
            metadata_path,
            {
                "city_id": city.city_id,
                "display_name": city.display_name,
                "country": city.country,
                "source": "Open-Meteo Historical Weather API",
                "source_url": url,
                "start_date": args.start_date,
                "end_date": args.end_date,
                "hourly_variables": HOURLY_VARIABLES,
            },
        )

        rows = normalize_open_meteo_payload(city.city_id, payload)
        write_normalized_csv(normalized_path, rows)
        climate_stats = build_climate_stats_from_rows(city.city_id, rows)
        write_climate_stats(stats_path_for_city(city.city_id, base_dir=stats_dir), climate_stats)

        print(
            f"{city.city_id}: wrote {len(rows)} normalized rows, "
            f"{len(climate_stats)} hourly stat buckets to {stats_dir}"
        )


def fetch_open_meteo_archive(*, latitude: float, longitude: float, start_date: str, end_date: str) -> tuple[dict[str, Any], str]:
    query = urlencode(
        {
            "latitude": latitude,
            "longitude": longitude,
            "start_date": start_date,
            "end_date": end_date,
            "hourly": ",".join(HOURLY_VARIABLES),
            "timezone": "GMT",
        }
    )
    url = f"{OPEN_METEO_ARCHIVE_URL}?{query}"
    with urlopen(url, timeout=60) as response:
        payload = json.loads(response.read().decode("utf-8"))
    return payload, url


def normalize_open_meteo_payload(city_id: str, payload: dict[str, Any]) -> list[dict[str, str]]:
    hourly = payload["hourly"]
    rows: list[dict[str, str]] = []
    for timestamp, temp, humidity, dew_point, cloud_cover, shortwave in zip(
        hourly["time"],
        hourly["temperature_2m"],
        hourly["relative_humidity_2m"],
        hourly["dew_point_2m"],
        hourly["cloud_cover"],
        hourly["shortwave_radiation"],
        strict=True,
    ):
        if temp is None or humidity is None or cloud_cover is None or shortwave is None:
            continue
        date_part, time_part = timestamp.split("T", maxsplit=1)
        year, month, day = date_part.split("-")
        hour = time_part.split(":", maxsplit=1)[0]
        rows.append(
            {
                "city_id": city_id,
                "timestamp_utc": timestamp,
                "year": year,
                "month": month,
                "day": day,
                "hour": hour,
                "temp_air_c": f"{float(temp):.2f}",
                "hr_pct": f"{float(humidity):.2f}",
                "dew_point_c": f"{float(dew_point):.2f}",
                "solar_wm2": f"{max(0.0, float(shortwave)):.2f}",
                "cloud_cover_pct": f"{float(cloud_cover):.2f}",
                "source": "open-meteo",
            }
        )
    return rows


def write_normalized_csv(path: Path, rows: list[dict[str, str]]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8", newline="") as handle:
        writer = csv.DictWriter(handle, fieldnames=list(rows[0].keys()))
        writer.writeheader()
        for row in rows:
            writer.writerow(row)


def write_json(path: Path, payload: dict[str, Any]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8") as handle:
        json.dump(payload, handle, ensure_ascii=True, indent=2)


if __name__ == "__main__":
    main()
