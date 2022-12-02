#include <cs50.h>
#include <stdio.h>

int main(void)
{
// Definitions

// Prompt the user for credit card number
    long n = get_long("Type your credit card number: ");

//Check Sum
// Multiply every other digit by 2, starting with second-to-last digit
    // Get second-to-last digit
    long second_last_digit(long n);
    {
        n = n /10;
        return n % 10;
    }

    scanf("%ld", &n);
    printf("Second To Last Digit of %ld = %ld", n, second_last_digit(n));


    // Add those products digits together
    // Add the sum to the sum of the digits that weren't multipliead by 2
    // Is it valid? Total's last digit is 0

// Detect type of credit card
    // American Express: 15 digits. 34 or 37
    // MasterCard: 16 digits. 51, 52, 53, 54, 55
    // Visa: 13 or 16 digits. 4 j

// Print AMEX, MASTERCARD, VISA or INVALID
}