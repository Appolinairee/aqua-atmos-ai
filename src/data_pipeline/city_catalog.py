from __future__ import annotations

from dataclasses import dataclass


@dataclass(frozen=True)
class CityDefinition:
    city_id: str
    display_name: str
    country: str
    latitude_deg: float
    longitude_deg: float
    climate_family: str
    rationale: str


CITY_DEFINITIONS: dict[str, CityDefinition] = {
    "agadir": CityDefinition(
        city_id="agadir",
        display_name="Agadir",
        country="Morocco",
        latitude_deg=30.4278,
        longitude_deg=-9.5981,
        climate_family="coastal_semi_arid",
        rationale="Coastal semi-arid Atlantic climate with moderate temperatures and marine humidity.",
    ),
    "dakar": CityDefinition(
        city_id="dakar",
        display_name="Dakar",
        country="Senegal",
        latitude_deg=14.7167,
        longitude_deg=-17.4677,
        climate_family="coastal_tropical",
        rationale="Warm Atlantic coastal climate with strong seasonal humidity shifts.",
    ),
    "abidjan": CityDefinition(
        city_id="abidjan",
        display_name="Abidjan",
        country="Ivory Coast",
        latitude_deg=5.3599,
        longitude_deg=-4.0083,
        climate_family="coastal_humid_tropical",
        rationale="Humid Gulf of Guinea climate representative of high-moisture coastal conditions.",
    ),
    "douala": CityDefinition(
        city_id="douala",
        display_name="Douala",
        country="Cameroon",
        latitude_deg=4.0511,
        longitude_deg=9.7679,
        climate_family="equatorial_hyper_humid",
        rationale="Very humid equatorial coastal climate useful for upper-bound AWG conditions.",
    ),
    "mombasa": CityDefinition(
        city_id="mombasa",
        display_name="Mombasa",
        country="Kenya",
        latitude_deg=-4.0435,
        longitude_deg=39.6682,
        climate_family="coastal_tropical_east_africa",
        rationale="Indian Ocean coastal climate with warm, humid and monsoon-influenced conditions.",
    ),
    "walvis_bay": CityDefinition(
        city_id="walvis_bay",
        display_name="Walvis Bay",
        country="Namibia",
        latitude_deg=-22.9576,
        longitude_deg=14.5053,
        climate_family="coastal_fog_desert",
        rationale="Cool desert coast influenced by Benguela fog, relevant for rare moisture capture patterns.",
    ),
}

CITY_ALIASES = {
    "agadir_coastal": "agadir",
    "dakar_coastal": "dakar",
}


def get_city_definition(name: str) -> CityDefinition:
    city_id = CITY_ALIASES.get(name, name)
    try:
        return CITY_DEFINITIONS[city_id]
    except KeyError as exc:
        available = ", ".join(sorted(CITY_DEFINITIONS))
        raise ValueError(f"Unknown city '{name}'. Available: {available}.") from exc


def list_city_ids() -> list[str]:
    return sorted(CITY_DEFINITIONS)
