from pathlib import Path

from data_pipeline.climate_stats import build_climate_stats_from_rows, write_climate_stats
from data_pipeline.labeler import label_cycle
from data_pipeline.synthetic_generator import generate_synthetic_dataset, generate_synthetic_year


def _write_test_stats(tmp_path: Path, city_id: str) -> Path:
    stats_dir = tmp_path / "stats"
    rows: list[dict[str, str]] = []

    for month in range(1, 13):
        for hour in range(24):
            for sample_index in range(5):
                solar = max(0.0, (1 - abs(hour - 12) / 6) * (420 + month * 12) + sample_index * 8) if 6 <= hour <= 18 else 0.0
                rows.append(
                    {
                        "month": str(month),
                        "hour": str(hour),
                        "temp_air_c": f"{18.0 + month * 0.8 + (hour - 12) * 0.25 + sample_index * 0.2:.2f}",
                        "hr_pct": f"{68.0 - abs(hour - 6) * 1.3 + month * 0.4 + sample_index * 0.3:.2f}",
                        "solar_wm2": f"{solar:.2f}",
                        "cloud_cover_pct": f"{42.0 + abs(hour - 12) * 1.1 + sample_index * 0.5:.2f}",
                    }
                )

    stats = build_climate_stats_from_rows(city_id, rows)
    write_climate_stats(stats_dir / f"{city_id}_hourly_stats.csv", stats)
    return stats_dir


def test_generate_synthetic_dataset_creates_24_cycles_per_day(tmp_path: Path) -> None:
    output_path = tmp_path / "synthetic.csv"
    stats_dir = _write_test_stats(tmp_path, "dakar")

    records = generate_synthetic_dataset(
        profile_name="dakar",
        days=2,
        month=8,
        seed=7,
        output_path=output_path,
        stats_dir=stats_dir,
    )

    assert len(records) == 48
    assert output_path.exists()
    assert records[0].profile_name == "dakar"
    assert records[-1].hour == 23


def test_generated_cycles_keep_physical_ranges(tmp_path: Path) -> None:
    stats_dir = _write_test_stats(tmp_path, "agadir")
    records = generate_synthetic_dataset(
        profile_name="agadir",
        days=2,
        month=7,
        seed=3,
        output_path=tmp_path / "ranges.csv",
        stats_dir=stats_dir,
    )

    assert all(25.0 <= record.hr_pct <= 99.0 for record in records)
    assert all(record.solar_wm2 >= 0.0 for record in records)
    assert all(0.0 <= record.pv_voltage <= 20.0 for record in records)
    assert all(0.0 <= record.reservoir_level_pct <= 100.0 for record in records)
    assert all(5.0 <= record.soc_battery_pct <= 100.0 for record in records)


def test_generated_night_cycles_have_zero_solar(tmp_path: Path) -> None:
    stats_dir = _write_test_stats(tmp_path, "dakar")
    records = generate_synthetic_dataset(
        profile_name="dakar",
        days=1,
        month=1,
        seed=1,
        output_path=tmp_path / "night.csv",
        stats_dir=stats_dir,
    )

    night_records = [record for record in records if record.hour < 6 or record.hour > 18]
    assert night_records
    assert all(record.solar_wm2 == 0.0 for record in night_records)
    assert all(record.pv_voltage == 0.0 for record in night_records)


def test_generated_labels_match_rule_engine(tmp_path: Path) -> None:
    stats_dir = _write_test_stats(tmp_path, "dakar")
    records = generate_synthetic_dataset(
        profile_name="dakar",
        days=1,
        month=9,
        seed=11,
        output_path=tmp_path / "labels.csv",
        stats_dir=stats_dir,
    )

    for record in records:
        labels = label_cycle(
            hr_pct=record.hr_pct,
            temp_air_c=record.temp_air_c,
            delta_hr_sorbent=record.delta_hr_sorbent,
            solar_wm2=record.solar_wm2,
            reservoir_level_pct=record.reservoir_level_pct,
            soc_battery_pct=record.soc_battery_pct,
        )
        assert record.vcrc_state == labels.vcrc_state
        assert record.sorbent_mode == labels.sorbent_mode
        assert record.heater_on == labels.heater_on


def test_generate_synthetic_year_creates_365_days(tmp_path: Path) -> None:
    output_path = tmp_path / "year.csv"
    stats_dir = _write_test_stats(tmp_path, "dakar")

    records = generate_synthetic_year(
        profile_name="dakar",
        seed=5,
        output_path=output_path,
        stats_dir=stats_dir,
    )

    assert len(records) == 365 * 24
    assert output_path.exists()
    assert records[0].day_index == 0
    assert records[-1].day_index == 364
