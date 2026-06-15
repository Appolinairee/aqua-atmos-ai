#include <unity.h>

#include "sensors/sensor_math.h"

namespace {

// reservoir_percent_from_adc

void test_reservoir_percent_from_adc_maps_zero_to_zero_percent() {
    TEST_ASSERT_FLOAT_WITHIN(
        0.001F,
        0.0F,
        aqua_atmos::sensors::reservoir_percent_from_adc(0));
}

void test_reservoir_percent_from_adc_maps_full_scale_to_100_percent() {
    TEST_ASSERT_FLOAT_WITHIN(
        0.001F,
        100.0F,
        aqua_atmos::sensors::reservoir_percent_from_adc(4095));
}

void test_reservoir_percent_from_adc_maps_mid_scale_to_half_percent() {
    TEST_ASSERT_FLOAT_WITHIN(
        0.1F,
        50.0F,
        aqua_atmos::sensors::reservoir_percent_from_adc(2048));
}

void test_reservoir_percent_from_adc_clamps_negative_values() {
    TEST_ASSERT_FLOAT_WITHIN(
        0.001F,
        0.0F,
        aqua_atmos::sensors::reservoir_percent_from_adc(-1));
}

void test_reservoir_percent_from_adc_clamps_values_above_full_scale() {
    TEST_ASSERT_FLOAT_WITHIN(
        0.001F,
        100.0F,
        aqua_atmos::sensors::reservoir_percent_from_adc(5000));
}

}  // namespace

void run_sensor_math_tests() {
    // reservoir_percent_from_adc
    RUN_TEST(test_reservoir_percent_from_adc_maps_zero_to_zero_percent);
    RUN_TEST(test_reservoir_percent_from_adc_maps_full_scale_to_100_percent);
    RUN_TEST(test_reservoir_percent_from_adc_maps_mid_scale_to_half_percent);
    RUN_TEST(test_reservoir_percent_from_adc_clamps_negative_values);
    RUN_TEST(test_reservoir_percent_from_adc_clamps_values_above_full_scale);
}
