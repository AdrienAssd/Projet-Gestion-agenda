#include "cells.h"
#include "lists.h"

// Fonction qui permet de créer une cellule avec comme arguments : sa valeur et son nombre de niveaux
t_d_cell * createCell(int valeur , int niveau){    
    t_d_cell *newcell = (t_d_cell *)malloc(sizeof(t_d_cell));    
    newcell->value = valeur;
    newcell->niveau = niveau;
    newcell->next = (t_d_cell**)malloc(niveau*sizeof (t_d_cell*));
    return newcell;
}

// Fonction récupérant les informations de l'utilisateur
t_d_cell * user_choice_cell(){
    int valeur, nbNiveau;
    t_d_cell *newcell;
    do{
        printf("Veuillez saisir une valeur entière et strictement supérieure 0 : ");
        scanf("%d", &valeur);
        if (valeur <= 0) {
            printf("La valeur doit être strictement supérieure à 0. Réessayez.\n");
        }
    } while (valeur <= 0);
    do{
        printf("Veuillez saisir le nombre de niveaux (entier et strictement supérieure 0) : ");
        scanf("%d", &nbNiveau);
        if (nbNiveau <= 0) {
            printf("La valeur doit être strictement supérieure à 0. Réessayez.\n");
        }
    } while (valeur <= 0);
    newcell = createCell(valeur, nbNiveau);
    return newcell;
}

