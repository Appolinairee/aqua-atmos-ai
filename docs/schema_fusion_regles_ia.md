# Fusion regles + IA - AQUA-ATMOS

Ce schema est concu comme un zoom sur le bloc `Fusion` du pipeline. Il explique comment les regles deterministes, l'IA et les securites sont combinees avant l'action physique.

```mermaid
flowchart TB
  R[Regles deterministes<br/>seuils physiques connus] --> F[Fusion prudente<br/>accord regles + IA]
  I[Inference IA<br/>prediction du mode optimal] --> F

  F --> V[VCRC final<br/>ON si regle ET IA]
  F --> S[Sorbant final<br/>mode pilote par les regles]
  F --> H[Chauffage final<br/>ON si regle ET IA]

  B[Hard block<br/>batterie, reservoir, temperature] --> X[Securite prioritaire<br/>tout OFF si danger]
  V --> X
  S --> X
  H --> X

  X --> A[Actionneurs<br/>relais, ventilation, servo]

  classDef sensor fill:#e8f5ff,stroke:#2563eb,color:#0f172a,stroke-width:1px;
  classDef iface fill:#ecfdf5,stroke:#059669,color:#0f172a,stroke-width:1px;
  classDef control fill:#fff7ed,stroke:#ea580c,color:#0f172a,stroke-width:1px;
  classDef output fill:#fef2f2,stroke:#dc2626,color:#0f172a,stroke-width:1px;

  class R sensor;
  class I iface;
  class F,V,S,H control;
  class B,X,A output;
```

## Lecture rapide

L'IA ne commande pas directement la machine. Les regles deterministes restent la base explicable, l'IA confirme ou affine certaines decisions, puis les securites peuvent encore bloquer les sorties avant les actionneurs.

## Message slide

L'IA propose, les regles valident, la securite garde le dernier mot.
