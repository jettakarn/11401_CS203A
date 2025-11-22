# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: jettakarn 
Email: itsjazzk@proton.me

## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  ```text
  function myHashInt(key, m):
    // m = table size, must be > 0

    if m <= 0:
        error("table size must be positive")

    // Step 1: treat key as 32-bit unsigned integer
    knuth = toUnsigned32Bit(key)

    // Step 2: multiply by Knuth's constant to mix bits
    knuth = knuth * 2654435761

    // Step 3: reduce value into range [0, m-1]
    hashValue = knuth mod m

    return hashValue
  ```
- Rationale: This reduces collisions by converting the key into a 32-bit unsigned value first so all bit patterns are handled consistently, and then multiplying it by Knuth’s constant. This multiplication creates a well-distributed value, and taking the result modulo m maps it into the table range. Because the values are already averagely mixed before the modulo step, the final hash outputs are more uniform, which lowers the chance that many keys fall into the same bucket.

### Non-integer Keys
- Formula / pseudocode:
  ```text
  function myHashString(str, m):
    if m <= 0:
        error("table size must be positive")

    h = 0

    for each character c in str:
        h = (h * 31 + ASCII_value(c)) mod m

    return h
  ```
- Rationale: This handles non-integer keys by converting the string into a number through a rolling process where each character updates the hash. Multiplying by 31 and adding the character value spreads differences between strings, even if they look similar. Taking the modulus at each step keeps values bounded and maintains a stable distribution. Overall, it is simple, fast, and gives a reasonably uniform spread of string keys, which helps reduce collisions.

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
### Integer Keys
| Table Size (m) | Index Sequence                        | Observation                        |
| -------------- | ------------------------------------- | ---------------------------------- |
| 10             | 9, 4, 9, 0, 5, 0, 1, 6, 7, 2          | Several collisions                 |
| 11             | 8, 3, 9, 8, 3, 9, 8, 3, 2, 8          | Strong repeating pattern (8–3–9)   |
| 37             | 32, 27, 22, 24, 19, 14, 16, 11, 13, 8 | More uniform                       |

### String Keys
| Table Size (m) | Index Sequence                        | Observation                        |
| -------------- | ------------------------------------- | ---------------------------------- |
| 10             | 2, 4, 1, 9, 3, 8, 0, 5, 0, 3          | Multiple collisions                |
| 11             | 10, 6, 6, 7, 9, 6, 5, 5, 0, 9         | Uneven distribution                |
| 37             | 27, 3, 28, 20, 25, 23, 26, 29, 27, 18 | Almost uniform                     |

## Compilation, Build, Execution, and Output

### Compilation
- I use Ubuntu, so I can compile .c and .cpp files using the default GNU compilers (gcc and g++).
  ```bash
  # Compile a C file
  gcc main.c -o main

  # Compile a C++ file
  g++ main.cpp -o main
  ```

- The project includes both C and C++ code, you can manage the build with a simple Makefile:
  ```bash
  # Build both C and C++ versions
  make all
  
  # Build only C version
  make c
  
  # Build only C++ version
  make cxx
  ```

### Result Snapshot
- Example output for integers:
  ```
  === Hash Function Observation (C Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      9
  22      4
  23      9
  24      0
  25      5
  26      0
  27      1
  28      6
  29      7
  30      2
  51      5
  52      0
  53      1
  54      6
  55      7
  56      2
  57      7
  58      8
  59      3
  60      8

  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      8
  22      3
  23      9
  24      8
  25      3
  26      9
  27      8
  28      3
  29      2
  30      8
  51      1
  52      7
  53      6
  54      1
  55      0
  56      6
  57      1
  58      0
  59      6
  60      1

  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      32
  22      27
  23      22
  24      24
  25      19
  26      14
  27      16
  28      11
  29      13
  30      8
  51      33
  52      28
  53      30
  54      25
  55      27
  56      22
  57      17
  58      19
  59      14
  60      9

  === Hash Function Observation (C++ Version) ===

  === Table Size m = 10 ===
  Key     Index
  -----------------
  21      9
  22      4
  23      9
  24      0
  25      5
  26      0
  27      1
  28      6
  29      7
  30      2
  51      5
  52      0
  53      1
  54      6
  55      7
  56      2
  57      7
  58      8
  59      3
  60      8

  === Table Size m = 11 ===
  Key     Index
  -----------------
  21      8
  22      3
  23      9
  24      8
  25      3
  26      9
  27      8
  28      3
  29      2
  30      8
  51      1
  52      7
  53      6
  54      1
  55      0
  56      6
  57      1
  58      0
  59      6
  60      1

  === Table Size m = 37 ===
  Key     Index
  -----------------
  21      32
  22      27
  23      22
  24      24
  25      19
  26      14
  27      16
  28      11
  29      13
  30      8
  51      33
  52      28
  53      30
  54      25
  55      27
  56      22
  57      17
  58      19
  59      14
  60      9
  ```

- Example output for strings:
  ```
  === String Hash (m = 10) ===
  Key     Index
  -----------------
  cat     2
  dog     4
  bat     1
  cow     9
  ant     3
  owl     8
  bee     0
  hen     5
  pig     0
  fox     3

  === String Hash (m = 11) ===
  Key     Index
  -----------------
  cat     10
  dog     6
  bat     6
  cow     7
  ant     9
  owl     6
  bee     5
  hen     5
  pig     0
  fox     9

  === String Hash (m = 37) ===
  Key     Index
  -----------------
  cat     27
  dog     3
  bat     28
  cow     20
  ant     25
  owl     23
  bee     26
  hen     29
  pig     27
  fox     18
  ```

- Observations: From the integer results, I observed that non-prime table sizes create clear patterns. For example, when using m = 10 or m = 11, many keys fall into repeating index cycles, and several positions get crowded. This shows that the modulus interacts with the key pattern and produces many collisions.

For the string results, a similar problem appears. With small non-prime values, several words end up in the same index, and the distribution looks unbalanced. Some indices are used many times, while others are almost never used.

When using a prime table size, like m = 37, both the integer and string hash values spread much more evenly. There are fewer collisions, and the distribution does not form simple repeating patterns. The results look more “random” and smooth.

Overall, the main observation is that the same hash function behaves very differently depending on the table size. Prime sizes avoid unwanted cycles and produce a more uniform distribution, while non-prime sizes often create clustering and repeated sequences.

## Analysis
- Prime vs non-prime `m`: Using a prime number avoids simple repeating cycles between the hash values and the modulus. This prevents keys from falling into predictable patterns and helps the hash spread values more averagely.
- Patterns or collisions: With non-prime mod values, the hash results often fall into small repeating sequences, which creates a lot of collisions. When the modulus does not share common factors with the hash’s internal math, the results become more random-ish, so collisions drop.
- Improvements: Use a larger prime table size and rehash when the table gets too full to keep collisions low.

## Reflection
In this experiment, I learned how the design of a hash function and the choice of the table size can strongly affect the distribution of hash values. Even though the hash formulas for integers and strings are simple, the results show that the output pattern depends a lot on the modulus we choose. When the modulus is not a prime number, the hash values often fall into repeating cycles, which creates many collisions and makes the distribution look uneven. But when the modulus is a prime number, these cycles disappear, and the keys are spread more smoothly across the table.

I also realized that hashing is not just about the function itself but also about how it interacts with the table size. A good hash function can still produce poor results if the table size is not chosen carefully. Using a prime number helps break unwanted patterns and gives the hash a more “random-like” behavior, even though the algorithm is deterministic.

From these tests, I saw that collisions are hard to avoid completely, but we can reduce them by using a larger prime table size, rehashing when the table becomes too full, or improving the mixing step of the hash function. Overall, this exercise helped me understand why hash tables need both a good hash function and a good table size to work efficiently.