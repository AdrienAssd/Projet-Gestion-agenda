#ifndef PROJET_SDD_CELLS_H
#define PROJET_SDD_CELLS_H
#include <stdio.h>
#include <stdlib.h>

// Structure de la cellule
typedef struct s_d_cell
{
    int value;
    int niveau;
    struct s_d_cell **next;
} t_d_cell;

// Prototypes des fonctions
t_d_cell * createCell(int valeur , int niveau);
t_d_cell * user_choice_cell();

#endif //PROJET_SDD_CELLS_H
