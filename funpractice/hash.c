// Implementation of a hash table

#include <stdio.h>
// Functions definitions

create_item(char *key, char *value);
create_table(int size);
void free_item(ht_item *item);
void free_table(HashTable *table);
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