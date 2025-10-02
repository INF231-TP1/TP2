# Rapport de Contributions - Mbezele Zoa Danielle Naomi (24G2837)

## Étudiante
**Mbezele Zoa Danielle Naomi**  
**Matricule :** 24G2837  
**Projet :** TP2 - Manipulation de Listes Chaînées  
**Cours :** INF 231 - Structure de Données II

---

## 📝 Résumé des Contributions

Ce document détaille mes contributions personnelles au projet TP2, qui consistaient à définir les structures de données fondamentales et à implémenter les fonctions de manipulation pour les **listes simplement chaînées** et les **listes simplement chaînées circulaires**.

### Fichiers Modifiés/Créés
- `tp2.h` : Définition des structures.
- `tp2.c` : Implémentation des fonctions.
- `main.c` : Mise à jour du programme principal.
- `tp2.c` : Suppression des fonctions devenues inutiles.
- `doc/` : Création de ce dossier et du présent fichier de rapport.

---

## 🔧 Détails Techniques des Contributions

### 1. Définition des Structures de Données (`tp2.h`)
J'ai défini les quatre structures de base pour les listes dans le fichier d'en-tête `tp2.h` :
- **`ListeSChainee`** : Pour les listes simplement chaînées standard.
- **`ListeSChaineeC`** : Pour les listes simplement chaînées circulaires.
- **`ListeDChainee`** : Pour les listes doublement chaînées standard.
- **`ListeDChaineeC`** : Pour les listes doublement chaînées circulaires.

Ces structures servent de fondation à toutes les opérations de manipulation implémentées dans le projet:cite[6].

### 2. Implémentation des Fonctions (`tp2.c`)

#### Pour les Listes Simplement Chaînées (Standard et Circulaire)
- **`last`** : Retourne le dernier élément d'une liste simplement chaînée. Cette fonction est cruciale pour de nombreuses autres opérations, notamment l'ajout en fin de liste:cite[6].
- **`ajoutElementSC`** : Insère un élément dans une liste simplement chaînée **triée**, en maintenant l'ordre des éléments.
- **`suppOccurenceSC`** : Parcourt une liste simplement chaînée, lit un élément et supprime **toutes ses occurrences** dans la liste:cite[4].
- **`affichage`** et **`affichageC`** : Fonctions pour parcourir et afficher le contenu des listes simplement chaînées standards et circulaires:cite[4].
- **`ajoutTeteSCC`** et **`ajoutQueueSCC`** : Implémentation des fonctions d'insertion d'un élément en **tête** et en **queue** d'une liste simplement chaînée circulaire:cite[6].

### 3. Mise à jour du Programme Principal (`main.c`)
J'ai mis à jour le fichier `main.c` pour intégrer les nouvelles fonctions dans le menu interactif. Cela permet à l'utilisateur de tester toutes les fonctionnalités implémentées, notamment les opérations sur les listes simplement chaînées circulaires.

### 4. Nettoyage du Code (`tp2.c`)
J'ai procédé à la **suppression des fonctions devenues inutiles** dans le fichier `tp2.c` pour maintenir le code clair et éviter toute redondance.

### 5. Création de la Documentation
J'ai créé le dossier `doc/` et ce fichier markdown (`24G2837NaomiDanielle-MbezeleZoa.md`) pour consigner de manière précise et transparente l'étendue de mon travail.

---

## ✅ Fonctionnalités Vérifiables

Les fonctionnalités suivantes, implémentées dans le cadre de mes contributions, sont désormais opérationnelles et accessibles via le menu du programme :

1.  **Suppression de toutes les occurrences** d'un élément dans une liste simplement chaînée.
2.  **Insertion d'un élément** dans une liste simplement chaînée **triée**.
3.  **Insertion en tête et en queue** dans une liste simplement chaînée **circulaire**.
4.  Affichage correct des listes simplement chaînées standards et circulaires.

---

## 🌟 Contexte Pédagogique

Ce travail a été réalisé dans le cadre du cours **INF 231 - Structure de Données II**, et a permis une mise en pratique approfondie des concepts de base des structures de données linéaires, en particulier le fonctionnement des pointeurs, l'allocation dynamique de mémoire et la gestion des différents types de listes chaînées.