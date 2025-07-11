#include "./lib/crud_etudiant.h"
#include <string.h>
#include <stdio.h>
#include "./lib/crud_classe.h"

void ajouter_etudiant(Etudiant *e) {
    FILE *fichier = fopen("data/etudiants.csv", "a");
    if(fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }
    if(chercher_etudiant(e->numero)) {
        printf("Etudiant deja enregistre.\n");
        return;
    }
    fprintf(fichier, "%s,%s,%s,%s,%s,%s\n", e->numero, e->nom, e->prenom, e->email, e->datenaissance, e->codeClasse);
    fclose(fichier);
    printf("Etudiant ajoute !\n");
}

void afficher_etudiants() {
    FILE *fichier = fopen("data/etudiants.csv", "r");
    if(fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }
    Etudiant e;
    char codeClasse[20];
    while (fscanf(fichier, "%19[^,],%49[^,],%49[^,],%99[^,],%19[^,],%19[^\n]\n", e.numero, e.nom, e.prenom, e.email, e.datenaissance, codeClasse) == 6) {
        printf("%s | %s | %s | %s | %s | %s\n", e.numero, e.nom, e.prenom, e.email, e.datenaissance, codeClasse);
    }
    fclose(fichier);
}

void modifier_etudiant(const char *numero) {
    FILE *fichier = fopen("data/etudiants.csv", "r");
    FILE *temp = fopen("data/etudiants_tmp.csv", "w");
    if (!fichier || !temp) {
        printf("Erreur lors de l'ouverture du fichier\n");
        if (fichier) fclose(fichier);
        if (temp) fclose(temp);
        return;
    }

    char entete[256];
    if (fgets(entete, sizeof(entete), fichier)) {
        fputs(entete, temp); 
    }

    Etudiant e;
    int trouve = 0;
    char codeClasse[20];
    while (fscanf(fichier, "%19[^,],%49[^,],%49[^,],%99[^,],%19[^,],%19[^\n]\n",e.numero, e.nom, e.prenom, e.email, e.datenaissance, e.codeClasse) == 6) {
        if (strcmp(e.numero, numero) == 0) {
            printf("Nouvelle classe : ");
            scanf("%s", codeClasse);
            if (chercher_classe(codeClasse) == NULL) {
                printf("Classe non trouvee. Modification annulee.\n");
                fprintf(temp, "%s,%s,%s,%s,%s,%s\n", e.numero, e.nom, e.prenom, e.email, e.datenaissance, e.codeClasse); 
                continue;
            }
            printf("Nouveau nom : ");
            scanf("%s", e.nom);
            printf("Nouveau prenom : ");
            scanf("%s", e.prenom);
            printf("Nouvel email : ");
            scanf("%s", e.email);
            printf("Nouvelle date de naissance : ");
            scanf("%s", e.datenaissance);
            fprintf(temp, "%s,%s,%s,%s,%s,%s\n", e.numero, e.nom, e.prenom, e.email, e.datenaissance, codeClasse);
            trouve = 1;
        } else {
            fprintf(temp, "%s,%s,%s,%s,%s,%s\n", e.numero, e.nom, e.prenom, e.email, e.datenaissance, codeClasse);
        }
    }

    fclose(fichier);
    fclose(temp);
    remove("data/etudiants.csv");
    rename("data/etudiants_tmp.csv", "data/etudiants.csv");
    if (trouve) printf("Etudiant modifie !\n");
    else {printf("Etudiant non trouve.\n"); remove("data/etudiants_tmp.csv");}
}

void supprimer_etudiant(const char *numero) {
    FILE *fichier = fopen("data/etudiants.csv", "r");
    FILE *temp = fopen("data/etudiants_tmp.csv", "w");
    if (!fichier || !temp) {
        printf("Erreur lors de l'ouverture du fichier\n");
        if (fichier) fclose(fichier);
        if (temp) fclose(temp);
        return;
    }

    char entete[256];
    if (fgets(entete, sizeof(entete), fichier)) {
        fputs(entete, temp); 
    }

    Etudiant e;
    int supprime = 0;
    while (fscanf(fichier, "%19[^,],%49[^,],%49[^,],%99[^,],%19[^,],%19[^\n]\n",
                  e.numero, e.nom, e.prenom, e.email, e.datenaissance, e.codeClasse) == 6) {
        if (strcmp(e.numero, numero) == 0) {
            supprime = 1; 
        } else {
            fprintf(temp, "%s,%s,%s,%s,%s,%s\n", e.numero, e.nom, e.prenom, e.email, e.datenaissance, e.codeClasse);
        }
    }

    fclose(fichier);
    fclose(temp);
    remove("data/etudiants.csv");
    rename("data/etudiants_tmp.csv", "data/etudiants.csv");
    if (supprime) printf("Etudiant supprime !\n");
    else {printf("Etudiant non trouve.\n"); remove("data/etudiants_tmp.csv");}
}

Etudiant* chercher_etudiant(const char *numero) {
    static Etudiant e;
    FILE *fichier = fopen("data/etudiants.csv", "r");
    if(fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return NULL;
    }
    char ligne[256];
    fgets(ligne, sizeof(ligne), fichier); 

    int trouve = 0;
    while (fscanf(fichier, "%19[^,],%49[^,],%49[^,],%99[^,],%19[^,],%19[^\n]\n", e.numero, e.nom, e.prenom, e.email, e.datenaissance, e.codeClasse) == 6) {
        if(strcmp(e.numero, numero) == 0) {
            trouve = 1;
            break;
        }
    }
    fclose(fichier);
    if(trouve) {
       
        if(chercher_classe(e.codeClasse) == NULL) {
            printf("Classe non trouve.\n");
            return NULL;
        }
         return &e;
    } else {
        return NULL;
    }
}
