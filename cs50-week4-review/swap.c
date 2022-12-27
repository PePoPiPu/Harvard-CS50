#include <stdio.h>

void swap(int a, int b);

int main (void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(x , y);
    printf("x is %i, y is %i\n", x, y);
}

void swap (int a, int b)
{
    // a and b are local variables only accessed by the sorrounding function. They cannot be accessed by main and that's why we don't see a swap in x and y.
    int tmp = a;
    a = b;
    b = tmp;
}