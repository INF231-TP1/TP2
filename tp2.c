#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include "tp2.h"

#define MAX 100

int lireEntier(const char* message, int min, int max) {
    char buffer[100];
    long valeurLong;
    char *endptr;
    
    do {
        printf("%s", message);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Erreur de lecture.\n");
            continue;
        }
        
        // Supprimer le saut de ligne
        buffer[strcspn(buffer, "\n")] = '\0';
        
        // Convertir en long
        errno = 0;
        valeurLong = strtol(buffer, &endptr, 10);
        
        // Vérifications
        if (endptr == buffer) {
            printf("Erreur: Veuillez entrer un nombre entier valide.\n");
        } else if (*endptr != '\0') {
            printf("Erreur: Caractères supplémentaires non autorisés.\n");
        } else if (errno == ERANGE || valeurLong < min || valeurLong > max) {
            printf("Erreur: La valeur doit être comprise entre %d et %d (valeur saisie: %ld).\n", min, max, valeurLong);
        } else {
            return (int)valeurLong;
        }
    } while (1);
}

ListeSChainee ajoutElementSC(ListeSChainee t){
    int v = lireEntier("Entrez l'entier à ajouter: ", 0, MAX);
    ListeSChainee nouveau = (ListeSChainee) malloc(sizeof(ListeSChainee));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return t;
    }
    nouveau->val = v;
    nouveau->next = NULL;
    if (t == NULL) {
        return nouveau;
    }
    if (t->val >= v) {
        nouveau->next = t;
        return nouveau;
    }
    ListeSChainee courant = t;
    while (courant->next != NULL && courant->next->val < v) {
        courant = courant->next;
    }
    nouveau->next = courant->next;
    courant->next = nouveau;
    return t;
}

ListeDChainee ajoutElementDC(ListeDChainee t){
    int v = lireEntier("Entrez l'entier à ajouter: ", 0, MAX);
    ListeDChainee nouveau = (ListeDChainee) malloc(sizeof(ListeDChainee));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return t;
    }
    nouveau->val = v;
    nouveau->prev = NULL;
    nouveau->next = NULL;
    if (t == NULL) {
        return nouveau;
    }
    if (t->val >= v) {
        nouveau->next = t;
        t->prev = nouveau;
        return nouveau;
    }
    ListeDChainee courant = t;
    while (courant->next != NULL && courant->next->val < v) {
        courant = courant->next;
    }
    nouveau->next = courant->next;
    nouveau->prev = courant;
        if (courant->next != NULL) {
        courant->next->prev = nouveau;
    }
    courant->next = nouveau;
    return t;
}

ListeSChainee suppOccurenceSC(ListeSChainee t){
    int v = lireEntier("Entrez l'entier à supprimer: ", 0, MAX);
    ListeSChainee courant = t;
    ListeSChainee precedent = NULL;
    ListeSChainee aSupprimer;
    int suppressions = 0;
    while (courant != NULL) {
        if (courant->val == v) {
            aSupprimer = courant;
            if (precedent == NULL) {
                t = courant->next;
            } else {
                precedent->next = courant->next;
            }
            courant = courant->next;
            free(aSupprimer);
            suppressions++;
        } else {
            precedent = courant;
            courant = courant->next;
        }
    }
    if (suppressions > 0) {
        printf("%d occurrence(s) supprimée(s) avec succès !\n", suppressions);
    } else {
        printf("Aucune occurrence trouvée.\n");
    }
    return t;
}

ListeDChainee suppOccurenceDC(ListeDChainee t){
    int v = lireEntier("Entrez l'entier à supprimer: ", 0, MAX);
    ListeDChainee courant = t;
    ListeDChainee aSupprimer;
    int suppressions = 0;
    while (courant != NULL) {
        if (courant->val == v) {
            aSupprimer = courant;
            if (courant->prev == NULL) {
                t = courant->next;
                if (t != NULL) {
                    t->prev = NULL;
                }
            } else {
                courant->prev->next = courant->next;
            }
            if (courant->next != NULL) {
                courant->next->prev = courant->prev;
            }
            courant = courant->next;
            free(aSupprimer);
            suppressions++;
        } else {
            courant = courant->next;
        }
    }
    if (suppressions > 0) {
        printf("%d occurrence(s) supprimée(s) avec succès !\n", suppressions);
    } else {
        printf("Aucune occurrence trouvée.\n");
    }
    return t;
}

void affichageSC(ListeSChainee t){
    ListeSChainee l = t;
    if (l == NULL) {
        printf("Liste vide\n");
    } else {
        while (l != NULL) {
            printf("\"%d\"  ", l->val);
            l = l->next;         
        }
        printf("\n");
    }
}

void affichageDC(ListeDChainee t){
    ListeDChainee l = t;
    if (l == NULL) {
        printf("Liste vide\n");
    } else {
        while (l != NULL) {
            printf("\"%d\"  ", l->val);
            l = l->next;         
        }
        printf("\n");
    }
}

void affichageSCC(ListeSChainee t){
    if (t == NULL) {
        printf("Liste vide\n");
        return;
    }
    ListeSChainee l = t;
    printf("\"%d\"  ", l->val);
    l = l->next;
    while (l != t) {
        printf("\"%d\"  ", l->val);
        l = l->next;
    }
    printf("\n");
}

void affichageDCC(ListeDChainee t){
    if (t == NULL) {
        printf("Liste vide\n");
        return;
    }
    ListeDChainee l = t;
    printf("\"%d\"  ", l->val);
    l = l->next;
    while (l != t) {
        printf("\"%d\"  ", l->val);
        l = l->next;
    }
    printf("\n");
}

ListeSChainee ajoutTeteSCC(ListeSChainee t){
    int v = lireEntier("Entrez l'entier à ajouter: ", 0, MAX);
    ListeSChainee m = (ListeSChainee) malloc (sizeof(ListeSChainee));
    if(m == NULL){
        printf("Erreur d'allocation de mémoire\n");
        return t;
    }
    m->val = v;
    if(t == NULL){
        m->next = m;
        return m;
    }
    ListeSChainee last = t;
    while(last->next != t){
        last = last->next;
    }
    m->next = t;    
    last->next = m;
    return m;
}

ListeSChainee ajoutQueueSCC(ListeSChainee t){
    int v = lireEntier("Entrez l'entier à ajouter: ", 0, MAX);
    ListeSChainee m = (ListeSChainee) malloc (sizeof(ListeSChainee));
    if(m == NULL){
        printf("Erreur d'allocation de mémoire\n");
        return t;
    }
    m->val = v;
    if(t == NULL){
        m->next = m;
        return m;
    }
    ListeSChainee last = t;
    while (last->next != t) {
        last = last->next;
    }
    m->next = t;
    last->next = m;
    return t;
}

ListeDChainee ajoutTeteDCC(ListeDChainee t){
    int v = lireEntier("Entrez l'entier à ajouter: ", 0, MAX);
    ListeDChainee m = (ListeDChainee) malloc (sizeof(ListeDChainee));
    if(m == NULL){
        printf("Erreur d'allocation de mémoire\n");
        return t;
    }
    m->val = v;
    if(t == NULL){
        m->next = m;
        m->prev = m;
        return m;
    }
    ListeDChainee last = t->prev;
    m->next = t;
    m->prev = last;
    t->prev = m;
    last->next = m;
    return m;
}

ListeDChainee ajoutQueueDCC(ListeDChainee t){
    int v = lireEntier("Entrez l'entier à ajouter: ", 0, MAX);
    ListeDChainee m = (ListeDChainee) malloc (sizeof(ListeDChainee));
    if(m == NULL){
        printf("Erreur d'allocation de mémoire\n");
        return t;
    }
    m->val = v;
    if(t == NULL){
        m->next = m;
        m->prev = m;
        return m;
    }
    ListeDChainee last = t->prev;
    m->next = t;
    m->prev = last;
    last->next = m;
    t->prev = m;
    return t;
}
