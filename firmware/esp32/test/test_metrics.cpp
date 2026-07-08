#include <unity.h>
#include <cmath>
#include "domain/metrics.h"
#include "config/constants.h"

using namespace aqua_atmos;

namespace {

/**
 * NIVEAU 2 : CALCULS PHYSIQUES
 */

void test_dew_point_accuracy() {
    // Cas nominal : 25°C, 60% HR -> ~16.7°C
    TEST_ASSERT_FLOAT_WITHIN(0.1F, 16.71F, domain::compute_dew_point_c(25.0F, 60.0F));
    // Cas froid : 10°C, 50% HR -> ~0.1°C
    TEST_ASSERT_FLOAT_WITHIN(0.2F, 0.1F, domain::compute_dew_point_c(10.0F, 50.0F));
}

void test_dew_point_safe_floor() {
    // Humidité nulle doit retourner exactement le plancher de -50.0
    TEST_ASSERT_EQUAL_FLOAT(-50.0F, domain::compute_dew_point_c(25.0F, 0.0F));
}

void test_delta_hr_sorbent_calculation() {
    // HR Ambiant = 60%, HR Sortie = 55% -> Delta = 5%
    TEST_ASSERT_EQUAL_FLOAT(5.0F, domain::compute_delta_hr_sorbent(60.0F, 55.0F));
}

void test_humidity_ratio_conversion() {
    // 25°C, 60% HR -> ~12.0 g/kg d'air sec
    TEST_ASSERT_FLOAT_WITHIN(0.5F, 11.95F, domain::compute_humidity_ratio_gkg(25.0F, 60.0F));
}

void test_temporal_cycles_sin_cos() {
    domain::SensorFrame s;
    domain::DerivedFrame d;

    // MIDI (12h) : sin(pi)=0, cos(pi)=-1
    s.hour_of_day = 12;
    domain::enrich_derived_frame(s, d);
    TEST_ASSERT_FLOAT_WITHIN(0.01F, 0.0F, d.hour_sin);
    TEST_ASSERT_FLOAT_WITHIN(0.01F, -1.0F, d.hour_cos);

    // MINUIT (0h) : sin(0)=0, cos(0)=1
    s.hour_of_day = 0;
    domain::enrich_derived_frame(s, d);
    TEST_ASSERT_FLOAT_WITHIN(0.01F, 0.0F, d.hour_sin);
    TEST_ASSERT_FLOAT_WITHIN(0.01F, 1.0F, d.hour_cos);
}

void test_enrichment_logic_flags() {
    domain::SensorFrame s;
    domain::DerivedFrame d;

    // Flag Daylight
    s.solar_wm2 = 100.0F; // > 50
    domain::enrich_derived_frame(s, d);
    TEST_ASSERT_EQUAL_INT(1, d.is_daylight);

    s.solar_wm2 = 20.0F; // < 50
    domain::enrich_derived_frame(s, d);
    TEST_ASSERT_EQUAL_INT(0, d.is_daylight);

    // Flag Batterie Stress (Critique + 5%)
    s.soc_battery_pct = 22.0F; // < 25
    domain::enrich_derived_frame(s, d);
    TEST_ASSERT_EQUAL_INT(1, d.battery_stress_flag);
}

} // namespace

void run_metrics_tests() {
    RUN_TEST(test_dew_point_accuracy);
    RUN_TEST(test_dew_point_safe_floor);
    RUN_TEST(test_delta_hr_sorbent_calculation);
    RUN_TEST(test_humidity_ratio_conversion);
    RUN_TEST(test_temporal_cycles_sin_cos);
    RUN_TEST(test_enrichment_logic_flags);
}
