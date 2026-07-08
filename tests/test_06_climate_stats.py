from pathlib import Path

from data_pipeline.city_catalog import get_city_definition, list_city_ids
from data_pipeline.climate_stats import build_climate_stats_from_rows, load_climate_stats, write_climate_stats


def test_city_catalog_exposes_final_african_city_set() -> None:
    city_ids = list_city_ids()

    assert city_ids == ["abidjan", "agadir", "dakar", "douala", "mombasa", "walvis_bay"]
    assert get_city_definition("dakar_coastal").city_id == "dakar"


def test_build_and_load_climate_stats_round_trip(tmp_path: Path) -> None:
    rows = [
        {
            "month": "1",
            "hour": "0",
            "temp_air_c": "20.0",
            "hr_pct": "80.0",
            "solar_wm2": "0.0",
            "cloud_cover_pct": "35.0",
        },
        {
            "month": "1",
            "hour": "0",
            "temp_air_c": "22.0",
            "hr_pct": "78.0",
            "solar_wm2": "0.0",
            "cloud_cover_pct": "45.0",
        },
        {
            "month": "1",
            "hour": "1",
            "temp_air_c": "21.0",
            "hr_pct": "82.0",
            "solar_wm2": "0.0",
            "cloud_cover_pct": "55.0",
        },
    ]

    stats = build_climate_stats_from_rows("agadir", rows)
    write_climate_stats(tmp_path / "agadir_hourly_stats.csv", stats)
    loaded = load_climate_stats("agadir", base_dir=tmp_path)

    assert len(stats) == 2
    assert loaded[(1, 0)].sample_count == 2
    assert loaded[(1, 0)].temp_mean_c == 21.0
    assert loaded[(1, 1)].hr_p50_pct == 82.0
