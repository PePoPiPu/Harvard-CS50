#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main (int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./list NUMBER\n");
    }
    // Memory for numbers
    node *list = NULL;
    // For each command line argument
    for (int i = 1; i < argc; i++)
    {
        // Convert argument to int
        int number = atoi(argv[i]);

        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        // Prepend node to list
        n->next = list;
        list = n;
    }

    // Print numbers
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
    }

    // Free memory
    ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr-> next;
        free(ptr);
        ptr = next;
    }
}