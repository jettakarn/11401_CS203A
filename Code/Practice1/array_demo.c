#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int n = 10;

    // 1. Initial Allocation
    array = (int *) malloc(n * sizeof(int));
    
    // Always check if memory allocation succeeded
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // 2. Initialize first 10 elements
    for(int i = 0; i < n; i++) {
        array[i] = i + 1;
    }

    // 3. Print initial array
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");

    // 4. Resize the array (Double the size)
    int old_n = n; // Keep track of old size for printing/logic
    n = n * 2;

    // Use a temporary pointer for realloc safety
    int *temp = (int *) realloc(array, n * sizeof(int));
    
    if (temp == NULL) {
        fprintf(stderr, "Reallocation failed\n");
        free(array); // Free original memory before exiting
        return 1;
    }
    array = temp; // Update original pointer to new memory block

    // 5. Initialize the NEW elements only
    for (int i = old_n; i < n; i++) {
        array[i] = i + 1;
    }

    // 6. Print the resized array
    printf("Resized array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // 7. Cleanup
    free(array);

    return 0;
}