# Rapport de Contributions - Azambou Marthe Nefertyti (23V2357)

## Étudiante
**Azambou Marthe Nefertyti**  
**Matricule :** 23V2357  
**Projet :** TP2 - Manipulation de Listes Chaînées  
**Cours :** INF 231 - Structure de Données II

---

## 📝 Résumé des Contributions

Ce document détaille mes contributions personnelles au projet TP2, qui ont porté sur l'implémentation complète des fonctions de manipulation des **listes doublement chaînées circulaires**. J'ai développé les fonctions d'insertion et d'affichage pour ce type spécifique de structure de données.

### Fichiers Modifiés/Créés
- `tp2.h` : Déclaration des en-têtes de fonctions
- `tp2.c` : Implémentation des fonctions
- `doc/` : Création de ce fichier de rapport

---

## 🔧 Détails Techniques des Contributions

### 1. Déclaration des Fonctions (`tp2.h`)
J'ai défini les en-têtes des fonctions suivantes pour la manipulation des listes doublement chaînées circulaires :
- **`ajoutTeteDCC`** : Insertion d'un élément en tête de liste doublement chaînée circulaire
- **`ajoutQueueDCC`** : Insertion d'un élément en queue de liste doublement chaînée circulaire  
- **`affichageDCC`** : Affichage du contenu des listes doublement chaînées circulaires

### 2. Implémentation des Fonctions (`tp2.c`)

#### Fonctions pour Listes Doublement Chaînées Circulaires
- **`ajoutTeteDCC`** : 
  - Implémentation de l'insertion en tête d'une liste doublement chaînée circulaire
  - Gestion correcte des pointeurs précédent/suivant pour maintenir la circularité
  - Prise en compte des cas particuliers (liste vide, un seul élément)

- **`ajoutQueueDCC`** :
  - Implémentation de l'insertion en queue d'une liste doublement chaînée circulaire  
  - Maintien de la structure circulaire après insertion
  - Optimisation grâce à l'accès direct au dernier élément via les liens circulaires

- **`affichageDCC`** :
  - Fonction de parcours et d'affichage des listes doublement chaînées circulaires
  - Détection de la fin de parcours grâce à la circularité
  - Affichage clair et structuré des éléments

---

## ✅ Fonctionnalités Implémentées et Vérifiables

Les fonctionnalités suivantes, implémentées dans le cadre de mes contributions, sont désormais opérationnelles :

1. **Insertion en tête** dans une liste doublement chaînée circulaire
2. **Insertion en queue** dans une liste doublement chaînée circulaire  
3. **Affichage complet** des listes doublement chaînées circulaires
4. **Gestion correcte de la circularité** dans toutes les opérations

---

## 🔄 Particularités Techniques des Listes Doublement Chaînées Circulaires

### Gestion des Pointeurs
- **Maintenance des liens bidirectionnels** entre tous les éléments
- **Préservation de la circularité** : le dernier élément pointe vers le premier et vice-versa
- **Gestion optimisée** des insertions grâce à l'accès direct aux extrémités

### Cas Spéciaux Implémentés
- **Liste vide** : création du premier élément avec circularité sur lui-même
- **Liste à un élément** : maintien des liens cohérents (précédent et suivant pointent vers le même élément)
- **Insertions multiples** : préservation de l'intégrité structurelle après plusieurs opérations

---

## 🌟 Contexte Pédagogique

Ce travail a été réalisé dans le cadre du cours **INF 231 - Structure de Données II** à l'Université de Yaoundé I. Il m'a permis d'approfondir ma compréhension des structures de données complexes, particulièrement :

- La manipulation avancée des pointeurs dans des structures bidirectionnelles
- La gestion de la circularité dans les listes chaînées
- L'implémentation d'algorithmes d'insertion optimisés pour les structures circulaires
- La résolution des problèmes spécifiques aux listes doublement chaînées circulaires

Cette expérience m'a également permis de développer mes compétences en programmation C et en conception d'algorithmes pour les structures de données.