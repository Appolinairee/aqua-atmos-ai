#include <unity.h>

#include "control/inference_engine.h"
#include "domain/metrics.h"

namespace {

using aqua_atmos::domain::DerivedFrame;
using aqua_atmos::domain::SensorFrame;
using aqua_atmos::domain::SorbentDecision;
using aqua_atmos::domain::VcrcDecision;

SensorFrame make_inference_frame(float hr_pct, float solar_wm2, float soc_pct,
                                 float reservoir_pct, float delta_hr_pct) {
    SensorFrame sensors;
    sensors.hour_of_day = 12;
    sensors.temp_air_c = 28.0F;
    sensors.hr_pct = hr_pct;
    sensors.hr_in_pct = hr_pct;
    sensors.hr_out_pct = hr_pct - delta_hr_pct;
    sensors.temp_cond_c = 22.0F;
    sensors.temp_collector_c = 42.0F;
    sensors.solar_wm2 = solar_wm2;
    sensors.pv_voltage = 12.4F;
    sensors.soc_battery_pct = soc_pct;
    sensors.reservoir_level_pct = reservoir_pct;
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

// run_inference

void test_run_inference_maps_nominal_frame_to_absorption_without_heater() {
    const SensorFrame sensors = make_inference_frame(60.0F, 600.0F, 80.0F, 30.0F, 5.0F);
    const DerivedFrame derived = derive_from(sensors);
    VcrcDecision vcrc;
    SorbentDecision sorbent;

    aqua_atmos::control::run_inference(sensors, derived, vcrc, sorbent);

    TEST_ASSERT_FALSE(vcrc.state);
    TEST_ASSERT_EQUAL_INT(static_cast<int>(SorbentDecision::Mode::Absorption),
                          static_cast<int>(sorbent.mode));
    TEST_ASSERT_FALSE(sorbent.heater_on);
}

void test_run_inference_maps_blocked_like_frame_to_idle_without_heater() {
    const SensorFrame sensors = make_inference_frame(60.0F, 700.0F, 10.0F, 99.0F, 0.5F);
    const DerivedFrame derived = derive_from(sensors);
    VcrcDecision vcrc;
    SorbentDecision sorbent;

    aqua_atmos::control::run_inference(sensors, derived, vcrc, sorbent);

    TEST_ASSERT_FALSE(vcrc.state);
    TEST_ASSERT_EQUAL_INT(static_cast<int>(SorbentDecision::Mode::Veille),
                          static_cast<int>(sorbent.mode));
    TEST_ASSERT_FALSE(sorbent.heater_on);
}

}  // namespace

void run_inference_tests() {
    // run_inference
    RUN_TEST(test_run_inference_maps_nominal_frame_to_absorption_without_heater);
    RUN_TEST(test_run_inference_maps_blocked_like_frame_to_idle_without_heater);
}
