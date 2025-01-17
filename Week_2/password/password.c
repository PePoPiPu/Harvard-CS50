// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int length = strlen(password);

    bool has_upper = false;
    bool has_lower = false;
    bool has_number = false;
    bool has_symbol = false;

    for (int i = 0; i < length; i++)
    {
        if (isupper(password[i])) has_upper = true;
        if (islower(password[i])) has_lower = true;
        if (isdigit(password[i])) has_number = true;
        if (!isalpha(password[i])) has_symbol = true;
    }

        if (!has_upper) return false;
        if (!has_lower) return false;
        if (!has_number) return false;
        if (!has_symbol) return false;

        return true;
}
