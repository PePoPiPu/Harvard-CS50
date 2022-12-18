#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    if(isdigit(argc))
    {
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}