// Testing of a hash function's distribution

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LENGTH 45
#define HASHTABLE_SIZE 10000

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node *hashtable[HASHTABLE_SIZE];

unsigned int hash(const char *word);
bool load(const char *dictionary);

int word_count = 0;

int main (int argc, char *argv[])
{
    if (argc < 2)
        printf("Usage: ./hashtest FILE\n");
    for (int i = 1; i < argc; i++)
    {
        int h = hash(argv[i]);
        printf("%i\n", h);
    }
}

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

bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
        return false;

    char word[LENGTH + 1];

    while(fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, word);
        int h = hash(n->word);
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