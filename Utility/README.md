# Utility

This directory contains **reusable helper headers** and **common data structure definitions** shared across multiple assignments.

## Files

| File | Description |
| :--- | :--- |
| **`CommonDef.h`** | Template definitions for `ListNode`, `DListNode`, and `TreeNode`. |

## Usage

Include these headers in your assignment source code using **relative paths**.

**Example:** If you are working in `Assignments/HW1/main.cpp`:

```cpp
#include "../../Utility/CommonDef.h"

int main() {
    // Create a Linked List Node
    ListNode<int>* head = new ListNode<int>(42);
    return 0;
}
```