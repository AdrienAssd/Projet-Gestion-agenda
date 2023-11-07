#include "cells.h"
#include "lists.h"

t_d_cell * createCell(int valeur , int niveau){
    t_d_cell *newcell = (t_d_cell *)malloc(sizeof(t_d_cell));
    newcell->value = valeur;
    newcell->niveau = niveau;
    newcell->next = (t_d_cell**)malloc(niveau*sizeof (t_d_cell*));
    return newcell;
}

t_d_cell * user_choice_cell(){
    int valeur, nbNiveau;
    t_d_cell *newcell;
    printf("quelle valeur voulez-vous ? ");
    scanf("%d", &valeur);
    printf("combien de niveaux voulez-vous ? ");
    scanf("%d", &nbNiveau);
    newcell = createCell(valeur, nbNiveau);
    return newcell;
}

