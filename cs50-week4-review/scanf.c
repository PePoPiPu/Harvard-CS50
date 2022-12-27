#include <stdio.h>

int main (void)
{
    int x;
    printf("x: ");
//"Scans" the input for the format in the placeholder. Then it passes the address in memory where we want that into put to go. In this case, we want it to go to a variable called x.
    scanf("%i", &x);
    printf("x: %i\n",x);
}