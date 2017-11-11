#include <stdio.h>

main() {
    int c, previous_char;
    previous_char = '\n';

    while ( (c = getchar()) != EOF ) {
        if (c != ' ' || previous_char != ' ') {
            printf("%c", c);
        }
        previous_char = c;
    }
}