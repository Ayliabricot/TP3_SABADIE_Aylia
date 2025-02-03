#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Note** creerTableau(int nb_notes) {
	Note** notes = malloc(nb_notes * sizeof(Note));
	for (int i = 0; i < nb_notes; i++) {
		notes[i] = NULL;
	}
	return notes;
}

Note* creerNote(Note** tableau_notes, int* taille, int frequence, int duree) {
	Note* nouvelle_note = malloc(sizeof(Note));

	nouvelle_note->frequence = frequence;
	nouvelle_note->duree = duree;

	tableau_notes[*taille] = nouvelle_note;
	*taille = *taille + 1;

	return nouvelle_note;
}

void librerNotes(Note** tableau_notes, int* taille) {
	for (int i = 0; i < *taille; i++) {
		free(tableau_notes[i]);
		tableau_notes[i] = NULL;
	}
	*taille = 0;
}