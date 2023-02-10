// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

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

// Initialize int that counts words in the dictionary
int word_count = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 52;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int l = strlen(word);
    char copy[LENGTH + 1];
    for (int i = 0; i < l; i++)
    {
        copy[i] = tolower(word[i]);
    }
    copy[l] = '\0';

    int h = hash(copy);

    node *cursor = hashtable[h];

    while(cursor != NULL)
    {
        if (strcasecmp(cursor->word, copy) == 0)
            return true;

        else
            cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int l = strlen(word);
    int ascii = 0;
    int sum = 0;
    int hash_value;

    for (int i = 0; i < l; i++)
    {
        ascii += word[i];
        sum = ascii + l;
        hash_value = ((sum * word[i]) % 2069) / 100;
    }
    return hash_value;
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
        int h = hash(n->word);
        // Initialize head to point at hashtable bucket
        node *head = hashtable[h];

        if (head == NULL)
        {
            hashtable[h] = n;
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
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
