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
    // Reads words of the file one by one, prints them one by one
    char word[45];
    while(fscanf(file, "%s", word) != EOF)
    {
        fscanf(file, "%s", word);
        printf("%s\n", word);
    }
}

