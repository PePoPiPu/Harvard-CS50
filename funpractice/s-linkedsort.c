// Linked list that sorts itself as items are added

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main (int argc, char* argv[])
{
    // Ensure proper usage
    if (argc < 2)
    {
        printf("Usage: ./s-linkedsort NUMBER\n");
    }

    // Memory for numbers
    node *list = NULL;
}