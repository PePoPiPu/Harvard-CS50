#include <stdio.h>
#include <stdlib.h>

int main (void)
{
// Initializing an array without any values. Gives us unknown values that were in memory for whatever program we were running before.
    int scores[3];
    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", scores[i]);
    }
}