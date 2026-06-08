#pragma once

#include "domain/types.h"
#include "control/generated/model_vcrc_state.h"
#include "control/generated/model_sorbent_mode_label.h"
#include "control/generated/model_heater_on_label.h"

namespace aqua_atmos::control {

inline void run_inference(
    const domain::SensorFrame& sensors,
    const domain::DerivedFrame& derived,
    domain::VcrcDecision& vcrc,
    domain::SorbentDecision& sorbent) {
    
    // Prepare input vector
    // Order must match export_models.py:
    // hour, temp_air_c, hr_pct, solar_wm2, pv_voltage,
    // temp_collector_c, temp_cond_c, delta_hr_sorbent, 
    // reservoir_level_pct, soc_battery_pct, dew_point_c, 
    // humidity_ratio_gkg, hour_sin, hour_cos, day_sin, day_cos, 
    // thermal_lift_c, collector_gain_c, is_daylight, 
    // high_humidity_flag, battery_stress_flag, reservoir_high_flag
    
    double input[22];
    input[0] = sensors.hour_of_day;
    input[1] = sensors.temp_air_c;
    input[2] = sensors.hr_pct;
    input[3] = sensors.solar_wm2;
    input[4] = sensors.pv_voltage;
    input[5] = sensors.temp_collector_c;
    input[6] = sensors.temp_cond_c;
    input[7] = derived.delta_hr_sorbent;
    input[8] = sensors.reservoir_level_pct;
    input[9] = sensors.soc_battery_pct;
    input[10] = derived.dew_point_c;
    input[11] = derived.humidity_ratio_gkg;
    input[12] = derived.hour_sin;
    input[13] = derived.hour_cos;
    input[14] = derived.day_sin;
    input[15] = derived.day_cos;
    input[16] = derived.thermal_lift_c;
    input[17] = derived.collector_gain_c;
    input[18] = derived.is_daylight;
    input[19] = derived.high_humidity_flag;
    input[20] = derived.battery_stress_flag;
    input[21] = derived.reservoir_high_flag;

    // VCRC Inference
    double vcrc_output[2];
    predict_vcrc_state(input, vcrc_output);
    vcrc.state = (vcrc_output[1] > vcrc_output[0]);

    // Sorbent Mode Inference (veille:0, absorption:1, regeneration:2)
    double sorbent_output[3];
    predict_sorbent_mode_label(input, sorbent_output);
    int mode_idx = 0;
    if (sorbent_output[1] > sorbent_output[0]) mode_idx = 1;
    if (sorbent_output[2] > sorbent_output[mode_idx]) mode_idx = 2;
    
    switch (mode_idx) {
        case 1: sorbent.mode = domain::SorbentDecision::Mode::Absorption; break;
        case 2: sorbent.mode = domain::SorbentDecision::Mode::Regeneration; break;
        default: sorbent.mode = domain::SorbentDecision::Mode::Veille; break;
    }

    // Heater Inference
    double heater_output[2];
    predict_heater_on_label(input, heater_output);
    sorbent.heater_on = (heater_output[1] > heater_output[0]);
}

}  // namespace aqua_atmos::control
