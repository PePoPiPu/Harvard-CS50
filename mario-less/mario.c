#include <cs50.h>
#include <stdio.h>

int main(void)
{
// Declaration of the variable
    int n;
// Prompt user for pyramid width
    do
    {
        n = get_int ("Height: \n");
    }
// While n is less than 1 OR greater than 8
    while (n < 1 || n > 8);
// Height
    for(int i = 0; i < n; i++)
    {
// Printing the hashes
        for (int j = 0; j <= i; j++)
        {
            printf ("#");
        }
// Escape sequence
        printf("\n");
    }
}

