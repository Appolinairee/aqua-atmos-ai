# Copilot Instructions - AQUA-ATMOS

Ce fichier definit les regles de generation de code pour Copilot dans ce depot.

Citation guide:
- L'honnetete dans les petites choses n'est pas une petite chose.
- Dieu est dans les details.

## 1) Source officielle du metier

Toutes les regles business sont documentees dans:
- docsq/BUSINESS_CONTEXT.md
- docsq/BUSINESS_RULES.md

Copilot ne doit pas inventer de nouvelles regles metier contradictoires.

## 2) Orientation Clean Code (Robert C. Martin)

Principes obligatoires:
- Le code doit se lire comme une prose technique claire.
- Une fonction fait une seule chose, la fait bien, et ne fait qu'elle.
- Un seul niveau d'abstraction par fonction.
- DRY: pas de duplication evitable.
- Simplicite d'abord: la logique simple laisse peu d'endroits aux bogues.

Noms:
- Choisir des noms revelateurs d'intention.
- Utiliser un mot unique par concept (get ou fetch, pas les deux selon les fichiers).
- Eviter la codification obscure et les jeux de mots.

Fonctions:
- Favoriser des fonctions courtes.
- Eviter les arguments booleens selecteurs.
- Preferer un argument (ou un objet de contexte) a de longues signatures.
- Separer commande et demande (Command/Query Separation).

Commentaires:
- Ne pas compenser un mauvais code par des commentaires.
- Ecrire du code explicite, puis commenter uniquement l'intention non evidente.
- Supprimer le code commente mort.

Gestion d'erreurs:
- Utiliser des exceptions, pas des codes d'erreur en cascade.
- Isoler le traitement d'erreurs pour ne pas masquer le flux nominal.
- Eviter `None`/`null` comme contrat implicite.

## 3) Architecture et frontieres

Separations attendues:
- logique metier pure dans src/aqua_atmos/*
- I/O et integration a la peripherie
- types partages dans types.py

Copilot doit limiter le couplage, eviter la navigation transitive, et reduire les interfaces exposees au strict necessaire.

## 4) TDD non negociable

Lois de travail:
1. Ecrire d'abord un test qui echoue.
2. Ecrire le minimum de code pour passer le test.
3. Refactoriser sans changer le comportement.

Ordre de realisation:
1. point de rosee
2. regles VCRC
3. regles sorbant
4. PWM
5. anomalies VCRC
6. anomalies sorbant
7. generateur synthetique
8. apprentissage en ligne
9. blend alpha
10. cycle complet
11. logger CSV

## 5) Qualite des tests (FIRST)

- Fast
- Independent
- Repeatable
- Self-validating
- Timely

Exigences minimales:
- couvrir explicitement les seuils limites (60, 70, 95, 20)
- ajouter un test de non-regression pour chaque bug corrige
- garder les tests lisibles et courts

## 6) Regles de suggestion Copilot

Quand Copilot propose du code, il doit:
- privilegier le code deterministe et testable
- eviter les dependances lourdes non justifiees
- preserver API publique et conventions du depot
- proposer les tests en meme temps que les changements de comportement
- refuser les heuristiques implicites non documentees

## 7) Hygiene continue (5S applique au code)

- Seiri (organisation): supprimer le superflu
- Seiton (ordre): ranger les modules de facon coherente
- Seiso (nettoyage): retirer duplication et code mort
- Seiketsu (standardiser): suivre conventions et formatage
- Shitsuke (discipline): maintenir ces pratiques a chaque PR
