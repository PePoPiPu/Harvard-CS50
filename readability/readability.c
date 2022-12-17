#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);

float l;
int main(void)
{
    string s = get_string("Text: ");
    int letters = count_letters(s);
    printf("%s\n");
}

int count_letters(string text)
{
    int chars = 0;
    for(int i = 0; text[i] != '\0' ; i++)
    {
        if (isalpha[i])
        {
            chars++
        }
    }
    return chars;
}
