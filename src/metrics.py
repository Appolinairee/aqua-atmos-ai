from __future__ import annotations

import math

from constants import DEFAULT_PRESSURE_HPA


def saturation_vapor_pressure_hpa(temp_c: float) -> float:
    """Return saturation vapor pressure in hPa using a common Magnus variant."""
    return 6.112 * math.exp((17.67 * temp_c) / (temp_c + 243.5))


def humidity_ratio_gkg(
    temp_c: float,
    rel_humidity_pct: float,
    pressure_hpa: float = DEFAULT_PRESSURE_HPA,
) -> float:
    """Return humidity ratio (g/kg dry air) from temperature and RH."""
    if not (0 < rel_humidity_pct <= 100):
        raise ValueError("Relative humidity must be in (0, 100].")
    if pressure_hpa <= 0:
        raise ValueError("Pressure must be positive.")

    sat_vapor_pressure = saturation_vapor_pressure_hpa(temp_c)
    actual_vapor_pressure = (rel_humidity_pct / 100.0) * sat_vapor_pressure

    if actual_vapor_pressure >= pressure_hpa:
        raise ValueError("Vapor pressure must be lower than ambient pressure.")

    return 1000.0 * 0.62198 * actual_vapor_pressure / (pressure_hpa - actual_vapor_pressure)
