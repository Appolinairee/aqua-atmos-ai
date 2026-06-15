#include <unity.h>

#include "config/constants.h"
#include "control/rule_engine.h"

namespace {

using aqua_atmos::domain::DerivedFrame;
using aqua_atmos::domain::SensorFrame;
using aqua_atmos::domain::SorbentDecision;
using aqua_atmos::domain::VcrcDecision;

SensorFrame make_safe_sensor_frame() {
    SensorFrame sensors;
    sensors.hr_pct = 60.0F;
    sensors.solar_wm2 = 100.0F;
    sensors.soc_battery_pct = 80.0F;
    sensors.reservoir_level_pct = 50.0F;
    return sensors;
}

DerivedFrame make_vcrc_ready_derived_frame() {
    DerivedFrame derived;
    derived.dew_point_c = aqua_atmos::config::VCRC_MIN_DEW_POINT_C + 1.0F;
    derived.humidity_ratio_gkg = aqua_atmos::config::VCRC_MIN_HUM_RATIO_GKG;
    derived.delta_hr_sorbent = 5.0F;
    return derived;
}

// safety

void test_is_reservoir_full_requires_value_above_threshold() {
    TEST_ASSERT_FALSE(aqua_atmos::control::is_reservoir_full(
        aqua_atmos::config::RESERVOIR_FULL_THRESHOLD));
    TEST_ASSERT_TRUE(aqua_atmos::control::is_reservoir_full(
        aqua_atmos::config::RESERVOIR_FULL_THRESHOLD + 0.1F));
}

void test_is_battery_low_requires_value_below_threshold() {
    TEST_ASSERT_FALSE(aqua_atmos::control::is_battery_low(
        aqua_atmos::config::BATTERY_CRITICAL_SOC));
    TEST_ASSERT_TRUE(aqua_atmos::control::is_battery_low(
        aqua_atmos::config::BATTERY_CRITICAL_SOC - 0.1F));
}

void test_is_hard_block_detects_reservoir_or_battery_block() {
    SensorFrame sensors = make_safe_sensor_frame();
    TEST_ASSERT_FALSE(aqua_atmos::control::is_hard_block(sensors));

    sensors.reservoir_level_pct = aqua_atmos::config::RESERVOIR_FULL_THRESHOLD + 0.1F;
    TEST_ASSERT_TRUE(aqua_atmos::control::is_hard_block(sensors));

    sensors = make_safe_sensor_frame();
    sensors.soc_battery_pct = aqua_atmos::config::BATTERY_CRITICAL_SOC - 0.1F;
    TEST_ASSERT_TRUE(aqua_atmos::control::is_hard_block(sensors));

    sensors = make_safe_sensor_frame();
    sensors.temp_cond_c = aqua_atmos::config::CONDENSER_MAX_TEMP_C + 0.1F;
    TEST_ASSERT_TRUE(aqua_atmos::control::is_hard_block(sensors));
}

// decide_vcrc

void test_decide_vcrc_turns_on_when_all_conditions_are_met() {
    const VcrcDecision decision =
        aqua_atmos::control::decide_vcrc(make_safe_sensor_frame(), make_vcrc_ready_derived_frame(), false, false);

    TEST_ASSERT_TRUE(decision.state);
}

void test_decide_vcrc_stays_off_when_humidity_is_too_low() {
    SensorFrame sensors = make_safe_sensor_frame();
    sensors.hr_pct = aqua_atmos::config::VCRC_MIN_HR_PCT - 0.1F;

    const VcrcDecision decision =
        aqua_atmos::control::decide_vcrc(sensors, make_vcrc_ready_derived_frame(), false, false);

    TEST_ASSERT_FALSE(decision.state);
}

void test_decide_vcrc_stays_off_on_hard_block() {
    SensorFrame sensors = make_safe_sensor_frame();
    sensors.reservoir_level_pct = aqua_atmos::config::RESERVOIR_FULL_THRESHOLD + 0.1F;

    const VcrcDecision decision =
        aqua_atmos::control::decide_vcrc(sensors, make_vcrc_ready_derived_frame(), true, false);

    TEST_ASSERT_FALSE(decision.state);
}

void test_decide_vcrc_stays_on_when_humidity_drops_within_hysteresis() {
    SensorFrame sensors = make_safe_sensor_frame();
    // Humidité à 38% (entre 37% et 40%)
    sensors.hr_pct = aqua_atmos::config::VCRC_MIN_HR_PCT - aqua_atmos::config::VCRC_HYSTERESIS_PCT + 1.0F;

    // Si on était déjà ON, on doit RESTER ON
    const VcrcDecision decision =
        aqua_atmos::control::decide_vcrc(sensors, make_vcrc_ready_derived_frame(), false, true);

    TEST_ASSERT_TRUE(decision.state);
}

void test_decide_vcrc_turns_off_when_humidity_drops_below_hysteresis() {
    SensorFrame sensors = make_safe_sensor_frame();
    // Humidité à 36% (sous le seuil de 37%)
    sensors.hr_pct = aqua_atmos::config::VCRC_MIN_HR_PCT - aqua_atmos::config::VCRC_HYSTERESIS_PCT - 1.0F;

    // Même si on était ON, on doit s'ÉTEINDRE
    const VcrcDecision decision =
        aqua_atmos::control::decide_vcrc(sensors, make_vcrc_ready_derived_frame(), false, true);

    TEST_ASSERT_FALSE(decision.state);
}

// decide_sorbent

void test_decide_sorbent_absorbs_when_humidity_is_available() {
    SensorFrame sensors = make_safe_sensor_frame();
    DerivedFrame derived = make_vcrc_ready_derived_frame();
    derived.delta_hr_sorbent = aqua_atmos::config::SORBENT_SATURATION_DELTA + 1.0F;

    const SorbentDecision decision = aqua_atmos::control::decide_sorbent(sensors, derived);

    TEST_ASSERT_EQUAL_INT(static_cast<int>(SorbentDecision::Mode::Absorption),
                          static_cast<int>(decision.mode));
    TEST_ASSERT_FALSE(decision.heater_on);
}

void test_decide_sorbent_regenerates_with_solar_without_heater() {
    SensorFrame sensors = make_safe_sensor_frame();
    sensors.solar_wm2 = aqua_atmos::config::SOLAR_PRODUCTION_THRESHOLD;
    DerivedFrame derived = make_vcrc_ready_derived_frame();
    derived.delta_hr_sorbent = aqua_atmos::config::SORBENT_SATURATION_DELTA;

    const SorbentDecision decision = aqua_atmos::control::decide_sorbent(sensors, derived);

    TEST_ASSERT_EQUAL_INT(static_cast<int>(SorbentDecision::Mode::Regeneration),
                          static_cast<int>(decision.mode));
    TEST_ASSERT_FALSE(decision.heater_on);
}

void test_decide_sorbent_regenerates_with_battery_heater_when_solar_is_missing() {
    SensorFrame sensors = make_safe_sensor_frame();
    sensors.solar_wm2 = aqua_atmos::config::SOLAR_PRODUCTION_THRESHOLD - 0.1F;
    sensors.soc_battery_pct = aqua_atmos::config::HEATER_MIN_SOC_PCT;
    DerivedFrame derived = make_vcrc_ready_derived_frame();
    derived.delta_hr_sorbent = aqua_atmos::config::SORBENT_SATURATION_DELTA;

    const SorbentDecision decision = aqua_atmos::control::decide_sorbent(sensors, derived);

    TEST_ASSERT_EQUAL_INT(static_cast<int>(SorbentDecision::Mode::Regeneration),
                          static_cast<int>(decision.mode));
    TEST_ASSERT_TRUE(decision.heater_on);
}

void test_decide_sorbent_stays_idle_on_hard_block() {
    SensorFrame sensors = make_safe_sensor_frame();
    sensors.soc_battery_pct = aqua_atmos::config::BATTERY_CRITICAL_SOC - 0.1F;

    const SorbentDecision decision =
        aqua_atmos::control::decide_sorbent(sensors, make_vcrc_ready_derived_frame());

    TEST_ASSERT_EQUAL_INT(static_cast<int>(SorbentDecision::Mode::Veille),
                          static_cast<int>(decision.mode));
    TEST_ASSERT_FALSE(decision.heater_on);
}

// fuse_decisions

void test_fuse_decisions_keeps_outputs_off_on_hard_block() {
    VcrcDecision rule_vcrc;
    rule_vcrc.state = true;
    VcrcDecision inference_vcrc;
    inference_vcrc.state = true;
    SorbentDecision rule_sorbent;
    rule_sorbent.mode = SorbentDecision::Mode::Regeneration;
    rule_sorbent.heater_on = true;
    SorbentDecision inference_sorbent = rule_sorbent;

    VcrcDecision fused_vcrc;
    SorbentDecision fused_sorbent;
    aqua_atmos::control::fuse_decisions(rule_vcrc,
                                        rule_sorbent,
                                        inference_vcrc,
                                        inference_sorbent,
                                        true,
                                        fused_vcrc,
                                        fused_sorbent);

    TEST_ASSERT_FALSE(fused_vcrc.state);
    TEST_ASSERT_EQUAL_INT(static_cast<int>(SorbentDecision::Mode::Veille),
                          static_cast<int>(fused_sorbent.mode));
    TEST_ASSERT_FALSE(fused_sorbent.heater_on);
}

void test_fuse_decisions_requires_rule_approval_for_vcrc() {
    VcrcDecision rule_vcrc;
    rule_vcrc.state = false;
    VcrcDecision inference_vcrc;
    inference_vcrc.state = true;
    SorbentDecision rule_sorbent;
    SorbentDecision inference_sorbent;

    VcrcDecision fused_vcrc;
    SorbentDecision fused_sorbent;
    aqua_atmos::control::fuse_decisions(rule_vcrc,
                                        rule_sorbent,
                                        inference_vcrc,
                                        inference_sorbent,
                                        false,
                                        fused_vcrc,
                                        fused_sorbent);

    TEST_ASSERT_FALSE(fused_vcrc.state);
}

void test_fuse_decisions_accepts_vcrc_when_rule_and_inference_agree() {
    VcrcDecision rule_vcrc;
    rule_vcrc.state = true;
    VcrcDecision inference_vcrc;
    inference_vcrc.state = true;
    SorbentDecision rule_sorbent;
    SorbentDecision inference_sorbent;

    VcrcDecision fused_vcrc;
    SorbentDecision fused_sorbent;
    aqua_atmos::control::fuse_decisions(rule_vcrc,
                                        rule_sorbent,
                                        inference_vcrc,
                                        inference_sorbent,
                                        false,
                                        fused_vcrc,
                                        fused_sorbent);

    TEST_ASSERT_TRUE(fused_vcrc.state);
}

void test_fuse_decisions_keeps_rule_sorbent_mode_as_safety_envelope() {
    VcrcDecision rule_vcrc;
    VcrcDecision inference_vcrc;
    SorbentDecision rule_sorbent;
    rule_sorbent.mode = SorbentDecision::Mode::Absorption;
    SorbentDecision inference_sorbent;
    inference_sorbent.mode = SorbentDecision::Mode::Regeneration;
    inference_sorbent.heater_on = true;

    VcrcDecision fused_vcrc;
    SorbentDecision fused_sorbent;
    aqua_atmos::control::fuse_decisions(rule_vcrc,
                                        rule_sorbent,
                                        inference_vcrc,
                                        inference_sorbent,
                                        false,
                                        fused_vcrc,
                                        fused_sorbent);

    TEST_ASSERT_EQUAL_INT(static_cast<int>(SorbentDecision::Mode::Absorption),
                          static_cast<int>(fused_sorbent.mode));
    TEST_ASSERT_FALSE(fused_sorbent.heater_on);
}

void test_fuse_decisions_allows_heater_only_when_rule_and_inference_agree() {
    VcrcDecision rule_vcrc;
    VcrcDecision inference_vcrc;
    SorbentDecision rule_sorbent;
    rule_sorbent.mode = SorbentDecision::Mode::Regeneration;
    rule_sorbent.heater_on = true;
    SorbentDecision inference_sorbent;
    inference_sorbent.mode = SorbentDecision::Mode::Regeneration;
    inference_sorbent.heater_on = true;

    VcrcDecision fused_vcrc;
    SorbentDecision fused_sorbent;
    aqua_atmos::control::fuse_decisions(rule_vcrc,
                                        rule_sorbent,
                                        inference_vcrc,
                                        inference_sorbent,
                                        false,
                                        fused_vcrc,
                                        fused_sorbent);

    TEST_ASSERT_EQUAL_INT(static_cast<int>(SorbentDecision::Mode::Regeneration),
                          static_cast<int>(fused_sorbent.mode));
    TEST_ASSERT_TRUE(fused_sorbent.heater_on);
}

// build_outputs

void test_build_outputs_maps_vcrc_on_to_relay_and_fan() {
    VcrcDecision vcrc;
    vcrc.state = true;
    SorbentDecision sorbent;

    const aqua_atmos::domain::OutputFrame output =
        aqua_atmos::control::build_outputs(vcrc, sorbent);

    TEST_ASSERT_TRUE(output.vcrc_relay_on);
    TEST_ASSERT_EQUAL_INT(200, output.vcrc_fan_pwm);
}

void test_build_outputs_maps_absorption_mode() {
    VcrcDecision vcrc;
    SorbentDecision sorbent;
    sorbent.mode = SorbentDecision::Mode::Absorption;

    const aqua_atmos::domain::OutputFrame output =
        aqua_atmos::control::build_outputs(vcrc, sorbent);

    TEST_ASSERT_EQUAL_INT(160, output.sorbent_fan_pwm);
    TEST_ASSERT_EQUAL_INT(90, output.servo_angle_deg);
}

void test_build_outputs_maps_regeneration_mode_and_heater() {
    VcrcDecision vcrc;
    SorbentDecision sorbent;
    sorbent.mode = SorbentDecision::Mode::Regeneration;
    sorbent.heater_on = true;

    const aqua_atmos::domain::OutputFrame output =
        aqua_atmos::control::build_outputs(vcrc, sorbent);

    TEST_ASSERT_TRUE(output.heater_relay_on);
    TEST_ASSERT_EQUAL_INT(220, output.sorbent_fan_pwm);
    TEST_ASSERT_EQUAL_INT(140, output.servo_angle_deg);
}

void test_build_outputs_maps_idle_mode_to_zeroed_actuators() {
    VcrcDecision vcrc;
    SorbentDecision sorbent;

    const aqua_atmos::domain::OutputFrame output =
        aqua_atmos::control::build_outputs(vcrc, sorbent);

    TEST_ASSERT_FALSE(output.vcrc_relay_on);
    TEST_ASSERT_FALSE(output.heater_relay_on);
    TEST_ASSERT_EQUAL_INT(0, output.vcrc_fan_pwm);
    TEST_ASSERT_EQUAL_INT(0, output.sorbent_fan_pwm);
    TEST_ASSERT_EQUAL_INT(0, output.servo_angle_deg);
}

}  // namespace

void run_control_tests() {
    // safety
    RUN_TEST(test_is_reservoir_full_requires_value_above_threshold);
    RUN_TEST(test_is_battery_low_requires_value_below_threshold);
    RUN_TEST(test_is_hard_block_detects_reservoir_or_battery_block);

    // decide_vcrc
    RUN_TEST(test_decide_vcrc_turns_on_when_all_conditions_are_met);
    RUN_TEST(test_decide_vcrc_stays_off_when_humidity_is_too_low);
    RUN_TEST(test_decide_vcrc_stays_off_on_hard_block);
    RUN_TEST(test_decide_vcrc_stays_on_when_humidity_drops_within_hysteresis);
    RUN_TEST(test_decide_vcrc_turns_off_when_humidity_drops_below_hysteresis);

    // decide_sorbent
    RUN_TEST(test_decide_sorbent_absorbs_when_humidity_is_available);
    RUN_TEST(test_decide_sorbent_regenerates_with_solar_without_heater);
    RUN_TEST(test_decide_sorbent_regenerates_with_battery_heater_when_solar_is_missing);
    RUN_TEST(test_decide_sorbent_stays_idle_on_hard_block);

    // fuse_decisions
    RUN_TEST(test_fuse_decisions_keeps_outputs_off_on_hard_block);
    RUN_TEST(test_fuse_decisions_requires_rule_approval_for_vcrc);
    RUN_TEST(test_fuse_decisions_accepts_vcrc_when_rule_and_inference_agree);
    RUN_TEST(test_fuse_decisions_keeps_rule_sorbent_mode_as_safety_envelope);
    RUN_TEST(test_fuse_decisions_allows_heater_only_when_rule_and_inference_agree);

    // build_outputs
    RUN_TEST(test_build_outputs_maps_vcrc_on_to_relay_and_fan);
    RUN_TEST(test_build_outputs_maps_absorption_mode);
    RUN_TEST(test_build_outputs_maps_regeneration_mode_and_heater);
    RUN_TEST(test_build_outputs_maps_idle_mode_to_zeroed_actuators);
}
