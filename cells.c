#include "cells.h"

t_d_cell * createCell(int valeur , int niveau){
    t_d_cell *newcell = (t_d_cell *)malloc(sizeof(t_d_cell));
    newcell->value = valeur;
    newcell->next = (t_d_cell*)malloc(niveau*sizeof (t_d_cell));
    return newcell;
}


