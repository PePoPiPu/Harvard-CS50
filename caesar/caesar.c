#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
bool only_digits(string s);
char rotate(char c, int k);

// Main function
int main(int argc, string argv[])
{
    // Check if program was run with one command-line argument
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert the key into an int
    int k = atoi(argv[1]);
    // Calll only_digits function. Takes argument vector 1 as an argument and outputs an answer.
    bool answer = only_digits(argv[1]);
    {
        if (answer == true)
        {
            string plaintext = get_string("Plaintext: ");
            printf("Ciphertext: ");

            int length_text = strlen(plaintext);
            for (int i = 0; i < length_text; i++)
            {
                printf("%c", rotate(plaintext[i], k));
            }
            printf("\n");
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
            return 1;
        }
    }
    return true;
}

// Function that takes the plaintext and rotates each character by n times.

char rotate (char c, int k)
{
    // Check if the character is alphabetical and if so, check if is upper/lower and apply formula
    if(isalpha(c))
    {
        if(isupper(c))
        {
            char new_c = ((c - 65 + k) % 26) + 65;
            return new_c;
        }

        else
        {
            char new_c = ((c - 97 + k) % 26) + 97;
            return new_c;
        }
    }
    // Return plain character without rotating it if it's not alphabetical
    else
    {
        return c;
    }
}
