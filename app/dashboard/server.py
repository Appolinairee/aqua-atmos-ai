from pathlib import Path
import time

import requests
from flask import Flask, jsonify, render_template, request, send_from_directory
from core.database import Database
import config

app = Flask(__name__)
_db: Database | None = None
_command_state: dict = {}
VCRC_MIN_OFF_SECONDS = 300
VCRC_MIN_RUN_SECONDS = 1200
_vcrc_settings = {
    "rest_seconds": VCRC_MIN_OFF_SECONDS,
    "run_seconds": VCRC_MIN_RUN_SECONDS,
    "allow_force": False,
}
DESIGNS_DIR = Path(__file__).resolve().parents[2] / "designs"
ASSETS_DIR = Path(__file__).resolve().parents[2] / "assets"


def init(db: Database) -> None:
    global _db
    _db = db


def apply_successful_command(cmd: str, value, payload: dict) -> dict:
    if cmd == "vcrc_override":
        vcrc_value = value in (True, "true", "1", 1)
        force = payload.pop("_force", False)
        cooldown = 0 if force else (_vcrc_settings["run_seconds"] if vcrc_value else _vcrc_settings["rest_seconds"])
        locked_until = time.time() + cooldown
        _command_state["vcrc_active"] = vcrc_value
        _command_state["vcrc_locked_until"] = locked_until
        payload["vcrc_active"] = vcrc_value
        payload["vcrc_cooldown_remaining_seconds"] = cooldown
        payload["vcrc_locked_until"] = locked_until
    elif cmd == "sorb_mode":
        _command_state["sorbent_mode"] = value
    return payload


@app.get("/")
def index():
    return render_template("index.html")


@app.get("/designs/<path:filename>")
def designs(filename: str):
    return send_from_directory(DESIGNS_DIR, filename)


@app.get("/assets/<path:filename>")
def assets(filename: str):
    return send_from_directory(ASSETS_DIR, filename)


@app.get("/api/latest")
def api_latest():
    latest = _db.get_latest() if _db else None
    if latest and _command_state:
        latest = {**latest, **_command_state}
    if latest and latest.get("vcrc_locked_until"):
        latest["vcrc_cooldown_remaining_seconds"] = max(
            0, int(latest["vcrc_locked_until"] - time.time())
        )
    return jsonify(latest)



@app.get("/api/history")
def api_history():
    return jsonify(_db.get_recent(limit=200))


@app.get("/api/vcrc_settings")
def api_vcrc_settings():
    return jsonify(_vcrc_settings)


@app.post("/api/vcrc_settings")
def api_save_vcrc_settings():
    params = request.json or {}
    _vcrc_settings["rest_seconds"] = max(0, int(params.get("rest_seconds", _vcrc_settings["rest_seconds"])))
    _vcrc_settings["run_seconds"] = max(0, int(params.get("run_seconds", _vcrc_settings["run_seconds"])))
    _vcrc_settings["allow_force"] = bool(params.get("allow_force", _vcrc_settings["allow_force"]))
    return jsonify(_vcrc_settings)


@app.post("/api/command")
def api_command():
    params = request.json or {}
    cmd = params.get("cmd")
    value = params.get("value")
    force = bool(params.get("force")) and _vcrc_settings["allow_force"]
    esp32_params = params.copy()
    esp32_params.pop("force", None)
    if cmd == "vcrc_override":
        esp32_params["cmd"] = "vcrc"

    try:
        if cmd == "sorb_mode":
            is_regen = (value == "REGEN")
            requests.post(
                f"http://{config.ESP32_HOST}/api/command",
                params={"cmd": "sorb_mode", "value": value},
                timeout=3,
            )
            r = requests.post(
                f"http://{config.ESP32_HOST}/api/command",
                params={"cmd": "heater", "value": "true" if is_regen else "false"},
                timeout=3,
            )
        else:
            r = requests.post(
                f"http://{config.ESP32_HOST}/api/command",
                params=esp32_params,
                timeout=3,
            )
        payload = r.json()
        if r.ok and payload.get("ok", True) is not False:
            payload["_force"] = force
            payload = apply_successful_command(cmd, value, payload)
        return jsonify(payload), r.status_code
    except Exception as e:
        if config.ESP32_HOST != "localhost:8080":
            try:
                if cmd == "sorb_mode":
                    is_regen = (value == "REGEN")
                    requests.post(
                        "http://localhost:8080/api/command",
                        params={"cmd": "sorb_mode", "value": value},
                        timeout=1,
                    )
                    r = requests.post(
                        "http://localhost:8080/api/command",
                        params={"cmd": "heater", "value": "true" if is_regen else "false"},
                        timeout=1,
                    )
                else:
                    r = requests.post(
                        "http://localhost:8080/api/command",
                        params=params,
                        timeout=1,
                    )
                payload = r.json()
                payload["fallback"] = "localhost:8080"
                if r.ok and payload.get("ok", True) is not False:
                    payload["_force"] = force
                    payload = apply_successful_command(cmd, value, payload)
                return jsonify(payload), r.status_code
            except Exception:
                pass
        return jsonify({"ok": False, "error": str(e)}), 503


@app.post("/api/inject_sensors")
def api_inject_sensors():
    params = request.json or {}
    active = params.get("active", False)
    payload = {
        "active": "true" if active else "false",
        "temp": params.get("temp", 25.0),
        "hum": params.get("hum", 60.0),
        "bat": params.get("bat", 80.0),
        "res": params.get("res", 30.0),
        "cond": params.get("cond", 25.0),
        "sol": params.get("sol", 0.0),
        "delta_hr": params.get("delta_hr", 5.0)
    }

    try:
        r = requests.post(
            f"http://{config.ESP32_HOST}/api/inject",
            params=payload,
            timeout=3
        )
        return jsonify(r.json()), r.status_code
    except Exception as e:
        if config.ESP32_HOST != "localhost:8080":
            try:
                r = requests.post(
                    "http://localhost:8080/api/inject",
                    params=payload,
                    timeout=1
                )
                return jsonify(r.json()), r.status_code
            except Exception:
                pass
        return jsonify({"ok": False, "error": str(e)}), 503


@app.get("/simulation")
def get_simulation():
    return render_template("simulation.html")
