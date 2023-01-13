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
    char *word = argv[1];

    for (int i = 0; i < sizeof(argv[1]); i++)
    {
        if(word[i] == 'a')
        {
            'a' == '6';
        }

        if(word[i] == 'e')
        {
            'e' == '3';
        }

        if(word[i] == 'i')
        {
            'i' == '1';
        }

        if(word[i] == 'o')
        {
            'o' == '0';
        }

        if(word[i] == 'u')
        {
            'u' == 'u';
        }


    }
    return 1;
}
