#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);

int main(void)
{
    string s = get_string("Text: ");
    printf("%s\n", s);
}

int count_letters(string text)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}
