#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
// Prompt user for pyramid width
    do
    {
        n = get_int ("Height: \n");
    }
// While n is less than 1 OR greater than 8
    while (n < 1 || n > 8);
}
// Print height
