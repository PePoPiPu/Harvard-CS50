// Program that creates a single linked list

#include <stdio.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main (void)
{
    // Declaring node *list
    node *list;
    // Alocating memory for a node
    node *n = malloc(sizeof(node));
    // Assigning an int to "number"
    n->number = 1;
    // Assigning NULL to node's next field
    n->next = NULL;
}