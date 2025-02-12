#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * struct shash_node_s - Node of a sorted hash table
 * @key: The key, string (cannot be empty)
 * @value: The value corresponding to a key
 * @next: A pointer to the next node in the same index
 * @sprev: A pointer to the previous element in sorted order
 * @snext: A pointer to the next element in sorted order
 */
typedef struct shash_node_s
{
    char *key;
    char *value;
    struct shash_node_s *next;
    struct shash_node_s *sprev;
    struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - Sorted hash table data structure
 * @size: The size of the array
 * @array: An array of size @size
 * @shead: Pointer to the first element of the sorted linked list
 * @stail: Pointer to the last element of the sorted linked list
 */
typedef struct shash_table_s
{
    unsigned long int size;
    shash_node_t **array;
    shash_node_t *shead;
    shash_node_t *stail;
} shash_table_t;

shash_table_t *shash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

#endif /* HASH_TABLES_H */