#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
    char *s = get_string ("s: ");
    char *t = get_string ("t :");

    if (strcmp (s, t) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}










// Example of incorrect comparison between strings
//int main (void)
//{
//    char *s = get_string("s: "); //Each char * POINTS to a different location in memory where the first character of the string is stored.
//    char *t = get_string("t: "); //Even if the characters are exactly the same, they exist in different points of memory, thus, being different.

//    if (s == t)
//    {
//        printf("Same\n");
//    }
//    else
//    {
//        printf("Different\n");
//    }
//}

// Basic program that compares 2 integers
//int main (void)
//{
//    int i = get_int("i: ");
//    int j = get_int("j: ");

//    if (i == j)
//    {
//        printf("Same\n");
//    }
//    else
//    {
//        printf("Different\n");
//    }
//}