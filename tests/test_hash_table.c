#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/hash_table.h"
#include "src/utils.h"

void test_insert_delete(void) {
    // Create a hash table with initial size 10
    HashTable* table = hash_table_new(10);
    
    if (table == NULL) {
        fprintf(stderr, "Failed to create hash table\n");
        exit(EXIT_FAILURE);
    }

    // Insert some key-value pairs
    char* keys[] = {"apple", "banana", "cherry"};
    char* values[] = {"red", "yellow", "green"};
    for (size_t i = 0; i < 3; i++) {
        if (!hash_table_insert(table, keys[i], values[i])) {
            fprintf(stderr, "Failed to insert key-value pair\n");
            hash_table_free(table);
            exit(EXIT_FAILURE);
        }
    }

    // Delete one key-value pair
    if (!hash_table_remove(table, "banana")) {
        fprintf(stderr, "Failed to delete key-value pair\n");
        hash_table_free(table);
        exit(EXIT_FAILURE);
    }

    // Check that the key-value pair was deleted
    if (hash_table_lookup(table, "banana") != NULL) {
        fprintf(stderr, "Key-value pair not deleted\n");
        hash_table_free(table);
        exit(EXIT_FAILURE);
    }

    // Free the hash table
    hash_table_free(table);
}

void test_collision_resolution(void) {
    // Create a hash table with initial size 10
    HashTable* table = hash_table_new(10);
    
    if (table == NULL) {
        fprintf(stderr, "Failed to create hash table\n");
        exit(EXIT_FAILURE);
    }

    // Insert multiple key-value pairs with the same hash value
    char* keys[] = {"apple", "banana", "cherry", "date", "elderberry"};
    char* values[] = {"red", "yellow", "green", "brown", "purple"};
    for (size_t i = 0; i < 5; i++) {
        if (!hash_table_insert(table, keys[i], values[i])) {
            fprintf(stderr, "Failed to insert key-value pair\n");
            hash_table_free(table);
            exit(EXIT_FAILURE);
        }
    }

    // Check that all key-value pairs were inserted correctly
    for (size_t i = 0; i < 5; i++) {
        if (hash_table_lookup(table, keys[i]) == NULL) {
            fprintf(stderr, "Key-value pair not inserted correctly\n");
            hash_table_free(table);
            exit(EXIT_FAILURE);
        }
    }

    // Free the hash table
    hash_table_free(table);
}

int main(void) {
    // Run the unit tests
    test_insert_delete();
    test_collision_resolution();

    return 0;
}
```

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/utils.h"

int test_hash_table(void) {
    // Create a hash table with initial size 10
    HashTable* table = hash_table_new(10);
    
    if (table == NULL) {
        fprintf(stderr, "Failed to create hash table\n");
        return EXIT_FAILURE;
    }

    // Insert some key-value pairs
    char* keys[] = {"apple", "banana", "cherry"};
    char* values[] = {"red", "yellow", "green"};
    for (size_t i = 0; i < 3; i++) {
        if (!hash_table_insert(table, keys[i], values[i])) {
            fprintf(stderr, "Failed to insert key-value pair\n");
            hash_table_free(table);
            return EXIT_FAILURE;
        }
    }

    // Lookup a key-value pair
    char* value = hash_table_lookup(table, "apple");
    if (value == NULL || strcmp(value, "red") != 0) {
        fprintf(stderr, "Failed to lookup key-value pair\n");
        hash_table_free(table);
        return EXIT_FAILURE;
    }

    // Remove a key-value pair
    if (!hash_table_remove(table, "banana")) {
        fprintf(stderr, "Failed to delete key-value pair\n");
        hash_table_free(table);
        return EXIT_FAILURE;
    }

    // Check that the key-value pair was deleted
    if (hash_table_lookup(table, "banana") != NULL) {
        fprintf(stderr, "Key-value pair not deleted\n");
        hash_table_free(table);
        return EXIT_FAILURE;
    }

    // Free the hash table
    hash_table_free(table);

    return EXIT_SUCCESS;
}