#include <stdio.h>
#include <stdlib.h>
#include "./lib/menu_classe.h"
#include "../crud/lib/crud_classe.h"
#include "utils_menu.h"

void ajouter_classe_menu() {
    clear_console();
    Classe c;
    printf("\n--- Ajouter une classe ---\n");
    printf("Code : ");
    scanf("%19s", c.code);
    printf("Nom : ");
    scanf("%49s", c.nom);
    printf("Niveau : ");
    scanf("%19s", c.niveau);
    ajouter_classe(&c);
    
}

void afficher_classe_menu() {
    clear_console();
    printf("\n--- Affichage des classes ---\n");
    afficher_classes();
}

void modifier_classe_menu() {
    clear_console();
    char code[20];
    printf("\n--- Modifier une classe ---\n");
    printf("Entrez le code de la classe a modifier : ");
    scanf("%19s", code);
    modifier_classe(code);
}

void supprimer_classe_menu() {
    clear_console();
    char code[20];
    printf("\n--- Supprimer une classe ---\n");
    printf("Entrez le code de la classe a supprimer : ");
    scanf("%19s", code);
    supprimer_classe(code);
}

void chercher_classe_menu() {
    clear_console();
    char code[20];
    printf("\n--- Rechercher une classe ---\n");
    printf("Entrez le code de la classe a rechercher : ");
    scanf("%19s", code);
    Classe *c = chercher_classe(code);
    if (c) {
        printf("Classe trouvee : code = %s, nom = %s, niveau = %s\n", c->code, c->nom, c->niveau); 
    } else {
        printf("Classe non trouvee.\n");
    }
}

void menu_classe() {
    clear_console();
    int choix;
    do {
        printf("\n--- MENU CLASSE ---\n");
        printf("1. Ajouter une classe\n");
        printf("2. Afficher les classes\n");
        printf("3. Modifier une classe\n");
        printf("4. Supprimer une classe\n");
        printf("5. Rechercher une classe\n");
        printf("0. Retour\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        switch(choix) {
            case 1:
                ajouter_classe_menu();
                break;
            case 2:
                afficher_classe_menu();
                break;
            case 3:
                modifier_classe_menu();
                break;
            case 4:
                supprimer_classe_menu();
                break;
            case 5:
                chercher_classe_menu();
                break;
            case 0:
                printf("Retour au menu principal.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while(choix != 0);
}
