#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Prompt user for text
    string text = get_string("Text: ");
    printf("%s\n", text);

    // Counting the letters of the text
    int letters = 0;
    // Setting the counter to 0, the loop runs for the length of the string, runs through every character.
    for (int i = 0; i < strlen(text); i++)
    {
        // If the character evaluated is a lowercase OR uppercase letter, add 1 to the 'letters' counter.
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
    }

    // Counting the number of words (Number of spaces + 1)
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }

    // Counting the number of sentences (Number of periods, exclamation and question markssub)
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }

    // Determining the reading grade level using the Coleman - Liau index
    float calculation = (0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8;
    int index = round(calculation);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", index);
    }

}


