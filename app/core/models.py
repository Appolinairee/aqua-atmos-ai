from dataclasses import dataclass
from datetime import datetime


@dataclass
class Snapshot:
    timestamp: datetime
    temp_c: float
    humidity_pct: float
    battery_pct: float
    flow_lpm: float
    hour: int
    vcrc_active: bool
    sorbent_mode: str
