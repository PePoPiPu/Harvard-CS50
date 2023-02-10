#include <stdio.h>
#include <stdlib.h>

unsigned int hash(int input);

int main (int argc, char *argv[])
{
    if(argc < 2)
        printf("Usage: ./hasp WORD\n");

    for (int i = 1; i < argc; i++)
    {
        int h = hash(atoi(argv[i]));
        printf("The hash values are %i\n", h);
    }
}

unsigned int hash(int input)
{
    int x = input % 10;
    return x;
}