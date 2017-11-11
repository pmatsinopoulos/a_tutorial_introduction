// A program to remove trailing blanks and tabs from each line of input
// and to delete entirely blank lines
#include <stdio.h>

#define NULL_CHARACTER '\0'
#define LIMIT 1000
#define FALSE 0
#define TRUE 1

int getNextLine(char line[], int limit);
int removeTrailingBlanks(char line[], char output[]);

int main() {
	int len = 0;
	char line[LIMIT + 1];
	char output[LIMIT + 1];

	while ((len = getNextLine(line, LIMIT)) > 0) {
		len = removeTrailingBlanks(line, output);
		if (len > 0) {
			printf("%s\n", output);
		}
	}
	return 0;
}

int removeTrailingBlanks(char line[], char output[]) {
	// find first non-blank character position
	int first_non_blank_pos = 0;
	while ((line[first_non_blank_pos] == ' ' || line[first_non_blank_pos] == '\t') && line[first_non_blank_pos] != NULL_CHARACTER) {
		first_non_blank_pos++;
	}

	// find last non-blank character position
	int last_non_blank_pos = first_non_blank_pos + 1;
	int r = last_non_blank_pos;
	while (line[r] != NULL_CHARACTER) {
		if (line[r] != ' ' && line[r] != '\t') {
			last_non_blank_pos = r;
		}
		r++;
	}

	// Transfer the appropriate characters from input to output.
	// The characters to transfer are from the first non-blank till the last non-blank character.

	int output_char_pos = 0;
	for (int input_char_pos = first_non_blank_pos; input_char_pos <= last_non_blank_pos; input_char_pos++, output_char_pos++) {
		output[output_char_pos] = line[input_char_pos];
	}
	return output_char_pos; // return the length of the output string
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
