from pathlib import Path

from data_pipeline.labeler import label_cycle
from data_pipeline.synthetic_generator import generate_synthetic_dataset, generate_synthetic_year


def test_generate_synthetic_dataset_creates_24_cycles_per_day(tmp_path: Path) -> None:
    output_path = tmp_path / "synthetic.csv"

    records = generate_synthetic_dataset(
        profile_name="dakar_coastal",
        days=2,
        month=8,
        seed=7,
        output_path=output_path,
    )

    assert len(records) == 48
    assert output_path.exists()
    assert records[0].profile_name == "dakar_coastal"
    assert records[-1].hour == 23


def test_generated_cycles_keep_physical_ranges(tmp_path: Path) -> None:
    records = generate_synthetic_dataset(
        profile_name="agadir_coastal",
        days=2,
        month=7,
        seed=3,
        output_path=tmp_path / "ranges.csv",
    )

    assert all(30.0 <= record.hr_pct <= 97.0 for record in records)
    assert all(record.solar_wm2 >= 0.0 for record in records)
    assert all(0.0 <= record.pv_voltage <= 20.0 for record in records)
    assert all(0.0 <= record.reservoir_level_pct <= 100.0 for record in records)
    assert all(5.0 <= record.soc_battery_pct <= 100.0 for record in records)


def test_generated_night_cycles_have_zero_solar(tmp_path: Path) -> None:
    records = generate_synthetic_dataset(
        profile_name="dakar_coastal",
        days=1,
        month=1,
        seed=1,
        output_path=tmp_path / "night.csv",
    )

    night_records = [record for record in records if record.hour < 6 or record.hour > 18]
    assert night_records
    assert all(record.solar_wm2 == 0.0 for record in night_records)
    assert all(record.pv_voltage == 0.0 for record in night_records)


def test_generated_labels_match_rule_engine(tmp_path: Path) -> None:
    records = generate_synthetic_dataset(
        profile_name="dakar_coastal",
        days=1,
        month=9,
        seed=11,
        output_path=tmp_path / "labels.csv",
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

    records = generate_synthetic_year(
        profile_name="dakar_coastal",
        seed=5,
        output_path=output_path,
    )

    assert len(records) == 365 * 24
    assert output_path.exists()
    assert records[0].day_index == 0
    assert records[-1].day_index == 364
