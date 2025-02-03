/*#include <stdio.h>

#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run2++; if (message) return message; } while (0)

int tests_run2 = 0;

const char* categorize_age(int age){
	if (age < 0) {
		return "Invalid age";
	}
	else if (age < 13) {
		return "Child";
	}
	else if (age < 20) {
		return "Teenager";
	}
	else if (age < 65) {
		return "Adult";
	}
	else {
		return "Senior";
	}
}

static char* test_categorize_age_invalid() {
	char* age = categorize_age(-1);
	mu_assert("Assert failed categorize_age(): l'age de -1 est invalide\n", age =="Invalid age");
}

static char* test_categorize_age_child() {
	char* age = categorize_age(10);
	mu_assert("Assert failed categorize_age(): l'age de 10 est un child\n", age == "Child");
}

static char* test_categorize_age_teenager() {
	char* age = categorize_age(15);
	mu_assert("Assert failed categorize_age(): l'age de 15 est un teenager\n", age == "Teenager");
}

static char* test_categorize_age_adult() {
	char* age = categorize_age(50);
	mu_assert("Assert failed categorize_age(): l'age de 50 est un adulte\n", age == "Adult");
}

static char* test_categorize_age_senior() {
	char* age = categorize_age(70);
	mu_assert("Assert failed categorize_age(): l'age de 70 est un senior\n", age == "Senior");
}

static char* all_tests2() {
	mu_run_test(test_categorize_age_invalid);
	mu_run_test(test_categorize_age_child);
	mu_run_test(test_categorize_age_teenager);
	mu_run_test(test_categorize_age_adult);
	mu_run_test(test_categorize_age_senior);

	return 0;
}

int main() {
	char* result2 = all_tests2();
	if (result2 != 0) {
		printf("%s\n", result2);
	}
	else {
		printf("All tests passed.\n");
	}
	printf("Tests run : %d\n", tests_run2);
}
*/