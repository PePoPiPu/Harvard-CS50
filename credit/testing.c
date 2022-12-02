#include <stdio.h>

int second_last_digit(int n);
{
n = n / 10;
return n % 10;
}

int main (void)
{
    int n;
    printf("Enter a number: ");
    scanf("%d, &n");

    printf("Second Last Digit of %d = %d", n, second_last_digit(n))
}