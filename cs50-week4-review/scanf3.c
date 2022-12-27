#include <stdio.h>
#include <stdlib.h>
//Example of a program that gives a segmentation fault.
int main (void)
{
    // The program works safely as long as we input a string less than 4 characters long. Higher than that, we try to touch memory that we haven't allocated, giving us a segmentation fault.
    char s[4];
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}