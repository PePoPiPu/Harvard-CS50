#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
}

bool only_digits(string s)
{
    for (int i = 0; length = strlen(s); i < length; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
        return true;
    }
}

