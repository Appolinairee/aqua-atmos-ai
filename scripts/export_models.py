import pandas as pd
import numpy as np
from sklearn.ensemble import RandomForestClassifier
import m2cgen as m2c
from pathlib import Path

# Load data
DATA_DIR = Path("data/processed")
train_df = pd.read_csv(DATA_DIR / "train_split.csv")

feature_columns = [
    "hour", "temp_air_c", "hr_pct", "solar_wm2", "pv_voltage",
    "temp_collector_c", "temp_cond_c", "delta_hr_sorbent", 
    "reservoir_level_pct", "soc_battery_pct", "dew_point_c", 
    "humidity_ratio_gkg", "hour_sin", "hour_cos", "day_sin", "day_cos", 
    "thermal_lift_c", "collector_gain_c", "is_daylight", 
    "high_humidity_flag", "battery_stress_flag", "reservoir_high_flag"
]

X_train = train_df[feature_columns]

targets = ["vcrc_state", "sorbent_mode_label", "heater_on_label", "sorbent_saturated_label"]

output_dir = Path("firmware/esp32/include/control/generated")
output_dir.mkdir(parents=True, exist_ok=True)

for target in targets:
    print(f"Training model for {target}...")
    if target == "Y1_production":
        # Check if column exists, it might be in AquaAtmos notebook but not train_split.csv
        if target not in train_df.columns:
             # Try to find target name in AquaAtmos notebook
             # ... simplified for now: if not in train_df, skip
             print(f"Column {target} not found in training data. Skipping.")
             continue
        from sklearn.ensemble import RandomForestRegressor
        model = RandomForestRegressor(n_estimators=10, max_depth=5, random_state=42)
    else:
        y_train = train_df[target]
        model = RandomForestClassifier(
            n_estimators=20, 
            max_depth=6, 
            random_state=42,
            n_jobs=-1
        )

    y_train = train_df[target]
    model.fit(X_train, y_train)

    print(f"Exporting model for {target} to C...")
    code = m2c.export_to_c(model, function_name=f"predict_{target}")
    ...
    header_path = output_dir / f"model_{target}.h"
    with open(header_path, "w") as f:
        f.write('#pragma once\n\n#include "control/generated/model_utils.h"\n\n')
        # Fix C++ compatibility and remove duplicate helpers
        import re
        
        # Remove add_vectors and mul_vector_number definitions
        fixed_code = re.sub(r"void add_vectors\(.*?\)\s*\{.*?\}", "", code, flags=re.DOTALL)
        fixed_code = re.sub(r"void mul_vector_number\(.*?\)\s*\{.*?\}", "", fixed_code, flags=re.DOTALL)
        
        # Pattern: memcpy(varX, (double[]){...}, N * sizeof(double))
        # We replace it with: { double _tmp[] = {val1, val2, ...}; memcpy(varX, _tmp, N * sizeof(double)); }
        fixed_code = fixed_code.replace("double * input", "const double * input")
        
        def make_cpp_compatible(match):
            var_name = match.group(1)
            values = match.group(2)
            size_expr = match.group(3)
            return f"{{ double _tmp[] = {{{values}}}; memcpy({var_name}, _tmp, {size_expr}); }}"

        fixed_code = re.sub(
            r"memcpy\((var\d+), \(double\[\]\)\{(.*?)\}, (.*?)\);",
            make_cpp_compatible,
            fixed_code
        )
        
        f.write(fixed_code)
    print(f"Saved to {header_path}")

print("Done.")
