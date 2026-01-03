/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp
    - 2025/11/18: Knuth's Mutiplication & 31-Multiplier, also added assert
    - 2025/11/20: Updated descriptions and inline comments of each function

   Developer: Che-Sen Wei <itsjazzk@proton.me>
 */
#include "hash_fn.hpp"

/*
 * @brief Computes the hash index for an integer key using Knuth's Hash
 * @param key The integer key to hash (treated as 32-bit value by the algorithm).
 * @param m The hash table size (must be > 0).
 * @return The computed hash index.
 */
int myHashInt(int key, int m) {
    // Table size must be > 0.
    assert(m > 0);

    // Treat `key` as a 32-bit unsigned value for the multiplicative hash.
    uint32_t knuth = static_cast<uint32_t>(key);
    // Multiply by Knuth's constant to mix the bits of the key.
    knuth *= 2654435761u;
    // Reduce to the table range [0, m-1]
    return knuth % m;
}

/*
 * @brief Computes the hash index for an integer key using Multiplier-31
 * @param str The input string to hash (bytes of the C++ `std::string`).
 * @param m The hash table size (must be > 0).
 * @return The computed hash index.
 */
int myHashString(const std::string& str, int m) {
    // Table size must be > 0.
    assert(m > 0);
    // Multiplier-31 rolling hash: h = (h*31 + byte) mod m.
    // Taking modulus each iteration keeps `h` small and avoids overflow.
    long long h = 0;
    for (unsigned char c : str) {
        h = (h * 31 + c) % m; // keep intermediate values bounded
    }

    return h;
}