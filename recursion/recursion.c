#include <stdio.h>
int fact (int n)
int main (void)
{

}


int fact(int n)
{
    // Base case
    if (n == 1)
        return 1;
    // Recursive case
    else
        return n * fact(n-1);
}