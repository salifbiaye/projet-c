#include "./lib/crud_sefaire.h"
#include <string.h>
#include "./lib/crud_matiere.h"
#include "./lib/crud_classe.h"
void associer_matiere_classe(const char *reference_matiere, const char *code_classe) {
    FILE *f = fopen("data/sefaire.csv", "a");
    if (!f) {
        printf("Erreur ouverture sefaire.csv\n");
        return;
    }
    if(chercher_association(reference_matiere,code_classe)) {
        printf("Association deja enregistree.\n");
        return;
    }
    if(chercher_matiere(reference_matiere) == NULL ) {
        printf("Matiere non trouvee.\n");
        return;
    }
    if(chercher_classe(code_classe) == NULL) {
        printf("Classe non trouvee.\n");
        return;
    }
    fprintf(f, "%s,%s\n", reference_matiere, code_classe);
    fclose(f);
    printf("Association ajoutee !\n");
}

void afficher_associations() {
    FILE *f = fopen("data/sefaire.csv", "r");
    if (!f) {
        printf("Aucune association enregistree.\n");
        return;
    }
    char ligne[128];
    fgets(ligne, sizeof(ligne), f); 
    printf("%-20s %-20s\n", "Reference Matiere", "Code Classe");
    char reference[20], code[20];
    while (fscanf(f, "%19[^,],%19[^\n]\n", reference, code) == 2) {
        printf("%-20s %-20s\n", reference, code);
    }
    fclose(f);
}

void supprimer_association(const char *reference_matiere, const char *code_classe) {
    FILE *f = fopen("data/sefaire.csv", "r");
    if (!f) { printf("Aucune association a supprimer.\n"); return; }
    FILE *tmp = fopen("data/sefaire_tmp.csv", "w");
    if (!tmp) { fclose(f); printf("Erreur ecriture temporaire.\n"); return; }
    char ligne[128];
    fgets(ligne, sizeof(ligne), f); 
    fprintf(tmp, "%s", ligne);
    int supprime = 0;
    char reference[20], code[20];
    while (fscanf(f, "%19[^,],%19[^\n]\n", reference, code) == 2) {
        reference[strcspn(reference, "\r")] = 0;
        code[strcspn(code, "\r")] = 0;
        if (strcmp(reference, reference_matiere) == 0 && strcmp(code, code_classe) == 0) {
            supprime = 1;
            continue;
        }
        fprintf(tmp, "%s,%s\n", reference, code);
    }
    fclose(f); fclose(tmp);
    remove("data/sefaire.csv");
    rename("data/sefaire_tmp.csv", "data/sefaire.csv");
    if (supprime) printf("Association supprimee !\n"); else {printf("Association non trouvee.\n"); remove("data/sefaire_tmp.csv");}
}

SeFaire* chercher_association(const char *reference_matiere, const char *code_classe) {
    static SeFaire s;
    FILE *f = fopen("data/sefaire.csv", "r");
    if (!f) return NULL;
    char ligne[128];
    fgets(ligne, sizeof(ligne), f); // saute l'en-tête
    char reference[20], code[20];
    while (fscanf(f, "%19[^,],%19[^\n]\n", reference, code) == 2) {
        // Nettoyage pour Windows
        reference[strcspn(reference, "\r")] = 0;
        code[strcspn(code, "\r")] = 0;
        if (strcmp(reference, reference_matiere) == 0 && strcmp(code, code_classe) == 0) {
            strcpy(s.referenceMatiere, reference);
            strcpy(s.codeClasse, code);
            fclose(f);
            return &s;
        }
    }
    fclose(f);
    return NULL;
}
