import os

ESP32_HOST = os.environ.get("ESP32_HOST", "192.168.4.1")

ESP32_API_URL = f"http://{ESP32_HOST}/api/data"
FETCH_INTERVAL_S = 2
DB_PATH = "data/history.db"
DASHBOARD_HOST = "0.0.0.0"
DASHBOARD_PORT = 5000


