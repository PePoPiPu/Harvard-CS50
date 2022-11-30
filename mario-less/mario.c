#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
// Prompt user for pyramid width
    do
    {
        n = get_int ("Width: \n");
    }
    while (n < 1); while (n > 8);
}
// Print
