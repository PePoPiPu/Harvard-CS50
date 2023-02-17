#include <stdio.h>

// Hash Function example
unsigned int hash(char* str);

int main (void)
{

}

unsigned int has(char* str)
{
    int sum = 0;
    for (int j = 0; str[j] != '\0'; j++)
    {
        sum += str[j];
    }
    return sum % HASH_MAX;
}