#include <stdio.h>
#include <stdlib.h>
unsigned int ascii_values (const char *word);
int main (int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./ascii WORD\n");
    }
    int ascii = ascii_values(argv[]);
    printf ("The ascii value is %i\n", ascii)
}

unsigned int ascii_values (const char *word)
{
    int l = strlen(word);
    int ascii = 0;
    for(int i = 0; i < l; i++)
    {
        ascii = word;
    }
    return ascii;
}