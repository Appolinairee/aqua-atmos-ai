import requests
from flask import Flask, jsonify, render_template, request
from core.database import Database
import config

app = Flask(__name__)
_db: Database | None = None


def init(db: Database) -> None:
    global _db
    _db = db


@app.get("/")
def index():
    return render_template("index.html")


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
