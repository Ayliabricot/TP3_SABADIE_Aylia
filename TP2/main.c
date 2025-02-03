#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
	int taille = 0;
	int* pTaille = &taille;
	Note** tableau_notes = creerTableau(10);
	Note* note1 = creerNote(tableau_notes,pTaille,20, 4);

	printf("%d %d", tableau_notes[0]->frequence, tableau_notes[0]->duree);

	librerNotes(tableau_notes, pTaille);

	return 0;
}