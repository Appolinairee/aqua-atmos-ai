#include <unity.h>
#include "control/inference_engine.h"
#include "domain/metrics.h"

using namespace aqua_atmos;

namespace {

domain::SensorFrame make_inference_frame(float hr_pct, float solar_wm2, float soc_pct) {
    domain::SensorFrame s;
    s.hour_of_day = 12;
    s.temp_air_c = 28.0F;
    s.hr_pct = hr_pct;
    s.hr_in_pct = hr_pct;
    s.hr_out_pct = hr_pct - 5.0F;
    s.temp_cond_c = 22.0F;
    s.temp_collector_c = 42.0F;
    s.solar_wm2 = solar_wm2;
    s.pv_voltage = 12.4F;
    s.soc_battery_pct = soc_pct;
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

void test_ia_inference_nominal() {
    const auto s = make_inference_frame(60.0F, 600.0F, 80.0F);
    const auto d = derive_from(s);
    domain::VcrcDecision v;
    domain::SorbentDecision sb;

    control::run_inference(s, d, v, sb);
    
    // On valide juste que l'IA repond (le contenu depend du modele entraine)
    TEST_ASSERT_EQUAL_INT(static_cast<int>(domain::SorbentDecision::Mode::Absorption), static_cast<int>(sb.mode));
}

} // namespace

void run_inference_tests() {
    RUN_TEST(test_ia_inference_nominal);
}
