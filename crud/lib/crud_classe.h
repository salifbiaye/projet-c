#ifndef CRUD_CLASSE_H
#define CRUD_CLASSE_H
#include "../../struct/structs.h"

void ajouter_classe(Classe *c);
void afficher_classes();
void modifier_classe(const char *code);
void supprimer_classe(const char *code);
Classe* chercher_classe(const char *code);

#endif
