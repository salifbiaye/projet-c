

all:
	gcc -Wall -g -o gestion_etudiants.exe main.c \
		crud/crud_etudiant.c crud/crud_matiere.c crud/crud_classe.c crud/crud_note.c crud/crud_sefaire.c \
		menus/menu_etudiant.c menus/menu_matiere.c menus/menu_classe.c menus/menu_note.c menus/menu_sefaire.c menus/utils_menu.c

run:
	.\gestion_etudiants.exe

clean_win:
	-cmd /c del gestion_etudiants.exe

clean_lin:
	-rm -f gestion_etudiants.exe


.PHONY: all clean run clean_win clean_lin
