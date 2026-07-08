import pytest

from metrics import humidity_ratio_gkg


def test_humidity_ratio_increases_with_relative_humidity() -> None:
    low = humidity_ratio_gkg(temp_c=25.0, rel_humidity_pct=40.0)
    high = humidity_ratio_gkg(temp_c=25.0, rel_humidity_pct=80.0)
    assert high > low


def test_humidity_ratio_rejects_invalid_humidity() -> None:
    with pytest.raises(ValueError):
        humidity_ratio_gkg(temp_c=20.0, rel_humidity_pct=0.0)

    with pytest.raises(ValueError):
        humidity_ratio_gkg(temp_c=20.0, rel_humidity_pct=101.0)


def test_humidity_ratio_rejects_non_positive_pressure() -> None:
    with pytest.raises(ValueError):
        humidity_ratio_gkg(temp_c=20.0, rel_humidity_pct=60.0, pressure_hpa=0.0)
