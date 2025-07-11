#include <stdio.h>
#include <stdlib.h>
#include "./lib/menu_matiere.h"
#include "../crud/lib/crud_matiere.h"
#include "utils_menu.h"

void ajouter_matiere_menu() {
    clear_console();
    Matiere m;
    printf("\n--- Ajouter une matiere ---\n");
    printf("Reference : ");
    scanf("%19s", m.reference);
    printf("Libelle : ");
    scanf("%49s", m.libelle);
    printf("Coefficient : ");
    scanf("%f", &m.coefficient);
    ajouter_matiere(&m);
 
}

void afficher_matiere_menu() {
    clear_console();
    printf("\n--- Affichage des matieres ---\n");
    afficher_matieres();
}

void modifier_matiere_menu() {
    clear_console();
    char reference[20];
    printf("\n--- Modifier une matiere ---\n");
    printf("Entrez la reference de la matiere a modifier : ");
    scanf("%19s", reference);
    modifier_matiere(reference);
}

void supprimer_matiere_menu() {
    clear_console();
    char reference[20];
    printf("\n--- Supprimer une matiere ---\n");
    printf("Entrez la reference de la matiere a supprimer : ");
    scanf("%19s", reference);
    supprimer_matiere(reference);
}

void chercher_matiere_menu() {
    clear_console();
    char reference[20];
    printf("\n--- Rechercher une matiere ---\n");
    printf("Entrez la reference de la matiere a rechercher : ");
    scanf("%19s", reference);
    Matiere *m = chercher_matiere(reference);
    if (m) {
        printf("Matiere trouvee :  reference = %s, libelle = %s, coefficient = %.2f \n", m->reference, m->libelle, m->coefficient);
    } else {
        printf("Matiere non trouvee.\n");
    }
}

void menu_matiere() {
    clear_console();
    int choix;
    do {
        printf("\n--- MENU MATIERE ---\n");
        printf("1. Ajouter une matiere\n");
        printf("2. Afficher les matieres\n");
        printf("3. Modifier une matiere\n");
        printf("4. Supprimer une matiere\n");
        printf("5. Rechercher une matiere\n");
        printf("0. Retour\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        switch(choix) {
            case 1:
                ajouter_matiere_menu();
                break;
            case 2:
                afficher_matiere_menu();
                break;
            case 3:
                modifier_matiere_menu();
                break;
            case 4:
                supprimer_matiere_menu();
                break;
            case 5:
                chercher_matiere_menu();
                break;
            case 0:
                printf("Retour au menu principal.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while(choix != 0);
}
