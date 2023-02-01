// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open dictionary file
    *dictionary = fopen(dictionary, "r");
    // If it doesn't open, return false
    if (dictionary == NULL)
        return false;
    else
        return true;

    // Read strings from file one at a time
    for (int i = 0; i < dictionary; i++)
    {
    fscanf(dictionary, "%s", word);
        if (fscanf == EOF)
        {
            break;
        }
    }

    // Create a new node that stores a word in hash table
    node *n = malloc(sizeof(node));
    strcpy(n->word, "word");
    n->next = NULL;
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}