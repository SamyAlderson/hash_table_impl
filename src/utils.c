// Include the necessary header file
#include <stdlib.h>

// Function to allocate memory
void* allocate_memory(size_t size) {
    return malloc(size);
}

// Function to free memory
void free_memory(void* ptr) {
    free(ptr);
}
