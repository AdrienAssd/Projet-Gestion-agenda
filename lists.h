#ifndef PROJET_SDD_LISTS_H
#define PROJET_SDD_LISTS_H
#include <stdio.h>
#include <stdlib.h>
#include "cells.h"

typedef struct s_d_list
{
    int niv_max;
    t_d_cell **head;
} t_d_list;

t_d_list *createEmptyList(int niv_max);
void addHeadSortList(t_d_list * list, t_d_cell * cell);
void displayList(t_d_list list);
t_d_list cellinlist();
t_d_list createListNiv(int n);
#endif //PROJET_SDD_LISTS_H
