#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int n = 10;

    // 1. Allocate memory for n integers
    array = (int *) malloc(n * sizeof(int));

    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("--- INITIAL ALLOCATION ---\n");
    printf("Base Address: %p\n", (void*)array);

    // Initialize elements
    for (int i = 0; i < n; i++) {
        array[i] = i + 1;
    }

    // Print elements with addresses
    for (int i = 0; i < n; i++) {
        // The line you requested:
        printf("Index %d -> Value: %d, Address: %p\n", i, array[i], (void*)&array[i]);
    }
    printf("\n");
    
    // 2. Double the size
    printf("--- RESIZING (REALLOC) ---\n");
    int old_n = n;
    n = n * 2;
    
    // Check pointer before realloc
    int *old_addr = array;

    array = (int *) realloc(array, n * sizeof(int));
    
    if (array == NULL) {
        fprintf(stderr, "Reallocation failed\n");
        return 1;
    }

    // Initialize new elements only
    for (int i = old_n; i < n; i++) {
        array[i] = i + 1;
    }

    // Print all elements with addresses
    for (int i = 0; i < n; i++) {
        printf("Index %d -> Value: %d, Address: %p\n", i, array[i], (void*)&array[i]);
    }
    printf("\n");

    // Compare addresses
    if (array == old_addr) {
        printf("Observation: The memory block was EXTENDED in place.\n");
        printf("(The base address did not change.)\n");
    } else {
        printf("Observation: The memory block was MOVED to a new location.\n");
        printf("(Old: %p -> New: %p)\n", (void*)old_addr, (void*)array);
    }

    free(array);
    return 0;
}