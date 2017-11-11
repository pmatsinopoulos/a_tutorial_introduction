// Print all input lines that are longer than 80 chars long
#include <stdio.h>

#define LIMIT 100
#define MAX_LENGTH_TO_PRINT 10
#define NULL_CHARACTER '\0'

int getNextLine(char line[], int limit);

int main() {
	int len = 0;
	char nextLine[LIMIT + 1]; // add 1 to put the null termination character

	while ((len = getNextLine(nextLine, LIMIT)) > 0) {
		if (len > MAX_LENGTH_TO_PRINT) {
			printf("%s\n", nextLine);
		}
	}
	return 0;
}

int getNextLine(char line[], int limit) {
	int i = 0;
	int c;

	while ((c = getchar()) != EOF && i < limit && c != '\n') {
		line[i] = c;
		i++;
	}
    line[i] = NULL_CHARACTER;

	return i;
}
