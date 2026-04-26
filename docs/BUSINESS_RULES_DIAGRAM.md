## Diagramme Mermaid - Vue globale lisible

```mermaid
flowchart LR
    D[NASA POWER 2 ans<br/>+ calcul Tdp/AH/Y1] --> M[Modele RF entraine<br/>X -> Y1]
    F[OpenWeatherMap 24h] --> P[Planification journaliere<br/>cycles VCRC]
    M --> P
    P --> R[Execution temps reel]
    S[Surcouche securite pure<br/>reservoir, SOC, limites physiques] --> R
    R --> L[Logging terrain]
    L --> U[Mise a jour mensuelle modele]
    U --> M
```

## Diagramme Mermaid - Couche IA (3 niveaux)

```mermaid
flowchart TD
    subgraph N1[Niveau 1 - Saisonnier offline]
        N11[NASA POWER historique<br/>Agadir 2 ans] --> N12[Random Forest saisonnier]
        N12 --> N13[Fenetres favorables<br/>par mois]
    end

    subgraph N2[Niveau 2 - Planification journaliere]
        N21[Previsions 24h<br/>HR, T, rayonnement] --> N22[X futurs par heure]
        N13 --> N23[Contexte saisonnier]
        N22 --> N24[RF prediction Y1]
        N23 --> N24
        N24 --> N25[Plan heures + durees VCRC]
    end

    subgraph N3[Niveau 3 - Affinage temps reel]
        N31[HR instantanee capteur] --> N32{Hysteresis microcontroleur}
        N25 --> N32
        N32 -->|HR > 60 pourcent| N33[Autoriser cycle]
        N32 -->|HR < 50 pourcent| N34[Arreter cycle]
    end
```

## Diagramme Mermaid - Couche regles heritees utiles

```mermaid
flowchart TD
    IN[Mesures physiques] --> VCRC{Regles VCRC}
    VCRC -->|HR < 40 pourcent| VOFF1[VCRC OFF]
    VCRC -->|Tdp <= 2 C| VOFF2[VCRC OFF anti-givrage]
    VCRC -->|AH < 6 g par kg| VOFF3[VCRC OFF faible humidite]
    VCRC -->|Evaporateur <= 0 C| VOFF4[VCRC OFF immediate]
    VCRC -->|Sinon| VON[VCRC eligible]

    IN --> SORB{Regles sorbant CaCl2}
    SORB -->|Saturation > 80 pourcent et Rayonnement > 500| SR[Sorbant regeneration]
    SORB -->|Delta HR entree-sortie proche de 0| SS[Sorbant sature]
    SORB -->|Sinon| SA[Sorbant absorption/veille]

    SAFE{Surcouche securite pure}
    RES[Niveau reservoir > 95 pourcent] --> SAFE
    SOC[SOC batterie < 20 pourcent] --> SAFE
    VOFF1 --> SAFE
    VOFF2 --> SAFE
    VOFF3 --> SAFE
    VOFF4 --> SAFE
    VON --> SAFE
    SR --> SAFE
    SS --> SAFE
    SA --> SAFE

    SAFE -->|Contrainte violee| STOP[Annuler activation]
    SAFE -->|Conforme| ACT[Execution actionneurs]
```

## Ce qui change vs ancienne logique

1. L IA ne sort plus des commandes finales multi-actionneurs: elle predit surtout Y1 pour planifier.
2. Le pilotage instantane est confie a l hysteresis microcontroleur, pour supprimer le chattering.
3. Les regles physiques historiques VCRC/Sorbant sont conservees, mais placees dans une couche de validation dure.
4. La surcouche securite pure garde l autorite finale sur toute activation.
5. L adaptation du modele passe par une boucle de feedback mensuelle, pas par correction decisionnelle continue en ligne.