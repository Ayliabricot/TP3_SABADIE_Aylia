#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "header.h"
#include <windows.h>

#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; if (message) return message; } while (0)

int tests_run = 0;

static char* test_creerTableau() {
	Note** notes = creerTableau(12);
	Note** test = malloc(12 * sizeof(Note));
	for (int i = 0; i < 12; i++) {
		test[i] = NULL;
	}
	int verifier = 0;
	for (int i = 0; i < 12; i++) {
		if (test[i] != notes[i]) {
			verifier = 1;
		}
	}
	mu_assert("Assert failed creerTableau(): le tableau de notes est mal initialise\n", verifier == 0);
}

static char* test_creerNote() {
	Note* note = creerNote(40,5);
	int verifier = 0;
	mu_assert("Assert failed creerNote(): la note est mal créée\n", note->frequence == 40 && note->duree==5);
}

static char* test_trouverNote_enregistree() {
	Note** test = creerTableau(12);
	float frequencies[12] = { 261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88 };
	for (int i = 0; i < 12; i++) {
		test[i] = creerNote(frequencies[i], 300);
	}
	int retour = trouverNote(test,'a');
	mu_assert("Assert failed trouverNote(): la touche est enregistree mais ne retourne pas la bonne note\n", retour == 1);
}

static char* test_trouverNote_non_enregistree() {
	Note** test = creerTableau(12);
	float frequencies[12] = { 261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88 };
	for (int i = 0; i < 12; i++) {
		test[i] = creerNote(frequencies[i], 300);
	}
	int retour = trouverNote(test, 'v');
	mu_assert("Assert failed trouverNote(): la touche n'est pas enregistree mais la fonction ne renvoie pas le 1 pour continuer\n", retour == 1);
}

static char* test_trouverNote_quitter() {
	Note** test = creerTableau(12);
	float frequencies[12] = { 261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88 };
	for (int i = 0; i < 12; i++) {
		test[i] = creerNote(frequencies[i], 300);
	}
	int retour = trouverNote(test, 'q');
	mu_assert("Assert failed trouverNote(): Le q ne permet pas de quitter le simulateur de piano\n", retour == 0);
}

static char* test_libererMemoire() {
	Note** notes_liberees = creerTableau(12);
	float frequencies[12] = { 261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88 };
	for (int i = 0; i < 12; i++) {
		notes_liberees[i] = creerNote(frequencies[i], 300);
	}
	libererNotes(notes_liberees, 12);
	Note** test = creerTableau(12);
	int verifier = 0;
	for (int i = 0; i < 12; i++) {
		if (test[i] != notes_liberees[i]) {
			verifier = 1;
		}
	}
	mu_assert("Assert failed trouverNote(): La memoire n'est pas liberee\n", verifier == 0);
}

static char* all_tests() {
	mu_run_test(test_creerTableau);
	mu_run_test(test_creerNote);
	mu_run_test(test_trouverNote_enregistree);
	mu_run_test(test_trouverNote_non_enregistree);
	mu_run_test(test_trouverNote_quitter);
	mu_run_test(test_libererMemoire);

	return 0;
}

int main() {
	char* result = all_tests();
	if (result != 0) {
		printf("%s\n", result);
	}
	else {
		printf("All tests passed.\n");
	}
	printf("Tests run : %d\n", tests_run);
}