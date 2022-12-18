#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    if(isdigit(argc))
    {
        printf("Key is correct\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}