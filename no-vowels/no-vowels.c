// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch
#include <cs50.h>
#include <stdio.h>
// Function prototypes
string replace (string argv[1]);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }


}

string replace (string argv[1])
{
    string s = argv[1];
    char arrayc [argv] = s;

    for (int i = 0; i < arrayc[argv[1]]; i++)
    {
        if(arrayc == 'a')
        {
            'a' == '6';
        }

        if(arrayc == 'e')
        {
            'e' == '3';
        }

        if(arrayc == 'i')
        {
            'i' == '1';
        }

        if(arrayc == 'o')
        {
            'o' == '0';
        }

        if(arrayc == 'u')
        {
            'u' == 'u';
        }


    }
    return 1;
}
