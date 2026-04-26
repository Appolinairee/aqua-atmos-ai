# AQUA-ATMOS - Decision Schemas

## Global View Without AI

```mermaid
flowchart TD
    A[Capteurs metier<br/>HR, T air, T condenseur<br/>Delta HR sorbant, T collecteur<br/>Rayonnement, Heure] --> B[Calculs derives]
    A2[Capteurs securite<br/>Niveau reservoir<br/>SOC batterie] --> D[Evaluation des regles metier]

    B --> B1[Point de rosee Td]
    B --> B2[Rapport humidite w_gkg]

    B1 --> D
    B2 --> D
    A --> D
    A2 --> D

    D --> V[Decision VCRC]
    D --> M[Decision sorbant]

    V --> F[Decision finale actionneurs]
    M --> F

    F --> G[Execution actionneurs]
    G --> L[Logging du cycle]
```

## Regles Metier VCRC

```mermaid
flowchart TD
    A[Entrees metier et securite] --> V

    V{Regles VCRC}
    V -->|Reservoir plein, niveau superieur a 95 pourcent| V1[OFF]
    V -->|Energie insuffisante, SOC inferieur a 20 pourcent| V2[OFF]
    V -->|HR faible, HR inferieure a 40 pourcent| V3[OFF]
    V -->|Anti givrage, Td inferieure ou egale a 2 C| V4[OFF anti-givrage]
    V -->|Humidite insuffisante, w_gkg inferieur a 6 g par kg| V5[OFF]
    V -->|Sinon| V6[ON]
```

## Regles Metier Sorbant

```mermaid
flowchart TD
    A[Entrees metier et securite] --> S

    S{Regles sorbant}
    S -->|Reservoir plein, niveau superieur a 95 pourcent| S1[Veille]
    S -->|Sorbant sature, delta HR absolu inferieur ou egal a 1 pourcent, extraction possible| S2[Regeneration]
    S -->|Sinon si HR suffisante, HR superieure ou egale a 40 pourcent| S3[Absorption]
    S -->|Sinon| S4[Veille]

    S2 --> S5{Extraction possible<br/>solaire superieur ou egal a 500 W par m2<br/>ou SOC superieur ou egal a 35 pourcent}
    S5 -->|Solaire suffisant| S6[Regeneration sans chauffage]
    S5 -->|Solaire insuffisant et SOC suffisant| S7[Regeneration avec chauffage]
    S5 -->|Fin regeneration a definir<br/>temperature, duree, delta HR| S8[Retour a l'absorption ou veille]
```

## A Discuter - Points D Ombre

- Oscillations autour des seuils:
  sans hysteresis, le systeme peut basculer trop souvent entre ON et OFF
- Saturation sorbant:
  le delta HR seul peut etre insuffisant ou trop bruite pour conclure
- Fin de regeneration:
  le critere operationnel reste a fixer clairement
- Vision partielle de l energie:
  le SOC ne represente pas toute la puissance reellement disponible
- Energie insuffisante:
  il faut preciser comment combiner batterie faible et ensoleillement insuffisant
- Robustesse capteurs:
  il faut anticiper bruit, derive, retard ou panne de mesure

## Pourquoi Ajouter L IA

```mermaid
flowchart TD
    A[Regles a seuils fixes] --> B[Lecture partielle du terrain]
    B --> C[Agadir: air cotier plus frais et humide]
    B --> D[Dakar: air plus chaud et plus humide]
    C --> E[Un meme seuil peut couper trop tot]
    D --> F[Un meme seuil peut declencher trop souvent ou trop tard]

    A --> G[Pas d apprentissage des donnees reelles]
    A --> H[Faible adaptation au vieillissement materiel]
    A --> I[Efficacite energetique limitee]
    A --> J[Faible previsibilite pour l utilisateur]
```

## Ce Que L IA Peut Faire Concretement

```mermaid
flowchart TD
    A[IA embarquee] --> B[Adapter la decision au site reel]
    A --> C[Apprendre progressivement des donnees terrain]
    A --> D[Ameliorer la precision des decisions]
    A --> E[Reduire le gaspillage d energie]
    A --> F[Mieux anticiper cycles et production]
    A --> G[Detecter derives et comportements anormaux]
```

## IA 1 - Reactivite Instantanee

```mermaid
flowchart TD
    A[X<br/>HR, T air, T condenseur<br/>Delta HR sorbant, T collecteur<br/>Solaire ou PV, Heure<br/>Td, w_gkg] --> B[Fonction de decision IA]
    B --> C1[Y1 VCRC_state<br/>predire si le VCRC doit etre ON ou OFF maintenant<br/>etats : ON, OFF]
    B --> C2[Y2 Sorbent_mode<br/>predire si le sorbant doit etre en absorption, regeneration ou veille maintenant<br/>etats : Absorption, Regeneration, Veille]

    C1 --> D[Validation par surcouche logique pure<br/>energie, niveau du reservoir]
    C2 --> D
    D --> E[Decision finale appliquee]
```

## Surcouche Energetique Pure

```mermaid
flowchart TD
    A[Decision proposee<br/>Regles ou IA] --> B{Verification energetique pure}
    E1[SOC batterie] --> B
    E2[Rayonnement disponible] --> B
    E3[Puissance electrique disponible] --> B
    E4[Niveau reservoir] --> B
    E5[Priorites systeme] --> B

    B -->|Contrainte violee| C[Decision forcee securite<br/>VCRC OFF<br/>Sorbant veille]
    B -->|Conforme| D[Decision autorisee]

    C --> F[Decision finale appliquee]
    D --> F

    F --> G[Execution actionneurs]
    G --> H[Logging complet]
```

## IA 2 - Prevision Des Cycles

```mermaid
flowchart TD
    A[IA prevision des cycles] --> B[Cycle VCRC]
    A --> C[Cycle sorbant]
    A --> D[Production]

    B --> B1[Debut probable]
    B --> B2[Duree utile]
    B --> B3[Fin probable]

    C --> C1[Saturation probable]
    C --> C2[Debut regeneration]
    C --> C3[Fin regeneration probable]

    D --> D1[Production probable comme consequence des cycles]
```
