#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// Function prototypes
bool only_digits(string s);

// Main function
int main(int argc, string argv[])
{
    // Check if program was run with one command-line argument
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Converting argv string to an intenger
    int k = atoi (argv[1]);
    // Check that the integer is possitive
    if (k < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Check if 
}

