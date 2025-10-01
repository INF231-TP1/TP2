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

int LireMot(const char* message, char* chaine, size_t tailleChaine){
    char buffer[100];
    char *retourFgets;
    if(chaine==NULL || tailleChaine==0){
        return 0;
    }
    do{
        printf("%s",message);
        retourFgets = fgets(buffer, sizeof(buffer), stdin);
        if(retourFgets == NULL){
            printf("Erreur de lecture ou fin de fichier atteinte.\n");
            return 0;
        }
        buffer[strcspn(buffer,'\n')]='\0';
        if(buffer[0] == '\0'){
            printf("Erreur : La cahine ne peut pas etre vide.\n");
            continue;
        }
        char *pointeurEspace = strchr(buffer,' ');
        if(pointeurEspace != NULL){
            printf("Erreur : Les espaces ne sont pas autorises.\n");
            continue;
        }
        if(strlen(buffer) >= sizeof(buffer)-1){
            int caractere;
            printf("Attention : L'entree a ete tronquee. Vidage du tampon...\n");
            while((caractere=getchar()) != '\n' && caractere != EOF);
            continue;
        }
        if(strlen(buffer) >= tailleChaine){
            printf("Erreur : La chaine saisie est trop longue pour l'espace prevu.\n");
            continue;
        }
        strcpy(chaine, buffer);
        return 1;
    }while(1);
}

Liste init(){
    return NULL;
}

Liste last(Liste t){
    Liste l=t;
    if(l==NULL){
        printf("Liste vide");
        return NULL;
    }else{
        while(l->next!=NULL){
            l = l->next;
        }
    }
    return l;
}

Liste inserthead(Liste t, int v){
    Liste l = (Liste) malloc (sizeof(Liste));
    l->val = v;
    l->prev = NULL;
    l->next = t;
    t=l;
    return t;
}

Liste insertbottom(Liste t, int v){
    if(t==NULL){
        t=inserthead(t,v);
        return t;
    }
    Liste l,m;
    l=last(t);
    m=last(t);
    l->next= (Liste) malloc (sizeof(Liste));
    l->next->prev = m;
    l->next->next = NULL;
    l->next->val = v;
    return t;
}

Liste deletehead(Liste t){
    if(t==NULL){
        printf("Liste vide");
        return t;
    }else{
        Liste m=t;
        t=t->next;
        free(m);
        return t;
    }
}

Liste deletebottom(Liste t){
    Liste l = t;
    if(t==NULL){
        printf("Liste vide");
        return t;
    }else if(l->next==NULL){
        free(l);
        l=NULL;
        return l;
    }else{
        l=last(t)->prev;
        free(l->next);
        l->next=NULL;
        return t;
    }
}

Liste sortascending(Liste t){
    
}

Liste sortdescending(Liste t){
    
}
