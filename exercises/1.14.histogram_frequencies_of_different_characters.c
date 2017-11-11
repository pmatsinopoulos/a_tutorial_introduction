#include <stdio.h>

#define NUMBER_OF_CHARACTERS 255

/* returns the histogram of the character occurrences */
main() {
	int number_of_occurrences[NUMBER_OF_CHARACTERS];

	for (int i = 0; i < NUMBER_OF_CHARACTERS; i++) {
		number_of_occurrences[i] = 0;
	}

	int c;

	while ((c = getchar()) != EOF) {
		number_of_occurrences[c]++;
	}

	for (int i = 0; i < NUMBER_OF_CHARACTERS; i++) {
		if (number_of_occurrences[i] == 0) {
			continue;
		}
		printf("%c:", i);
		for (int j = 0; j < number_of_occurrences[i]; j++) {
			printf("X");
		}
		printf("\n");
	}

	return 0;
}
