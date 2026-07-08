import os
import glob

workspace_dir = "/home/user/projects/aqua-atmos-ai/firmware/esp32"
files = glob.glob(os.path.join(workspace_dir, "**", "*.[hc]pp"), recursive=True) + glob.glob(os.path.join(workspace_dir, "**", "*.h"), recursive=True)

for file in files:
    with open(file, "r") as f:
        content = f.read()
    
    new_content = content.replace("hr_pct", "rh_pct")
    new_content = new_content.replace("hr_in_pct", "rh_in_pct")
    new_content = new_content.replace("hr_out_pct", "rh_out_pct")
    new_content = new_content.replace("delta_hr_sorbent", "delta_rh_sorbent")
    new_content = new_content.replace("VCRC_MIN_HR_PCT", "VCRC_MIN_RH_PCT")
    new_content = new_content.replace("SORBENT_MIN_HR_PCT", "SORBENT_MIN_RH_PCT")
    
    if new_content != content:
        with open(file, "w") as f:
            f.write(new_content)
        print(f"Updated {file}")
