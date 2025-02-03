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

static char* all_tests() {
	mu_run_test(test_creerTableau);

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