#include <unity.h>
#include "sensors/sensor_math.h"

using namespace aqua_atmos::sensors;

namespace {

/**
 * NIVEAU 1 : VALIDATION HARDWARE / MATHS
 */

void test_adc_to_percent_mapping() {
    // 0 ADC -> 0%
    TEST_ASSERT_FLOAT_WITHIN(0.1F, 0.0F, reservoir_percent_from_adc(0));
    // 4095 ADC -> 100%
    TEST_ASSERT_FLOAT_WITHIN(0.1F, 100.0F, reservoir_percent_from_adc(4095));
    // Mid scale
    TEST_ASSERT_FLOAT_WITHIN(1.0F, 50.0F, reservoir_percent_from_adc(2048));
}

void test_adc_clamping() {
    // Valeurs hors limites
    TEST_ASSERT_EQUAL_FLOAT(0.0F, reservoir_percent_from_adc(-100));
    TEST_ASSERT_EQUAL_FLOAT(100.0F, reservoir_percent_from_adc(5000));
}

void test_flow_meter_conversion() {
    // YF-S201: 7.5 Hz par L/min.
    // 7.5 pulses/sec -> 1000 mL/min
    TEST_ASSERT_FLOAT_WITHIN(0.1F, 1000.0F, flow_pulses_to_ml_min(7.5F));
    // 0 pulse -> 0 mL/min
    TEST_ASSERT_EQUAL_FLOAT(0.0F, flow_pulses_to_ml_min(0));
}

} // namespace

void run_sensor_math_tests() {
    RUN_TEST(test_adc_to_percent_mapping);
    RUN_TEST(test_adc_clamping);
    RUN_TEST(test_flow_meter_conversion);
}
