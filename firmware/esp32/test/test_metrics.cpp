#include <unity.h>

#include "config/constants.h"
#include "domain/metrics.h"

namespace {

using aqua_atmos::domain::DerivedFrame;
using aqua_atmos::domain::SensorFrame;

SensorFrame make_nominal_sensor_frame() {
    SensorFrame sensors;
    sensors.temp_air_c = 25.0F;
    sensors.hr_pct = 60.0F;
    sensors.hr_in_pct = 65.0F;
    sensors.hr_out_pct = 48.0F;
    sensors.temp_cond_c = 18.0F;
    sensors.temp_collector_c = 42.0F;
    sensors.solar_wm2 = 800.0F;
    sensors.soc_battery_pct = 80.0F;
    sensors.reservoir_level_pct = 30.0F;
    sensors.hour_of_day = 12;
    return sensors;
}

// compute_dew_point_c

void test_dew_point_matches_reference_condition() {
    const float dew_point_c = aqua_atmos::domain::compute_dew_point_c(25.0F, 60.0F);

    TEST_ASSERT_FLOAT_WITHIN(0.1F, 16.7F, dew_point_c);
}

void test_dew_point_returns_safe_floor_for_zero_humidity() {
    const float dew_point_c = aqua_atmos::domain::compute_dew_point_c(25.0F, 0.0F);

    TEST_ASSERT_EQUAL_FLOAT(-50.0F, dew_point_c);
}

// compute_humidity_ratio_gkg

void test_humidity_ratio_matches_reference_condition() {
    const float ratio_gkg = aqua_atmos::domain::compute_humidity_ratio_gkg(25.0F, 60.0F);

    TEST_ASSERT_FLOAT_WITHIN(0.5F, 12.0F, ratio_gkg);
}

// compute_delta_hr_sorbent

void test_delta_hr_sorbent_is_inlet_minus_outlet() {
    const float delta_pct = aqua_atmos::domain::compute_delta_hr_sorbent(65.0F, 48.0F);

    TEST_ASSERT_FLOAT_WITHIN(0.001F, 17.0F, delta_pct);
}

// enrich_derived_frame

void test_enrich_derived_frame_computes_continuous_features() {
    const SensorFrame sensors = make_nominal_sensor_frame();
    DerivedFrame derived;

    aqua_atmos::domain::enrich_derived_frame(sensors, derived);

    TEST_ASSERT_FLOAT_WITHIN(0.01F, 0.0F, derived.hour_sin);
    TEST_ASSERT_FLOAT_WITHIN(0.01F, -1.0F, derived.hour_cos);
    TEST_ASSERT_FLOAT_WITHIN(0.001F, 7.0F, derived.thermal_lift_c);
    TEST_ASSERT_FLOAT_WITHIN(0.001F, 17.0F, derived.collector_gain_c);
}

void test_enrich_derived_frame_sets_flags_when_thresholds_are_met() {
    SensorFrame sensors = make_nominal_sensor_frame();
    sensors.hr_pct = aqua_atmos::config::VCRC_MIN_HR_PCT;
    sensors.soc_battery_pct = aqua_atmos::config::BATTERY_CRITICAL_SOC + 5.0F;
    sensors.reservoir_level_pct = aqua_atmos::config::RESERVOIR_HIGH_THRESHOLD;
    sensors.solar_wm2 = aqua_atmos::config::SOLAR_DAYLIGHT_THRESHOLD + 0.1F;
    DerivedFrame derived;

    aqua_atmos::domain::enrich_derived_frame(sensors, derived);

    TEST_ASSERT_EQUAL_INT(1, derived.is_daylight);
    TEST_ASSERT_EQUAL_INT(1, derived.high_humidity_flag);
    TEST_ASSERT_EQUAL_INT(1, derived.battery_stress_flag);
    TEST_ASSERT_EQUAL_INT(1, derived.reservoir_high_flag);
}

void test_enrich_derived_frame_clears_flags_below_thresholds() {
    SensorFrame sensors = make_nominal_sensor_frame();
    sensors.hr_pct = aqua_atmos::config::VCRC_MIN_HR_PCT - 0.1F;
    sensors.soc_battery_pct = aqua_atmos::config::BATTERY_CRITICAL_SOC + 5.1F;
    sensors.reservoir_level_pct = aqua_atmos::config::RESERVOIR_HIGH_THRESHOLD - 0.1F;
    sensors.solar_wm2 = aqua_atmos::config::SOLAR_DAYLIGHT_THRESHOLD;
    DerivedFrame derived;

    aqua_atmos::domain::enrich_derived_frame(sensors, derived);

    TEST_ASSERT_EQUAL_INT(0, derived.is_daylight);
    TEST_ASSERT_EQUAL_INT(0, derived.high_humidity_flag);
    TEST_ASSERT_EQUAL_INT(0, derived.battery_stress_flag);
    TEST_ASSERT_EQUAL_INT(0, derived.reservoir_high_flag);
}

}  // namespace

void run_metrics_tests() {
    // compute_dew_point_c
    RUN_TEST(test_dew_point_matches_reference_condition);
    RUN_TEST(test_dew_point_returns_safe_floor_for_zero_humidity);

    // compute_humidity_ratio_gkg
    RUN_TEST(test_humidity_ratio_matches_reference_condition);

    // compute_delta_hr_sorbent
    RUN_TEST(test_delta_hr_sorbent_is_inlet_minus_outlet);

    // enrich_derived_frame
    RUN_TEST(test_enrich_derived_frame_computes_continuous_features);
    RUN_TEST(test_enrich_derived_frame_sets_flags_when_thresholds_are_met);
    RUN_TEST(test_enrich_derived_frame_clears_flags_below_thresholds);
}
