from __future__ import annotations

from dataclasses import dataclass


@dataclass(frozen=True)
class ClimateProfile:
    name: str
    latitude_deg: float
    monthly_temp_c: tuple[float, ...]
    monthly_hr_pct: tuple[float, ...]
    monthly_sun_hours: tuple[float, ...]
    temp_daily_amplitude_c: float
    humidity_daily_amplitude_pct: float
    cloudiness_pct: float


CLIMATE_PROFILES: dict[str, ClimateProfile] = {
    "dakar_coastal": ClimateProfile(
        name="dakar_coastal",
        latitude_deg=14.7167,
        monthly_temp_c=(22.5, 22.8, 23.4, 23.8, 24.8, 26.7, 27.8, 28.3, 28.5, 28.3, 26.8, 24.3),
        monthly_hr_pct=(55.0, 60.0, 63.0, 67.0, 70.0, 69.0, 71.0, 75.0, 75.0, 72.0, 61.0, 52.0),
        monthly_sun_hours=(8.8, 9.0, 9.2, 8.7, 8.1, 7.0, 5.9, 5.4, 6.1, 7.5, 8.6, 8.9),
        temp_daily_amplitude_c=5.5,
        humidity_daily_amplitude_pct=12.0,
        cloudiness_pct=0.20,
    ),
    "agadir_coastal": ClimateProfile(
        name="agadir_coastal",
        latitude_deg=30.4278,
        monthly_temp_c=(14.8, 15.8, 17.3, 18.3, 20.0, 22.0, 24.0, 24.8, 23.7, 22.0, 18.8, 16.0),
        monthly_hr_pct=(70.0, 70.0, 71.0, 72.0, 74.0, 77.0, 81.0, 82.0, 80.0, 77.0, 73.0, 70.0),
        monthly_sun_hours=(7.2, 7.8, 8.3, 8.8, 9.3, 10.1, 10.4, 9.9, 8.9, 8.1, 7.3, 7.0),
        temp_daily_amplitude_c=7.0,
        humidity_daily_amplitude_pct=14.0,
        cloudiness_pct=0.14,
    ),
}


def get_climate_profile(name: str) -> ClimateProfile:
    try:
        return CLIMATE_PROFILES[name]
    except KeyError as exc:
        available = ", ".join(sorted(CLIMATE_PROFILES))
        raise ValueError(f"Unknown climate profile '{name}'. Available: {available}.") from exc
