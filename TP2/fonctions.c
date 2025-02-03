#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "header.h"
#include <windows.h>

Note** creerTableau(int nb_notes) {
	Note** notes = malloc(nb_notes * sizeof(Note));
	for (int i = 0; i < nb_notes; i++) {
		notes[i] = NULL;
	}
	return notes;
}

Note* creerNote(float frequence, int duree) {
	Note* nouvelle_note = malloc(sizeof(Note));

	nouvelle_note->frequence = frequence;
	nouvelle_note->duree = duree;

	return nouvelle_note;
}

int trouverNote(Note** tableau_notes, int touche) {
	switch (touche) {
	case 97:
		Beep(tableau_notes[0]->frequence, tableau_notes[0]->duree);
		break;
	case 122:
		Beep(tableau_notes[1]->frequence, tableau_notes[1]->duree);
		break;
	case 101:
		Beep(tableau_notes[2]->frequence, tableau_notes[2]->duree);
		break;
	case 114:
		Beep(tableau_notes[3]->frequence, tableau_notes[3]->duree);
		break;
	case 116:
		Beep(tableau_notes[4]->frequence, tableau_notes[4]->duree);
		break;
	case 121:
		Beep(tableau_notes[5]->frequence, tableau_notes[5]->duree);
		break;
	case 117:
		Beep(tableau_notes[6]->frequence, tableau_notes[6]->duree);
		break;
	case 105:
		Beep(tableau_notes[7]->frequence, tableau_notes[7]->duree);
		break;
	case 111:
		Beep(tableau_notes[8]->frequence, tableau_notes[8]->duree);
		break;
	case 112:
		Beep(tableau_notes[9]->frequence, tableau_notes[9]->duree);
		break;
	case 115:
		Beep(tableau_notes[10]->frequence, tableau_notes[10]->duree);
		break;
	case 100:
		Beep(tableau_notes[11]->frequence, tableau_notes[11]->duree);
		break;
	case 113:
		return 0;
	}
	return 1;
}

void libererNotes(Note** tableau_notes, int taille) {
	for (int i = 0; i < taille; i++) {
		free(tableau_notes[i]);
		tableau_notes[i] = NULL;
	}
}