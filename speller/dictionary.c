// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

#define HASHTABLE_SIZE 10000
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node *hashtable[HASHTABLE_SIZE];
// Hash function
int hash_function(char* hash_word)
{
    // FUNCTION YET TO BE DEFINED
    return 1;
}
// Initialize int that counts words in the dictionary
int word_count = 0;

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
    FILE *file = fopen(dictionary, "r");
    // If it doesn't open, return false
    if (file == NULL)
        return false;
    // Read strings from file one at a time, stores it in a word array
    char word[LENGTH + 1];
    // While reading words one by one and we don't reach EOF
    while(fscanf(file, "%s", word) != EOF)
    {
        // Creates a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            unload();
            return false;
        }
        strcpy(n->word, word);
        // Hash word to obtain hash value
        int h = hash_function(n->word);
        // Initialize head to point at hashtable bucket
        node *head = hashtable[h];

        if (head == NULL)
        {
            hashtable[h] =n;
            word_count++;
        }
        else
        {
            n->next = hashtable[h];
            hashtable[h] = n;
            word_count++;
        }
    }
    fclose(file);
    return true;
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
