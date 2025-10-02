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
    int v = lireEntier("Entrez l'entier à ajouter", 0, MAX);
    ListeSChainee l = t;
    ListeSChainee m = (ListeSChainee) malloc (sizeof(ListeSChainee));
    if(l == NULL) {
        m->val = v;
        m->next = NULL;
        return m;
    }
    while(l->next != NULL && l->next->val < v){
        if(l->next->next == NULL || l->next->next->val > v){
            m->val = v;
            m->next = l->next->next;
            l->next->next = m;
            return t;
        }
        l = l->next;
    }
    m->val = v;
    m->next = l;
    return m;
}

ListeDChainee ajoutElementDC(ListeDChainee t){
    int v = lireEntier("Entrez l'entier à ajouter", 0, MAX);
    ListeDChainee l = t;
    ListeDChainee m = (ListeDChainee) malloc (sizeof(ListeDChainee));
    if(l == NULL) {
        m->prev = NULL;
        m->val = v;
        m->next = NULL;
        return m;
    }
    while(l->next != NULL && l->next->val < v){
        if(l->next->next == NULL || l->next->next->val > v){
            m->prev = l->next;
            m->val = v;
            m->next = l->next->next;
            l->next->next = m;
            return t;
        }
        l = l->next;
    }
    m->prev = NULL;
    m->val = v;
    m->next = l;
    return m;
}

ListeSChainee suppOccurenceSC(ListeSChainee t){
    int v = lireEntier("Entrez l'entier à supprimer", 0, MAX);
    ListeSChainee l = t, m;
    while(l != NULL){
        if(l->val == v){
            m = l;
            l = l->next;
            free(m);
            continue;
        }
        l = l->next;
    }
    printf("Opérations effectuées avec succes !");
    return t;
}

ListeDChainee suppOccurenceDC(ListeDChainee t){
    int v = lireEntier("Entrez l'entier à supprimer", 0, MAX);
    ListeDChainee l = t, m;
    while(l != NULL){
        if(l->val == v){
            m = l;
            l = l->next;
            free(m);
            continue;
        }
        l = l->next;
    }
    printf("Opérations effectuées avec succes !");
    return t;
}

void affichageSC(ListeSChainee t){
	ListeSChainee l=t;
	if(l==NULL){
		printf("Liste vide\n");
	}else{
		while(l!=NULL){
			printf("\"%d\"  ",l->val);
			l = l->next;         
		}
	}
}

void affichageDC(ListeDChainee t){
	ListeDChainee l=t;
	if(l==NULL){
		printf("Liste vide\n");
	}else{
		while(l!=NULL){
			printf("\"%d\"  ",l->val);
			l = l->next;         
		}
	}
}

void affichageSCC(ListeSChaineeC t){
	ListeSChaineeC l=t;
	if(l==NULL){
		printf("Liste vide\n");
	}else{
		while(l->indice > l->next->indice){
			printf("\"%d\"  ",l->val);
			l = l->next;
		}
        printf("\"%d\" ",l->val);
	}
}

void affichageDCC(ListeDChaineeC t){
	ListeDChaineeC l=t;
	if(l==NULL){
		printf("Liste vide\n");
	}else{
		while(l->indice > l->next->indice){
			printf("\"%d\"  ",l->val);
			l = l->next;
		}
        printf("\"%d\" ",l->val);
	}
}

ListeSChaineeC ajoutTeteSCC(ListeSChaineeC t){
    int v = lireEntier("Entrez l'entier à ajouter", 0, MAX);
    ListeSChaineeC l = t;
    ListeSChaineeC m = (ListeSChaineeC) malloc (sizeof(ListeSChaineeC));
    if(l == NULL){
        m->indice = 1;
        m->val = v;
        m->next = m;
        return m;
    }
    while(l->indice > l->next->indice){
        if(l->next->indice < l->next->next->indice){
            ListeSChaineeC p = l->next->next;
            m->indice = l->next->next->indice + 1;
            m->val = v;
            l->next->next = m;
            m->next = p;
            return t;
        }
        l = l->next;
    }
    m->indice = 2;
    m->val = v;
    m->next = l;
    l->next = m;
    return t;
}

ListeDChaineeC ajoutTeteDCC(ListeDChaineeC t){
    int v = lireEntier("Entrez l'entier à ajouter", 0, MAX);
    ListeDChaineeC l = t;
    ListeDChaineeC m = (ListeDChaineeC) malloc (sizeof(ListeDChaineeC));
    if(l == NULL){
        m->indice = 1;
        m->prev = NULL;
        m->val = v;
        m->next = m;
        return m;
    }
    while(l->indice > l->next->indice){
        if(l->next->indice < l->next->next->indice){
            ListeDChaineeC p = l->next->next;
            m->indice = l->next->next->indice + 1;
            m->val = v;
            l->next->next = m;
            p->prev = m;
            m->prev = l->next;
            m->next = p;
            return t;
        }
        l = l->next;
    }
    m->indice = 2;
    m->val = v;
    m->next = l;
    l->next = m;
    return t;
}

ListeSChaineeC ajoutQueueSCC(ListeSChaineeC t){
    int v = lireEntier("Entrez l'entier à ajouter", 0, MAX);
    ListeSChaineeC l = t;
    ListeSChaineeC m = (ListeSChaineeC) malloc (sizeof(ListeSChaineeC));
    if(l == NULL){
        m->indice = 1;
        m->val = v;
        m->next = m;
        return m;
    }
    while(l->indice > l->next->indice){
        if(l->next->indice < l->next->next->indice){
            m->indice = l->next->indice - 1;
            m->val = v;
            m->next = l->next->next;
            l->next->next = m;
            return t;
        }
        l = l->next;
    }
    m->indice = 0;
    m->val = v;
    m->next = l;
    l->next = m;
    return t;
}

ListeDChaineeC ajoutQueueDCC(ListeDChaineeC t){
    int v = lireEntier("Entrez l'entier à ajouter", 0, MAX);
    ListeDChaineeC l = t;
    ListeDChaineeC m = (ListeDChaineeC) malloc (sizeof(ListeDChaineeC));
    if(l == NULL){
        m->indice = 1;
        m->val = v;
        m->prev = NULL;
        m->next = m;
        return m;
    }
    while(l->indice > l->next->indice){
        if(l->next->indice < l->next->next->indice){
            m->indice = l->next->indice - 1;
            m->val = v;
            l->next->next->prev = m;
            m->prev = l->next;
            m->next = l->next->next;
            l->next->next = m;
            return t;
        }
        l = l->next;
    }
    m->indice = 0;
    m->val = v;
    m->next = l;
    l->next = m;
    return t;
}
