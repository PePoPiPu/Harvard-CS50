#include <stdio.h>

long second_last_digit(long n)
{
n = n / 10;
return n % 10;
}

int main (void)
{
    long n;
    printf("Enter a number: ");
    scanf("%ld", &n);

    printf("Second Last Digit of %ld = %ld", n, second_last_digit(n));
    printf("\n");
}
