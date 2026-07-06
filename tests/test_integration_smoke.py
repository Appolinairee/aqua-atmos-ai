"""Smoke test de la stack simulée (mock ESP32 + dashboard)."""

from __future__ import annotations

import os
import subprocess
import sys
import time
from pathlib import Path

import pytest
import requests

ROOT = Path(__file__).resolve().parents[1]
MOCK_URL = "http://127.0.0.1:8080/api/data"
DASHBOARD_URL = "http://127.0.0.1:5000/api/latest"
STARTUP_TIMEOUT_S = 30


def _wait_for(url: str) -> None:
    deadline = time.time() + STARTUP_TIMEOUT_S
    last_error: Exception | None = None
    while time.time() < deadline:
        try:
            response = requests.get(url, timeout=2)
            if response.status_code == 200:
                return
        except requests.RequestException as exc:
            last_error = exc
        time.sleep(0.5)
    raise RuntimeError(f"Service unavailable: {url}") from last_error


@pytest.fixture(scope="module")
def simulated_stack():
    mock = subprocess.Popen(
        [sys.executable, str(ROOT / "app" / "mock_esp32.py")],
        cwd=ROOT,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    )
    app_env = {
        **os.environ,
        "ESP32_HOST": "127.0.0.1:8080",
        "PYTHONPATH": "app",
    }
    dashboard = subprocess.Popen(
        [sys.executable, str(ROOT / "app" / "main.py")],
        cwd=ROOT,
        env=app_env,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    )
    try:
        _wait_for(MOCK_URL)
        _wait_for(DASHBOARD_URL)
        yield
    finally:
        for proc in (dashboard, mock):
            proc.terminate()
            try:
                proc.wait(timeout=5)
            except subprocess.TimeoutExpired:
                proc.kill()


@pytest.mark.integration
def test_mock_esp32_returns_sensor_payload(simulated_stack) -> None:
    payload = requests.get(MOCK_URL, timeout=5).json()
    for key in ("temp", "hum", "bat", "vcrc", "sorb"):
        assert key in payload


@pytest.mark.integration
def test_dashboard_ingests_mock_data(simulated_stack) -> None:
    time.sleep(3)
    payload = requests.get(DASHBOARD_URL, timeout=5).json()
    assert payload
    assert "temp_c" in payload
    assert "humidity_pct" in payload
