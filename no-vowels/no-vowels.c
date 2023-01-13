// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch
#include <cs50.h>
#include <stdio.h>
// Function prototypes
char replace (char argv[1]);

int main(int argc, char* argv[])
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


    for (int i = 0; i < sizeof(argv[1]); i++)
    {
        if(argv[i] == 'a')
        {
            argv[i] = '6';
        }

        if(argv[i] == 'e')
        {
            argv[i] = '3';
        }

        if(argv[i] == 'i')
        {
            argv[i] = '1';
        }

        if(argv[i] == 'o')
        {
            argv[i] = '0';
        }

        if(argv[i] == 'u')
        {
            argv[i] = 'u';
        }


    }
    return argv[1];
}
