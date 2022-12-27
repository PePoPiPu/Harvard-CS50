#include <stdio.h>

int main (void)
{
    char *s = "HI!";
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
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