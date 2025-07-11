#include "./lib/crud_note.h"
#include <string.h>

void ajouter_note(Note *n) {
    FILE *f = fopen("data/notes.csv", "a");
    if (!f) {
        printf("Erreur ouverture notes.csv\n");
        return;
    }
    if(chercher_note(n->numeroEtudiant, n->referenceMatiere)) {
        printf("Note deja enregistree.\n");
        return;
    }
    fprintf(f, "%s,%s,%.2f,%.2f\n", n->numeroEtudiant, n->referenceMatiere, n->noteCC, n->noteDS);
    fclose(f);
    printf("Note ajoutee !\n");
}

void afficher_notes() {
    FILE *f = fopen("data/notes.csv", "r");
    if (!f) {
        printf("Aucune note enregistree.\n");
        return;
    }
    char ligne[256];
    fgets(ligne, sizeof(ligne), f); 
    printf("%-20s %-20s %-10s %-10s\n", "Numero etudiant", "Reference matiere", "NoteCC", "NoteDS");
    char numero[20], reference[20];
    float cc, ds;
    while (fscanf(f, "%19[^,],%19[^,],%f,%f\n", numero, reference, &cc, &ds) == 4) {
        printf("%-20s %-20s %-10.2f %-10.2f\n", numero, reference, cc, ds);
    }
    fclose(f);
}

void modifier_note(const char *numero_etudiant, const char *reference_matiere) {
    FILE *f = fopen("data/notes.csv", "r");
    if (!f) { printf("Aucune note a modifier.\n"); return; }
    FILE *tmp = fopen("data/notes_tmp.csv", "w");
    if (!tmp) { fclose(f); printf("Erreur ecriture temporaire.\n"); return; }
    char ligne[256];
    fgets(ligne, sizeof(ligne), f); 
    fprintf(tmp, "%s", ligne);
    int trouve = 0;
    char numero[20], reference[20];
    float cc, ds;
    while (fscanf(f, "%19[^,],%19[^,],%f,%f\n", numero, reference, &cc, &ds) == 4) {
        if (strcmp(numero, numero_etudiant) == 0 && strcmp(reference, reference_matiere) == 0) {
            printf("Nouvelle note CC : "); scanf("%f", &cc);
            printf("Nouvelle note DS : "); scanf("%f", &ds);
            trouve = 1;
        }
        fprintf(tmp, "%s,%s,%.2f,%.2f\n", numero, reference, cc, ds);
    }
    fclose(f); fclose(tmp);
    remove("data/notes.csv");
    rename("data/notes_tmp.csv", "data/notes.csv");
    if (trouve) printf("Note modifiee !\n"); else {printf("Note non trouvee.\n"); remove("data/notes_tmp.csv");}
}

void supprimer_note(const char *numero_etudiant, const char *reference_matiere) {
    FILE *f = fopen("data/notes.csv", "r");
    if (!f) { printf("Aucune note a supprimer.\n"); return; }
    FILE *tmp = fopen("data/notes_tmp.csv", "w");
    if (!tmp) { fclose(f); printf("Erreur ecriture temporaire.\n"); return; }
    char ligne[256];
    fgets(ligne, sizeof(ligne), f); 
    fprintf(tmp, "%s", ligne);
    int supprime = 0;
    char numero[20], reference[20];
    float cc, ds;
    while (fscanf(f, "%19[^,],%19[^,],%f,%f\n", numero, reference, &cc, &ds) == 4) {
        if (strcmp(numero, numero_etudiant) == 0 && strcmp(reference, reference_matiere) == 0) {
            supprime = 1;
            continue;
        }
        fprintf(tmp, "%s,%s,%.2f,%.2f\n", numero, reference, cc, ds);
    }
    fclose(f); fclose(tmp);
    remove("data/notes.csv");
    rename("data/notes_tmp.csv", "data/notes.csv");
    if (supprime) printf("Note supprimee !\n"); else {printf("Note non trouvee.\n"); remove("data/notes_tmp.csv");}
}

Note* chercher_note(const char *numero_etudiant, const char *reference_matiere) {
    static Note n;
    FILE *f = fopen("data/notes.csv", "r");
    if (!f) return NULL;
    char ligne[256];
    fgets(ligne, sizeof(ligne), f); 
    char numero[20], reference[20];
    float cc, ds;
    while (fscanf(f, "%19[^,],%19[^,],%f,%f\n", numero, reference, &cc, &ds) == 4) {
        if (strcmp(numero, numero_etudiant) == 0 && strcmp(reference, reference_matiere) == 0) {
            strcpy(n.numeroEtudiant, numero);
            strcpy(n.referenceMatiere, reference);
            n.noteCC = cc;
            n.noteDS = ds;
            fclose(f);
            return &n;
        }
    }
    fclose(f);
    return NULL;
}
