import pytest

from dew_point import magnus_dew_point


def test_magnus_dew_point_known_value_30c_70rh() -> None:
    """Known reference point for Magnus constants a=17.625, b=243.04."""
    dew_point = magnus_dew_point(temp_c=30.0, rel_humidity_pct=70.0)
    assert dew_point == pytest.approx(23.93, abs=0.2)


def test_dew_point_increases_with_relative_humidity() -> None:
    low_humidity = magnus_dew_point(temp_c=25.0, rel_humidity_pct=40.0)
    high_humidity = magnus_dew_point(temp_c=25.0, rel_humidity_pct=80.0)
    assert high_humidity > low_humidity


def test_magnus_rejects_out_of_range_humidity() -> None:
    with pytest.raises(ValueError):
        magnus_dew_point(temp_c=20.0, rel_humidity_pct=0.0)

    with pytest.raises(ValueError):
        magnus_dew_point(temp_c=20.0, rel_humidity_pct=101.0)
