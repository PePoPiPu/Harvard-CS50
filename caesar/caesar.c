#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
bool only_digits(string s);
int atoi(string s);

// Main function
int main(int argc, string argv[])
{
    // Check if program was run with one command-line argument
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Callling only_digits function. Takes argument vector 1 as an argument and outputs an answer.
    bool answer = only_digits(argv[1]);
    {
        if (answer == true)
        {
            return 0;
        }
    }
}

// Function that checks if input is made up of only digits, returns boolean value
bool only_digits(string s)
{
    for (int i = 0, length = strlen(s);i < length; i++)
    {
        if (!isdigit(s[i]))
        {
            printf("Usage: ./caesar key\n");
            return false;
        }
    }
    return true;
}

