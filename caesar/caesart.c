#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main (int argc, string argv[])
{
        char c = get_char("Key:");
    if(isdigit(c))
    {
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}