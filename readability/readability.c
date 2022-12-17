#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    // Prompt user for text
    string text = get_string("Text: ");
    printf("%s\n", text);

    // Counting the letters of the text

    int letters = 0;
    for(int i = 0; i < strlen(text); i++)
    {
        if((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        letters++;
    }
    printf("%i letters", letters);
    printf("\n");
}


