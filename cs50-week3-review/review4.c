#include <cs50.h>
#include <stdio.h>
// This is a review of recursion. The ability of a function to call itself

void draw (int n);

int main (void)
{
    int height = get_int("Height: ");

    draw(height);
}

void draw (int n) // Draw function that takes an argument, n.
{
    // Uses a loop to print n rows with more and more bricks in each row.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}