//
// Created by Adrien Assouad on 07/11/2023.
//

#include "research.h"
#include "lists.h"
#include "cells.h"
#include "timer.h"
#include "math.h"

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
                if (temp->value == val){
                    //printf("%d\n", temp->value);
                    return val;
                }
                save = temp;
                temp = temp->next[i];
            }
        }
        else{
            save = list.head[i-1];
        }

    }
    return 0;
}

void timeResearch(){
    FILE *log_file = fopen("log.txt","w");
    char format[] = "%d\t%s\t%s\n" ;
    int level;
    char *time_lvl0;
    char *time_all_levels;
    level = 3;
    while (level != 17)
    {
        printf("en cours %d\n",level);
        t_d_list list = createListNiv(level);
        //faire test pour lvl0
        startTimer();
        for (int i = 0; i < 10000; i++){
            researchclassique(list, rand() % (int)pow(2,level));
        }
        stopTimer();
        displayTime();
        time_lvl0 = getTimeAsString();
        //faire test pour all lvls
        startTimer();
        for (int i = 0; i < 10000; i++){
            researchNivHaut(list, rand() % (int)pow(2,level));
        }
        stopTimer();
        displayTime();
        time_all_levels = getTimeAsString();
        fprintf(log_file,format,level,time_lvl0, time_all_levels);
        level++;
        free(time_lvl0);
        free(time_all_levels);
    }
    fclose(log_file);
}