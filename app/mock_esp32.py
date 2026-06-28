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
    "hour": 12
}

@app.route("/api/data")
def data():
    # Simuler des variations
    state["temp"] = round(state["temp"] + random.uniform(-0.1, 0.1), 1)
    state["hum"] = min(100.0, max(20.0, round(state["hum"] + random.uniform(-0.3, 0.3), 1)))
    state["bat"] = min(100.0, max(5.0, round(state["bat"] + (0.05 if not state["vcrc"] else -0.1), 1)))
    
    # Calcul du point de rosée (Magnus)
    t, rh = state["temp"], state["hum"]
    gamma = math.log(max(0.001, rh / 100.0)) + (17.625 * t) / (243.04 + t)
    state["dew"] = round((243.04 * gamma) / (17.625 - gamma), 1)
    
    # Simuler les règles simplifiées
    state["vcrc"] = (state["hum"] >= 40.0 and state["dew"] > 2.0 and state["bat"] > 20.0)
    state["sorb"] = "ABSORPTION" if state["hum"] >= 40.0 else "VEILLE"
    state["flow"] = round(random.uniform(0.5, 1.8), 2) if state["vcrc"] else 0.0
    
    return jsonify(state)

@app.route("/api/command", methods=["POST"])
def command():
    cmd = request.args.get("cmd")
    val = request.args.get("value")
    if cmd == "vcrc_override":
        state["vcrc"] = (val == "true" or val == "1")
    elif cmd == "sorb_mode":
        state["sorb"] = val
    return jsonify({"ok": True})

if __name__ == "__main__":
    print("[MOCK ESP32] Running on http://localhost:8080")
    app.run(host="0.0.0.0", port=8080)
