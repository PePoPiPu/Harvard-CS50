#include <stdio.h>

int main (void)
{
    char *s = "HI!";
    printf("%c\n", *s); //Go directly to the address stored in s
    printf("%c\n", *(s + 1));// Go directly to the address stored in s and go to the next location in memory, a byte higher.
    printf("%c\n", *(s + 2));
}




// An example of syntactic sugar. This way is easier to write and read by a human
//int main (void)
//{
//    char *s = "HI!";
//    printf("%c\n", s[0]);
//    printf("%c\n", s[1]);
//    printf("%c\n", s[2]);
//}