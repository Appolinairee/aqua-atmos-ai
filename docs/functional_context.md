# AQUA-ATMOS - Contexte Metier

## Vision

AQUA-ATMOS est un systeme hybride de production d'eau atmospherique pour des zones isolees.

- Cible climat: panel cotier africain representatif (Agadir, Dakar, Abidjan, Douala, Mombasa, Walvis Bay)
- Objectif de production: 1.0 a 1.8 L/jour
- Contrainte: autonomie solaire
- Plateforme cible: ESP32

## Modules de production

### Module VCRC

- Condensation par refroidissement sous le point de rosee
- Plus efficace quand HR > 60%
- Actionneurs: relais ON/OFF + PWM ventilateurs

### Module sorbant CaCl2

- Absorption nocturne de l'humidite
- Regeneration diurne par chaleur solaire
- Actionneurs: servo-volets + ventilateurs

## Complementarite journaliere

- Jour: VCRC actif selon conditions, sorbant en regeneration
- Soiree: phase de transition
- Nuit: sorbant en absorption, VCRC actif si HR suffisante

## Entrees IA (features X)

- HR ambiante
- Temperature ambiante
- Point de rosee (calcule)
- Temperature condenseur
- Delta HR sorbant (entree - sortie)
- Temperature collecteur
- Tension panneau PV (proxy rayonnement)
- Heure (RTC)

## Entrees securite hors IA

- Niveau reservoir
- SOC batterie

Ces entrees ne transitent pas par l'IA.

## Sorties (labels Y)

- VCRC_state: OFF/ON
- Sorbant_mode: absorption/regeneration/veille
- Fan_PWM: 0.0 a 1.0
