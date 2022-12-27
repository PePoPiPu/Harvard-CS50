#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int *x = malloc(3 * sizeof(int));
    x[0] = 72;
    x[1] = 73;
    x[2] = 33;

    free(x);
}

// VALGRIND command tells us "12 bytes in 1 blocks are definitely lost in loss record 1 of 1" if we don't free our memory.