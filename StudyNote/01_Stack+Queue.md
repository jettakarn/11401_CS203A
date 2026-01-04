# My Study Notes: Stacks and Queues

## What are they?

Here are the definitions and analogies I use to keep them straight:

### 1. Stack (LIFO)
A **Stack** operates on the **Last-In, First-Out (LIFO)** principle. This means the last item you put in is the first one you take out.
* **Visual:** Think of a stack of dinner plates. You can only add a new plate to the top, and you can only take a plate off the top.
* **Key Operations:**
    * **Push:** Add an item to the top.
    * **Pop:** Remove the item from the top.

### 2. Queue (FIFO)
A **Queue** operates on the **First-In, First-Out (FIFO)** principle. This means the first item that enters is the first one to leave.
* **Visual:** Think of a line of people waiting for a bus. The person who arrived first gets on the bus first.
* **Key Operations:**
    * **Enqueue:** Add an item to the rear (back).
    * **Dequeue:** Remove an item from the front.

---

## Comparison Summary

Here is a quick reference table I made to compare the rules and terminology.

| Feature | Stack | Queue |
| :--- | :--- | :--- |
| **Rule** | **LIFO** (Last-In, First-Out) | **FIFO** (First-In, First-Out) |
| **Input** | **Push** (at the Top) | **Enqueue** (at the Rear) |
| **Output** | **Pop** (from the Top) | **Dequeue** (from the Front) |
| **Access Ends** | Single end (Input and Output at Top) | Two ends (Input at Rear, Output at Front) |
| **Common Use** | Undo buttons, function calls (recursion) | Printer jobs, scheduling tasks |

---

## Implementation Details

It is important to know how to build these using Arrays or Linked Lists.

### Implementing a Stack
* **Direction:** Everything happens at one end (the Top).
* **Array:** You just keep an index called `top`. When you push, you increment `top`; when you pop, you decrement it.
* **Linked List:** You insert and remove from the `head` of the list because it is $O(1)$.

### Implementing a Queue
* **Direction:** You need two ends: `Rear` for input and `Front` for output.
* **Linked List:** You need a pointer to the `head` (front) and the `tail` (rear) so you can add and remove in $O(1)$ time.
* **Array (Tricky part):** If you use a normal array, removing from the front causes all other items to shift (which is slow). To fix this, we use a **Circular Array** where the indices wrap around to the beginning.

---

## Performance (Big O)

The best part about Stacks and Queues is that they are very fast for their specific jobs.

| Operation | Time Complexity | Notes |
| :--- | :--- | :--- |
| **Push / Enqueue** | $O(1)$ | Instant addition (unless resizing a dynamic array) |
| **Pop / Dequeue** | $O(1)$ | Instant removal |
| **Peek / Front** | $O(1)$ | Just looking at the item is instant |
| **Searching** | $O(n)$ | These structures are **not** meant for searching; you have to look through everything |

---

## Key Takeaways

1.  Use a **Stack** when you need to "backtrack" or return to the most recent state (like the "Back" button in a browser).
2.  Use a **Queue** when you need to manage a buffer or schedule tasks fairly (first come, first served).
3.  **Watch out for:** "Underflow" (trying to pop from an empty stack) and "Overflow" (trying to push to a full fixed-size stack).

---

## Learning Assistance: Gemini

Stacks and Queues are simple conceptually, but implementing them can get tricky. Here is how I use AI to assist my learning:

* **Visualizing the "Circular" Queue:** It is hard to imagine an array wrapping around. I ask the AI, "Draw a step-by-step diagram of a circular queue of size 5 handling 7 enqueues and 2 dequeues," to see how the indices move.
* **Algorithm Tracing:** When solving a maze problem using DFS (Stack) vs. BFS (Queue), I ask the AI to "Trace the pathfinding process for this maze," and it lists the order in which nodes are visited.
* **Converting Ideas to Code:** I can say, "Show me how to implement a Queue using two Stacks in Python," and the AI provides the code pattern (which is a common interview question!).
* **Clarifying Amortized Time:** If I don't understand why a dynamic array push is "amortized $O(1)$," the AI can explain the math behind array resizing in simple terms.