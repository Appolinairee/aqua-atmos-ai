# Sources

## API et reference primaire

- Open-Meteo Historical Weather API:
  https://open-meteo.com/en/docs/historical-weather-api
- NASA POWER Hourly API:
  https://power.larc.nasa.gov/docs/services/api/temporal/hourly/
- NASA POWER API tutorials:
  https://power.larc.nasa.gov/docs/tutorials/service-data-request/api/

## Variables utilisees pour l'ingestion ouverte

- `temperature_2m`
- `relative_humidity_2m`
- `dew_point_2m`
- `cloud_cover`
- `shortwave_radiation`

## Usage dans le generateur

- statistiques reelles `ville x mois x heure`
- quantiles `p01, p05, p50, p95, p99`
- moyenne et ecart-type sur temperature, HR, solaire, nebulosite
- injection controlee de cas rares: `heatwave`, `humid_night`, `dust`, `fog`
