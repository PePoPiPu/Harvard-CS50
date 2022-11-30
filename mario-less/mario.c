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

    for(int i = 0; i < n; i++)
    {
        printf ("#\n");
        for (int j = n; j > i; j--)
        {
            printf("#");
        }
        printf("\n");
    }
}

