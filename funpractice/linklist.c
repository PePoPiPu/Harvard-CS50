// Program that creates a single linked list and searchs through it

#include <stdio.h>
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
    if (argc < 2)
        printf("Usage: ./linklist WORD\n");

    // Create a linked list
    node *list = NULL;
    // Dinamically allocate memory for a new node
    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
            return 1;

        new_node->number = number;
        new_node->next = NULL;

        // Prepend node to list
        new_node->next = list;
        list = new_node;
    }
}