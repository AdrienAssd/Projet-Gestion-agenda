#include <stdio.h>
#include "cells.h"

int main() {
    int nbValeur, nbNiveau;
    t_d_cell *newcell;
    printf("combien de valeurs voulez-vous ? ");
    scanf("%d", &nbValeur);
    printf("combien de niveaux voulez-vous ? ");
    scanf("%d", &nbNiveau);
    newcell = createCell(nbValeur, nbNiveau);


    return 0;
}
