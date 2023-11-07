//
// Created by Adrien Assouad on 07/11/2023.
//

#include "research.h"
#include "lists.h"
#include "cells.h"

int researchclassique (t_d_list list, int val){
    t_d_cell * temp = list.head[0];
    while (temp != NULL){
        if (val == temp->value){
            return val;
        }
        temp = temp->next[0];
    }
    return 0; // La valeur n'est pas trouvée
}



int researchNivHaut(t_d_list list, int val){
    int nivMax = list.niv_max-1;
    t_d_cell * temp = list.head[nivMax];
    t_d_cell * save = temp;
    for( int i = nivMax; i >= 0; i--){
        temp = save;
        if (list.head[i]->value <= val){
            while (temp != NULL && temp->value <= val){
                printf("%d\t", temp->value);
                if (temp->value == val){
                    return val;
                }
                save = temp;
                temp = temp->next[i];
            }printf("\n");
        }
        else{
            save = list.head[i-1];
        }

    }
    return 0;
}

