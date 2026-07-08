from __future__ import annotations

import math

from constants import MAGNUS_A, MAGNUS_B


def magnus_dew_point(temp_c: float, rel_humidity_pct: float) -> float:
    """Compute dew point (C) from ambient temperature and relative humidity."""
    if not (0 < rel_humidity_pct <= 100):
        raise ValueError("Relative humidity must be in (0, 100].")

    gamma = math.log(rel_humidity_pct / 100.0) + (MAGNUS_A * temp_c) / (MAGNUS_B + temp_c)
    return (MAGNUS_B * gamma) / (MAGNUS_A - gamma)
