#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};
    // Initializing for loop, index 0 (1st position in the array), while the index is less than 7th position, count up once.
    for (int i = 0; i < 7; i++)
    {
    // If one of the numbers in the array equals 0, print and return and exit status of 0
        if (numbers[i] == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}