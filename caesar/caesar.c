#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if(isdigit(argc))
    {
        return 0;
    }
    else
    {
        printf ("Usage: ./caesar key\n");
        return 1;
    }

    // Check if the Key is made up of only digits
    bool only_digits(string s);
    {
        char c = get_char("Key: ");
        if (isdigit(c))
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

