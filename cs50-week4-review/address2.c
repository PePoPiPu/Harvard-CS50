#include <cs50.h>
#include <stdio.h>

int main (void)
{
    string s = "HI!";
    char c = s[0];
    char *p = &c;
    printf("%p\n", s);
    printf("%p\n", p);
}








// Example of use of string data type, include in the CS50 library
//int main (void)
//{
//    string s = "HI!";
//    printf("%s\n", s);
//}