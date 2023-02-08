// Implementation of a hash table

#include <stdio.h>
#include <string.h>

// Defines the HashTable item
typedef struct ht_item
{
    char *key;
    char *value;
}
ht_item;

// Defines the HashTable
typedef struct HashTable
{
    // Conatains an array of pointers to items
    ht_item **items;
    // Retunrs size of the hash table
    int size;
    // Returns number of elements
    int count;
}
HashTable;

// Functions definitions

ht_item *create_item(char *key, char *value);
HashTable *create_table(int size);
void free_item(ht_item *item);
void free_table(HashTable *table);

// Function that allocates memory and creates items

ht_item *create_item(char *key, char *value)
{
    // Creates a pointer to a new HashTable item
    ht_item *item = malloc(sizeof(ht_item));
    item->key = malloc(strlen(key) + 1);
    item->value = malloc(strlen(value) + 1);
    strcpy(item->key, key);
    strcpy(item->value, value);
    return item;
}