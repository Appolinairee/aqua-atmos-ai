<p>
	<img src="assets/logo.png" alt="AQUA-ATMOS logo" width="220" />
</p>

# AQUA-ATMOS

Reference implementation of the AQUA-ATMOS hybrid control loop for atmospheric water harvesting in isolated, solar-powered contexts.

## Scope

This repository currently provides:

- Core business formulas: dew point (Magnus) and humidity ratio.
- Deterministic decision rules for VCRC and sorbent modules.
- Hard safety overrides (reservoir and battery).
- Rule-based cycle labeling.
- Open-weather ingestion for selected African coastal cities.
- Synthetic climate cycle generation and yearly dataset export from observed hourly statistics.
- Begin models training
- Unit tests covering nominal and boundary cases.

## Quick start

```bash
python -m venv .venv
source .venv/bin/activate
python -m pip install --upgrade pip
python -m pip install pytest
```

Run test suite:

```bash
PYTHONPATH=src pytest -q

Build climate inputs from the open API:

```bash
PYTHONPATH=src python scripts/ingest_open_meteo.py --cities all --start-date 2019-01-01 --end-date 2024-12-31
```
```
