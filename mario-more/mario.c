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
    while (n < 1 || n > 8);
// Ask for height when n is lesser than 1 or greater than 8
// Height of first pyramid
// Print spaces of the first pyramid
// Print hashes of the first pyramid
// Print space between the two pyramids
// Height of second pyramid
// Print hashes of second pyramid
}