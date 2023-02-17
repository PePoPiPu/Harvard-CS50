// Program that uses a hash function to print hash values
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
   int l = strlen(word);
   int ascii = 0;
   int sum = 0;
   int hash_value;

   for (int i = 0; i < l; i++)
   {
        ascii += word[i] % 599;
        sum = ascii + l;
        hash_value = sum/100;

        if (hash_value == 0)
        {
            hash_value = sum/100 + 1;
        }
   }
   return hash_value;
}