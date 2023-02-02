#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main (int argc; char *argv[])
{
    // Memory for numbers
    node *list = NULL;
    // For each command line argument
    for (int i = 1; i < argc; i++)
    {
        // Convert argument to int
        int number = atoi(argv[i]);
    }
}