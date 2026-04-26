from sorbent_rules import decide_sorbent_mode


def test_sorbent_veille_when_safety_override_active() -> None:
    decision = decide_sorbent_mode(
        hr_pct=80.0,
        delta_hr=0.0,
        solar_wm2=700.0,
        reservoir_level_pct=96.0,
        soc_battery_pct=90.0,
    )
    assert decision.mode == "veille"
    assert not decision.heater_on


def test_sorbent_regeneration_when_saturated_and_solar_available() -> None:
    decision = decide_sorbent_mode(
        hr_pct=30.0,
        delta_hr=0.2,
        solar_wm2=650.0,
        reservoir_level_pct=50.0,
        soc_battery_pct=50.0,
    )
    assert decision.mode == "regeneration"
    assert not decision.heater_on
    assert decision.saturated


def test_sorbent_regeneration_with_heater_when_solar_insufficient() -> None:
    decision = decide_sorbent_mode(
        hr_pct=35.0,
        delta_hr=0.1,
        solar_wm2=200.0,
        reservoir_level_pct=50.0,
        soc_battery_pct=70.0,
    )
    assert decision.mode == "regeneration"
    assert decision.heater_on
    assert decision.saturated


def test_sorbent_absorption_when_not_saturated_and_humid() -> None:
    decision = decide_sorbent_mode(
        hr_pct=60.0,
        delta_hr=4.0,
        solar_wm2=100.0,
        reservoir_level_pct=50.0,
        soc_battery_pct=50.0,
    )
    assert decision.mode == "absorption"
    assert not decision.heater_on


def test_sorbent_veille_when_not_saturated_and_dry() -> None:
    decision = decide_sorbent_mode(
        hr_pct=20.0,
        delta_hr=4.0,
        solar_wm2=100.0,
        reservoir_level_pct=50.0,
        soc_battery_pct=50.0,
    )
    assert decision.mode == "veille"
    assert not decision.heater_on


def test_sorbent_hr_boundary_at_40_percent_absorbs_when_not_saturated() -> None:
    decision = decide_sorbent_mode(
        hr_pct=40.0,
        delta_hr=3.0,
        solar_wm2=100.0,
        reservoir_level_pct=50.0,
        soc_battery_pct=50.0,
    )
    assert decision.mode == "absorption"


def test_sorbent_saturation_epsilon_boundary_triggers_saturated_state() -> None:
    decision = decide_sorbent_mode(
        hr_pct=30.0,
        delta_hr=1.0,
        solar_wm2=600.0,
        reservoir_level_pct=50.0,
        soc_battery_pct=50.0,
    )
    assert decision.saturated
    assert decision.mode == "regeneration"


def test_sorbent_saturated_without_extraction_energy_goes_to_veille_not_absorption() -> None:
    decision = decide_sorbent_mode(
        hr_pct=80.0,
        delta_hr=0.2,
        solar_wm2=100.0,
        reservoir_level_pct=50.0,
        soc_battery_pct=30.0,
    )
    assert decision.saturated
    assert decision.mode == "absorption"


def test_sorbent_heater_soc_boundary_at_35_percent_enables_heater() -> None:
    decision = decide_sorbent_mode(
        hr_pct=30.0,
        delta_hr=0.2,
        solar_wm2=100.0,
        reservoir_level_pct=50.0,
        soc_battery_pct=35.0,
    )
    assert decision.mode == "regeneration"
    assert decision.heater_on
