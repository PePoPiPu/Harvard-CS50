#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Program that opens a file, and copies each line into a node
// Definition of node struct
typedef struct node
{
    char word[45 + 1];
    struct node *next;
}
node;

int main (void)
{
    // Opens the file and checks for failure/success
    FILE *file = fopen("large","r");
    if (file == NULL)
    {
        printf("Could not open file\n");
    }
    else
    {
        printf("Could open file in read mode\n");
    }
    // Reads words of the file one by one
    char word[45];
    while(fscanf(file, "%s", word) != EOF)
    {
        fscanf(file, "%s", word);
        node *n = malloc(sizeof(node));
        strcpy(n->word, "%s");
        n->next = n;
    }
    fclose(file);
}
