// Program that uses a hash function to print hash values
#include <stdio.h>
#include <stdlib.h>
unsigned int hash (const char *word);
int main (int argc, char *argv[])
{
    // Ensure proper usage
    if (argc < 2)
        printf("Usage: ./hash WORD\n");

    for (int i = 1; i < argc; i++)
    {
        int h = hash(argv[i]);
        printf("%i\n", h);
    }
}

unsigned int hash (const char *word)
{
    
}