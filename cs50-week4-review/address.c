#include <stdio.h>

int main (void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p); //%p os the format code to print an adress. After it we need to use the name of the variable we have created, p.
    printf("%i\n", *p);//In this case,* is a dereference operator. Goes to the address in p to get the value stored there.
}