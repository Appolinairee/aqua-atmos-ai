#include <unity.h>
#include "control/inference_engine.h"
#include "control/rule_engine.h"
#include "domain/metrics.h"

using namespace aqua_atmos;

namespace {

domain::SensorFrame make_nominal_sensors() {
    domain::SensorFrame s;
    s.hour_of_day = 12;
    s.temp_air_c = 28.0F;
    s.hr_pct = 60.0F;
    s.hr_in_pct = 60.0F;
    s.hr_out_pct = 55.0F;
    s.temp_cond_c = 22.0F;
    s.temp_collector_c = 42.0F;
    s.solar_wm2 = 600.0F;
    s.pv_voltage = 12.4F;
    s.soc_battery_pct = 80.0F;
    s.reservoir_level_pct = 30.0F;
    return s;
}

domain::DerivedFrame derive_from(const domain::SensorFrame& s) {
    domain::DerivedFrame d;
    d.dew_point_c = domain::compute_dew_point_c(s.temp_air_c, s.hr_pct);
    d.humidity_ratio_gkg = domain::compute_humidity_ratio_gkg(s.temp_air_c, s.hr_pct);
    d.delta_hr_sorbent = domain::compute_delta_hr_sorbent(s.hr_in_pct, s.hr_out_pct);
    domain::enrich_derived_frame(s, d);
    return d;
}

void test_full_pipeline_fusion() {
    const auto s = make_nominal_sensors();
    const auto d = derive_from(s);
    const bool hard_block = control::is_hard_block(s);

    domain::VcrcDecision rv, mv, fv;
    domain::SorbentDecision rs, ms, fs;

    rv = control::decide_vcrc(s, d, hard_block, false);
    rs = control::decide_sorbent(s, d, hard_block);
    control::run_inference(s, d, mv, ms);

    control::fuse_decisions(rv, rs, mv, ms, hard_block, fv, fs);
    domain::OutputFrame out = control::build_outputs(fv, fs);

    // Si les deux sont d'accord (selon le modele actuel)
    if (rv.state && mv.state) {
        TEST_ASSERT_TRUE(out.vcrc_relay_on);
    } else {
        TEST_ASSERT_FALSE(out.vcrc_relay_on);
    }
}

} // namespace

void run_decision_pipeline_tests() {
    RUN_TEST(test_full_pipeline_fusion);
}
