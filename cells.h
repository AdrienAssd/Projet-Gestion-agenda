#ifndef PROJET_SDD_CELLS_H
#define PROJET_SDD_CELLS_H
#include <stdio.h>
#include <stdlib.h>


typedef struct s_d_cell
{
    int value;
    struct s_d_cell *next;

} t_d_cell;


t_d_cell * createCell(int valeur , int niveau);

#endif //PROJET_SDD_CELLS_H
