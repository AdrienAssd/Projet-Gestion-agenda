#include "lists.h"
#include "cells.h"
#include <math.h>
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


void addHeadSortList(t_d_list * list, t_d_cell * cell){
    for (int i = 0; i < cell->niveau; i++){
        if (list->head == NULL){
            list->head[i] = cell;
        }
        else{
            t_d_cell * temp, *prev;
            temp = list->head[i];
            prev = NULL;
            while (temp != NULL && temp->value <cell->value){
                prev = temp;
                temp=temp->next[i];
            }
            if (prev == NULL){
                cell->next[i] = list->head[i];
                list->head[i] = cell;
            }
            else{
                prev->next[i] = cell;
                cell->next[i] = temp;
            }
        }
    }
}


/*void displayList(t_d_list list){
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
}*/

void displayList(t_d_list list){
    t_d_cell * temp, *temp2;
    for (int i = 0; i <list.niv_max; i++){
        temp = list.head[i];
        temp2 = list.head[0];
        printf("[list head_%d @-]", i);
        while (temp != NULL){
            while (temp->value != temp2->value){
                if(temp2->value <10){
                    printf("----------");
                }
                else{
                    printf("-----------");
                }
                temp2 = temp2->next[0];
            }
            printf("-->[ %d|@-]", temp->value);
            temp = temp->next[i];
            temp2 = temp2->next[0];
        }
        while(temp2!=NULL && temp==NULL){
            if(temp2->value <10){
                printf("----------");
            }
            else{
                printf("-----------");
            }
            temp2 = temp2->next[0];
        }
        printf("-->NULL\n");
    }
    printf("\n");
}




t_d_list cellinlist(){
    int nbValeur, nbNiveau;
    t_d_list * list;
    t_d_cell * newcell;
    printf("combien de valeurs voulez-vous ? ");
    scanf("%d", &nbValeur);
    printf("combien de niveaux voulez-vous ? ");
    scanf("%d", &nbNiveau);
    list = createEmptyList(nbNiveau);
    for (int i = 0; i < nbValeur; i++){
        newcell = user_choice_cell();
        addHeadSortList(list, newcell);
        displayList(*list);
    }
    displayList(*list);
    return *list;
}



t_d_list createListNiv(int n){
    int nbCell, niveau;
    t_d_list * listNiv;
    t_d_cell *newCell;
    listNiv = createEmptyList(n);
    nbCell = (int)pow(2, n) - 1;
    for (int i = 0; i < nbCell; i++) {
        niveau = 0;
        for (int j = 0; j<n ;j++)
        {
            if ((i+1)%(int)pow(2, j)==0)
            {
                niveau++;
            }
        }
        newCell = createCell(i+1, niveau);
        addHeadSortList(listNiv, newCell);
    }
    //displayList(*listNiv);
    return *listNiv;
}
