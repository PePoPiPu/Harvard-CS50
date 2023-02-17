#include <stdio.h>
#include <stdlib.h>

int main (void)
{
//Getting enough memory for 3 times the size of an int (4 x 3 = 12 bytes)
    int *x = malloc(3 * sizeof(int));
//Starting an array with 1 instead of 0 (Remember that all arrays are 0 indexed). We are trying to access memory beyond the bounds of what we have access to.
    x[1] = 72;
    x[2] = 73;
    x[3] = 33;
//We didn't free the memory we allocated.
}

//These mistakes aren't bad enough here but in a real setting, it might cause a segmentation fault.
//Executing VALGRIND gives us: Invalid write of size for at memory.c:11 due to the indexing error. We'll fix it in memory2.c