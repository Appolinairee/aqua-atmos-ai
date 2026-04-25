# AQUA-ATMOS - Regles Metier

## Formule physique

Point de rosee par Magnus:
- a = 17.625
- b = 243.04

Formulation:
- gamma(T, HR) = ln(HR / 100) + (a * T) / (b + T)
- Td = (b * gamma) / (a - gamma)

Avec:
- T: temperature ambiante en degres C
- HR: humidite relative en pourcentage (0 < HR <= 100)
- Td: point de rosee en degres C

Source scientifique de reference:
- Alduchov, O. A., and R. E. Eskridge (1996), "Improved Magnus Form Approximation of Saturation Vapor Pressure", Journal of Applied Meteorology, 35(4), 601-609.
- DOI: 10.1175/1520-0450(1996)035<0601:IMFAOS>2.0.CO;2

Le condenseur doit passer sous le point de rosee pour condenser.

## Regles empiriques de base

### VCRC

- Jour (06h-18h): ON si HR > 60% et rayonnement suffisant, sinon OFF
- Nuit: ON si HR > 70%, sinon OFF

### Sorbant

- Jour + rayonnement suffisant: mode regeneration
- Nuit: mode absorption
- Reservoir plein ou batterie faible: mode veille

### PWM ventilateurs

- Monte avec HR ambiante
- Diminue si ecart condenseur/point de rosee faible
- Module selon SOC batterie

## Detection d'anomalies

### VCRC

Anomalie si VCRC ON depuis X minutes et condenseur toujours >= point de rosee.

### Sorbant

- Absorption + delta HR proche de 0: sorbant sature
- Regeneration + temperature collecteur < 45 C apres X minutes: echec regeneration

## Architecture hybride IA + regles

A chaque cycle horaire:
1. Lire capteurs
2. Appliquer securite hors IA
3. Produire Y_regles
4. Produire Y_modele
5. Fusionner avec alpha
6. Actionner
7. Apprendre en ligne avec 1 ligne
8. Logger le cycle

## Politique alpha

- 0-100 lignes: alpha max 0.0
- 100-300 lignes: alpha max 0.3
- 300-500 lignes: alpha max 0.5
- 500-1000 lignes: alpha max 0.7
- >1000 lignes: alpha max 0.8

Garde-fou:
- Si ecart modele/regles > seuil, forcer alpha=0 sur la decision courante
- Alpha ne depasse jamais 0.8

## Contraintes absolues

1. Les regles empiriques restent un backup permanent
2. Les overrides reservoir/batterie ne passent jamais par l'IA
3. Le modele n'impose pas une decision en cas de grand ecart avec les regles
4. Le modele reste embarquable
5. Apprentissage strictement en ligne

## Logging terrain minimal

Une ligne par cycle:
- timestamp
- variables X
- Y_regles
- Y_modele
- decision finale
- alpha utilise
- production eau
- temperature condenseur min
- delta HR moyen
