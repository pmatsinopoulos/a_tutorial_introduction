#include <stdio.h>

/* count characters in input; 1st version */
main()
{
    long nc;
    
    nc = 0;

    while (getchar()!= EOF)
        ++nc;

    printf("Number of characters: %ld\n", nc);
}
