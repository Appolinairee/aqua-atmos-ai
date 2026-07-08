from flask import Flask, jsonify, request
import random
import math

app = Flask(__name__)

state = {
    "temp": 25.0,
    "hum": 60.0,
    "bat": 80.0,
    "flow": 0.0,
    "dew": 16.5,
    "vcrc": False,
    "sorb": "VEILLE",
    "hour": 12,
    "sim": False,
    "res": 30.0,
    "delta_hr": 5.0,
    "sol": 0.0,
    "cond": 25.0,
    "heater": False,
    "heater_override": False,
    "sorb_override": False,
    "vcrc_override": False
}

@app.route("/api/data")
def data():
    if not state["sim"]:
        # Simuler des variations
        state["temp"] = round(state["temp"] + random.uniform(-0.1, 0.1), 1)
        state["hum"] = min(100.0, max(20.0, round(state["hum"] + random.uniform(-0.3, 0.3), 1)))
        state["bat"] = min(100.0, max(5.0, round(state["bat"] + (0.05 if not state["vcrc"] else -0.1), 1)))
    
    # Calcul du point de rosée (Magnus)
    t, rh = state["temp"], state["hum"]
    gamma = math.log(max(0.001, rh / 100.0)) + (17.625 * t) / (243.04 + t)
    state["dew"] = round((243.04 * gamma) / (17.625 - gamma), 1)
    saturation_pressure = 6.112 * math.exp((17.67 * t) / (t + 243.5))
    vapor_pressure = (rh / 100.0) * saturation_pressure
    humidity_ratio = 621.98 * vapor_pressure / (1013.25 - vapor_pressure)
    
    # Simuler les règles simplifiées
    hard_block = state["bat"] < 20.0 or state["res"] >= 95.0
    vcrc_thermal_block = state["cond"] > 60.0
    if not state["vcrc_override"]:
        state["vcrc"] = (
            not hard_block
            and not vcrc_thermal_block
            and state["hum"] >= 40.0
            and state["dew"] > 2.0
            and humidity_ratio >= 6.0
        )
    if hard_block:
        state["sorb"] = "VEILLE"
        state["sorb_override"] = False
        if not state["heater_override"]:
            state["heater"] = False
    elif state["sorb_override"]:
        pass
    elif state["delta_hr"] <= 1.0 and state["sol"] >= 300.0:
        state["sorb"] = "REGEN"
        if not state["heater_override"]:
            state["heater"] = True
    else:
        state["sorb"] = "ABSORPTION" if state["hum"] >= 40.0 else "VEILLE"
        if not state["heater_override"]:
            state["heater"] = False
    state["flow"] = 0.0
    
    return jsonify(state)

@app.route("/api/command", methods=["POST"])
def command():
    cmd = request.args.get("cmd")
    val = request.args.get("value")
    if cmd == "vcrc_override" or cmd == "vcrc":
        state["vcrc"] = (val == "true" or val == "1")
        state["vcrc_override"] = True
    elif cmd == "sorb_mode":
        state["sorb"] = val
        state["sorb_override"] = True
        state["heater"] = val == "REGEN"
        state["heater_override"] = False
    elif cmd == "heater":
        state["heater"] = (val == "true" or val == "1")
        state["heater_override"] = True
    elif cmd == "heater_auto":
        state["heater_override"] = False
    return jsonify({"ok": True})

@app.route("/api/inject", methods=["POST"])
def inject():
    active = request.args.get("active", "false")
    state["sim"] = active not in ("false", "0")
    state["vcrc_override"] = False
    state["sorb_override"] = False
    state["heater_override"] = False
    if state["sim"]:
        state["temp"] = float(request.args.get("temp", state["temp"]))
        state["hum"] = float(request.args.get("hum", state["hum"]))
        state["bat"] = float(request.args.get("bat", state["bat"]))
        state["res"] = float(request.args.get("res", state["res"]))
        state["cond"] = float(request.args.get("cond", state["cond"]))
        state["sol"] = float(request.args.get("sol", state["sol"]))
        state["delta_hr"] = float(request.args.get("delta_hr", state["delta_hr"]))
        if "sorb" in request.args:
            state["sorb"] = request.args.get("sorb", state["sorb"])
            state["sorb_override"] = True
        if "heater" in request.args:
            state["heater"] = request.args.get("heater") in ("true", "1")
            state["heater_override"] = True
        if "vcrc" in request.args:
            state["vcrc"] = request.args.get("vcrc") in ("true", "1")
            state["vcrc_override"] = True
    return jsonify({"ok": True, "simulation": state["sim"]})

if __name__ == "__main__":
    print("[MOCK ESP32] Running on http://localhost:8080")
    app.run(host="0.0.0.0", port=8080)
