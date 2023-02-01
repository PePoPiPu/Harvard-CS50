#include <stdio.h>

// Program that opens a file, scans it word by word and closes it

int main (void)
{
    FILE *file = fopen("large.txt","r");
    if (file == NULL)
    {
        printf("Could not open file\n");
    }
    else
    {
        fprintf(file, "Could open file in read mode\n");
        fclose(file);
    }
    return 0;
}