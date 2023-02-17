#include <cs50.h>
#include <stdio.h>
// This is a review of recursion. The ability of a function to call itself

// We can write a recursive function that calls itself to draw a smaller pyramid before adding another row
 void draw(int n); // Prototyping "draw" function

 int main (void)
 {
    int height = get_int("Height: ");

    draw(height); // Calling "draw" function
 }

void draw(int n) // Defining "draw" function
{
    if (n <= 0) // If n is 0 or negative, we stop without printing. We make sure we stop for some base case so our function doesn't call itself over and over forever.
    {
        return;
    }

    draw(n - 1); // Calling draw to print a pyramid of size n - 1

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}








// One way to print a pyramid of n height
//void draw (int n);

//int main (void)
//{
//    int height = get_int("Height: ");
//
//    draw(height);
//}

//void draw (int n) // Draw function that takes an argument, n.
//{
    // Uses a loop to print n rows with more and more bricks in each row.
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < i + 1; j++)
//        {
//            printf("#");
//        }
//        printf("\n");
//    }
//}