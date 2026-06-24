# CONTEXTE ET ARCHITECTURE IA - AQUA-ATMOS

## 1. Les entrées physiques (Capteurs)
Le système récolte en temps réel les données environnementales et l'état interne de la machine :
* **Données environnementales** : Température et humidité relative de l'air ambiant, intensité du rayonnement solaire et tension générée par le panneau photovoltaïque (proxy de l'ensoleillement).
* **Données thermiques** : Températures du condenseur et du collecteur thermique solaire.
* **Données du sorbant** : Humidité de l'air à l'entrée et à la sortie du lit de sorbant (chlorure de calcium).
* **Données temporelles** : Heure de la journée fournie par l'horloge système.
* **Données de sécurité** : Niveau de remplissage du réservoir d'eau et état de charge de la batterie.

---

## 2. La préparation des données (Traitement physique et temporel)
Avant d'être envoyées aux modèles, les mesures brutes sont transformées en indicateurs physiques :
* **Indicateurs thermodynamiques** : Calcul du point de rosée (seuil de condensation de l'eau) et du rapport d'humidité de l'air (quantité absolue d'eau par kilogramme d'air sec).
* **Indicateurs d'efficacité** : Différence d'humidité relative à travers le sorbant (pour mesurer l'absorption de l'eau) et gains thermiques du collecteur.
* **Cyclicité temporelle** : Transformation mathématique de l'heure et du jour en coordonnées sinusoïdales pour aider l'IA à appréhender les cycles naturels jour/nuit et saisonniers.
* **Statuts logiques** : Alertes de stress de batterie, de réservoir haut et de forte humidité.

---

## 3. Les modèles d'intelligence artificielle
Pour s'exécuter sur un microcontrôleur à faibles ressources (ESP32), les algorithmes sont légers, évalués dans le document [04_entrainement_et_benchmark_modeles.ipynb](file:///home/user/projects/aqua-atmos-ai/notebooks/04_entrainement_et_benchmark_modeles.ipynb) et convertis en code machine optimisé :
* **Technologie** : Forêts aléatoires de classification, configurées avec un nombre d'arbres et une profondeur limités pour s'intégrer dans la mémoire du processeur.
* **Exportation** : Les modèles entraînés sous Python sont traduits en fonctions C++ pures pour une exécution immédiate sans dépendance externe dans [inference_engine.h](file:///home/user/projects/aqua-atmos-ai/firmware/esp32/include/control/inference_engine.h).
* **Décisions prédites par l'IA** :
  * L'activation ou l'arrêt du module de condensation.
  * Le mode de fonctionnement du lit de sorbant (Veille, Absorption d'humidité ou Régénération thermique).
  * L'allumage ou l'extinction de la résistance électrique chauffante d'appoint.
  * La détection de la saturation en eau du sorbant chimique.

---

## 4. La logique de décision (Hybridation IA et règles matérielles)
Le contrôle de la machine repose sur une double autorité, détaillée dans le document [decision_rules.md](file:///home/user/projects/aqua-atmos-ai/docs/decision_rules.md) :
* **Apprentissage et anticipation (IA)** : L'IA prédit le mode de fonctionnement optimal à adopter en fonction du climat local réel (s'adapter aux climats côtiers plus ou moins humides) et du comportement observé de la machine.
* **Sécurité absolue (Règles physiques)** : Une surcouche logique non négociable surveille en permanence la batterie et le réservoir. Si la batterie descend sous le seuil critique (20 %) ou si le réservoir dépasse le seuil de remplissage (95 %), cette logique coupe immédiatement tous les actionneurs (arrêt de la condensation, fermeture des volets du sorbant et extinction de la résistance), annulant toute proposition ou prédiction faite par l'IA.
