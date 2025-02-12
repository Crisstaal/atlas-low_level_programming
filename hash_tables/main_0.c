#include "hash_tables.h"

int main(void)
{
    shash_table_t *ht;

    ht = shash_table_create(1024);
    if (!ht)
        return (1);
    shash_table_delete(ht);
    return (0);
}
