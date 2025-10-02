#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp2.h"

int main() {
    printf("\t\tBIENVENUE DANS LE MENU PRINCIPAL\n");
    char input[100];
    char n;
    ListeSChainee t1 = NULL;
    ListeDChainee t2 = NULL;
    
    do {
        printf("0- Quitter\n1- Effectuez des opérations dans une liste simplement chaînée non circulaire\n2- Effectuez des opérations dans une liste simplement chaînée circulaire\n3- Effectuez des opérations dans une liste doublement chaînée non circulaire\n4- Effectuez des opérations dans une liste doublement chaînée circulaire\n");
        printf("Entrez le chiffre correspondant à votre choix : ");
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        
        if (strlen(input) > 2 || (strlen(input) == 1 && input[0] == '\n')) {
            printf("Erreur ! Veuillez entrer un seul caractère.\n");
            continue;
        }
        
        n = input[0];
        
        switch(n) {

            case '1':
                do {
                    printf("0- Quitter\n1- Ajouter un élément dans la liste\n2- Lire un élément et supprimer toutes les occurences dans la liste\n3- Afficher la liste\n");
                    printf("Entrez le chiffre correspondant à votre choix : ");
        
                    if (fgets(input, sizeof(input), stdin) == NULL) {
                        break;
                    }
        
                    if (strlen(input) > 2 || (strlen(input) == 1 && input[0] == '\n')) {
                        printf("Erreur ! Veuillez entrer un seul caractère.\n");
                        continue;
                    }
        
                    n = input[0];
                        
                    switch(n) {
                        case '1': t1 = ajoutElementSC(t1); break;
                        case '2': t1 = suppOccurenceSC(t1); break;
                        case '3': affichageSC(t1); break;
                        case '0': printf("Au Revoir !\n"); break;
                        default: printf("Erreur ! Veuillez choisir une option valable.\n");
                    }
                    printf("\n");
                } while(n != '0');
            break;

            case '2':
                do {
                    printf("0- Quitter\n1- Ajouter un élément en tête de la liste\n2- Ajouter un élément en queue de la liste\n3- Afficher la liste\n");
                    printf("Entrez le chiffre correspondant à votre choix : ");
        
                    if (fgets(input, sizeof(input), stdin) == NULL) {
                        break;
                    }
        
                    if (strlen(input) > 2 || (strlen(input) == 1 && input[0] == '\n')) {
                        printf("Erreur ! Veuillez entrer un seul caractère.\n");
                        continue;
                    }
        
                    n = input[0];
                        
                    switch(n) {
                        case '1': t1 = ajoutTeteSCC(t1); break;
                        case '2': t1 = ajoutQueueSCC(t1); break;
                        case '3': affichageSCC(t1); break;
                        case '0': printf("Au Revoir !\n"); break;
                        default: printf("Erreur ! Veuillez choisir une option valable.\n");
                    }
                    printf("\n");
                } while(n != '0');
            break;

            case '3':
                do {
                    printf("0- Quitter\n1- Ajouter un élément dans la liste\n2- Lire un élément et supprimer toutes les occurences dans la liste\n3- Afficher la liste\n");
                    printf("Entrez le chiffre correspondant à votre choix : ");
        
                    if (fgets(input, sizeof(input), stdin) == NULL) {
                        break;
                    }
        
                    if (strlen(input) > 2 || (strlen(input) == 1 && input[0] == '\n')) {
                        printf("Erreur ! Veuillez entrer un seul caractère.\n");
                        continue;
                    }
        
                    n = input[0];
                        
                    switch(n) {
                        case '1': t2 = ajoutElementDC(t2); break;
                        case '2': t2 = suppOccurenceDC(t2); break;
                        case '3': affichageDC(t2); break;
                        case '0': printf("Au Revoir !\n"); break;
                        default: printf("Erreur ! Veuillez choisir une option valable.\n");
                    }
                    printf("\n");
                } while(n != '0');
            break;
            
            case '4':
                do {
                    printf("0- Quitter\n1- Ajouter un élément en tête de la liste\n2- Ajouter un élément en queue de la liste\n3- Afficher la liste\n");
                    printf("Entrez le chiffre correspondant à votre choix : ");
        
                    if (fgets(input, sizeof(input), stdin) == NULL) {
                        break;
                    }
        
                    if (strlen(input) > 2 || (strlen(input) == 1 && input[0] == '\n')) {
                        printf("Erreur ! Veuillez entrer un seul caractère.\n");
                        continue;
                    }
        
                    n = input[0];
                        
                    switch(n) {
                        case '1': t2 = ajoutTeteDCC(t2); break;
                        case '2': t2 = ajoutQueueDCC(t2); break;
                        case '3': affichageDCC(t2); break;
                        case '0': printf("Au Revoir !\n"); break;
                        default: printf("Erreur ! Veuillez choisir une option valable.\n");
                    }
                    printf("\n");
                } while(n != '0');
            break;

            case '0': printf("Au Revoir !\n"); break;
            default: printf("Erreur ! Veuillez choisir une option valable.\n");
        }
        printf("\n");
    } while(n != '0');
    
    return 0;
}
