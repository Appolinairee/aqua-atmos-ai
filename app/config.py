ESP32_HOST = "192.168.4.1" # Production (ESP32 AP)
# ESP32_HOST = "localhost:8080" # Test local (avec mock_esp32.py)

ESP32_API_URL = f"http://{ESP32_HOST}/api/data"
FETCH_INTERVAL_S = 2
DB_PATH = "data/history.db"
DASHBOARD_HOST = "0.0.0.0"
DASHBOARD_PORT = 5000

