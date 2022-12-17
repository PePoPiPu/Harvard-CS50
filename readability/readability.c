#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);

float l;
int main(void)
{
    string text = get_string("Text: ");
    printf("%s\n", text);
}

