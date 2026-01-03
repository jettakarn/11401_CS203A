#include <iostream>
#include <vector>

int main() {
    int n = 10;
    
    // 1. Creation (std::vector replaces malloc)
    // We can reserve memory to avoid multiple small reallocations
    std::vector<int> array;
    array.reserve(n); 

    // 2. Initialize first 10 elements
    for(int i = 0; i < n; i++) {
        array.push_back(i + 1);
    }

    // 3. Print initial array
    std::cout << "Original array:" << std::endl;
    for (int num : array) { // Range-based for loop (easier to read)
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    // 4. Resize (std::vector handles the realloc logic internally)
    int old_n = n;
    n = n * 2;
    
    // resize() adds new elements initialized to 0 (or default)
    // We iterate from old_n to update them
    array.resize(n); 

    // 5. Initialize NEW elements
    for (int i = old_n; i < n; i++) {
        array[i] = i + 1;
    }

    // 6. Print resized array
    std::cout << "Resized array:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    // No free() needed; vector cleans itself up automatically.
    return 0;
}