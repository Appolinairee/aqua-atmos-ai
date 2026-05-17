# Notebooks ML

Ce dossier contient les notebooks de travail pour la suite du pipeline ML.

## Ordre conseille

1. `02_visualisation_climat_et_synthetique.ipynb`
2. `03_pretraitement_pour_entrainement.ipynb`
3. `04_entrainement_et_benchmark_modeles.ipynb`

## Convention de structure

Pour chaque nouvelle section:

- ajouter une cellule Markdown avec `Objectif`
- ajouter une cellule Markdown avec `Resultat attendu`
- ensuite seulement la cellule de code

## Bonnes pratiques pour la suite

- separer strictement `train`, `validation` et `test`
- ne jamais fitter scaler, encodeur ou selection de variables sur validation ou test
- comparer les modeles sur les memes splits et les memes metriques
- suivre les performances globales et les performances sur cas rares
- garder un resume des decisions et resultats directement dans le notebook
