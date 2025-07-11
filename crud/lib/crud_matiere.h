#ifndef CRUD_MATIERE_H
#define CRUD_MATIERE_H
#include "../../struct/structs.h"

void ajouter_matiere(Matiere *m);
void afficher_matieres();
void modifier_matiere(const char *reference);
void supprimer_matiere(const char *reference);
Matiere* chercher_matiere(const char *reference);

#endif
