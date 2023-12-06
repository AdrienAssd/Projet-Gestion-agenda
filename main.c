#include <stdio.h>
#include "cells.h"
#include "lists.h"
#include "research.h"
#include "contact.h"

int main() {
    t_d_list list;
    //list = cellinlist();
    //printf("%d\n",researchclassique(list, 5));
    //printf("%d",researchNivHaut(list, 5));
    //createListNiv(3);
    //timeResearch();

    Agenda *agenda = (Agenda *)malloc(sizeof(Agenda));
    agenda->head = NULL;

    int nb_entrees;
    printf("Combien d'entrées d'agenda souhaitez-vous ajouter ? ");
    scanf("%d", &nb_entrees);

    for (int i = 0; i < nb_entrees; i++) {
        printf("Ajouter une entrée d'agenda\n");
        EntreeAgenda *nouvelle_entree = new_entree_agenda();
        ajouter_entree_agenda(agenda, nouvelle_entree);
    }

    // Afficher les entrées d'agenda
    EntreeAgenda *currentEntree = agenda->head;
    while (currentEntree != NULL) {
        afficher_entree_agenda(currentEntree);
        currentEntree = currentEntree->next;
    }
    return 0;
}