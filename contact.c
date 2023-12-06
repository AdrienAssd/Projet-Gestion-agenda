//
// Created by Adrien Assouad on 09/11/2023.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"


char *scanString() {
    char text_user[256];
    char *tab;
    int len;
    fgets(text_user, sizeof(text_user), stdin);
    len = strlen(text_user);
    tab = (char *)malloc(len * sizeof(char));
    for (int i = 0; text_user[i] != '\0'; i++) {
        if (text_user[i] >= 'A' && text_user[i] <= 'Z') {
            text_user[i] = text_user[i] + 32;
        }
        if (text_user[i] == ' ') {
            text_user[i] = '_';
        }
    }
    if (len > 0 && text_user[len - 1] == '\n') {
        text_user[len - 1] = '\0';
    }
    strcpy(tab, text_user);
    return tab;
}

Contact *create_contact() {
    Contact *newContact = (Contact *)malloc(sizeof(Contact));
    printf("Saisir nom : ");
    fflush(stdin);
    newContact->nom = scanString();
    fflush(stdin);
    printf("Saisir prénom : ");
    newContact->prenom = scanString();
    fflush(stdin);
    return newContact;
}

Rdv *create_rdv() {
    Rdv *newRDV = (Rdv *)malloc(sizeof(Rdv));
    if (newRDV == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire pour le nouveau rendez-vous\n");
        exit(EXIT_FAILURE);
    }

    printf("Saisir jj/mm/aa du rendez-vous : ");
    fflush(stdin);
    scanf("%d/%d/%d", &newRDV->date.jour, &newRDV->date.mois, &newRDV->date.annee);
    printf("Saisir l'heure du rendez-vous (hhHmm): ");
    fflush(stdin);
    scanf("%dH%d", &newRDV->heure_rdv.heure, &newRDV->heure_rdv.minute);
    printf("Saisir la durée du rendez-vous (hhHmm): ");
    fflush(stdin);
    scanf("%dH%d", &newRDV->duree_rdv.heure, &newRDV->duree_rdv.minute);
    printf("Saisir l'objet du rendez-vous : ");
    fflush(stdin);
    newRDV->objet = scanString();
    newRDV->next = NULL;
    return newRDV;
}

void ajouter_rdv(EntreeAgenda *entree, Rdv *nouveauRDV) {
    if (entree->list_rdv == NULL) {
        entree->list_rdv = nouveauRDV;
    } else {
        Rdv *currentRDV = entree->list_rdv;
        while (currentRDV->next != NULL) {
            currentRDV = currentRDV->next;
        }
        currentRDV->next = nouveauRDV;
    }
}

void afficher_entree_agenda(EntreeAgenda *entree) {
    printf("Contact : %s %s", entree->contact.nom, entree->contact.prenom);
    printf("\nListe des rendez-vous :\n");

    Rdv *currentRDV = entree->list_rdv;
    while (currentRDV != NULL) {
        printf("Date : %d/%d/%d\n", currentRDV->date.jour, currentRDV->date.mois, currentRDV->date.annee);
        printf("Heure : %d:%d\n", currentRDV->heure_rdv.heure, currentRDV->heure_rdv.minute);
        printf("Durée : %d:%d\n", currentRDV->duree_rdv.heure, currentRDV->duree_rdv.minute);
        printf("Objet : %s\n", currentRDV->objet);

        currentRDV = currentRDV->next;
    }
}

EntreeAgenda *new_entree_agenda() {
    EntreeAgenda *entree = (EntreeAgenda *)malloc(sizeof(EntreeAgenda));
    entree->contact = *create_contact();
    printf("Ajouter un rdv\n");
    entree->list_rdv = create_rdv();
    return entree;
}

Agenda *createEmptyAgenda(int niv_max) {
    Agenda *newAgenda = (Agenda *)malloc(sizeof(Agenda));
    newAgenda->niv_max = niv_max;
    newAgenda->head = (EntreeAgenda **)malloc(newAgenda->niv_max * sizeof(EntreeAgenda *));

    for (int i = 0; i < newAgenda->niv_max; i++) {
        newAgenda->head[i] = NULL;
    }

    return newAgenda;
}

void ajouter_entree_agenda(Agenda *agenda, EntreeAgenda *nouvelleEntree) {
    if (agenda->head == NULL || agenda->head[0] == NULL || strcmp(agenda->head[0]->contact.nom, nouvelleEntree->contact.nom) > 0) {
        // Ajouter en tête si la liste est vide ou si la nouvelle entrée a un nom plus petit
        nouvelleEntree->next = agenda->head[0];
        agenda->head[0] = nouvelleEntree;
    } else {
        // Sinon, trouver la position d'insertion dans l'ordre alphabétique
        EntreeAgenda *currentEntree = agenda->head[0];
        while (currentEntree->next != NULL && strcmp(currentEntree->next->contact.nom, nouvelleEntree->contact.nom) < 0) {
            currentEntree = currentEntree->next;
        }

        // Insérer la nouvelle entrée à la bonne position
        nouvelleEntree->next = currentEntree->next;
        currentEntree->next = nouvelleEntree;
    }
}
