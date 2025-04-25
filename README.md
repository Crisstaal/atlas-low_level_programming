# 🌟 Advanced Hash Tables Project 🌟

## 🧩 Project Overview

This project implements **sorted hash tables** in **C**, inspired by PHP’s hash table functionality but with added sorting of keys in ASCII order. The goal is to design an efficient data structure for storing and retrieving key-value pairs while maintaining key order in a linked list.

### Key Functions:
- **shash_table_create()**: Creates a new hash table.
- **shash_table_set()**: Inserts key-value pairs, ensuring keys are sorted.
- **shash_table_get()**: Retrieves the value for a given key.
- **shash_table_print()**: Prints the hash table in sorted order.
- **shash_table_print_rev()**: Prints the hash table in reverse order.
- **shash_table_delete()**: Deletes the hash table and frees memory.

## 🛠️ How to Run:

1. Clone the repository.
2. Compile the code:
    ```bash
    gcc -Wall -pedantic -Werror -Wextra -std=gnu89 100-main.c 100-sorted_hash_table.c 1-djb2.c 2-key_index.c -o sht
    ```

Thanks for checking out my project! ✨
