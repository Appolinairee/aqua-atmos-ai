# Data Layer

Ce dossier contient la logique de donnees synthetiques pour AQUA-ATMOS.

## Organisation

- `climate_profiles.py`: compatibilite minimale avec les anciens profils nommes
- `city_catalog.py`: liste finale des villes africaines retenues
- `climate_stats.py`: statistiques horaires derivees de donnees ouvertes reelles
- `labeler.py`: generation des labels a partir des regles metier
- `schema.py`: schema d'une ligne de cycle
- `synthetic_generator.py`: generation sequentielle du dataset
- `climate/raw/`: reponses brutes de l'API ouverte
- `climate/normalized/`: historiques horaires normalises
- `climate/stats/`: statistiques horaires par ville, mois et heure
- `synthetic/`: sorties CSV synthetiques
- `real/`: futures lignes ESP32 terrain
- `merged/`: jeux mixtes pour apprentissage local

Le generateur peut produire:
- un jeu mensuel
- un jeu annuel complet sur 365 jours

## Villes finales retenues

- `agadir`: cote atlantique semi-aride
- `dakar`: cote atlantique tropicale
- `abidjan`: cote du golfe de Guinee tres humide
- `douala`: equatorial cotier hyper-humide
- `mombasa`: cote est tropicale ocean Indien
- `walvis_bay`: desert cotier a brouillard

## Base de calibration

Le pipeline repose maintenant sur:

- Open-Meteo Historical Weather API pour l'historique horaire ouvert
- statistiques horaires par `ville x mois x heure`
- generation synthetique contrainte par distributions observees et cas rares injectes

Les liens utilises sont listes dans `SOURCES.md`.

Le generateur ne recopie pas les historiques reels heure par heure.
Il produit des series plausibles a partir de statistiques reelles, de variabilite journaliere et d'evenements rares documentes.
