// Write a program that reverses its input a line at a time.
// Define a reverse(s) function that reverses the character s.
#include <stdio.h>

#define NULL_CHARACTER '\0'
#define LIMIT 1000

int getNextLine(char line[], int limit);
void reverse(char line[], int len);

int main() {
	int len = 0;
	char line[LIMIT + 1];

	while ((len = getNextLine(line, LIMIT)) > 0) {
		if (len > 0) {
			reverse(line, len);
			printf("%s\n", line);
		}
	}
	return 0;
}

void reverse(char line[], int len) {
	// "1234567", reverse
	// "654321"
	// character at position 0 goes to len - 1
	//                       1 goes to len - 2
    //                       2 goes to len - 3
	// ...................................
	//                      len-1 goes to 0
	//                      len-2 goes to 1
	//
	// the repetition ends when we swap item in position len / 2 - 1
	int middle = len / 2 - 1;
	for (int i = 0; i <= middle; i++) {
		int right_pos = len - (i + 1);
		int c = line[right_pos];
		line[right_pos] = line[i];
		line[i] = c;
	}
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
