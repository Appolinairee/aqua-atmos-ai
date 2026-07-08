import time
import threading
import config
from core.fetcher import fetch
from core.database import Database
from dashboard import server as dashboard


def fetch_loop(db: Database) -> None:
    while True:
        snapshot = fetch(config.ESP32_API_URL)
        if snapshot:
            db.insert(snapshot)
        time.sleep(config.FETCH_INTERVAL_S)


def main() -> None:
    db = Database(config.DB_PATH)
    dashboard.init(db)

    thread = threading.Thread(target=fetch_loop, args=(db,), daemon=True)
    thread.start()

    dashboard.app.run(
        host=config.DASHBOARD_HOST,
        port=config.DASHBOARD_PORT,
        debug=False,
    )


if __name__ == "__main__":
    main()
