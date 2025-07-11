#ifndef CRUD_SEFAIRE_H
#define CRUD_SEFAIRE_H
#include "../../struct/structs.h"

void associer_matiere_classe(const char *reference_matiere, const char *code_classe);
void afficher_associations();
void supprimer_association(const char *reference_matiere, const char *code_classe);
SeFaire* chercher_association(const char *reference_matiere, const char *code_classe);

#endif
