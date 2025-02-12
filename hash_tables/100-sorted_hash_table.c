#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the hash table.
 *
 * Return: A pointer to the created hash table, or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;
    
    ht = malloc(sizeof(shash_table_t));
    if (!ht)
        return (NULL);
    
    ht->size = size;
    ht->array = calloc(size, sizeof(shash_node_t *));
    if (!ht->array)
    {
        free(ht);
        return (NULL);
    }

    ht->shead = ht->stail = NULL;
    return (ht);
}

/**
 * shash_table_set - Adds an element to the sorted hash table.
 * @ht: The hash table.
 * @key: The key (string, cannot be empty).
 * @value: The value associated with the key.
 *
 * Return: 1 on success, 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    shash_node_t *new_node, *temp;

    if (!ht || !key || *key == '\0' || !value)
        return (0);
    index = key_index((const unsigned char *)key, ht->size);
    temp = ht->array[index];

    while (temp)
    {
        if (strcmp(temp->key, key) == 0)
        {
            free(temp->value);
            temp->value = strdup(value);
            return (1);
        }
        temp = temp->next;
    }

    new_node = malloc(sizeof(shash_node_t));
    if (!new_node)
        return (0);
    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    /* Sorted insertion */
    if (!ht->shead)
    {
        ht->shead = ht->stail = new_node;
        new_node->sprev = new_node->snext = NULL;
    }
    else
    {
        shash_node_t *prev = NULL, *curr = ht->shead;
        while (curr && strcmp(curr->key, key) < 0)
        {
            prev = curr;
            curr = curr->snext;
        }
        new_node->snext = curr;
        new_node->sprev = prev;
        if (curr)
            curr->sprev = new_node;
        else
            ht->stail = new_node;
        if (prev)
            prev->snext = new_node;
        else
            ht->shead = new_node;
    }
    return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key.
 * @ht: The hash table.
 * @key: The key to search for.
 *
 * Return: The value, or NULL if key is not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *temp;

    if (!ht || !key || *key == '\0')
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);
    temp = ht->array[index];

    while (temp)
    {
        if (strcmp(temp->key, key) == 0)
            return (temp->value);
        temp = temp->next;
    }
    return (NULL);
}

/**
 * shash_table_print - Prints the sorted hash table in order.
 * @ht: The hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *node;

    if (!ht)
        return;

    printf("{");
    node = ht->shead;
    while (node)
    {
        printf("'%s': '%s'", node->key, node->value);
        if (node->snext)
            printf(", ");
        node = node->snext;
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints the hash table in reverse order.
 * @ht: The hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *node;

    if (!ht)
        return;

    printf("{");
    node = ht->stail;
    while (node)
    {
        printf("'%s': '%s'", node->key, node->value);
        if (node->sprev)
            printf(", ");
        node = node->sprev;
    }
    printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: The hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *node, *temp;

    if (!ht)
        return;

    node = ht->shead;
    while (node)
    {
        temp = node;
        node = node->snext;
        free(temp->key);
        free(temp->value);
        free(temp);
    }

    free(ht->array);
    free(ht);
}