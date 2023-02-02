#include <stdio.h>
// Program that creates a linked list

typedef struct node
{
    char *word[45 + 1];
    struct node *next;
}
node;
int main (void)
{
node *word;
node *n = malloc(sizeof(node));
n->word = "Hello";
n->next = NULL;
word = n;
}