#include "hash_tables.h"

/**
 * key_index - Generates the index of a key using the djb2 algorithm.
 * @key: The key to hash.
 * @size: The size of the hash table.
 *
 * Return: The index where the key/value pair should be stored.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    return (hash_djb2(key) % size);
}
