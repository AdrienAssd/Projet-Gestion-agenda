//
// Created by Adrien Assouad on 09/11/2023.
//

#ifndef GESTION_AGENDA_CONTACT_H
#define GESTION_AGENDA_CONTACT_H
#include "cells.h"
typedef struct contact {
    char *nom;
    char *prenom;
} Contact;

typedef struct date {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct heure {
    int heure;
    int minute;
} Heure;

typedef struct rendez_vous {
    Date date;
    Heure heure_rdv;
    Heure duree_rdv;
    char *objet;
    struct rendez_vous *next;
} Rdv;

typedef struct entree_agenda {
    Contact contact;
    Rdv *list_rdv;
    struct entree_agenda *next;
} EntreeAgenda;

typedef struct Agenda {
    int niv_max;
    EntreeAgenda **head;
} Agenda;

char *scanString();
Contact *create_contact();
Rdv *create_rdv();
void ajouter_rdv(EntreeAgenda *entree, Rdv *nouveauRDV);
EntreeAgenda *new_entree_agenda();
void ajouter_entree_agenda(Agenda *agenda, EntreeAgenda *nouvelleEntree);
void afficher_entree_agenda(EntreeAgenda *entree);
Agenda *createEmptyAgenda(int niv_max);
#endif //GESTION_AGENDA_CONTACT_H
