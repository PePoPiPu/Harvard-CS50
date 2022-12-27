#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
    char *s = get_string("s: ");
    char *t = malloc(strlen(s) + 1);
// If our computer is out of memory, malloc returns NULL
    if (t == NULL)
    {
        return 1;
    }

    strcpy(t, s); // Copying s into t without typing a whole for loop
//Checking if t has a lenght
    if (strlen(t) > 0)
    {
    t[0] = toupper(t[0]);
    }
    printf("s: %s\n", s);
    printf("t: %s\n", t);
//Freeing allocated memory
    free(t);
}