from __future__ import annotations

import json
import textwrap
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
NOTEBOOKS_DIR = ROOT / "notebooks"


def md_cell(text: str) -> dict[str, object]:
    lines = [line.rstrip() for line in textwrap.dedent(text).strip().splitlines()]
    return {
        "cell_type": "markdown",
        "metadata": {},
        "source": [line + "\n" for line in lines],
    }


def code_cell(code: str) -> dict[str, object]:
    lines = [line.rstrip() for line in textwrap.dedent(code).strip().splitlines()]
    return {
        "cell_type": "code",
        "execution_count": None,
        "metadata": {},
        "outputs": [],
        "source": [line + "\n" for line in lines],
    }


def notebook(cells: list[dict[str, object]]) -> dict[str, object]:
    return {
        "cells": cells,
        "metadata": {
            "kernelspec": {
                "display_name": "Python 3",
                "language": "python",
                "name": "python3",
            },
            "language_info": {
                "name": "python",
                "version": "3.11",
            },
        },
        "nbformat": 4,
        "nbformat_minor": 5,
    }


def write_notebook(path: Path, payload: dict[str, object]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(payload, ensure_ascii=True, indent=2) + "\n", encoding="utf-8")


def build_visualization_notebook() -> dict[str, object]:
    cells = [
        md_cell(
            """
            # Visualisation Des Donnees AQUA-ATMOS

            Ce notebook sert a explorer les donnees climatiques ouvertes et les donnees synthetiques qui serviront a l'entrainement.
            """
        ),
        md_cell(
            """
            ## 1. Chargement

            **Objectif**
            Charger les donnees synthetiques annuelles et les historiques climatiques normalises.

            **Resultat attendu**
            Obtenir deux DataFrames propres, avec les types numeriques corrects et une liste claire des villes disponibles.
            """
        ),
        code_cell(
            """
            from pathlib import Path

            import matplotlib.pyplot as plt
            import pandas as pd
            import seaborn as sns

            try:
                from IPython.display import display
            except Exception:
                def display(value):
                    print(value)

            sns.set_theme(style="whitegrid", context="talk")

            PROJECT_ROOT = Path.cwd().resolve()
            if PROJECT_ROOT.name == "notebooks":
                PROJECT_ROOT = PROJECT_ROOT.parent
            SYNTHETIC_PATH = PROJECT_ROOT / "data" / "synthetic" / "synthetic_year.csv"
            CLIMATE_DIR = PROJECT_ROOT / "data" / "climate" / "normalized"


            def load_climate_history(climate_dir: Path) -> pd.DataFrame:
                frames = []
                for csv_path in sorted(climate_dir.glob("*_hourly.csv")):
                    frame = pd.read_csv(csv_path)
                    frame["timestamp_utc"] = pd.to_datetime(frame["timestamp_utc"])
                    numeric_columns = [
                        "year",
                        "month",
                        "day",
                        "hour",
                        "temp_air_c",
                        "hr_pct",
                        "dew_point_c",
                        "solar_wm2",
                        "cloud_cover_pct",
                    ]
                    frame[numeric_columns] = frame[numeric_columns].apply(pd.to_numeric)
                    frames.append(frame)
                return pd.concat(frames, ignore_index=True)


            synthetic_df = pd.read_csv(SYNTHETIC_PATH)
            climate_df = load_climate_history(CLIMATE_DIR)

            synthetic_df.head(), climate_df.head(), sorted(climate_df["city_id"].unique().tolist())
            """
        ),
        md_cell(
            """
            ## 2. Vue D'Ensemble

            **Objectif**
            Verifier la taille, les colonnes et les statistiques descriptives principales.

            **Resultat attendu**
            Confirmer que les deux jeux de donnees sont exploitables avant de passer aux graphiques.
            """
        ),
        code_cell(
            """
            print("Synthetic shape:", synthetic_df.shape)
            print("Climate shape:", climate_df.shape)

            display(synthetic_df.describe(include="all").T)
            display(climate_df.describe(include="all").T)
            """
        ),
        md_cell(
            """
            ## 3. Couverture Par Ville

            **Objectif**
            Mesurer la couverture temporelle et le volume de donnees pour chaque ville.

            **Resultat attendu**
            Verifier qu'aucune ville n'est sous-representee avant l'entrainement.
            """
        ),
        code_cell(
            """
            coverage = (
                climate_df.groupby("city_id")
                .agg(
                    rows=("timestamp_utc", "size"),
                    start=("timestamp_utc", "min"),
                    end=("timestamp_utc", "max"),
                    min_temp=("temp_air_c", "min"),
                    max_temp=("temp_air_c", "max"),
                    min_hr=("hr_pct", "min"),
                    max_hr=("hr_pct", "max"),
                )
                .sort_index()
            )
            display(coverage)
            """
        ),
        md_cell(
            """
            ## 4. Distributions Climatiques

            **Objectif**
            Comparer les distributions de temperature, humidite relative et rayonnement solaire entre les villes.

            **Resultat attendu**
            Voir si le panel retenu couvre bien des regimes climatiques differents.
            """
        ),
        code_cell(
            """
            fig, axes = plt.subplots(1, 3, figsize=(24, 7))

            sns.boxplot(data=climate_df, x="city_id", y="temp_air_c", ax=axes[0])
            axes[0].set_title("Temperature par ville")
            axes[0].tick_params(axis="x", rotation=45)

            sns.boxplot(data=climate_df, x="city_id", y="hr_pct", ax=axes[1])
            axes[1].set_title("Humidite relative par ville")
            axes[1].tick_params(axis="x", rotation=45)

            sns.boxplot(data=climate_df, x="city_id", y="solar_wm2", ax=axes[2])
            axes[2].set_title("Rayonnement solaire par ville")
            axes[2].tick_params(axis="x", rotation=45)

            plt.tight_layout()
            plt.show()
            """
        ),
        md_cell(
            """
            ## 5. Profils Horaires Moyens

            **Objectif**
            Visualiser le cycle journalier moyen de la temperature, de l'humidite et du solaire pour chaque ville.

            **Resultat attendu**
            Verifier que les donnees reelles restituent des profils jour/nuit coherents.
            """
        ),
        code_cell(
            """
            hourly_profile = (
                climate_df.groupby(["city_id", "hour"])
                .agg(
                    temp_air_c=("temp_air_c", "mean"),
                    hr_pct=("hr_pct", "mean"),
                    solar_wm2=("solar_wm2", "mean"),
                )
                .reset_index()
            )

            fig, axes = plt.subplots(3, 1, figsize=(18, 18), sharex=True)
            metrics = ["temp_air_c", "hr_pct", "solar_wm2"]
            titles = ["Temperature", "Humidite relative", "Rayonnement solaire"]

            for ax, metric, title in zip(axes, metrics, titles):
                sns.lineplot(data=hourly_profile, x="hour", y=metric, hue="city_id", marker="o", ax=ax)
                ax.set_title(title)
                ax.set_xlabel("Heure")
                ax.legend(title="Ville", bbox_to_anchor=(1.02, 1), loc="upper left")

            plt.tight_layout()
            plt.show()
            """
        ),
        md_cell(
            """
            ## 6. Saisonnalite

            **Objectif**
            Etudier les variations mensuelles par ville.

            **Resultat attendu**
            Identifier les mois favorables et defavorables a la production potentielle.
            """
        ),
        code_cell(
            """
            monthly_profile = (
                climate_df.groupby(["city_id", "month"])
                .agg(
                    temp_air_c=("temp_air_c", "mean"),
                    hr_pct=("hr_pct", "mean"),
                    solar_wm2=("solar_wm2", "mean"),
                )
                .reset_index()
            )

            fig, axes = plt.subplots(3, 1, figsize=(18, 18), sharex=True)
            for ax, metric, title in zip(axes, ["temp_air_c", "hr_pct", "solar_wm2"], ["Temperature", "Humidite", "Solaire"]):
                sns.lineplot(data=monthly_profile, x="month", y=metric, hue="city_id", marker="o", ax=ax)
                ax.set_title(f"Saisonnalite - {title}")
                ax.legend(title="Ville", bbox_to_anchor=(1.02, 1), loc="upper left")

            plt.tight_layout()
            plt.show()
            """
        ),
        md_cell(
            """
            ## 7. Cas Rares Et Extemes

            **Objectif**
            Isoler les queues de distribution qui devront etre preservees lors de l'entrainement et de l'evaluation.

            **Resultat attendu**
            Obtenir un tableau des seuils extremes par ville pour guider les scenarios de test.
            """
        ),
        code_cell(
            """
            extremes = (
                climate_df.groupby("city_id")
                .agg(
                    temp_p01=("temp_air_c", lambda s: s.quantile(0.01)),
                    temp_p99=("temp_air_c", lambda s: s.quantile(0.99)),
                    hr_p01=("hr_pct", lambda s: s.quantile(0.01)),
                    hr_p99=("hr_pct", lambda s: s.quantile(0.99)),
                    solar_p01=("solar_wm2", lambda s: s.quantile(0.01)),
                    solar_p99=("solar_wm2", lambda s: s.quantile(0.99)),
                )
                .sort_index()
            )
            display(extremes)
            """
        ),
        md_cell(
            """
            ## 8. Cibles Synthetiques

            **Objectif**
            Observer l'equilibre des labels produits par les regles metier.

            **Resultat attendu**
            Identifier les eventuels desequilibres de classes avant l'entrainement.
            """
        ),
        code_cell(
            """
            fig, axes = plt.subplots(1, 3, figsize=(24, 6))

            synthetic_df["profile_name"].value_counts().sort_index().plot(kind="bar", ax=axes[0], title="Profils synthetiques")
            synthetic_df["vcrc_state"].value_counts().sort_index().plot(kind="bar", ax=axes[1], title="Distribution VCRC")
            synthetic_df["sorbent_mode"].value_counts().sort_index().plot(kind="bar", ax=axes[2], title="Modes sorbant")

            for ax in axes:
                ax.tick_params(axis="x", rotation=30)

            plt.tight_layout()
            plt.show()
            """
        ),
        md_cell(
            """
            ## 9. Lecture Pour La Suite

            **Objectif**
            Resumer ce qui doit etre retenu avant de lancer le pretraitement et l'entrainement.

            **Resultat attendu**
            Une courte checklist pour la prochaine etape.
            """
        ),
        code_cell(
            """
            checklist = [
                "Verifier qu'aucune ville n'est massivement sous-representee.",
                "Verifier qu'il n'y a pas de fuite temporelle entre train, validation et test.",
                "Conserver les cas extremes dans les jeux d'evaluation.",
                "Comparer plusieurs modeles sur la meme partition et les memes metriques.",
            ]

            pd.DataFrame({"checklist_avant_entrainement": checklist})
            """
        ),
    ]
    return notebook(cells)


def build_preprocessing_notebook() -> dict[str, object]:
    cells = [
        md_cell(
            """
            # Pretraitement Pour L'Entrainement AQUA-ATMOS

            Ce notebook prepare un jeu d'entree propre, documente et reutilisable pour la comparaison de modeles.
            """
        ),
        md_cell(
            """
            ## 1. Chargement

            **Objectif**
            Charger le jeu synthetique principal et verifier qu'il contient bien les colonnes necessaires.

            **Resultat attendu**
            Disposer d'un DataFrame de depart pret pour les transformations.
            """
        ),
        code_cell(
            """
            from pathlib import Path

            import numpy as np
            import pandas as pd

            try:
                from IPython.display import display
            except Exception:
                def display(value):
                    print(value)

            PROJECT_ROOT = Path.cwd().resolve()
            if PROJECT_ROOT.name == "notebooks":
                PROJECT_ROOT = PROJECT_ROOT.parent
            SYNTHETIC_PATH = PROJECT_ROOT / "data" / "synthetic" / "synthetic_year.csv"
            OUTPUT_DIR = PROJECT_ROOT / "data" / "processed"
            OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

            df = pd.read_csv(SYNTHETIC_PATH)
            df.head()
            """
        ),
        md_cell(
            """
            ## 2. Controle De Qualite

            **Objectif**
            Controler les types, doublons et valeurs manquantes avant toute transformation.

            **Resultat attendu**
            Identifier tout point bloquant avant l'entrainement.
            """
        ),
        code_cell(
            """
            quality_report = {
                "shape": df.shape,
                "missing_values": df.isna().sum().to_dict(),
                "duplicates": int(df.duplicated().sum()),
            }

            quality_report
            """
        ),
        md_cell(
            """
            ## 3. Normalisation Des Noms De Profils

            **Objectif**
            Rapprocher les anciens identifiants synthetiques des identifiants de villes standardises.

            **Resultat attendu**
            Obtenir une colonne `city_id` stable pour les futurs modeles et dashboards.
            """
        ),
        code_cell(
            """
            city_aliases = {
                "agadir_coastal": "agadir",
                "dakar_coastal": "dakar",
                "abidjan_coastal": "abidjan",
                "douala_coastal": "douala",
                "mombasa_coastal": "mombasa",
                "walvis_bay_coastal": "walvis_bay",
            }

            df["city_id"] = df["profile_name"].replace(city_aliases)
            df[["profile_name", "city_id"]].drop_duplicates().sort_values(["city_id", "profile_name"])
            """
        ),
        md_cell(
            """
            ## 4. Variables Temporelles Cycliques

            **Objectif**
            Encoder les cycles jour/nuit et saisonniers sans casser la periodicite.

            **Resultat attendu**
            Ajouter des variables robustes pour les modeles lineaires et arborescents.
            """
        ),
        code_cell(
            """
            df["hour_sin"] = np.sin(2 * np.pi * df["hour"] / 24)
            df["hour_cos"] = np.cos(2 * np.pi * df["hour"] / 24)
            df["day_sin"] = np.sin(2 * np.pi * df["day_index"] / 365)
            df["day_cos"] = np.cos(2 * np.pi * df["day_index"] / 365)

            df[["hour", "hour_sin", "hour_cos", "day_index", "day_sin", "day_cos"]].head()
            """
        ),
        md_cell(
            """
            ## 5. Variables Derivees Metier

            **Objectif**
            Creer quelques indicateurs interpretablement utiles pour l'entrainement.

            **Resultat attendu**
            Enrichir le jeu sans dupliquer inutilement les informations deja presentes.
            """
        ),
        code_cell(
            """
            df["thermal_lift_c"] = df["temp_air_c"] - df["temp_cond_c"]
            df["collector_gain_c"] = df["temp_collector_c"] - df["temp_air_c"]
            df["is_daylight"] = (df["solar_wm2"] > 0).astype(int)
            df["high_humidity_flag"] = (df["hr_pct"] >= 70).astype(int)
            df["battery_stress_flag"] = (df["soc_battery_pct"] <= 25).astype(int)
            df["reservoir_high_flag"] = (df["reservoir_level_pct"] >= 80).astype(int)

            engineered_columns = [
                "thermal_lift_c",
                "collector_gain_c",
                "is_daylight",
                "high_humidity_flag",
                "battery_stress_flag",
                "reservoir_high_flag",
            ]
            df[engineered_columns].describe().T
            """
        ),
        md_cell(
            """
            ## 6. Encodage Des Cibles

            **Objectif**
            Preparer des cibles numeriques stables pour les taches de classification.

            **Resultat attendu**
            Obtenir des labels exploitables pour les comparaisons de modeles.
            """
        ),
        code_cell(
            """
            sorbent_mode_mapping = {
                "veille": 0,
                "absorption": 1,
                "regeneration": 2,
            }

            df["sorbent_mode_label"] = df["sorbent_mode"].map(sorbent_mode_mapping)
            df["heater_on_label"] = df["heater_on"].astype(int)
            df["sorbent_saturated_label"] = df["sorbent_saturated"].astype(int)

            df[["sorbent_mode", "sorbent_mode_label", "heater_on_label", "sorbent_saturated_label"]].head()
            """
        ),
        md_cell(
            """
            ## 7. Colonnes D'Entree Proposees

            **Objectif**
            Definir explicitement la table des features de reference pour la phase de benchmark.

            **Resultat attendu**
            Avoir une liste de colonnes stable et auditable.
            """
        ),
        code_cell(
            """
            feature_columns = [
                "temp_air_c",
                "hr_pct",
                "solar_wm2",
                "pv_voltage",
                "temp_collector_c",
                "temp_cond_c",
                "delta_hr_sorbent",
                "reservoir_level_pct",
                "soc_battery_pct",
                "dew_point_c",
                "humidity_ratio_gkg",
                "hour_sin",
                "hour_cos",
                "day_sin",
                "day_cos",
                "thermal_lift_c",
                "collector_gain_c",
                "is_daylight",
                "high_humidity_flag",
                "battery_stress_flag",
                "reservoir_high_flag",
            ]

            target_columns = [
                "vcrc_state",
                "sorbent_mode_label",
                "heater_on_label",
                "sorbent_saturated_label",
            ]

            pd.DataFrame(
                {
                    "feature_columns": pd.Series(feature_columns),
                    "target_columns": pd.Series(target_columns),
                }
            )
            """
        ),
        md_cell(
            """
            ## 8. Partition Sans Fuite

            **Objectif**
            Construire une separation `train / validation / test` par blocs temporels.

            **Resultat attendu**
            Eviter qu'un modele voie indirectement le futur pendant l'apprentissage.
            """
        ),
        code_cell(
            """
            df = df.sort_values(["city_id", "day_index", "hour"]).reset_index(drop=True)

            train_mask = df["day_index"] < 255
            valid_mask = (df["day_index"] >= 255) & (df["day_index"] < 310)
            test_mask = df["day_index"] >= 310

            split_summary = pd.DataFrame(
                {
                    "split": ["train", "validation", "test"],
                    "rows": [int(train_mask.sum()), int(valid_mask.sum()), int(test_mask.sum())],
                    "day_index_min": [
                        int(df.loc[train_mask, "day_index"].min()),
                        int(df.loc[valid_mask, "day_index"].min()),
                        int(df.loc[test_mask, "day_index"].min()),
                    ],
                    "day_index_max": [
                        int(df.loc[train_mask, "day_index"].max()),
                        int(df.loc[valid_mask, "day_index"].max()),
                        int(df.loc[test_mask, "day_index"].max()),
                    ],
                }
            )

            split_summary
            """
        ),
        md_cell(
            """
            ## 9. Export Des Jeux Prepares

            **Objectif**
            Sauvegarder des tables reutilisables pour les notebooks d'entrainement.

            **Resultat attendu**
            Produire des fichiers CSV clairs, versionnables et lisibles sans code supplementaire.
            """
        ),
        code_cell(
            """
            prepared_df = df[["city_id", "day_index", "hour", *feature_columns, *target_columns]].copy()

            train_df = prepared_df.loc[train_mask].copy()
            valid_df = prepared_df.loc[valid_mask].copy()
            test_df = prepared_df.loc[test_mask].copy()

            prepared_path = OUTPUT_DIR / "training_dataset_prepared.csv"
            train_path = OUTPUT_DIR / "train_split.csv"
            valid_path = OUTPUT_DIR / "validation_split.csv"
            test_path = OUTPUT_DIR / "test_split.csv"

            prepared_df.to_csv(prepared_path, index=False)
            train_df.to_csv(train_path, index=False)
            valid_df.to_csv(valid_path, index=False)
            test_df.to_csv(test_path, index=False)

            pd.DataFrame(
                {
                    "file": [prepared_path.name, train_path.name, valid_path.name, test_path.name],
                    "rows": [len(prepared_df), len(train_df), len(valid_df), len(test_df)],
                }
            )
            """
        ),
        md_cell(
            """
            ## 10. Regles Pour Le Notebook D'Entrainement

            **Objectif**
            Fixer les bonnes pratiques pour la prochaine etape de benchmark de modeles.

            **Resultat attendu**
            Une ligne directrice simple avant d'ecrire le notebook d'entrainement.
            """
        ),
        code_cell(
            """
            training_guidelines = [
                "Comparer plusieurs modeles sur exactement les memes splits.",
                "Faire le fit des scalers et encodeurs uniquement sur le train.",
                "Conserver validation pour le choix des hyperparametres, test pour l'evaluation finale.",
                "Reporter precision, recall, F1 et matrice de confusion par cible.",
                "Garder un suivi separe des cas extremes pour verifier la robustesse.",
            ]

            pd.DataFrame({"guideline": training_guidelines})
            """
        ),
    ]
    return notebook(cells)


def build_training_notebook() -> dict[str, object]:
    cells = [
        md_cell(
            """
            # Entrainement Et Benchmark Des Modeles AQUA-ATMOS

            Ce notebook compare plusieurs modeles sur les memes splits et les memes metriques, sans fuite de pretraitement.
            """
        ),
        md_cell(
            """
            ## 1. Chargement Des Splits

            **Objectif**
            Charger les jeux `train`, `validation` et `test` prepares au notebook precedent.

            **Resultat attendu**
            Disposer de trois jeux alignes et prets pour un benchmark reproductible.
            """
        ),
        code_cell(
            """
            from pathlib import Path

            import numpy as np
            import pandas as pd

            try:
                from IPython.display import display
            except Exception:
                def display(value):
                    print(value)

            PROJECT_ROOT = Path.cwd().resolve()
            if PROJECT_ROOT.name == "notebooks":
                PROJECT_ROOT = PROJECT_ROOT.parent

            DATA_DIR = PROJECT_ROOT / "data" / "processed"
            MODEL_DIR = PROJECT_ROOT / "data" / "modeling"
            MODEL_DIR.mkdir(parents=True, exist_ok=True)

            train_df = pd.read_csv(DATA_DIR / "train_split.csv")
            valid_df = pd.read_csv(DATA_DIR / "validation_split.csv")
            test_df = pd.read_csv(DATA_DIR / "test_split.csv")

            train_df.shape, valid_df.shape, test_df.shape
            """
        ),
        md_cell(
            """
            ## 2. Definition Des Features Et Des Cibles

            **Objectif**
            Declarer explicitement les colonnes d'entree et les cibles du benchmark.

            **Resultat attendu**
            Eviter toute ambiguite entre les modeles compares.
            """
        ),
        code_cell(
            """
            feature_columns = [
                "city_id",
                "hour",
                "temp_air_c",
                "hr_pct",
                "solar_wm2",
                "pv_voltage",
                "temp_collector_c",
                "temp_cond_c",
                "delta_hr_sorbent",
                "reservoir_level_pct",
                "soc_battery_pct",
                "dew_point_c",
                "humidity_ratio_gkg",
                "hour_sin",
                "hour_cos",
                "day_sin",
                "day_cos",
                "thermal_lift_c",
                "collector_gain_c",
                "is_daylight",
                "high_humidity_flag",
                "battery_stress_flag",
                "reservoir_high_flag",
            ]

            target_columns = [
                "vcrc_state",
                "sorbent_mode_label",
                "heater_on_label",
                "sorbent_saturated_label",
            ]

            categorical_features = ["city_id"]
            numeric_features = [column for column in feature_columns if column not in categorical_features]

            pd.DataFrame(
                {
                    "feature_columns": pd.Series(feature_columns),
                    "target_columns": pd.Series(target_columns),
                }
            )
            """
        ),
        md_cell(
            """
            ## 3. Baselines Et Pipelines

            **Objectif**
            Definir un ensemble minimal mais serieux de modeles a comparer.

            **Resultat attendu**
            Avoir des pipelines homogenes et reutilisables pour chaque cible.
            """
        ),
        code_cell(
            """
            from sklearn.compose import ColumnTransformer
            from sklearn.dummy import DummyClassifier
            from sklearn.ensemble import HistGradientBoostingClassifier, RandomForestClassifier
            from sklearn.impute import SimpleImputer
            from sklearn.linear_model import LogisticRegression
            from sklearn.pipeline import Pipeline
            from sklearn.preprocessing import OneHotEncoder, StandardScaler


            def make_preprocessor(scale_numeric: bool) -> ColumnTransformer:
                numeric_steps = [("imputer", SimpleImputer(strategy="median"))]
                if scale_numeric:
                    numeric_steps.append(("scaler", StandardScaler()))

                categorical_transformer = Pipeline(
                    steps=[
                        ("imputer", SimpleImputer(strategy="most_frequent")),
                        ("encoder", OneHotEncoder(handle_unknown="ignore")),
                    ]
                )

                return ColumnTransformer(
                    transformers=[
                        ("numeric", Pipeline(steps=numeric_steps), numeric_features),
                        ("categorical", categorical_transformer, categorical_features),
                    ]
                )


            model_factories = {
                "dummy_most_frequent": lambda: DummyClassifier(strategy="most_frequent"),
                "logistic_regression": lambda: LogisticRegression(max_iter=2000, class_weight="balanced"),
                "random_forest": lambda: RandomForestClassifier(
                    n_estimators=120,
                    max_depth=8,
                    min_samples_leaf=2,
                    random_state=42,
                    n_jobs=-1,
                    class_weight="balanced_subsample",
                ),
                "hist_gradient_boosting": lambda: HistGradientBoostingClassifier(
                    learning_rate=0.08,
                    max_depth=6,
                    max_iter=120,
                    random_state=42,
                ),
            }


            def make_pipeline(model_name: str) -> Pipeline:
                estimator = model_factories[model_name]()
                scale_numeric = model_name == "logistic_regression"
                return Pipeline(
                    steps=[
                        ("preprocessor", make_preprocessor(scale_numeric=scale_numeric)),
                        ("model", estimator),
                    ]
                )
            """
        ),
        md_cell(
            """
            ## 4. Metriques Et Cas Extemes

            **Objectif**
            Utiliser les memes metriques sur chaque cible et suivre separement les cas difficiles.

            **Resultat attendu**
            Pouvoir comparer les modeles sans se limiter a l'accuracy globale.
            """
        ),
        code_cell(
            """
            from sklearn.metrics import accuracy_score, balanced_accuracy_score, f1_score, precision_score, recall_score


            X_train = train_df[feature_columns].copy()
            X_valid = valid_df[feature_columns].copy()
            X_test = test_df[feature_columns].copy()

            y_train = {target: train_df[target].copy() for target in target_columns}
            y_valid = {target: valid_df[target].copy() for target in target_columns}
            y_test = {target: test_df[target].copy() for target in target_columns}


            train_extreme_thresholds = {
                "temp_air_c_low": train_df["temp_air_c"].quantile(0.01),
                "temp_air_c_high": train_df["temp_air_c"].quantile(0.99),
                "hr_pct_high": train_df["hr_pct"].quantile(0.99),
                "solar_wm2_low_nonzero": train_df.loc[train_df["solar_wm2"] > 0, "solar_wm2"].quantile(0.05),
                "soc_battery_pct_low": train_df["soc_battery_pct"].quantile(0.05),
            }


            def build_extreme_mask(frame: pd.DataFrame) -> pd.Series:
                return (
                    (frame["temp_air_c"] <= train_extreme_thresholds["temp_air_c_low"])
                    | (frame["temp_air_c"] >= train_extreme_thresholds["temp_air_c_high"])
                    | (frame["hr_pct"] >= train_extreme_thresholds["hr_pct_high"])
                    | ((frame["solar_wm2"] > 0) & (frame["solar_wm2"] <= train_extreme_thresholds["solar_wm2_low_nonzero"]))
                    | (frame["soc_battery_pct"] <= train_extreme_thresholds["soc_battery_pct_low"])
                )


            extreme_masks = {
                "validation": build_extreme_mask(valid_df),
                "test": build_extreme_mask(test_df),
            }


            def classification_metrics(y_true: pd.Series, y_pred: np.ndarray) -> dict[str, float]:
                if len(pd.Series(y_true).unique()) == 1:
                    balanced_accuracy = float((pd.Series(y_true).to_numpy() == y_pred).mean())
                else:
                    balanced_accuracy = balanced_accuracy_score(y_true, y_pred)

                return {
                    "accuracy": accuracy_score(y_true, y_pred),
                    "balanced_accuracy": balanced_accuracy,
                    "precision_macro": precision_score(y_true, y_pred, average="macro", zero_division=0),
                    "recall_macro": recall_score(y_true, y_pred, average="macro", zero_division=0),
                    "f1_macro": f1_score(y_true, y_pred, average="macro", zero_division=0),
                }
            """
        ),
        md_cell(
            """
            ## 5. Benchmark Sur Validation

            **Objectif**
            Entrainer tous les modeles sur le train et les comparer sur validation.

            **Resultat attendu**
            Identifier un meilleur modele par cible avec un tableau clair des scores.
            """
        ),
        code_cell(
            """
            validation_rows = []
            fitted_models = {}

            for target_name in target_columns:
                fitted_models[target_name] = {}
                for model_name in model_factories:
                    pipeline = make_pipeline(model_name)
                    pipeline.fit(X_train, y_train[target_name])

                    y_valid_pred = pipeline.predict(X_valid)
                    metrics = classification_metrics(y_valid[target_name], y_valid_pred)

                    extreme_mask = extreme_masks["validation"]
                    extreme_metrics = classification_metrics(
                        y_valid[target_name].loc[extreme_mask],
                        y_valid_pred[extreme_mask.to_numpy()],
                    )

                    validation_rows.append(
                        {
                            "target": target_name,
                            "model": model_name,
                            **{f"validation_{name}": value for name, value in metrics.items()},
                            **{f"validation_extreme_{name}": value for name, value in extreme_metrics.items()},
                        }
                    )
                    fitted_models[target_name][model_name] = pipeline

            validation_results = pd.DataFrame(validation_rows).sort_values(
                ["target", "validation_f1_macro", "validation_balanced_accuracy"],
                ascending=[True, False, False],
            )

            display(validation_results)
            """
        ),
        md_cell(
            """
            ## 6. Selection Du Meilleur Modele Par Cible

            **Objectif**
            Choisir un seul modele par cible sur la base de la validation.

            **Resultat attendu**
            Avoir une selection explicite avant toute evaluation sur test.
            """
        ),
        code_cell(
            """
            best_models = (
                validation_results.sort_values(
                    ["target", "validation_f1_macro", "validation_balanced_accuracy"],
                    ascending=[True, False, False],
                )
                .groupby("target", as_index=False)
                .first()
                .rename(columns={"model": "selected_model"})
            )

            display(best_models[["target", "selected_model", "validation_f1_macro", "validation_balanced_accuracy"]])
            """
        ),
        md_cell(
            """
            ## 7. Evaluation Finale Sur Test

            **Objectif**
            Evaluer uniquement les modeles retenus sur le jeu de test.

            **Resultat attendu**
            Obtenir une estimation finale non biaisee des performances.
            """
        ),
        code_cell(
            """
            test_rows = []

            for row in best_models.itertuples(index=False):
                target_name = row.target
                model_name = row.selected_model
                pipeline = fitted_models[target_name][model_name]

                y_test_pred = pipeline.predict(X_test)
                metrics = classification_metrics(y_test[target_name], y_test_pred)

                extreme_mask = extreme_masks["test"]
                extreme_metrics = classification_metrics(
                    y_test[target_name].loc[extreme_mask],
                    y_test_pred[extreme_mask.to_numpy()],
                )

                test_rows.append(
                    {
                        "target": target_name,
                        "selected_model": model_name,
                        **{f"test_{name}": value for name, value in metrics.items()},
                        **{f"test_extreme_{name}": value for name, value in extreme_metrics.items()},
                    }
                )

            test_results = pd.DataFrame(test_rows).sort_values("target")
            display(test_results)
            """
        ),
        md_cell(
            """
            ## 8. Matrices De Confusion

            **Objectif**
            Qualifier les erreurs du meilleur modele sur chaque cible.

            **Resultat attendu**
            Voir clairement quelles classes sont confondues.
            """
        ),
        code_cell(
            """
            import matplotlib.pyplot as plt
            import seaborn as sns
            from sklearn.metrics import confusion_matrix

            fig, axes = plt.subplots(2, 2, figsize=(18, 14))
            axes = axes.ravel()

            for ax, row in zip(axes, best_models.itertuples(index=False)):
                target_name = row.target
                model_name = row.selected_model
                pipeline = fitted_models[target_name][model_name]
                y_pred = pipeline.predict(X_test)

                labels = sorted(y_test[target_name].unique().tolist())
                matrix = confusion_matrix(y_test[target_name], y_pred, labels=labels)
                sns.heatmap(matrix, annot=True, fmt="d", cmap="Blues", cbar=False, ax=ax)
                ax.set_title(f"{target_name} - {model_name}")
                ax.set_xlabel("Prediction")
                ax.set_ylabel("Verite")
                ax.set_xticklabels(labels)
                ax.set_yticklabels(labels)

            plt.tight_layout()
            plt.show()
            """
        ),
        md_cell(
            """
            ## 9. Export Des Resultats

            **Objectif**
            Sauvegarder les tableaux de benchmark pour les reutiliser dans un rapport ou un dashboard.

            **Resultat attendu**
            Obtenir des CSV de synthese lisibles hors notebook.
            """
        ),
        code_cell(
            """
            validation_path = MODEL_DIR / "benchmark_validation_results.csv"
            best_models_path = MODEL_DIR / "selected_models.csv"
            test_path = MODEL_DIR / "benchmark_test_results.csv"

            validation_results.to_csv(validation_path, index=False)
            best_models.to_csv(best_models_path, index=False)
            test_results.to_csv(test_path, index=False)

            pd.DataFrame(
                {
                    "file": [validation_path.name, best_models_path.name, test_path.name],
                    "rows": [len(validation_results), len(best_models), len(test_results)],
                }
            )
            """
        ),
        md_cell(
            """
            ## 10. Resume Final

            **Objectif**
            Resumer les decisions a retenir pour la suite du projet.

            **Resultat attendu**
            Produire une table courte pour guider l'industrialisation du meilleur pipeline.
            """
        ),
        code_cell(
            """
            final_summary = best_models.merge(test_results, on="target", how="left")
            display(
                final_summary[
                    [
                        "target",
                        "selected_model_x",
                        "validation_f1_macro",
                        "validation_balanced_accuracy",
                        "test_f1_macro",
                        "test_balanced_accuracy",
                        "test_extreme_f1_macro",
                        "test_extreme_balanced_accuracy",
                    ]
                ]
                .rename(columns={"selected_model_x": "selected_model"})
                .sort_values("target")
            )
            """
        ),
    ]
    return notebook(cells)


def main() -> None:
    write_notebook(NOTEBOOKS_DIR / "02_visualisation_climat_et_synthetique.ipynb", build_visualization_notebook())
    write_notebook(NOTEBOOKS_DIR / "03_pretraitement_pour_entrainement.ipynb", build_preprocessing_notebook())
    write_notebook(NOTEBOOKS_DIR / "04_entrainement_et_benchmark_modeles.ipynb", build_training_notebook())


if __name__ == "__main__":
    main()
