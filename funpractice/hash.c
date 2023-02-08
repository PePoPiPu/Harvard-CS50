// Implementation of a hash table

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    ht_item** items;
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
void print_table(HashTable *table);
int main (void)
{
    // NOT YET
}
// Function that allocates memory and creates items

ht_item *create_item(char *key, char *value)
{
    // Creates a pointer to a new HashTable item
    ht_item *item = (ht_item*) malloc(sizeof(ht_item));
    item->key = (char*) malloc(strlen(key) + 1);
    item->value = (char*) malloc(strlen(value) + 1);
    strcpy(item->key, key);
    strcpy(item->value, value);
    return item;
}

// Function that creates the hash table

HashTable* create_table(int size)
{
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    // Allocates memory for the items and initializes it to 0
    table->items = (ht_item **) calloc(table->size, sizeof(ht_item*));

    for (int i = 0; i < table->size; i++)
        table->items[i] = NULL;

    return table;
}

void free_item (ht_item *item)
{
    // Frees an item
    free(item->key);
    free(item->value);
    free(item);
}

void free_table (HashTable *table)
{
    // Frees the table
    for (int i = 0; i < table->size; i++)
    {
        ht_item* item = table->items[i];

        if (item != NULL)
            free_item(item);
    }

    free(table->items);
    free(table);
}

void print_table(HashTable *table)
{
    printf("\nHash Table\n--------------------\n");

    for (int i = 0; i < table->size; i++)
    {
        if (table->items[i])
        {
            printf("Index:%d, Key:%s, Value%s\n", i, table->items[i]->key, table->items[i]->value);
        }
    }

    printf("--------------------\n\n");
}