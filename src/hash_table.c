#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TABLE_SIZE 1024
#define MAX_KEY_LENGTH 100

typedef struct Node {
    char key[MAX_KEY_LENGTH];
    char value[MAX_KEY_LENGTH];
    struct Node* next;
} Node;

typedef struct HashTable {
    Node** table;
} HashTable;

HashTable* hash_table_new() {
    HashTable* table = malloc(sizeof(HashTable));
    table->table = calloc(TABLE_SIZE, sizeof(Node*));
    return table;
}

int hash_function(char* key) {
    int hash = 0;
    while (*key != '\0') {
        hash += *key;
        key++;
    }
    return hash % TABLE_SIZE;
}

void hash_table_insert(HashTable* table, char* key, char* value) {
    int index = hash_function(key);
    Node* node = table->table[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            strcpy(node->value, value);
            return;
        }
        node = node->next;
    }
    Node* new_node = malloc(sizeof(Node));
    strcpy(new_node->key, key);
    strcpy(new_node->value, value);
    new_node->next = table->table[index];
    table->table[index] = new_node;
}

void hash_table_remove(HashTable* table, char* key) {
    int index = hash_function(key);
    Node* node = table->table[index];
    if (node != NULL && strcmp(node->key, key) == 0) {
        table->table[index] = node->next;
        free(node);
        return;
    }
    while (node->next != NULL) {
        if (strcmp(node->next->key, key) == 0) {
            Node* temp = node->next;
            node->next = node->next->next;
            free(temp);
            return;
        }
        node = node->next;
    }
}

char* hash_table_get(HashTable* table, char* key) {
    int index = hash_function(key);
    Node* node = table->table[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

void hash_table_free(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* node = table->table[i];
        while (node != NULL) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(table->table);
    free(table);
}

int main() {
    HashTable* table = hash_table_new();
    hash_table_insert(table, "key1", "value1");
    hash_table_insert(table, "key2", "value2");
    printf("%s\n", hash_table_get(table, "key1"));
    hash_table_remove(table, "key1");
    printf("%s\n", hash_table_get(table, "key1"));
    hash_table_free(table);
    return 0;
}
```

```c
#include <stdio.h>
#include <string.h>

void print_table(HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %d: ", i);
        Node* node = table->table[i];
        while (node != NULL) {
            printf("(%s, %s) ", node->key, node->value);
            node = node->next;
        }
        printf("\n");
    }
}

void test_hash_table() {
    HashTable* table = hash_table_new();
    hash_table_insert(table, "key1", "value1");
    hash_table_insert(table, "key2", "value2");
    print_table(table);
    hash_table_remove(table, "key1");
    print_table(table);
    hash_table_free(table);
}