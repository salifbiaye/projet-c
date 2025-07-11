#ifndef CRUD_ETUDIANT_H
#define CRUD_ETUDIANT_H
#include "../../struct/structs.h"

void ajouter_etudiant(Etudiant *e);
void afficher_etudiants();
void modifier_etudiant(const char *numero);
void supprimer_etudiant(const char *numero);
Etudiant* chercher_etudiant(const char *numero);

#endif
