# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

* Developer: CHE-SEN WEI (jettakarn)
* Email: [itsjazzk@proton.me](mailto:itsjazzk@proton.me)

## Repository Structure
```text
AssignmentIV/
├── C/                      # C implementation directory
│   ├── hash_fn.c           # Hash function implementation in C
│   ├── hash_fn.h           # Header file for C hash functions
│   └── main.c              # Main program calling hash functions
├── CXX/                    # C++ implementation directory
│   ├── hash_fn.cpp         # Hash function implementation in C++
│   ├── hash_fn.hpp         # Header file for C++ hash functions
│   └── main.cpp            # Main program calling hash functions
├── Makefile                # Build configuration file for Linux platform
├── README.md               # README documentation
└── VSCode.md               # VS Code setup instructions
```

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

### Prerequisites & Build
- Tool
  - Microsoft Visual Studio Code

- System Dependencies
  - Make: Automating the compilation workflow
  - Git: Cloning and version control

- Environment
  - OS: Ubuntu 24.04.3 LTS
  - Compiler: GCC and G++
  - Standard: C17 and C++23

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"

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
- Build with a simple Makefile:
  ```bash
  # Build both C and C++ versions
  make all
  
  # Build only C version
  make c
  
  # Build only C++ version
  make cxx

  # Remove compiled files
  make clean
  ```

- Use the default GNU compilers (manual compilation)
  ```bash
  # Compile a C file
  gcc -std=c17 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c

  # Compile a C++ file
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
  ```

- Program execution
  ```bash
  # Execute the C version
  ./hash_function

  # Execute the C++ version
  ./hash_function_cpp
  ```

### Output Snapshot
- Integer
  <img width="263" height="523" alt="int_1" src="https://github.com/user-attachments/assets/dbff0e92-b698-445d-a7a5-c13cb445b7f5" />
  <img width="263" height="523" alt="int_2" src="https://github.com/user-attachments/assets/ed6c23fa-89c7-46aa-bcc3-0c5f65c90c77" />
  <img width="263" height="523" alt="int_3" src="https://github.com/user-attachments/assets/02faa17c-5406-447c-b6ea-58af1efec58d" />

- String
  <img width="290" height="301" alt="str_1" src="https://github.com/user-attachments/assets/23ffa6b5-c104-48c6-9e86-2f481af9ba2b" />
  <img width="290" height="301" alt="str_2" src="https://github.com/user-attachments/assets/ae780c83-4f26-4c33-a8cc-64d1e20aa3fe" />
  <img width="290" height="301" alt="str_3" src="https://github.com/user-attachments/assets/6bfc6418-0298-44d6-95ce-41f7717ca3d4" />

### Observations
From the integer results, I observed that non-prime table sizes create clear patterns. For example, when using m = 10 or m = 11, many keys fall into repeating index cycles, and several positions get crowded. This shows that the modulus interacts with the key pattern and produces many collisions.

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

## References
### Why I chose 31-Multiplier
31 is a prime number. Using a prime number as a multiplier in hashing algorithms generally leads to a better distribution of hash values, which helps in reducing collisions within hash tables. This is particularly relevant when the modulus (often the size of the hash table) is also a prime number or when the multiplier is relatively prime to the modulus.
- [Link](https://www.quora.com/Why-is-31-used-in-Hashcode)


### Why I chose Knuth's Mutiplicative Hash
 It's a fast and simple method that provides a good distribution of keys for hash tables, especially when the table size is a power of two. It works by multiplying a key by a constant, taking the fractional part of the result, and then multiplying by the table size to determine the index.
 - [Link](https://stackoverflow.com/questions/11871245/knuth-multiplicative-hash)
