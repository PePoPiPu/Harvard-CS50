// Implementation of a hash table and hash function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    const int p = 53;
    const int m = 1e9 + 9;
    int hash_value = 0;
    int p_pow = 1;
    for (char c)
    {
        hash_value = (hash_value +(c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
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

        strcpy (new_node->word, word);
        int hash_value = hash(new_node->word);
        node *head = hashtable[hash_value];

        if (head == NULL)
        {
            hastable[hash_value] = new_node;
            word_count++;
        }
        else
        {
            new_node->next = hashtable[hash_value];
            hashtable[hash_value] = new_node;
            word_count++;
        }

    }
}

