#include <stdio.h>

// Program that opens a file, scans it word by word and closes it

int main (void)
{
    // Opens the file and checks for failure/success
    FILE *file = fopen("large.txt","r");
    if (file == NULL)
    {
        printf("Could not open file\n");
    }
    else
    {
        printf("Could open file in read mode\n");
    }
    // Reads words of the file one by one

    while(fscanf(file, "%s") != EOF)
    {
        char word[45];
        fscanf(file, "%s", word);
        printf("%s\n", word)
    }
}

