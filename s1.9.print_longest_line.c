#include <stdio.h>

#define MAXLINE 1000
#define NULL_CHARACTER '\0'

int myGetline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
	int len; /* current line length */
	int max; /* maximum length seen so far */
	char line[MAXLINE]; /* current input line */
	char longest[MAXLINE]; /* longest line saved here*/

	max = 0;
	while ((len = myGetline(line, MAXLINE)) > 0 ) {
		if (len > max) {
			max = len; // get the new max length
			copy(longest, line);
		}
	}

	if (max > 0) {
		printf("%s", longest);
	}
	return 0;
}

int myGetline(char line[], int maxline) {
	int c, i;

	for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}

	if (c == '\n') {
		line[i] = c;
		++i;
	}

	line[i] = NULL_CHARACTER;
	return i;
}

/* assumes that there is enough space at the destination for the line to be copied to */
void copy(char to[], char from[]) {
	int i;
	i = 0;
	while ((to[i] = from[i]) != NULL_CHARACTER) // copies until it copies the string termination character NULL
		++i;
}
