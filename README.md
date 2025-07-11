# Guide du Projet Gestion d'Étudiants en C

Ce projet est une application console simple pour gérer des étudiants, des classes, des matières, des notes et leurs associations.

---

## Structure complète du projet

```
projet-c/
├── main.c
├── Makefile
├── gestion_etudiants.exe
├── crud/
│   ├── crud_classe.c
│   ├── crud_etudiant.c
│   ├── crud_matiere.c
│   ├── crud_note.c
│   ├── crud_sefaire.c
│   └── lib/
│       ├── crud_classe.h
│       ├── crud_etudiant.h
│       ├── crud_matiere.h
│       ├── crud_note.h
│       └── crud_sefaire.h
├── data/
│   ├── classes.csv
│   ├── etudiants.csv
│   ├── matieres.csv
│   ├── notes.csv
│   └── sefaire.csv
├── menus/
│   ├── menu_classe.c
│   ├── menu_etudiant.c
│   ├── menu_matiere.c
│   ├── menu_note.c
│   ├── menu_sefaire.c
│   └── lib/
│       ├── menu_classe.h
│       ├── menu_etudiant.h
│       ├── menu_matiere.h
│       ├── menu_note.h
│       └── menu_sefaire.h
└── struct/
    └── structs.h
```

### Détail des dossiers :
- **crud/** : Fonctions CRUD (Create, Read, Update, Delete) pour chaque entité.
- **crud/lib/** : Fichiers d'en-tête (.h) associés aux CRUD.
- **data/** : Fichiers CSV utilisés comme base de données simple (un fichier par entité).
- **menus/** : Fonctions pour gérer les menus utilisateurs (console).
- **menus/lib/** : Headers pour les menus.
- **struct/** : Fichier `structs.h` qui définit toutes les structures (`Etudiant`, `Classe`, etc.).
- **main.c** : Point d'entrée du programme, gère le menu principal.
- **Makefile** : Fichier pour compiler automatiquement tout le projet.

---

## Guide rapide : le Makefile

### Qu'est-ce qu'un Makefile ?
Un **Makefile** permet d'automatiser la compilation d'un projet C. Au lieu de taper une longue commande `gcc` à chaque fois, il suffit d'écrire `make` dans le terminal, et tout est compilé automatiquement.

**Avantages :**
- Plus besoin de se souvenir de toutes les options de compilation.
- Mise à jour automatique : seuls les fichiers modifiés sont recompilés.
- Possibilité d'ajouter des commandes utiles (nettoyage, exécution...).

### Contenu du Makefile (expliqué ligne par ligne)

```makefile
all:
	gcc -Wall -g -o gestion_etudiants.exe main.c \
	    crud/crud_etudiant.c crud/crud_matiere.c crud/crud_classe.c crud/crud_note.c crud/crud_sefaire.c \
	    menus/menu_etudiant.c menus/menu_matiere.c menus/menu_classe.c menus/menu_note.c menus/menu_sefaire.c
      menus/utils_menu.c

run:
	./gestion_etudiants.exe

clean_win:
	cmd /c del gestion_etudiants.exe

clean_lin:
  rm -rf gestion_etudiants.exe
```

#### Explications :
- **all:**
  - C'est la règle par défaut. Quand tu tapes `make`, cette règle est exécutée.
  - Elle compile tous les fichiers `.c` en un seul exécutable `gestion_etudiants.exe`.
  - `gcc` : le compilateur C.
  - `-Wall` : affiche tous les warnings (recommandé pour apprendre !).
  - `-g` : ajoute les infos de debug.
  - `-o gestion_etudiants.exe` : nom du programme compilé.
  - Les fichiers `.c` listés sont tous les modules du projet.

- **run:**
  - Permet de lancer le programme compilé directement avec `make run`.

- **clean_win:**
  - Supprime les fichiers `.exe` sur Windows (commande DOS).

- **clean_lin:**
  - Supprime les fichiers `.exe` sur Linux (commande Unix).

### Pourquoi utiliser un Makefile ?
- **Simplicité** : Un seul mot (`make`) pour tout compiler.
- **Automatisation** : Pas besoin de retaper les commandes à chaque changement.
- **Organisation** : Tu peux ajouter des règles pour exécuter, nettoyer, etc.
- **Partage** : Le projet est plus facile à relancer sur un autre PC.

---

## Comment lancer le projet ?

1. Ouvre un terminal dans le dossier du projet.
2. Compile avec :
   ```
   make
   ```
3. Lance le programme :
   ```
   make run
   ```
4. Pour nettoyer les exécutables :
   - Sous Windows : `make clean_win`
   - Sous Linux : `make clean_lin`

---

## Remarque

Bonne découverte !
