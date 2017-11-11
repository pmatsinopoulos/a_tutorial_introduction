#include <stdio.h>

/*
 * Prints the histogram of words lengths of the input text.
 */

#define MAXIMUM_WORD_LENGTH 20
#define IN_WORD 1
#define OUT_OF_WORD 2

main() {
    int word_lengths[MAXIMUM_WORD_LENGTH];
    /* word_lengths[0] holds the number of words with length 1,
     * word_lengths[1] holds the number of words with length 2,
     * e.t.c.
     */
    int i = 0;
    for (i = 0; i < MAXIMUM_WORD_LENGTH; ++i) {
        word_lengths[i] = 0;
    }

    int state = OUT_OF_WORD;
    int current_length = 0;
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN_WORD) {
                state = OUT_OF_WORD;
                ++word_lengths[current_length - 1];
                current_length = 0;
            }
        }
        else {
            state = IN_WORD;
            ++current_length;
        }
    }

    for (i = 0; i < MAXIMUM_WORD_LENGTH; ++i) {
        printf("length %2d: ", i + 1);
        for (int j = 0; j < word_lengths[i]; ++j) {
            printf("X");
        }
        printf("\n");
    }
}

