from pathlib import Path

import requests
from flask import Flask, jsonify, render_template, request, send_from_directory
from core.database import Database
import config

app = Flask(__name__)
_db: Database | None = None
_command_state: dict = {}
DESIGNS_DIR = Path(__file__).resolve().parents[2] / "designs"
ASSETS_DIR = Path(__file__).resolve().parents[2] / "assets"


def init(db: Database) -> None:
    global _db
    _db = db


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
    return jsonify(latest)


@app.get("/api/history")
def api_history():
    return jsonify(_db.get_recent(limit=200))


@app.post("/api/command")
def api_command():
    params = request.json or {}
    cmd = params.get("cmd")
    value = params.get("value")
    if cmd == "vcrc_override":
        _command_state["vcrc_active"] = value in (True, "true", "1", 1)
    elif cmd == "sorb_mode":
        _command_state["sorbent_mode"] = value

    try:
        r = requests.post(
            f"http://{config.ESP32_HOST}/api/command",
            params=params,
            timeout=3,
        )
        return jsonify(r.json()), r.status_code
    except Exception as e:
        if config.ESP32_HOST != "localhost:8080":
            try:
                r = requests.post(
                    "http://localhost:8080/api/command",
                    params=params,
                    timeout=1,
                )
                payload = r.json()
                payload["fallback"] = "localhost:8080"
                return jsonify(payload), r.status_code
            except Exception:
                pass
        return jsonify({"ok": False, "error": str(e)}), 503
