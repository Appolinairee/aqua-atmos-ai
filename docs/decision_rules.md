# AQUA-ATMOS - Regles Metier

## Formules de calcul

### Point de rosee (Magnus)

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
- NOAA Tide Predictions (reference operationnelle)
- Precision annoncee de la formule sur la plage -40 C a +50 C: meilleure que 0.4% (source secondaire: Ezcalculator)

### Humidite absolue (AH)

Formule (forme volumique):
- AH = (RH * Psat) / (461.5 * T_kelvin * 100)

Avec:
- AH: humidite absolue (base volumique)
- RH: humidite relative (%)
- Psat: pression de vapeur saturante
- T_kelvin: temperature en Kelvin
- 461.5: constante des gaz pour la vapeur d'eau (J/kg.K)

Source:
- Omni Calculator (reference operationnelle)

### Rapport d'humidite (w) pour regles en g/kg

Pour les regles de coupure en g/kg, la grandeur utilisee est le rapport d'humidite w (air sec), pas AH.

Formulation recommandee:
- es(T) = 6.112 * exp((17.67 * T) / (T + 243.5))
- e = (RH / 100) * es(T)
- w_gkg = 1000 * 0.62198 * e / (P - e)

Avec:
- T en degres C
- RH en pourcentage
- e, es, P en hPa
- w_gkg en g/kg d'air sec
- P = 1013.25 hPa par defaut si pas de capteur pression

Le condenseur doit passer sous le point de rosee pour condenser.

## Regles empiriques de base

### VCRC ON/OFF

Regles retenues pour generation de Y:
- HR < 40% -> VCRC OFF
- Point de rosee <= 2 C -> VCRC OFF (anti-givrage)
- w_gkg < 6 -> VCRC OFF
- HR >= 40% ET point de rosee > 2 C ET w_gkg >= 6 -> VCRC ON

Observations complementaires (contexte):
- Coupure basse observee sur certaines unites autour de 30-35% HR
- Limite inferieure pratique VCR autour de 40% HR
- Conditions optimales annoncees entre 40% et 100% HR
- Givrage marque si point de rosee < 0 C
- COP VCRC typique: 2.5 a 4.0 (mesure reportee: 3.6 sur systeme EW-1000 AWG-VCRS, Masdar City 2023-2024)
- Production nulle observee sur periodes a HR moyenne 37-46%

Sources associees:
- Thewildrx
- Springer
- Homewatertreatmentsystems
- Thermopedia
- ScienceDirect

### Sorbant

Logique prioritaire retenue:
1. Si sorbant sature ET (rayonnement suffisant OU energie suffisante pour plaque chauffante) -> extraction / regeneration
2. Sinon, si humidite relative >= seuil -> ouvrir (absorption), independamment jour/nuit
3. Sinon -> fermer et veille

Variables de decision:
- seuil humidite relative: HR_seuil_sorbant (a calibrer, valeur initiale 40%)
- saturation sorbant: detectee via delta HR proche de zero sur duree
- rayonnement suffisant: seuil solaire systeme
- energie suffisante chauffage: seuil SOC ou puissance disponible

### Resistance chauffante

Role:
- appoint de chaleur pour extraire / aider la regeneration quand le solaire est insuffisant

Regle retenue:
- Sorbant sature + rayonnement insuffisant + energie suffisante -> resistance ON
- Sorbant non sature -> resistance OFF
- SOC faible ou reservoir plein -> resistance OFF

## Detection d'anomalies

### VCRC

Anomalie si VCRC ON depuis X minutes et condenseur toujours >= point de rosee.

### Sorbant

- Absorption + delta HR proche de 0: sorbant sature
- Regeneration + temperature collecteur < 45 C apres X minutes: echec regeneration

## Architecture hybride IA + regles

A chaque cycle horaire:
1. Lire les entrees metier et les entrees de securite
2. Appliquer la securite pure hors IA
3. Calculer les variables derivees
4. Evaluer les regles Y
5. Actionner le systeme selon les regles pures
6. Generer ou injecter une ligne dans l'historique
7. Apprendre en ligne avec la ligne disponible
8. Produire la prediction du modele pour analyse ou diagnostic
9. Logger le cycle

## Rôle du modele IA

Le modele ne fait pas de ponderation avec les regles.
Il apprend en ligne a partir des donnees historiques, d'abord synthetiques, puis reelles.
Les regles pures restent la reference de controle et de generation des labels.

## Surcouche energetique pure (autorite finale)

La surcouche energetique pure valide ou bloque toute decision proposee (regles ou IA).

Entrees de la surcouche:
- SOC batterie
- rayonnement disponible
- puissance electrique disponible
- niveau reservoir
- priorites systeme

Comportement:
- si une contrainte energie/securite est violee: aucune activation (VCRC OFF, chauffage OFF, sorbant veille)
- sinon: decision autorisee

## Flux des donnees d'apprentissage

- Phase initiale: generation de donnees synthetiques a partir des regles.
- Phase terrain: injection d'une ligne reelle a chaque historique.
- Reajustement du modele sur la ligne reelle disponible.
- Les donnees reelles prennent progressivement le dessus dans l'historique.

## Contraintes absolues

1. Les regles empiriques restent un backup permanent
2. Les overrides reservoir/batterie ne passent jamais par l'IA
3. Le modele n'impose pas la decision finale des actionneurs
4. Le modele reste embarquable
5. Apprentissage strictement en ligne

## Logging terrain minimal

Une ligne par cycle:
- timestamp
- variables X
- Y_regles
- Y_modele
- decision finale
- production eau
- temperature condenseur min
- delta HR moyen
