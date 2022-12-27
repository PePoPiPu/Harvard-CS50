#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    string s = get_string ("s: ");

    string t = s; //Copying the value of s into t. This means we set s and t to the same adress, capitalizing the same first character.

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}