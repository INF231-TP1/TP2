#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp2.h"

int main() {
    printf("\t\tBIENVENUE DANS LE MENU PRINCIPAL\n");
    char input[100];
    char n;
    
    do {
        printf("0- Quitter\n1- Lire un élément et supprimer toutes les occurences dans la liste\n2- Insertion d'un élément dans une liste simplement chaînée triée\n3- Insertion d'un élément dans une liste doublement chaînée triée\n4- Insertion en tête et en queue dans une liste simplement chaînée circulaire\n5- Insertion en tête et en queue dans une liste doublement chaînée circulaire\n");
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
            case '1': ; break;
            case '2': ; break;
            case '3': ; break;
            case '4': ; break;
            case '5': ; break;
            case '0': printf("Au Revoir !\n"); break;
            default: printf("Erreur ! Veuillez choisir une option valable.\n");
        }
        printf("\n");
    } while(n != '0');
    
    return 0;
}
