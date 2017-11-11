#include <stdio.h>

#define NULL_CHARACTER '\0'
#define NEW_LINE_CHARACTER '\n'
#define MAX_LENGTH_TO_PRINT 10

void copy(char to[], char from[]);

int main() {
	int c;
	int currentLength = 0;
	int maxLength = 0;
	char maxLengthCase[MAX_LENGTH_TO_PRINT + 1]; // add 1 to store the null character
	char currentCase[MAX_LENGTH_TO_PRINT + 1]; // add 1 to store the null character
	int i = 0;

	while ((c = getchar())!=EOF) {
		currentLength += 1;
		if (i <= MAX_LENGTH_TO_PRINT - 1)
		  currentCase[i] = c;
		i++;

		// while we are getting a character from the input
		while ((c = getchar()) != NEW_LINE_CHARACTER) {
			currentLength += 1;
			if (i <= MAX_LENGTH_TO_PRINT - 1)
			  currentCase[i] = c;
			i++;
		}
		// we are at the end of a line
		if (currentLength > maxLength) {
			maxLength = currentLength;
			currentCase[MAX_LENGTH_TO_PRINT] = NULL_CHARACTER;
			copy(maxLengthCase, currentCase);
		}
		currentLength = 0;
		i = 0;
	}

	printf("max length %d\n", maxLength);
	printf("max length word %s\n", maxLengthCase);
	return 0;
}

/* assumes that there is enough space at the destination for the line to be copied to */
void copy(char to[], char from[]) {
	int i;
	i = 0;
	while ((to[i] = from[i]) != NULL_CHARACTER) // copies until it copies the string termination character NULL
		++i;
}
