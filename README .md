# Data Structures & Algorithms (C++)

A single-file C++ collection of classic sorting algorithms and core data
structure implementations, built with templates for reuse across types.

## Contents

### Sorting Algorithms
| Function | Description | Time Complexity |
|---|---|---|
| `insertionsort(arr, n)` | Insertion sort | O(n²) worst/avg, O(n) best |
| `selectionsort(arr, n)` | Selection sort | O(n²) |
| `bubblesort(arr, n)` | Bubble sort | O(n²) |
| `shellsort(arr, n)` | Shell sort (gap sequence n/2, n/4, ...) | O(n log n) to O(n²) depending on gap sequence |
| `mergesort(arr, l, r)` / `merge(...)` | Merge sort | O(n log n) |
| `quicksort(arr, low, high)` / `partition(...)` | Quicksort (Lomuto partition) | O(n log n) avg, O(n²) worst |
| `countSort(A, n, k)` | Counting sort (stable, needs max value `k`) | O(n + k) |
| `radixSort(A, n)` | Radix sort (LSD, base 10, uses counting sort per digit) | O(d·(n + b)) |

### Linked List
- `Node` / `newnode` — singly linked list with:
  - `insert(val)` — append at tail
  - `display()` — print all values
  - `reverse()` — in-place reversal
  - `deleteNode(key)` — delete by value
  - `insertAtPosition(val, pos)` — insert at a given index

### Stack
- `stack` — singly-linked-list-based stack: `push`, `pop`, `first` (top element)

### Queues
- `Queue<T, size>` — array-based queue (linear, no wraparound; fills up permanently)
- `circularQueue<T, size>` — array-based circular queue (reuses freed slots via modulo)
- `QueueSLL<T>` — singly-linked-list-based queue with `enqueue`, `dequeue`, `first`, and
  `remove(value)` for removing an arbitrary element

### Priority Queue
- `PriorityQueue<T, size>` — unsorted array-backed priority queue.
  `top()`/`pop()` do a linear scan for the max each time — O(n) per operation
  (not a heap-based implementation).

### Trees
- `BST<T>` — binary search tree:
  - `insert`, `remove` (delete-by-copying using inorder predecessor)
  - `inorder`, `preorder`, `postorder` (DFS)
  - `levelOrder` (BFS, uses `std::queue`)
  - `successor(key)`, `predecessor(key)`
- `AVL<T>` — self-balancing BST:
  - `insert`, `remove`, `search`, `inorder`
  - Handles LL, RR, LR, RL rotation cases with height tracking and rebalancing

### Heap
- `MaxHeap<T>` — array-based binary max-heap:
  - `insert`, `extractMax`, `maxHeapify`, `buildMaxHeap`
  - `heapSort()` — in-place heap sort using the same array
  - `increaseKey(i, newVal)`, `remove(i)` (delete by index)

### Hash Table
- `HashTable` — hash table with **separate chaining** (`vector<list<pair<int,string>>>`):
  - `insert(key, value)` — inserts or updates if key exists
  - `search(key)` — returns value or `"Not Found"`
  - `remove(key)` — erases the matching node from its bucket's chain
  - Hash function: `key % size`
  - Fixed capacity — no automatic resizing/rehashing as load increases

### Supporting Types
- `Ticket` — example record type (`id`, `name`, `from`, `to`) with `operator==` by `id`,
  used to demonstrate `QueueSLL<Ticket>`

## Usage

The `main()` function currently demonstrates the `HashTable`:

```cpp
HashTable ht(10);

ht.insert(101, "Ahmed");
ht.insert(202, "Ali");
ht.insert(303, "Omar");

cout << ht.search(202) << endl;   // Ali
ht.remove(202);
cout << ht.search(202) << endl;   // Not Found
```

Earlier demo blocks for `QueueSLL<Ticket>` and `MaxHeap<int>` are present but commented
out — uncomment them to try those structures instead.

## Build

```bash
g++ -std=c++17 -o dsa main.cpp
./dsa
```

## Notes

- Sorting functions operate on raw C-style arrays (`int arr[]`), not `std::vector`.
- `Queue`, `circularQueue`, and `PriorityQueue` use a fixed-size array (`size = 100` by
  default) — capacity does not grow.
- `HashTable` is a fixed-bucket-count table; performance degrades as more keys collide
  into the same bucket, since there is no rehashing.
- `BST` and `AVL` are separate implementations (not inherited from one another) with
  overlapping but not identical interfaces.
