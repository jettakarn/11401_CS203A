/*
   ========================================
   hash_fn.h — declare your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/17: Initial implementation
    - 2025/11/20: Adjusted few libraries

   Developer: Che-Sen Wei <itsjazzk@proton.me>
 */
#ifndef HASH_FN_H
#define HASH_FN_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include "hash_fn.c"

int myHashString(const char* str, int m);
int myHashInt(int key, int m);

#endif