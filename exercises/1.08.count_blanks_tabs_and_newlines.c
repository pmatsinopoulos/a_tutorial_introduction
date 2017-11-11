#include <stdio.h>

main()
{
    int number = 0;
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t' || c == ' ' || c == '\n') {
            ++number;
        }
    }

    printf("Number of blanks, tabs and newlines: %d\n", number);
}
