import sqlite3
from pathlib import Path
from .models import Snapshot


class Database:
    def __init__(self, path: str):
        Path(path).parent.mkdir(parents=True, exist_ok=True)
        self._conn = sqlite3.connect(path, check_same_thread=False)
        self._create_table()

    def _create_table(self):
        self._conn.execute("""
            CREATE TABLE IF NOT EXISTS snapshots (
                id            INTEGER PRIMARY KEY AUTOINCREMENT,
                timestamp     TEXT    NOT NULL,
                temp_c        REAL,
                humidity_pct  REAL,
                battery_pct   REAL,
                flow_lpm      REAL,
                hour          INTEGER,
                vcrc_active   INTEGER,
                sorbent_mode  TEXT
            )
        """)
        self._conn.commit()

    def insert(self, s: Snapshot) -> None:
        self._conn.execute(
            """INSERT INTO snapshots
               (timestamp, temp_c, humidity_pct, battery_pct, flow_lpm, hour, vcrc_active, sorbent_mode)
               VALUES (?, ?, ?, ?, ?, ?, ?, ?)""",
            (s.timestamp.isoformat(), s.temp_c, s.humidity_pct,
             s.battery_pct, s.flow_lpm, s.hour, int(s.vcrc_active), s.sorbent_mode),
        )
        self._conn.commit()

    def get_recent(self, limit: int = 100) -> list[dict]:
        cur = self._conn.execute(
            """SELECT timestamp, temp_c, humidity_pct, battery_pct, flow_lpm, hour, vcrc_active, sorbent_mode
               FROM snapshots ORDER BY id DESC LIMIT ?""",
            (limit,),
        )
        cols = [c[0] for c in cur.description]
        return [dict(zip(cols, row)) for row in cur.fetchall()]

    def get_latest(self) -> dict | None:
        rows = self.get_recent(limit=1)
        return rows[0] if rows else None
