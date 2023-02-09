// Testing of a hash function's distribution

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int hash(const char *word);

int main (int argc, char *argv[])
{
    if (argc < 2)
        printf("Usage: ./hashtest FILE\n");

    for (int i = 1; i < argc; i++)
    {
        int h = hash(argv[i]);
        printf("%i\n", h);
    }
}

unsigned int hash(const char *word)
{
       int l = strlen(word);
   int ascii = 0;
   int sum = 0;
   int hash_value;

   for (int i = 0; i < l; i++)
   {
        ascii += word[i];
        sum = ascii + l;
        hash_value = sum % 2069;
   }
   return hash_value;
}