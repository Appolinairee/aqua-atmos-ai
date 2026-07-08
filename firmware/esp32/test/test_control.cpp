#include <unity.h>
#include "config/constants.h"
#include "control/rule_engine.h"
#include "control/safety.h"

using namespace aqua_atmos;

namespace {

domain::SensorFrame make_safe_frame() {
    domain::SensorFrame s;
    s.hr_pct = 60.0F;
    s.soc_battery_pct = 80.0F;
    s.reservoir_level_pct = 10.0F;
    s.float_switch_active = false;
    s.temp_cond_c = 30.0F;
    return s;
}

domain::DerivedFrame make_vcrc_ok_derived() {
    domain::DerivedFrame d;
    d.dew_point_c = 15.0F;
    d.humidity_ratio_gkg = 10.0F;
    return d;
}

/**
 * NIVEAU 3 : SECURITES VITALES
 */
void test_safety_hard_blocks() {
    domain::SensorFrame s = make_safe_frame();
    TEST_ASSERT_FALSE(control::is_hard_block(s));

    s.soc_battery_pct = 15.0F; // Batterie basse
    TEST_ASSERT_TRUE(control::is_hard_block(s));

    s = make_safe_frame();
    s.float_switch_active = true; // Flotteur physique
    TEST_ASSERT_TRUE(control::is_hard_block(s));

    s = make_safe_frame();
    s.temp_cond_c = 65.0F; // Surchauffe
    TEST_ASSERT_TRUE(control::is_hard_block(s));
}

/**
 * NIVEAU 4 : LOGIQUES METIER (RULES)
 */
void test_vcrc_rule_logic_with_hysteresis() {
    domain::SensorFrame s = make_safe_frame();
    domain::DerivedFrame d = make_vcrc_ok_derived();

    // Allumage nominal (40.5% HR)
    s.hr_pct = 40.5F;
    domain::VcrcDecision dec = control::decide_vcrc(s, d, false, false);
    TEST_ASSERT_TRUE(dec.state);

    // Maintien Hysteresis (38% HR, deja ON)
    s.hr_pct = 38.0F;
    dec = control::decide_vcrc(s, d, false, true);
    TEST_ASSERT_TRUE(dec.state);

    // Extinction (35% HR)
    s.hr_pct = 35.0F;
    dec = control::decide_vcrc(s, d, false, true);
    TEST_ASSERT_FALSE(dec.state);
}

/**
 * NIVEAU 5 : FUSION HYBRIDE (IA VS REGLES)
 */
void test_hybrid_fusion_logic() {
    domain::VcrcDecision rule, ml, fused;
    domain::SorbentDecision rule_s, ml_s, fused_s;

    // VETO DES REGLES : IA veut ON, Regles disent OFF
    rule.state = false; ml.state = true;
    control::fuse_decisions(rule, rule_s, ml, ml_s, false, fused, fused_s);
    TEST_ASSERT_FALSE(fused.state);

    // INHIBITION IA : Regles disent ON, IA juge inefficace
    rule.state = true; ml.state = false;
    control::fuse_decisions(rule, rule_s, ml, ml_s, false, fused, fused_s);
    TEST_ASSERT_FALSE(fused.state);

    // ACCORD TOTAL
    rule.state = true; ml.state = true;
    control::fuse_decisions(rule, rule_s, ml, ml_s, false, fused, fused_s);
    TEST_ASSERT_TRUE(fused.state);
}

} // namespace

void run_control_tests() {
    RUN_TEST(test_safety_hard_blocks);
    RUN_TEST(test_vcrc_rule_logic_with_hysteresis);
    RUN_TEST(test_hybrid_fusion_logic);
}
