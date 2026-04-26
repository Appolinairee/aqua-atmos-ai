# Sources

## API et reference primaire

- NASA POWER Climatology API:
  https://power.larc.nasa.gov/docs/services/api/temporal/climatology/
- NASA POWER API tutorials:
  https://power.larc.nasa.gov/docs/tutorials/service-data-request/api/

## Calibration climatologique pratique

- Dakar temperature, cloud cover, humidite percue:
  https://weatherspark.com/y/31520/Average-Weather-in-Dakar-Senegal-Year-Round
- Dakar humidite mensuelle:
  https://www.climate.top/senegal/dakar/humidity/
- Agadir temperature, cloud cover, humidite percue:
  https://weatherspark.com/y/31972/Average-Weather-in-Agadir-Morocco-Year-Round
- Agadir humidite mensuelle:
  https://weather-and-climate.com/average-monthly-Humidity-perc%2Cagadir%2CMorocco

## Usage dans le generateur

- `monthly_temp_c`: moyenne mensuelle plausible par climat cible
- `monthly_hr_pct`: moyenne mensuelle recalee sur les pages humidite
- `monthly_sun_hours`: proxy d'ensoleillement utilise pour moduler `solar_wm2`
- `cloudiness_pct`: coefficient simple de reduction du solaire journalier
