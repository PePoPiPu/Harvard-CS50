#include <cs50.h>
#include <stdio.h>

int main(void)
{
// Declaration of the variable "n"
   int n;
// Prompt user for pyramid height
    do
    {
        n = get_int("Height: \n");
    }
// Ask for height when n is lesser than 1 or greater than 8
    while (n < 1 || n > 8);
// Height of first pyramid
    for (int i = 0; i < n; i++)
    {
// Print spaces of the first pyramid
        for (int j = n - 1; j > i; j--)
        {
            printf(" ");
        }
// Print hashes of the first pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
// Print spaces between pyramids
        for (int j = 2; j <= i)
        {
            printf ("  ");
        }
// Print hashes of second pyramid
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

// Escape Sequence
    printf("\n");
    }
}