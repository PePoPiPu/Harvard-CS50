#include <cs50.h>
#include <stdio.h>

int main (void)
{
    string s = "HI!";
    char c = s[0]; //Storing the first character of s into c
    char *p = &c;
    printf("%p\n", s); //Priting out the address of the first character
    printf("%p\n", p); // Printing out s as an address
}








// Example of use of string data type, include in the CS50 library
//int main (void)
//{
//    string s = "HI!";
//    printf("%s\n", s);
//}