#include <cs50.h>
#include <stdio.h>
float mult_two_floats (float a, float b);
int add_two_ints (int a, int b);
int main (void)
{
    int x = get_int("Give me an integer: \n");

    int y = get_int("Give me another integer \n");

    int z = add_two_ints (x, y);

    printf("The sum if %i and %i is %i\n", x, y, z);
}

float mult_two_floats(float a, float b)
{
    float product = a * b;
    return product;
}

int add_two_ints (int a, int b)
{
    int sum = a + b;
    return sum;
}