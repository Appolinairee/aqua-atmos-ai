from vcrc_rules import decide_vcrc_state

def test_vcrc_forced_off_when_reservoir_full() -> None:
    decision = decide_vcrc_state(hr_pct=80.0, temp_air_c=24.0, reservoir_level_pct=99.0, soc_battery_pct=80.0)
    assert decision.state == 0
    assert decision.reason == "reservoir_full"


def test_vcrc_forced_off_when_battery_low() -> None:
    decision = decide_vcrc_state(hr_pct=80.0, temp_air_c=24.0, reservoir_level_pct=50.0, soc_battery_pct=10.0)
    assert decision.state == 0
    assert decision.reason == "battery_low"


def test_vcrc_off_when_hr_below_threshold() -> None:
    decision = decide_vcrc_state(hr_pct=39.9, temp_air_c=30.0, reservoir_level_pct=50.0, soc_battery_pct=80.0)
    assert decision.state == 0
    assert decision.reason == "low_hr"


def test_vcrc_off_when_dew_point_not_safe() -> None:
    decision = decide_vcrc_state(hr_pct=45.0, temp_air_c=8.0, reservoir_level_pct=50.0, soc_battery_pct=80.0)
    assert decision.state == 0
    assert decision.reason == "anti_frost"


def test_vcrc_on_when_all_conditions_met() -> None:
    decision = decide_vcrc_state(hr_pct=75.0, temp_air_c=26.0, reservoir_level_pct=50.0, soc_battery_pct=80.0)
    assert decision.state == 1
    assert decision.reason == "eligible"


def test_vcrc_reservoir_boundary_at_95_percent_not_forced_off() -> None:
    decision = decide_vcrc_state(hr_pct=75.0, temp_air_c=26.0, reservoir_level_pct=95.0, soc_battery_pct=80.0)
    assert decision.reason != "reservoir_full"


def test_vcrc_battery_boundary_at_20_percent_not_forced_off() -> None:
    decision = decide_vcrc_state(hr_pct=75.0, temp_air_c=26.0, reservoir_level_pct=50.0, soc_battery_pct=20.0)
    assert decision.reason != "battery_low"


def test_vcrc_hr_boundary_at_40_percent_can_be_eligible() -> None:
    decision = decide_vcrc_state(hr_pct=40.0, temp_air_c=30.0, reservoir_level_pct=50.0, soc_battery_pct=80.0)
    assert decision.reason != "low_hr"


def test_vcrc_humidity_ratio_boundary_at_6_gkg_blocks_when_just_below() -> None:
    decision = decide_vcrc_state(hr_pct=40.0, temp_air_c=20.0, reservoir_level_pct=50.0, soc_battery_pct=80.0)
    assert decision.state == 0
    assert decision.reason == "low_humidity_ratio"


def test_vcrc_dew_point_boundary_at_2_c_blocks() -> None:
    decision = decide_vcrc_state(hr_pct=40.0, temp_air_c=14.9, reservoir_level_pct=50.0, soc_battery_pct=80.0)
    assert decision.state == 0
    assert decision.reason == "anti_frost"
