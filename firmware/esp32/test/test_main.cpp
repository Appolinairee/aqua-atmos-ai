#include <unity.h>

void run_control_tests();
void run_decision_pipeline_tests();
void run_inference_tests();
void run_metrics_tests();
void run_output_guard_tests();
void run_sensor_math_tests();

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    UNITY_BEGIN();
    run_metrics_tests();
    run_control_tests();
    run_inference_tests();
    run_decision_pipeline_tests();
    run_output_guard_tests();
    run_sensor_math_tests();
    return UNITY_END();
}
