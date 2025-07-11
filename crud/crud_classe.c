#include "./lib/crud_classe.h"
#include <string.h>

void ajouter_classe(Classe *c) {
    FILE *f = fopen("data/classes.csv", "a");
    if (!f) {
        printf("Erreur ouverture classes.csv\n");
        return;
    }
    if(chercher_classe(c->code)) {
        printf("Classe deja enregistree.\n");
        return;
    }
    fprintf(f, "%s,%s,%s\n", c->code, c->nom, c->niveau);
    fclose(f);
    printf("Classe ajoutee !\n");
}

void afficher_classes() {
    FILE *f = fopen("data/classes.csv", "r");
    if (!f) {
        printf("Aucune classe enregistree.\n");
        return;
    }
    char ligne[256];
    fgets(ligne, sizeof(ligne), f); 
    printf("%-20s %-20s %-20s\n", "Code", "Nom", "Niveau");
    char code[20], nom[50], niveau[20];
    while (fscanf(f, "%19[^,],%49[^,],%19[^\n]\n", code, nom, niveau) == 3) {
        printf("%-20s %-20s %-20s\n", code, nom, niveau);
    }
    fclose(f);
}

void modifier_classe(const char *code) {
    FILE *f = fopen("data/classes.csv", "r");
    if (!f) { printf("Aucune classe a modifier.\n"); return; }
    FILE *tmp = fopen("data/classes_tmp.csv", "w");
    if (!tmp) { fclose(f); printf("Erreur ecriture temporaire.\n"); return; }
    char ligne[256];
    fgets(ligne, sizeof(ligne), f); // header
    fprintf(tmp, "%s", ligne);
    int trouve = 0;
    char c_code[20], c_nom[50], c_niveau[20];
    while (fscanf(f, "%19[^,],%49[^,],%19[^\n]\n", c_code, c_nom, c_niveau) == 3) {
        if (strcmp(c_code, code) == 0) {
            printf("Nouveau nom : "); scanf("%49s", c_nom);
            printf("Nouveau niveau : "); scanf("%19s", c_niveau);
            trouve = 1;
        }
        fprintf(tmp, "%s,%s,%s\n", c_code, c_nom, c_niveau);
    }
    fclose(f); fclose(tmp);
    remove("data/classes.csv");
    rename("data/classes_tmp.csv", "data/classes.csv");
    if (trouve) printf("Classe modifiee !\n"); else printf("Classe non trouvee.\n");
}

void supprimer_classe(const char *code) {
    FILE *f = fopen("data/classes.csv", "r");
    if (!f) { printf("Aucune classe a supprimer.\n"); return; }
    FILE *tmp = fopen("data/classes_tmp.csv", "w");
    if (!tmp) { fclose(f); printf("Erreur ecriture temporaire.\n"); return; }
    char ligne[256];
    fgets(ligne, sizeof(ligne), f); // header
    fprintf(tmp, "%s", ligne);
    int supprime = 0;
    char c_code[20], c_nom[50], c_niveau[20];
    while (fscanf(f, "%19[^,],%49[^,],%19[^\n]\n", c_code, c_nom, c_niveau) == 3) {
        if (strcmp(c_code, code) == 0) {
            supprime = 1;
            continue;
        }
        fprintf(tmp, "%s,%s,%s\n", c_code, c_nom, c_niveau);
    }
    fclose(f); fclose(tmp);
    remove("data/classes.csv");
    rename("data/classes_tmp.csv", "data/classes.csv");
    if (supprime) printf("Classe supprimee !\n"); else printf("Classe non trouvee.\n");
}

Classe* chercher_classe(const char *code) {
    static Classe c;
    FILE *f = fopen("data/classes.csv", "r");
    if (!f) return NULL;
    char ligne[256];
    fgets(ligne, sizeof(ligne), f); // header
    char c_code[20], c_nom[50], c_niveau[20];
    while (fscanf(f, "%19[^,],%49[^,],%19[^\n]\n", c_code, c_nom, c_niveau) == 3) {
        if (strcmp(c_code, code) == 0) {
            strcpy(c.code, c_code);
            strcpy(c.nom, c_nom);
            strcpy(c.niveau, c_niveau);
            fclose(f);
            return &c;
        }
    }
    fclose(f);
    return NULL;
}
