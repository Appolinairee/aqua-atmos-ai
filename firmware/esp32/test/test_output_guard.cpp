#include <unity.h>
#include "control/output_guard.h"
#include "config/timing.h"

using namespace aqua_atmos;

namespace {

domain::OutputFrame make_vcrc_req(bool state) {
    domain::OutputFrame o;
    o.vcrc_relay_on = state;
    o.fans_relay_on = state; // Allume aussi les ventilos dans le test pour simuler l'absorption
    return o;
}

/**
 * NIVEAU 6 : PROTECTIONS TEMPORELLES
 */

void test_minimum_run_time_vcrc() {
    control::OutputGuardState state;
    unsigned long now = 1000;

    // Allumage
    domain::OutputFrame guarded = control::apply_output_guard(make_vcrc_req(true), state, now, false);
    TEST_ASSERT_TRUE(guarded.vcrc_relay_on);

    // Tentative arrêt prématuré (après 10 sec)
    now += 10000;
    guarded = control::apply_output_guard(make_vcrc_req(false), state, now, false);
    
    // DOIT RESTER ON (MRT 20 min)
    TEST_ASSERT_TRUE_MESSAGE(guarded.vcrc_relay_on, "Le VCRC doit rester ON pendant le MRT");
}

void test_minimum_off_time_vcrc() {
    control::OutputGuardState state;
    unsigned long now = 1000;

    // Allumage puis arrêt légitime après MRT
    control::apply_output_guard(make_vcrc_req(true), state, now, false);
    now += config::VCRC_MIN_RUN_MS + 1000;
    control::apply_output_guard(make_vcrc_req(false), state, now, false);
    
    // Tentative rallumage immédiat (après 10 sec)
    now += 10000;
    domain::OutputFrame guarded = control::apply_output_guard(make_vcrc_req(true), state, now, false);
    
    // DOIT RESTER OFF (MOT 5 min)
    TEST_ASSERT_FALSE_MESSAGE(guarded.vcrc_relay_on, "Le VCRC ne doit pas redemarrer avant le MOT");
}

void test_hard_block_overrides_temporal_guards() {
    control::OutputGuardState state;
    unsigned long now = 1000;

    // Allumage
    control::apply_output_guard(make_vcrc_req(true), state, now, false);
    
    // Alarme batterie après 1 min
    now += 60000;
    domain::OutputFrame guarded = control::apply_output_guard(make_vcrc_req(true), state, now, true); // hard_block = true
    
    // DOIT COUPER TOUT DE SUITE
    TEST_ASSERT_FALSE(guarded.vcrc_relay_on);
}

} // namespace

void run_output_guard_tests() {
    RUN_TEST(test_minimum_run_time_vcrc);
    RUN_TEST(test_minimum_off_time_vcrc);
    RUN_TEST(test_hard_block_overrides_temporal_guards);
}
