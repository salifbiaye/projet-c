#include "./lib/crud_matiere.h"
#include <string.h>

void ajouter_matiere(Matiere *m) {
    FILE *f = fopen("data/matieres.csv", "a");
    if (!f) {
        printf("Erreur ouverture matieres.csv\n");
        return;
    }
    if(chercher_matiere(m->reference)){
        printf("matiere ndeja enregistree");
        return;
    }
    fprintf(f, "%s,%s,%.2f\n", m->reference, m->libelle, m->coefficient);
    fclose(f);
    printf("Matiere ajoutee !\n");
}

void afficher_matieres() {
    FILE *f = fopen("data/matieres.csv", "r");
    if (!f) {
        printf("Aucune matiere enregistree.\n");
        return;
    }
    char ligne[256];
    fgets(ligne, sizeof(ligne), f); 
    printf("%-20s %-50s %-10s\n", "Reference", "Libelle", "Coefficient");
    char reference[20], libelle[50];
    float coefficient;
    while (fscanf(f, "%19[^,],%49[^,],%f\n", reference, libelle, &coefficient) == 3) {
        printf("%-20s %-50s %-10.2f\n", reference, libelle, coefficient);
    }
    fclose(f);
}

void modifier_matiere(const char *reference) {
    FILE *f = fopen("data/matieres.csv", "r");
    if (!f) { printf("Aucune matiere a modifier.\n"); return; }
    FILE *tmp = fopen("data/matieres_tmp.csv", "w");
    if (!tmp) { fclose(f); printf("Erreur ecriture temporaire.\n"); return; }
    char ligne[256];
    fgets(ligne, sizeof(ligne), f); // header
    fprintf(tmp, "%s", ligne);
    int trouve = 0;
    char m_ref[20], m_libelle[50];
    float m_coef;
    while (fscanf(f, "%19[^,],%49[^,],%f\n", m_ref, m_libelle, &m_coef) == 3) {
        if (strcmp(m_ref, reference) == 0) {
            printf("Nouveau libelle : "); scanf("%49s", m_libelle);
            printf("Nouveau coefficient : "); scanf("%f", &m_coef);
            trouve = 1;
        }
        fprintf(tmp, "%s,%s,%.2f\n", m_ref, m_libelle, m_coef);
    }
    fclose(f); fclose(tmp);
    remove("data/matieres.csv");
    rename("data/matieres_tmp.csv", "data/matieres.csv");
    if (trouve) printf("Matiere modifiee !\n"); else printf("Matiere non trouvee.\n");
}

void supprimer_matiere(const char *reference) {
    FILE *f = fopen("data/matieres.csv", "r");
    if (!f) { printf("Aucune matière a supprimer.\n"); return; }
    FILE *tmp = fopen("data/matieres_tmp.csv", "w");
    if (!tmp) { fclose(f); printf("Erreur ecriture temporaire.\n"); return; }
    char ligne[256];
    fgets(ligne, sizeof(ligne), f); // header
    fprintf(tmp, "%s", ligne);
    int supprime = 0;
    char m_ref[20], m_libelle[50];
    float m_coef;
    while (fscanf(f, "%19[^,],%49[^,],%f\n", m_ref, m_libelle, &m_coef) == 3) {
        if (strcmp(m_ref, reference) == 0) {
            supprime = 1;
            continue;
        }
        fprintf(tmp, "%s,%s,%.2f\n", m_ref, m_libelle, m_coef);
    }
    fclose(f); fclose(tmp);
    remove("data/matieres.csv");
    rename("data/matieres_tmp.csv", "data/matieres.csv");
    if (supprime) printf("Matiere supprimee !\n"); else printf("Matiere non trouvee.\n");
}

Matiere* chercher_matiere(const char *reference) {
    static Matiere m;
    FILE *f = fopen("data/matieres.csv", "r");
    if (!f) return NULL;
    char ligne[256];
    fgets(ligne, sizeof(ligne), f); 
    char m_ref[20], m_libelle[50];
    float m_coef;
    while (fscanf(f, "%19[^,],%49[^,],%f\n", m_ref, m_libelle, &m_coef) == 3) {
        if (strcmp(m_ref, reference) == 0) {
            strcpy(m.reference, m_ref);
            strcpy(m.libelle, m_libelle);
            m.coefficient = m_coef;
            fclose(f);
            return &m;
        }
    }
    fclose(f);
    return NULL;
}
