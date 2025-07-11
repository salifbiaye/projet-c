#include <stdio.h>
#include <stdlib.h>
#include "./lib/menu_sefaire.h"
#include "../crud/lib/crud_sefaire.h"
#include "utils_menu.h"

void ajouter_sefaire_menu() {
    clear_console();
    SeFaire s;
    printf("\n--- Associer une matiere a une classe ---\n");
    printf("Reference matiere : ");
    scanf("%19s", s.referenceMatiere);
    printf("Code classe : ");
    scanf("%19s", s.codeClasse);
    associer_matiere_classe(s.referenceMatiere, s.codeClasse);
}

void afficher_sefaire_menu() {
    clear_console();
    printf("\n--- Affichage des associations ---\n");
    afficher_associations();
}

void supprimer_sefaire_menu() {
    clear_console();
    SeFaire s;
    printf("\n--- Supprimer une association ---\n");
    printf("Entrez la reference de la matiere : ");
    scanf("%19s", s.referenceMatiere);
    printf("Entrez le code de la classe : ");
    scanf("%19s", s.codeClasse);
    supprimer_association(s.referenceMatiere, s.codeClasse);
}

void chercher_sefaire_menu() {
    clear_console();
    SeFaire s;
    printf("\n--- Rechercher une association ---\n");
    printf("Entrez la reference de la matiere : ");
    scanf("%19s", s.referenceMatiere);
    printf("Entrez le code de la classe : ");
    scanf("%19s", s.codeClasse);
    SeFaire *res = chercher_association(s.referenceMatiere, s.codeClasse);
    if (res) {
        printf("Association trouvee : reference = %s, code = %s\n", res->referenceMatiere, res->codeClasse); 
    } else {
        printf("Association non trouvee.\n");
    }
}

void menu_sefaire() {
    clear_console();
    int choix;
    do {
        printf("\n--- MENU ASSOCIATION MATIERE-CLASSE ---\n");
        printf("1. Associer une matiere a une classe\n");
        printf("2. Afficher les associations\n");
        printf("3. Supprimer une association\n");
        printf("4. Rechercher une association\n");
        printf("0. Retour\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        switch(choix) {
            case 1:
                ajouter_sefaire_menu();
                break;
            case 2:
                afficher_sefaire_menu();
                break;
            case 3:
                supprimer_sefaire_menu();
                break;
            case 4:
                chercher_sefaire_menu();
                break;
            case 0:
                printf("Retour au menu principal.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while(choix != 0);
}
