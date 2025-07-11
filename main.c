#include <stdio.h>
#include <stdlib.h>
#include "struct/structs.h"
#include "crud/lib/crud_etudiant.h"
#include "crud/lib/crud_matiere.h"
#include "crud/lib/crud_classe.h"
#include "crud/lib/crud_note.h"
#include "crud/lib/crud_sefaire.h"
#include "menus/lib/menu_etudiant.h"
#include "menus/lib/menu_matiere.h"
#include "menus/lib/menu_classe.h"
#include "menus/lib/menu_note.h"
#include "menus/lib/menu_sefaire.h"

void menu() {
    int choix;
    do {
        printf("\n==== MENU PRINCIPAL ====");
        printf("\n1. Gerer les etudiants");
        printf("\n2. Gerer les matieres");
        printf("\n3. Gerer les classes");
        printf("\n4. Gerer les notes");
        printf("\n5. Gerer les associations matiere-classe");
        printf("\n0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        switch(choix) {
            case 1:
                menu_etudiant();
                break;
            case 2:
                menu_matiere();
                break;
            case 3:
                menu_classe();
                break;
            case 4:
                menu_note();
                break;
            case 5:
                menu_sefaire();
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while(choix != 0);
}

int main() {
    menu();
    return 0;
}
