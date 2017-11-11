#include <stdio.h>

#define IN_WORD 1
#define OUT_OF_WORD 0

main() {
    int c;
    int state = OUT_OF_WORD;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN_WORD) {
                state = OUT_OF_WORD;
                printf("\n");
            }
            else {
                /* ignore */
            }
        }
        else {
            state = IN_WORD;
            printf("%c", c);
        }
    }
}