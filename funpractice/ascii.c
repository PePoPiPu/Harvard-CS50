#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./ascii WORD\n");
    }

    for (int i = 1; i < argc; i++)
    {
        int h = atoi(argv[i]);
        printf("The ascii value is: %i\n", h);
    }
}