import requests
from datetime import datetime
from .models import Snapshot


def fetch(api_url: str, timeout: int = 3) -> Snapshot | None:
    try:
        d = requests.get(api_url, timeout=timeout).json()
        return Snapshot(
            timestamp=datetime.now(),
            temp_c=d["temp"],
            humidity_pct=d["hum"],
            battery_pct=d["bat"],
            reservoir_level_pct=d.get("res", 30.0),
            flow_lpm=d.get("flow", 0.0),
            hour=d.get("hour", 0),
            vcrc_active=d["vcrc"],
            sorbent_mode=d["sorb"],
            heater_active=d.get("heater", d["sorb"] == "REGEN"),
        )
    except Exception:
        return None
