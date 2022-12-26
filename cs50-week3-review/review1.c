#include <cs50.h>
#include <stdio.h>
// This is a review of arrays
int main (void)
{
    // Initializing the array
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};
    // Initializing for loop, index 0 (1st position in the array), while the index is less than 7th position, count up once.
    for (int i = 0; i < 7; i++)
    {
    // If one of the numbers in the array equals 0, print and return and exit status of 0
        if (numbers[i] == -1)
        {
            printf("Found\n");
    // Exit code of 0: Indicates success.
            return 0;
        }
    }
    printf("Not found\n");
    // Exit code of 1: Error code
    return 1;
}