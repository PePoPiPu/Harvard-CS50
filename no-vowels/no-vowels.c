// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch
#include <cs50.h>
#include <stdio.h>
// Function prototypes
char replace (char argv[1]);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    printf("%c\n", replace(argv[1]));

}

char replace (char argv[1])
{
    char word[sizeof(argv[1])] = 0;
    char *word[sizeof(argv[1])] = argv[1];

    for (int i = 0; i < sizeof(argv[1]); i++)
    {
        if(word[i] == 'a')
        {
            word[i] = '6';
        }

        if(word[i] == 'e')
        {
            word[i] = '3';
        }

        if(word[i] == 'i')
        {
            word[i] = '1';
        }

        if(word[i] == 'o')
        {
            word[i] = '0';
        }

        if(word[i] == 'u')
        {
            word[i] = 'u';
        }


    }
    return word;
}
