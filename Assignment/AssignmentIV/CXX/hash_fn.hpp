/*
   ========================================
   hash_fn.hpp — declare your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/17: Initial implementation
    - 2025/11/18: Adjusted few libraries

   Developer: Che-Sen Wei <itsjazzk@proton.me>
 */
#ifndef HASH_FN_HPP
#define HASH_FN_HPP

#include <cstdint>
#include <cassert>
#include <string>

int myHashString(const std::string& str, int m);
int myHashInt(int key, int m);

#endif