#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <stdlib.h>


typedef struct Classe {
    char code[20];
    char nom[50];
    char niveau[20];
} Classe;


typedef struct Matiere {
    char reference[20];
    char libelle[50];
    float coefficient;
} Matiere;


typedef struct Etudiant {
    char numero[20];
    char nom[50];
    char prenom[50];
    char email[100];
    char datenaissance[11]; 
    char codeClasse[20]; 
} Etudiant;

typedef struct Note {
    float noteCC;
    float noteDS;
    char referenceMatiere[20];
    char numeroEtudiant[20];
} Note;

typedef struct SeFaire {
    char referenceMatiere[20];
    char codeClasse[20];
} SeFaire;

#endif
