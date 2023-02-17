#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    char *s = malloc(4);
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}



//Example of erroneous program
//int main (void)
//{
//    char *s;
//    printf("s: ");
//Scanf is writing our string to an unknown address in memory since we didn't allocate any.
//    scanf("%s", s);
//    printf("s: %s\n", s);
//}