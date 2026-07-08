from __future__ import annotations

from dataclasses import dataclass

from .city_catalog import get_city_definition, list_city_ids


@dataclass(frozen=True)
class ClimateProfile:
    name: str
    latitude_deg: float


def get_climate_profile(name: str) -> ClimateProfile:
    city = get_city_definition(name)
    return ClimateProfile(name=city.city_id, latitude_deg=city.latitude_deg)


def list_climate_profiles() -> list[str]:
    return list_city_ids()
