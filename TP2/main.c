#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "header.h"
#include <windows.h>

int main() {
	int taille = 0;
	int continuer = 1;
	int touche;
	
	Note** tableau_notes = creerTableau(12);
	float frequencies[12] = { 261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88 };
	
	for (int i = 0; i < 12; i++) {
		tableau_notes[i] = creerNote(frequencies[i], 80);
		taille = taille + 1;
	}

	printf("Voici votre piano :\na z e r t y u i o p s d\nTapez 'q' pour quitter.");
	while (continuer==1) {
		continuer = trouverNote(tableau_notes);
	}

	return 0;
}