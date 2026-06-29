# Schema electronique - AQUA-ATMOS

Ce schema est concu pour etre place a droite de la photo du prototype. Il reste compact et montre les grands blocs electroniques sans reprendre le pipeline complet deja presente en slide A2.

```mermaid
flowchart TB
  C[Capteurs<br/>air, eau, batterie] --> I[Entrees ESP32<br/>I2C, GPIO, ADC]
  I --> E[ESP32<br/>lecture + controle local]
  E --> O[Sorties ESP32<br/>relais, PWM, servo]
  O --> A[Elements pilotes<br/>VCRC, chauffage, ventilation]
  E --> L[Signalisation<br/>LEDs, alarme]

  classDef sensor fill:#e8f5ff,stroke:#2563eb,color:#0f172a,stroke-width:1px;
  classDef iface fill:#ecfdf5,stroke:#059669,color:#0f172a,stroke-width:1px;
  classDef control fill:#fff7ed,stroke:#ea580c,color:#0f172a,stroke-width:1px;
  classDef output fill:#fef2f2,stroke:#dc2626,color:#0f172a,stroke-width:1px;

  class C sensor;
  class I iface;
  class E control;
  class O,A,L output;
```

## Lecture rapide

Les capteurs arrivent sur les entrees de l'ESP32. La carte centralise les signaux et pilote les sorties adaptees aux elements physiques. Cette vue reste volontairement generale : le detail acquisition, calculs, securite, decision et actionneurs est traite dans la slide A2.
