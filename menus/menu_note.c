#include <stdio.h>
#include <stdlib.h>
#include "./lib/menu_note.h"
#include "../crud/lib/crud_note.h"
#include "../crud/lib/crud_etudiant.h"
#include "../crud/lib/crud_matiere.h"
#include "utils_menu.h"

void ajouter_note_menu() {
    clear_console();
    Note n;
    printf("\n--- Ajouter une note ---\n");
    printf("Numero etudiant : ");
    scanf("%19s", n.numeroEtudiant);
    printf("Reference matiere : ");
    scanf("%19s", n.referenceMatiere);
    printf("Note CC : ");
    scanf("%f", &n.noteCC);
    printf("Note DS : ");
    scanf("%f", &n.noteDS);
    if (!chercher_etudiant(n.numeroEtudiant)) {
        printf("Etudiant non trouve. Ajout annule.\n");
        return;
    }
    if (!chercher_matiere(n.referenceMatiere)) {
        printf("Matiere non trouvee. Ajout annule.\n");
        return;
    }
    ajouter_note(&n);
    
}

void afficher_note_menu() {
    clear_console();
    printf("\n--- Affichage des notes ---\n");
    afficher_notes();
}

void modifier_note_menu() {
    clear_console();
    Note n;
    printf("\n--- Modifier une note ---\n");
    printf("Entrez le numero de l'etudiant : ");
    scanf("%19s", n.numeroEtudiant);
    printf("Entrez la reference de la matiere : ");
    scanf("%19s", n.referenceMatiere);
    modifier_note(n.numeroEtudiant, n.referenceMatiere);
}

void supprimer_note_menu() {
    clear_console();
    Note n;
    printf("\n--- Supprimer une note ---\n");
    printf("Entrez le numero de l'etudiant : ");
    scanf("%19s", n.numeroEtudiant);
    printf("Entrez la reference de la matiere : ");
    scanf("%19s", n.referenceMatiere);
    supprimer_note(n.numeroEtudiant, n.referenceMatiere);
}

void chercher_note_menu() {
    clear_console();
    Note n;
    printf("\n--- Rechercher une note ---\n");
    printf("Entrez le numero de l'etudiant : ");
    scanf("%19s", n.numeroEtudiant);
    printf("Entrez la reference de la matiere : ");
    scanf("%19s", n.referenceMatiere);
    Note *note = chercher_note(n.numeroEtudiant, n.referenceMatiere);
    if (note) {
        printf("Note trouvee : numero = %s, matiere = %s, noteCC = %.2f, noteDS = %.2f \n", note->numeroEtudiant, note->referenceMatiere, note->noteCC, note->noteDS); 
    } else {
        printf("Note non trouvee.\n");
    }
}

void menu_note() {
    clear_console();
    int choix;
    do {
        printf("\n--- MENU NOTE ---\n");
        printf("1. Donner une note a un etudiant\n");
        printf("2. Afficher les notes\n");
        printf("3. Modifier une note\n");
        printf("4. Supprimer une note\n");
        printf("5. Rechercher une note\n");
        printf("0. Retour\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        switch(choix) {
            case 1:
                ajouter_note_menu();
                break;
            case 2:
                afficher_note_menu();
                break;
            case 3:
                modifier_note_menu();
                break;
            case 4:
                supprimer_note_menu();
                break;
            case 5:
                chercher_note_menu();
                break;
            case 0:
                printf("Retour au menu principal.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while(choix != 0);
}
