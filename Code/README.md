# CS203A – Data Structures · Code Practice

## Practice 1
### C: Pointers
This mimics C-style coding using C++ operators (`new` and `delete`).

* **How it works:** You manually request memory: `int* array = new int[n];`.
* **Resizing:** C++ `new` cannot expand memory like C's `realloc`. You must:
    1. Allocate a **new** array.
    2. **Copy** all data manually.
    3. **Delete** the old array.
    4. Reassign the pointer.
* **Key Risk:** High chance of memory leaks if you forget `delete[]` or handle pointers incorrectly.

### C++: `std::vector`
This uses the C++ Standard Template Library (STL). It automates memory management using the **RAII** principle (Resource Acquisition Is Initialization).

* **How it works:** `std::vector<int> array;` handles the underlying array logic for you.
* **Resizing:** Calling `.resize()` or `.push_back()` automatically reallocates memory, moves data, and frees the old block.
* **Key Benefit:** No manual cleanup required; prevents memory leaks.

### Quick Comparison
| Feature | C++ | C |
| :--- | :--- | :--- |
| **Memory Management** | **Automatic** (Self-cleaning) | **Manual** (Must use `delete[]`) |
| **Resizing** | **Easy** (`vec.resize(n)`) | **Hard** (Alloc $\rightarrow$ Copy $\rightarrow$ Free) |
| **Safety** | **High** (Exception safe) | **Low** (Prone to leaks/crashes) |
| **Best For** | 99% of C++ Development | Learning internals or legacy code |

## Practice 2
### Overview
This program demonstrates **dynamic memory allocation** in C. It specifically visualizes how the operating system manages memory addresses when an array is created, populated, and resized during runtime.

### Dynamic Allocation (`malloc`)
* Allocates a block of heap memory for 10 integers.
* Unlike static arrays (e.g., `int arr[10]`), this size is determined at runtime.

### Memory Inspection
* **Feature:** `printf("... Address: %p", ...)`
* **Purpose:** Prints the specific hexadecimal memory address of each element.
* **Observation:** Users can verify that elements are stored contiguously (addresses increase by exactly 4 bytes for each `int`).

### Array Resizing (`realloc`)
* Doubles the array size from 10 to 20 elements.
* **Critical Observation:** It checks if the memory block was simply extended (same base address) or moved to a new location entirely (different base address) to accommodate the larger size.

### Memory Safety
* Demonstrates best practices by checking for `NULL` pointers after allocation and using `free()` to release memory at the end to prevent memory leaks.

## Learning Assistance

**AI Tool Used:** Google Gemini

In completing this project, I utilized Gemini to deepen my understanding of dynamic memory management in C and C++. The AI assisted in the following areas:

1.  **Code Completion & Logic:** analyzing incomplete code snippets to implement correct `malloc` and `realloc` sequences.
2.  **Concept Visualization:** Explaining the underlying behavior of memory addresses during array resizing (e.g., contiguous allocation vs. block relocation).
3.  **Cross-Language Comparison:** Generating comparative examples between C (manual memory management) and C++ (using `std::vector`), which helped clarify the benefits of modern RAII practices.