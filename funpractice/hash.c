// Implementation of a hash table and hash function

#include <stdio.h>
#include <stdlib.h>

#define HASHTABLE_SIZE 10000
#define LENGTH 45

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
// Initializing hashtable 
node *hashtable[HASHTABLE_SIZE];

int word_count = 0;

const unsigned int N = 52