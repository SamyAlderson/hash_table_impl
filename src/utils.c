#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Function to duplicate a string
// This is a simple, naive approach that uses malloc and strcpy
// It's not the most efficient way to duplicate a string, but it gets the job done
char* duplicate_string(const char* str) {
    // Calculate the length of the string
    size_t len = strlen(str);

    // Allocate memory for the duplicated string
    char* duplicated = malloc(len + 1);

    // Check if the memory allocation was successful
    if (duplicated == NULL) {
        fprintf(stderr, "Memory allocation failed for duplicated string\n");
        exit(EXIT_FAILURE);
    }

    // Copy the characters from the original string to the duplicated string
    strcpy(duplicated, str);

    return duplicated;
}

// Function to compare two strings
// This function uses strcmp from the standard library
// It's a simple, straightforward approach that works as expected
int compare_strings(const char* str1, const char* str2) {
    return strcmp(str1, str2);
}

// Function to split a string into an array of substrings
// This function splits the string at each whitespace character
// It's a basic approach that uses malloc and strcpy to create a new array of substrings
char** split_string(const char* str) {
    // Calculate the number of substrings
    size_t num_substrings = 0;
    char* token = strtok((char*)str, " ");
    while (token != NULL) {
        num_substrings++;
        token = strtok(NULL, " ");
    }

    // Allocate memory for the array of substrings
    char** substrings = malloc((num_substrings + 1) * sizeof(char*));

    // Check if the memory allocation was successful
    if (substrings == NULL) {
        fprintf(stderr, "Memory allocation failed for substrings array\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the array of substrings
    substrings[num_substrings] = NULL;

    // Split the string into substrings
    size_t index = 0;
    token = strtok((char*)str, " ");
    while (token != NULL) {
        substrings[index] = duplicate_string(token);
        index++;
        token = strtok(NULL, " ");
    }

    return substrings;
}

// Function to free the memory allocated for the array of substrings
void free_substrings(char** substrings) {
    // Iterate over the array of substrings
    for (size_t i = 0; substrings[i] != NULL; i++) {
        // Free the memory allocated for each substring
        free(substrings[i]);
    }

    // Free the memory allocated for the array of substrings
    free(substrings);
}
```

```c
// Function to calculate the length of a string
// This function uses strlen from the standard library
size_t calculate_string_length(const char* str) {
    return strlen(str);
}