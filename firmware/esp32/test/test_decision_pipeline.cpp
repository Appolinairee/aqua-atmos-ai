#include <unity.h>

#include "control/inference_engine.h"
#include "control/rule_engine.h"
#include "domain/metrics.h"

namespace {

using aqua_atmos::domain::DerivedFrame;
using aqua_atmos::domain::OutputFrame;
using aqua_atmos::domain::SensorFrame;
using aqua_atmos::domain::SorbentDecision;
using aqua_atmos::domain::VcrcDecision;

SensorFrame make_pipeline_frame() {
    SensorFrame sensors;
    sensors.hour_of_day = 12;
    sensors.temp_air_c = 28.0F;
    sensors.hr_pct = 60.0F;
    sensors.hr_in_pct = 60.0F;
    sensors.hr_out_pct = 55.0F;
    sensors.temp_cond_c = 22.0F;
    sensors.temp_collector_c = 42.0F;
    sensors.solar_wm2 = 600.0F;
    sensors.pv_voltage = 12.4F;
    sensors.soc_battery_pct = 80.0F;
    sensors.reservoir_level_pct = 30.0F;
    return sensors;
}

DerivedFrame derive_from(const SensorFrame& sensors) {
    DerivedFrame derived;
    derived.dew_point_c = aqua_atmos::domain::compute_dew_point_c(sensors.temp_air_c, sensors.hr_pct);
    derived.humidity_ratio_gkg =
        aqua_atmos::domain::compute_humidity_ratio_gkg(sensors.temp_air_c, sensors.hr_pct);
    derived.delta_hr_sorbent =
        aqua_atmos::domain::compute_delta_hr_sorbent(sensors.hr_in_pct, sensors.hr_out_pct);
    aqua_atmos::domain::enrich_derived_frame(sensors, derived);
    return derived;
}

// hybrid decision pipeline

void test_pipeline_uses_inference_to_gate_vcrc_and_preserves_safe_sorbent_output() {
    const SensorFrame sensors = make_pipeline_frame();
    const DerivedFrame derived = derive_from(sensors);
    const bool hard_block = aqua_atmos::control::is_hard_block(sensors);

    const VcrcDecision rule_vcrc = aqua_atmos::control::decide_vcrc(sensors, derived);
    const SorbentDecision rule_sorbent = aqua_atmos::control::decide_sorbent(sensors, derived);
    VcrcDecision inference_vcrc;
    SorbentDecision inference_sorbent;
    aqua_atmos::control::run_inference(sensors, derived, inference_vcrc, inference_sorbent);

    VcrcDecision fused_vcrc;
    SorbentDecision fused_sorbent;
    aqua_atmos::control::fuse_decisions(rule_vcrc,
                                        rule_sorbent,
                                        inference_vcrc,
                                        inference_sorbent,
                                        hard_block,
                                        fused_vcrc,
                                        fused_sorbent);
    const OutputFrame outputs = aqua_atmos::control::build_outputs(fused_vcrc, fused_sorbent);

    TEST_ASSERT_TRUE(rule_vcrc.state);
    TEST_ASSERT_FALSE(inference_vcrc.state);
    TEST_ASSERT_FALSE(outputs.vcrc_relay_on);
    TEST_ASSERT_EQUAL_INT(0, outputs.vcrc_fan_pwm);
    TEST_ASSERT_EQUAL_INT(160, outputs.sorbent_fan_pwm);
    TEST_ASSERT_EQUAL_INT(90, outputs.servo_angle_deg);
}

void test_pipeline_forces_all_outputs_off_on_hard_block() {
    SensorFrame sensors = make_pipeline_frame();
    sensors.reservoir_level_pct = aqua_atmos::config::RESERVOIR_FULL_THRESHOLD + 0.1F;
    const DerivedFrame derived = derive_from(sensors);
    const bool hard_block = aqua_atmos::control::is_hard_block(sensors);

    const VcrcDecision rule_vcrc = aqua_atmos::control::decide_vcrc(sensors, derived);
    const SorbentDecision rule_sorbent = aqua_atmos::control::decide_sorbent(sensors, derived);
    VcrcDecision inference_vcrc;
    SorbentDecision inference_sorbent;
    aqua_atmos::control::run_inference(sensors, derived, inference_vcrc, inference_sorbent);

    VcrcDecision fused_vcrc;
    SorbentDecision fused_sorbent;
    aqua_atmos::control::fuse_decisions(rule_vcrc,
                                        rule_sorbent,
                                        inference_vcrc,
                                        inference_sorbent,
                                        hard_block,
                                        fused_vcrc,
                                        fused_sorbent);
    const OutputFrame outputs = aqua_atmos::control::build_outputs(fused_vcrc, fused_sorbent);

    TEST_ASSERT_TRUE(hard_block);
    TEST_ASSERT_FALSE(outputs.vcrc_relay_on);
    TEST_ASSERT_FALSE(outputs.heater_relay_on);
    TEST_ASSERT_EQUAL_INT(0, outputs.vcrc_fan_pwm);
    TEST_ASSERT_EQUAL_INT(0, outputs.sorbent_fan_pwm);
    TEST_ASSERT_EQUAL_INT(0, outputs.servo_angle_deg);
}

}  // namespace

void run_decision_pipeline_tests() {
    // hybrid decision pipeline
    RUN_TEST(test_pipeline_uses_inference_to_gate_vcrc_and_preserves_safe_sorbent_output);
    RUN_TEST(test_pipeline_forces_all_outputs_off_on_hard_block);
}
