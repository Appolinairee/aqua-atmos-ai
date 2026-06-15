#include <unity.h>

#include "config/constants.h"
#include "control/output_guard.h"

namespace {

using aqua_atmos::domain::OutputFrame;

OutputFrame make_outputs(bool vcrc_on, bool heater_on) {
    OutputFrame outputs;
    outputs.vcrc_relay_on = vcrc_on;
    outputs.heater_relay_on = heater_on;
    outputs.vcrc_fan_pwm = vcrc_on ? 200 : 0;
    outputs.sorbent_fan_pwm = heater_on ? 220 : 0;
    outputs.servo_angle_deg = heater_on ? 140 : 0;
    return outputs;
}

// apply_output_guard

void test_output_guard_allows_initial_activation() {
    aqua_atmos::control::OutputGuardState state;
    const OutputFrame guarded =
        aqua_atmos::control::apply_output_guard(make_outputs(true, true), state, 1000UL);

    TEST_ASSERT_TRUE(guarded.vcrc_relay_on);
    TEST_ASSERT_TRUE(guarded.heater_relay_on);
}

void test_output_guard_blocks_vcrc_restart_before_minimum_off_time() {
    aqua_atmos::control::OutputGuardState state;
    aqua_atmos::control::apply_output_guard(make_outputs(true, false), state, 1000UL);
    aqua_atmos::control::apply_output_guard(make_outputs(false, false), state, 2000UL);

    const OutputFrame guarded =
        aqua_atmos::control::apply_output_guard(make_outputs(true, false),
                                                state,
                                                2000UL + aqua_atmos::config::VCRC_MIN_OFF_MS - 1UL);

    TEST_ASSERT_FALSE(guarded.vcrc_relay_on);
    TEST_ASSERT_EQUAL_INT(0, guarded.vcrc_fan_pwm);
}

void test_output_guard_allows_vcrc_restart_after_minimum_off_time() {
    aqua_atmos::control::OutputGuardState state;
    aqua_atmos::control::apply_output_guard(make_outputs(true, false), state, 1000UL);
    aqua_atmos::control::apply_output_guard(make_outputs(false, false), state, 2000UL);

    const OutputFrame guarded =
        aqua_atmos::control::apply_output_guard(make_outputs(true, false),
                                                state,
                                                2000UL + aqua_atmos::config::VCRC_MIN_OFF_MS);

    TEST_ASSERT_TRUE(guarded.vcrc_relay_on);
    TEST_ASSERT_EQUAL_INT(200, guarded.vcrc_fan_pwm);
}

void test_output_guard_blocks_heater_restart_before_minimum_off_time() {
    aqua_atmos::control::OutputGuardState state;
    aqua_atmos::control::apply_output_guard(make_outputs(false, true), state, 1000UL);
    aqua_atmos::control::apply_output_guard(make_outputs(false, false), state, 2000UL);

    const OutputFrame guarded =
        aqua_atmos::control::apply_output_guard(make_outputs(false, true),
                                                state,
                                                2000UL + aqua_atmos::config::HEATER_MIN_OFF_MS - 1UL);

    TEST_ASSERT_FALSE(guarded.heater_relay_on);
}

void test_output_guard_forces_outputs_off_on_hard_block() {
    aqua_atmos::control::OutputGuardState state;
    const OutputFrame guarded =
        aqua_atmos::control::apply_output_guard(make_outputs(true, true), state, 1000UL, true);

    TEST_ASSERT_FALSE(guarded.vcrc_relay_on);
    TEST_ASSERT_FALSE(guarded.heater_relay_on);
    TEST_ASSERT_EQUAL_INT(0, guarded.vcrc_fan_pwm);
    TEST_ASSERT_EQUAL_INT(0, guarded.sorbent_fan_pwm);
}

}  // namespace

void run_output_guard_tests() {
    // apply_output_guard
    RUN_TEST(test_output_guard_allows_initial_activation);
    RUN_TEST(test_output_guard_blocks_vcrc_restart_before_minimum_off_time);
    RUN_TEST(test_output_guard_allows_vcrc_restart_after_minimum_off_time);
    RUN_TEST(test_output_guard_blocks_heater_restart_before_minimum_off_time);
    RUN_TEST(test_output_guard_forces_outputs_off_on_hard_block);
}
