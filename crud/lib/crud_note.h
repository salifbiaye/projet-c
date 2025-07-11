#ifndef CRUD_NOTE_H
#define CRUD_NOTE_H
#include "../../struct/structs.h"

void ajouter_note(Note *n);
void afficher_notes();
void modifier_note(const char *numero_etudiant, const char *reference_matiere);
void supprimer_note(const char *numero_etudiant, const char *reference_matiere);
Note* chercher_note(const char *numero_etudiant, const char *reference_matiere);

#endif
