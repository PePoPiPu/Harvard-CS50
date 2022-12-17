#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);

float l;
int main(void)
{
    string s = get_string("Text: ");
    printf("%i\n", int);
}

int count_letters(string text)
{
    l = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha (text[i]))
        {
            l++;
        }
    }
    return l;
}
