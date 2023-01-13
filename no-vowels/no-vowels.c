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
    


    for (int i = 0; i < s; i++)
    {
        if(s == 'a')
        {
            'a' == '6';
        }

        if(s == 'e')
        {
            'e' == '3';
        }

        if(s == 'i')
        {
            'i' == '1';
        }

        if(s == 'o')
        {
            'o' == '0';
        }

        if(s == 'u')
        {
            'u' == 'u';
        }


    }
    return 1;
}
