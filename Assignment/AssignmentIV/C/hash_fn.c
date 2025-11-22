/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h
    - 2025/11/20: Knuth's Mutiplication & 31-Multiplier, also added assert
    - 2025/11/20: Updated descriptions and inline comments of each function

   Developer: Che-Sen Wei <itsjazzk@proton.me>
 */

#include "hash_fn.h"

/*
 * @brief Computes the hash index for an integer key using Knuth's multiplicative method.
 * @param key The integer key to hash (treated as 32-bit value by the algorithm).
 * @param m The hash table size (must be > 0).
 * @return The computed hash index in the range [0, m-1].
 */
int myHashInt(int key, int m) {
    // Table size must be > 0.
    assert(m > 0);

    // Treat `key` as 32-bit unsigned and apply Knuth's multiplicative constant.
    uint32_t knuth = (uint32_t)key;
    knuth *= 2654435761u;
    return (int)(knuth % (uint32_t)m);
}

/*
 * @brief Computes the hash index for a C-style string using multiplier-31.
 * @param str The input NUL-terminated string to hash (must be non-NULL).
 * @param m The hash table size (must be > 0).
 * @return The computed hash index in the range [0, m-1].
 */
int myHashString(const char* str, int m) {
    assert(str != NULL);
    assert(m > 0);

    // Multiplier-31 rolling hash: h = (h*31 + byte) mod m.
    // Taking modulus each iteration keeps `h` small and avoids overflow.
    unsigned long h = 0;
    const unsigned char* p = (const unsigned char*)str;
    while (*p) {
        h = (h * 31 + *p) % (unsigned long)m; // keep values bounded.
        ++p;
    }
    return (int)(h % (unsigned long)m);
}