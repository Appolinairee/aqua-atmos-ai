from pathlib import Path

import requests
from flask import Flask, jsonify, render_template, request, send_from_directory
from core.database import Database
import config

app = Flask(__name__)
_db: Database | None = None
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
    return jsonify(_db.get_latest())


@app.get("/api/history")
def api_history():
    return jsonify(_db.get_recent(limit=200))


@app.post("/api/command")
def api_command():
    params = request.json or {}
    try:
        r = requests.post(
            f"http://{config.ESP32_HOST}/api/command",
            params=params,
            timeout=3,
        )
        return jsonify(r.json()), r.status_code
    except Exception as e:
        return jsonify({"ok": False, "error": str(e)}), 503
