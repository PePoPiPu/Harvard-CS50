#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    bool is_prime = false;
    for (int i = number; i <= max; i++)
    {
        if((i % i + 1 && i % 1 && i % 2) == 0)
        {
            is_prime = false;
        }
        else
            is_prime = true;
    }

    return is_prime;
}
