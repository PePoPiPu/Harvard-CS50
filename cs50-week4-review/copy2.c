#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
    char *s = get_string("s: ");
    char *t = malloc(strlen(s) + 1); // Allocating memory for s lenght + 1 to leave space for the null character.

    for (int i = 0, n = strlen(s) + 1; i < n; i++) //Copying each character one at a time. We use strlen(s) + 1 to copy the null character too.
    {
        t[i] = s[i]; //Assigning the characters of s to t
    }

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}