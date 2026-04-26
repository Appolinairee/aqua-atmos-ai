# Data Layer

Ce dossier contient la logique de donnees synthetiques pour AQUA-ATMOS.

## Organisation

- `climate_profiles.py`: profils mensuels plausibles pour Agadir et Dakar
- `labeler.py`: generation des labels a partir des regles metier
- `schema.py`: schema d'une ligne de cycle
- `synthetic_generator.py`: generation sequentielle du dataset
- `synthetic/`: sorties CSV synthetiques
- `real/`: futures lignes ESP32 terrain
- `merged/`: jeux mixtes pour apprentissage local

Le generateur peut produire:

- un jeu mensuel
- un jeu annuel complet sur 365 jours

## Base de calibration

Les profils sont calibres pour des climats cotiers cibles `Agadir` et `Dakar` a partir de:

- NASA POWER pour les variables energie / solaire et les ordres de grandeur climatiques
- pages climatologiques mensuelles grand public pour verifier temperature, humidite et ensoleillement

Les liens utilises sont listes dans `SOURCES.md`.

Le generateur ne copie pas des historiques reels heure par heure.
Il produit des series plausibles, contraintes par les saisons, le cycle journalier et les regles metier.
