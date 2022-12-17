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
    int length = strlen(text);
    int count = 0;

    for (int i = 0; 1 < length; i++)
        if (isalpha(text[i])) count++;

    return count;
}
