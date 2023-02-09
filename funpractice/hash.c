// Implementation of a hash table and hash function

#include <stdio.h>
#include <stdlib.h>

#define HASHTABLE_SIZE 10000
#define LENGTH 45

unsigned int hash(const char *word);
bool load (const char *large);

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
// Initializing hashtable
node *hashtable[HASHTABLE_SIZE];

int word_count = 0;

const unsigned int N = 52;

int main (void)
{

}

unsigned int hash(const char *word)
{

}

bool load (const char *large)
{
    FILE *file = fopen(large, "r");
    if (file == NULL)
    {
        printf("Could not load file\n");
        return false;
    }

    char word[LENGTH + 1];

    while(fscanf(file, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
            return false;

        
    }
}