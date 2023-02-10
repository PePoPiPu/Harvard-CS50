// Program that creates a single linked list and searchs through it

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main (int argc, )
{
    node *list;
    node *new_node = malloc(sizeof(node));
}