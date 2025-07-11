#include <stdio.h>
#include <stdlib.h>
#include "./lib/menu_etudiant.h"
#include "../crud/lib/crud_etudiant.h"
#include "../crud/lib/crud_classe.h"
#include "utils_menu.h"

void ajouter_etudiant_menu() {
    clear_console();
    Etudiant e;
    
    printf("\n--- Ajouter un etudiant ---\n");
    printf("Numero : ");
    scanf("%19s", e.numero);
    printf("Nom : ");
    scanf("%49s", e.nom);
    printf("Prenom : ");
    scanf("%49s", e.prenom);
    printf("Email : ");
    scanf("%99s", e.email);
    printf("Date de naissance (YYYY-MM-DD) : ");
    scanf("%10s", e.datenaissance);
    printf("Code de la classe : ");
    scanf("%19s", e.codeClasse);
    if (chercher_classe(e.codeClasse) == NULL) {
        printf("Classe non trouvee. Ajout annule.\n");
        return;
    }
    ajouter_etudiant(&e);
    
}

void afficher_etudiant_menu() {
    clear_console();
    printf("\n--- Affichage des etudiants ---\n");
    afficher_etudiants();
}

void modifier_etudiant_menu() {
    clear_console();
    char numero[20];
    printf("\n--- Modifier un etudiant ---\n");
    printf("Entrez le numero de l'etudiant a modifier : ");
    scanf("%19s", numero);
    modifier_etudiant(numero);
}

void supprimer_etudiant_menu() {
    clear_console();
    char numero[20];
    printf("\n--- Supprimer un etudiant ---\n");
    printf("Entrez le numero de l'etudiant a supprimer : ");
    scanf("%19s", numero);
    supprimer_etudiant(numero);
}

void chercher_etudiant_menu() {
    clear_console();
    char numero[20];
    printf("\n--- Rechercher un etudiant ---\n");
    printf("Entrez le numero de l'etudiant a rechercher : ");
    scanf("%19s", numero);
    Etudiant *e = chercher_etudiant(numero);
    if (e) {
        printf("Etudiant trouve : numero = %s, nom = %s, prenom = %s, email = %s, date naissance = %s, classe = %s\n", e->numero, e->nom, e->prenom, e->email, e->datenaissance, e->codeClasse);
    } else {
        printf("Etudiant non trouve.\n");
    }
}

void menu_etudiant() {
    clear_console();
    int choix;
    do {
        printf("\n--- MENU ETUDIANT ---\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Afficher les etudiants\n");
        printf("3. Modifier un etudiant\n");
        printf("4. Supprimer un etudiant\n");
        printf("5. Rechercher un etudiant\n");
        printf("0. Retour\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        switch(choix) {
            case 1:
                ajouter_etudiant_menu();
                break;
            case 2:
                afficher_etudiant_menu();
                break;
            case 3:
                modifier_etudiant_menu();
                break;
            case 4:
                supprimer_etudiant_menu();
                break;
            case 5:
                chercher_etudiant_menu();
                break;
            case 0:
                printf("Retour au menu principal.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while(choix != 0);
}
