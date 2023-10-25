#include "lists.h"
#include "cells.h"

t_d_list *createEmptyList(int niv_max)
{
    t_d_list *newlist = (t_d_list*)malloc(sizeof(t_d_list));
    newlist->niv_max = niv_max;
    newlist->head = (t_d_cell**)malloc(newlist->niv_max*sizeof(t_d_cell*));
    for(int i = 0 ; i < newlist->niv_max ; i++)
    {
        newlist->head[i] = NULL;
    }
    return newlist;
}


void addHeadList(t_d_list * list, t_d_cell * cell){
    for (int i = 0; i < cell->niveau; i++){
        if (list->head == NULL){
            list->head[i] = cell;
        }
        else{
            t_d_cell * temp;
            temp = cell;
            temp->next[i] = list->head[i];
            list->head[i] = temp;
        }
    }
}

void displayList(t_d_list list){
    t_d_cell * temp;
    for (int i = 0; i <list.niv_max; i++){
        temp = list.head[i];
        printf("[list head_%d @-]-->", i);
        while (temp != NULL){
            printf("[ %d|@-]-->", temp->value);
            temp = temp->next[i];
        }
        printf("NULL\n");
    }
    printf("\n");
}


t_d_list cellinlist(){
    int nbValeur, nbNiveau;
    t_d_list * list;
    t_d_cell * newcell;
    printf("combien de valeurs voulez-vous ?");
    scanf("%d", &nbValeur);
    printf("combien de niveaux voulez-vous ?");
    scanf("%d", &nbNiveau);
    list = createEmptyList(nbNiveau);
    for (int i = 0; i < nbValeur; i++){
        newcell = user_choice_cell();
        addHeadList(list, newcell);
        displayList(*list);
    }
    displayList(*list);
    return *list;
}
