// Implementation of a hash table
// Tutorial reference: https://www.digitalocean.com/community/tutorials/hash-table-in-c-plus-plus

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Size of the Hash Table
#define CAPACITY 50000

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
unsigned long hash_function(char* str);
void free_item(ht_item *item);
void free_table(HashTable *table);
void print_table(HashTable *table);
void ht_insert(HashTable* table, char* key, char* value);
char* ht_search(HashTable* table, char* key); // CHECK FUNCTION!
void print_search(HashTable* table, char* key);


int main (void)
{

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

unsigned long hash_function(char* str)
{
    unsigned long i = 0;

    for (int j = 0; str[j]; j++)
        i += str[j];

    return i % CAPACITY;
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

void ht_insert(HashTable* table, char* key, char* value)
{
    // Creates the item
    ht_item* item = create_item(key, value);

    // Computes the index

    int index = hash_function(key);

    ht_item* current_item = table->items[index];

    if (current_item == NULL)
    {
        if (table->count == table->size)
        {
            //HashTable is full
            printf("Insert Error: Hash Table is full\n")
            free_item(item);
            return;
        }

        // Insert directly
        table->items[index] = item;
        table->count++;
    }
    else
    {
        // If {key: value} pair exists, update the value
        if (strcmp(current_item->key, key) == 0)
        {
            strcpy(table->items[index] -> value, value);
            return;
        }
    }
    else
    {
        // If a collision has to be handled, a placeholder is added
        handle_collision(table, item);
        return;
    }
}

char* ht_search(HashTable* table, char* key)
{
    // Searches for the key in the HashTable
    // Returns NULL if it doesn't exist
    int index = hash_function(key);
    ht_item* item = table->items[index];

    // Provide only non NULL values
    if (item != NULL)
    {
        if(strcmp(item->key, key) == 0)
            return item->value;
    }

    return NULL;
}

void print_search(HashTable* table, char* key);