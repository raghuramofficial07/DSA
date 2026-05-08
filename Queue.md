
<div align="center"><img width="841" alt="Screenshot 2025-06-22 at 10 51 31 AM" src="https://github.com/user-attachments/assets/501c98ee-809c-4376-b32d-6d38ae07c489" /></div>


# 🗂️ Queues — Complete DSA Guide
### C++ · Python · JavaScript

> **#CodeWithRaghuRam** | DSA Journey » From Zero ➤ Hero
> `TopicLogs/Queues.md` — Part of [RAGHURAMOFFICIAL07](https://github.com/RAGHURAMOFFICIAL07)'s DSA Archive

---

## 📌 Table of Contents

| # | Topic |
|---|-------|
| 01 | [What is a Queue?](#-what-is-a-queue) |
| 02 | [How a Queue Works — Visual](#-how-a-queue-works--visual) |
| 03 | [Types of Queues](#-types-of-queues) |
| 04 | [Queue in C++](#-queue-in-c) |
| 05 | [Queue in Python](#-queue-in-python) |
| 06 | [Queue in JavaScript](#-queue-in-javascript) |
| 07 | [Method Cheatsheet — All 3 Languages](#-method-cheatsheet--all-3-languages) |
| 08 | [Time & Space Complexity](#-time--space-complexity) |
| 09 | [Real-World Use Cases](#-real-world-use-cases) |
| 10 | [Common Interview Problems](#-common-interview-problems) |
| 11 | [Quick Revision Sheet](#-quick-revision-sheet) |

---

## 📖 What is a Queue?

A **Queue** is a linear data structure that follows the **FIFO** principle:

```
FIFO = First In, First Out
```

> Think of a **queue at a ticket counter** — the first person to join is the first to be served. No cutting in line. 🎟️

### Key Properties

- **Front** → where elements are removed (dequeued)
- **Rear / Back** → where elements are added (enqueued)
- Elements can only enter from the **rear** and leave from the **front**
- No random access — you cannot reach the middle directly

---

## 🎨 How a Queue Works — Visual

```
ENQUEUE (Add) ──────────────────────────────► DEQUEUE (Remove)
                                              ◄──────────────────
         REAR                                      FRONT
          │                                          │
          ▼                                          ▼
    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
    │   40    │   30    │   20    │   10    │   ___   │
    └─────────┴─────────┴─────────┴─────────┴─────────┘
    (last in)                              (first out)
```

### Step-by-step Trace

```
Initial Queue:  [ ]   ← empty

enqueue(10)  →  [ 10 ]
enqueue(20)  →  [ 10, 20 ]
enqueue(30)  →  [ 10, 20, 30 ]
dequeue()    →  [ 20, 30 ]        removes 10 (front)
peek/front() →  20                looks at front, doesn't remove
dequeue()    →  [ 30 ]            removes 20
dequeue()    →  [ ]               removes 30 → Queue is now empty
```

---

## 🧩 Types of Queues

| Type | Description | Use Case |
|------|-------------|----------|
| **Simple Queue** | Basic FIFO | Task scheduling |
| **Circular Queue** | Rear connects back to Front | CPU scheduling, buffers |
| **Double-Ended Queue (Deque)** | Insert/delete from both ends | Sliding window problems |
| **Priority Queue** | Element with highest priority served first | Dijkstra's algorithm, hospital triage |

---

## 🔵 Queue in C++

### Method 1 — Using `<queue>` STL (Recommended)

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // ── ENQUEUE ──────────────────────────────────────
    q.push(10);          // adds 10 to the rear
    q.push(20);          // adds 20 to the rear
    q.push(30);          // adds 30 to the rear
    // Queue: [10, 20, 30]  front=10, rear=30

    // ── ACCESS ───────────────────────────────────────
    cout << q.front();   // 10  ← returns front element
    cout << q.back();    // 30  ← returns rear element

    // ── DEQUEUE ──────────────────────────────────────
    q.pop();             // removes 10 (front)
    // Queue: [20, 30]

    // ── SIZE & EMPTY CHECK ───────────────────────────
    cout << q.size();    // 2
    cout << q.empty();   // 0 (false, not empty)

    return 0;
}
```

### Method 2 — Using `<deque>` (Double-Ended Queue)

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_back(10);    // add to rear
    dq.push_back(20);
    dq.push_front(5);    // add to front ← unique to deque!
    // dq: [5, 10, 20]

    dq.pop_front();      // remove from front → [10, 20]
    dq.pop_back();       // remove from rear  → [10]

    cout << dq.front();  // 10
    cout << dq.back();   // 10

    return 0;
}
```

### Method 3 — Priority Queue

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    // MAX heap (default) — largest element at front
    priority_queue<int> pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    cout << pq.top();    // 50 ← highest priority (max)
    pq.pop();            // removes 50
    cout << pq.top();    // 30

    // MIN heap — smallest element at front
    priority_queue<int, vector<int>, greater<int>> minPQ;
    minPQ.push(30);
    minPQ.push(10);
    minPQ.push(50);
    cout << minPQ.top(); // 10 ← lowest value = highest priority
}
```

### C++ Queue Methods — Full Reference

```cpp
queue<int> q;

q.push(x)    // ► Enqueue: add x to rear          O(1)
q.pop()      // ► Dequeue: remove front element    O(1)
q.front()    // ► Peek front (read only)           O(1)
q.back()     // ► Peek rear  (read only)           O(1)
q.size()     // ► Number of elements               O(1)
q.empty()    // ► true if queue is empty           O(1)
q.swap(q2)   // ► Swap contents with another queue O(1)
```

---

## 🟡 Queue in Python

Python has **3 ways** to implement a queue. Each has its best use case.

### Method 1 — Using `collections.deque` ✅ Best for General Use

```python
from collections import deque

q = deque()

# ── ENQUEUE ───────────────────────────────────────────
q.append(10)         # adds 10 to the right (rear)
q.append(20)
q.append(30)
# q: deque([10, 20, 30])

# ── DEQUEUE ───────────────────────────────────────────
q.popleft()          # removes and returns 10 (front)  O(1)
# q: deque([20, 30])

# ── ACCESS ────────────────────────────────────────────
print(q[0])          # 20  ← front element (peek)
print(q[-1])         # 30  ← rear element  (peek)

# ── SIZE & CHECK ──────────────────────────────────────
print(len(q))        # 2
print(not q)         # False (queue is not empty)

# ── DOUBLE-ENDED (deque bonus) ────────────────────────
q.appendleft(5)      # add to front ← unique to deque!
q.pop()              # remove from rear
```

> ⚠️ **Why not use a list?**
> `list.pop(0)` is **O(n)** because it shifts all elements.
> `deque.popleft()` is **O(1)** — always prefer `deque` for queues.

### Method 2 — Using `queue.Queue` ✅ Best for Multithreading

```python
import queue

q = queue.Queue(maxsize=5)   # maxsize=0 means unlimited

# ── ENQUEUE ───────────────────────────────────────────
q.put(10)            # blocks if queue is full (maxsize reached)
q.put(20)
q.put(30)

# ── DEQUEUE ───────────────────────────────────────────
item = q.get()       # removes and returns front element (blocks if empty)
print(item)          # 10

# ── NON-BLOCKING ──────────────────────────────────────
q.put_nowait(40)     # raises queue.Full if full
item = q.get_nowait() # raises queue.Empty if empty

# ── CHECK ─────────────────────────────────────────────
print(q.empty())     # False
print(q.full())      # False (size=2 out of maxsize=5)
print(q.qsize())     # 2
```

### Method 3 — Using `heapq` for Priority Queue

```python
import heapq

pq = []

# ── ENQUEUE ───────────────────────────────────────────
heapq.heappush(pq, 30)   # push 30
heapq.heappush(pq, 10)   # push 10
heapq.heappush(pq, 50)   # push 50
heapq.heappush(pq, 20)   # push 20
# pq: [10, 20, 50, 30] ← min-heap, smallest at index 0

# ── PEEK ──────────────────────────────────────────────
print(pq[0])             # 10 ← smallest element (front)

# ── DEQUEUE ───────────────────────────────────────────
print(heapq.heappop(pq)) # 10 ← removes smallest
print(heapq.heappop(pq)) # 20

# ── MAX HEAP (negate values trick) ────────────────────
max_pq = []
for val in [30, 10, 50, 20]:
    heapq.heappush(max_pq, -val)   # store negatives

print(-heapq.heappop(max_pq))      # 50 ← largest
```

### Python Queue Methods — Full Reference

```python
# ── collections.deque ─────────────────────────────────
dq.append(x)         # ► add to rear                   O(1)
dq.appendleft(x)     # ► add to front                  O(1)
dq.popleft()         # ► remove from front             O(1)
dq.pop()             # ► remove from rear              O(1)
dq[0]                # ► peek front                    O(1)
dq[-1]               # ► peek rear                     O(1)
len(dq)              # ► number of elements            O(1)
dq.clear()           # ► empty the queue               O(n)
dq.rotate(n)         # ► rotate n steps right (+) / left (-) O(k)
dq.count(x)          # ► count occurrences of x        O(n)
dq.reverse()         # ► reverse in place              O(n)

# ── queue.Queue ───────────────────────────────────────
q.put(x)             # ► enqueue (blocking)            O(1)
q.get()              # ► dequeue (blocking)            O(1)
q.put_nowait(x)      # ► enqueue (non-blocking)        O(1)
q.get_nowait()       # ► dequeue (non-blocking)        O(1)
q.empty()            # ► True if empty                 O(1)
q.full()             # ► True if full                  O(1)
q.qsize()            # ► approximate size              O(1)
q.task_done()        # ► signal task completed         O(1)
q.join()             # ► block until all tasks done    O(n)
```

---

## 🟢 Queue in JavaScript

JavaScript has **no built-in Queue class** — we implement it using arrays or custom classes.

### Method 1 — Using Array (Simple, Beginner-Friendly)

```javascript
const queue = [];

// ── ENQUEUE ───────────────────────────────────────────
queue.push(10);          // add to rear   → [10]
queue.push(20);          // add to rear   → [10, 20]
queue.push(30);          // add to rear   → [10, 20, 30]

// ── DEQUEUE ───────────────────────────────────────────
queue.shift();           // remove front  → [20, 30]  ⚠️ O(n)

// ── ACCESS ────────────────────────────────────────────
console.log(queue[0]);   // 20  ← peek front
console.log(queue[queue.length - 1]); // 30 ← peek rear

// ── SIZE & CHECK ──────────────────────────────────────
console.log(queue.length);     // 2
console.log(queue.length === 0); // false (not empty)
```

> ⚠️ **`shift()` is O(n)** — fine for small queues, avoid in performance-critical code.

### Method 2 — Custom Queue Class ✅ Efficient O(1) Operations

```javascript
class Queue {
    #data = {};
    #head = 0;
    #tail = 0;

    // ── ENQUEUE ─────────────────────────────────────
    enqueue(value) {
        this.#data[this.#tail] = value;
        this.#tail++;
    }

    // ── DEQUEUE ─────────────────────────────────────
    dequeue() {
        if (this.isEmpty()) return undefined;
        const value = this.#data[this.#head];
        delete this.#data[this.#head];
        this.#head++;
        return value;
    }

    // ── PEEK ────────────────────────────────────────
    peek() {
        return this.#data[this.#head];
    }

    // ── SIZE ────────────────────────────────────────
    size() {
        return this.#tail - this.#head;
    }

    // ── EMPTY CHECK ─────────────────────────────────
    isEmpty() {
        return this.size() === 0;
    }

    // ── CLEAR ───────────────────────────────────────
    clear() {
        this.#data = {};
        this.#head = 0;
        this.#tail = 0;
    }

    // ── ITERATOR ────────────────────────────────────
    toArray() {
        return Object.values(this.#data);
    }
}

// ── USAGE ───────────────────────────────────────────────
const q = new Queue();
q.enqueue(10);
q.enqueue(20);
q.enqueue(30);
console.log(q.peek());    // 10
console.log(q.dequeue()); // 10
console.log(q.size());    // 2
console.log(q.toArray()); // [20, 30]
```

### Method 3 — Priority Queue in JavaScript

```javascript
class MinPriorityQueue {
    #heap = [];

    enqueue(value, priority) {
        this.#heap.push({ value, priority });
        this.#bubbleUp();
    }

    dequeue() {
        if (this.isEmpty()) return null;
        this.#swap(0, this.#heap.length - 1);
        const min = this.#heap.pop();
        this.#sinkDown();
        return min;
    }

    peek() {
        return this.#heap[0] || null;
    }

    isEmpty() { return this.#heap.length === 0; }
    size()    { return this.#heap.length; }

    #bubbleUp() {
        let idx = this.#heap.length - 1;
        while (idx > 0) {
            const parent = Math.floor((idx - 1) / 2);
            if (this.#heap[parent].priority <= this.#heap[idx].priority) break;
            this.#swap(parent, idx);
            idx = parent;
        }
    }

    #sinkDown() {
        let idx = 0;
        const length = this.#heap.length;
        while (true) {
            let smallest = idx;
            const left = 2 * idx + 1, right = 2 * idx + 2;
            if (left < length && this.#heap[left].priority < this.#heap[smallest].priority)
                smallest = left;
            if (right < length && this.#heap[right].priority < this.#heap[smallest].priority)
                smallest = right;
            if (smallest === idx) break;
            this.#swap(idx, smallest);
            idx = smallest;
        }
    }

    #swap(i, j) {
        [this.#heap[i], this.#heap[j]] = [this.#heap[j], this.#heap[i]];
    }
}

// ── USAGE ───────────────────────────────────────────────
const pq = new MinPriorityQueue();
pq.enqueue("Task A", 3);
pq.enqueue("Task B", 1);    // highest priority
pq.enqueue("Task C", 2);

console.log(pq.peek());     // { value: 'Task B', priority: 1 }
console.log(pq.dequeue());  // { value: 'Task B', priority: 1 }
console.log(pq.dequeue());  // { value: 'Task C', priority: 2 }
```

### JavaScript Queue Methods — Full Reference

```javascript
// ── Array-based (built-in) ────────────────────────────
arr.push(x)           // ► add to rear                  O(1) amortized
arr.shift()           // ► remove from front            O(n) ⚠️
arr[0]                // ► peek front                   O(1)
arr[arr.length-1]     // ► peek rear                    O(1)
arr.length            // ► size                         O(1)
arr.length === 0      // ► isEmpty check                O(1)
arr.includes(x)       // ► search element               O(n)
arr.indexOf(x)        // ► find index                   O(n)

// ── Custom Queue Class (O(1) everything) ──────────────
q.enqueue(x)          // ► add to rear                  O(1)
q.dequeue()           // ► remove from front            O(1)
q.peek()              // ► read front (no removal)      O(1)
q.size()              // ► number of elements           O(1)
q.isEmpty()           // ► boolean empty check          O(1)
q.clear()             // ► reset the queue              O(1)
q.toArray()           // ► convert to array             O(n)
```

---

## 📊 Method Cheatsheet — All 3 Languages

| Operation | C++ (`queue`) | Python (`deque`) | JavaScript (Array) | JavaScript (Class) |
|-----------|--------------|------------------|--------------------|--------------------|
| **Enqueue (add rear)** | `q.push(x)` | `dq.append(x)` | `arr.push(x)` | `q.enqueue(x)` |
| **Dequeue (remove front)** | `q.pop()` | `dq.popleft()` | `arr.shift()` ⚠️ | `q.dequeue()` |
| **Peek front** | `q.front()` | `dq[0]` | `arr[0]` | `q.peek()` |
| **Peek rear** | `q.back()` | `dq[-1]` | `arr[arr.length-1]` | — |
| **Size** | `q.size()` | `len(dq)` | `arr.length` | `q.size()` |
| **Is Empty** | `q.empty()` | `not dq` | `arr.length === 0` | `q.isEmpty()` |
| **Clear** | — | `dq.clear()` | `arr = []` | `q.clear()` |
| **Add to front** | ❌ (use deque) | `dq.appendleft(x)` | `arr.unshift(x)` ⚠️ | ❌ |
| **Remove from rear** | ❌ (use deque) | `dq.pop()` | `arr.pop()` | ❌ |

> ⚠️ = O(n) — avoid in loops or performance-critical paths

---

## ⏱️ Time & Space Complexity

| Operation | Time Complexity | Notes |
|-----------|----------------|-------|
| Enqueue | **O(1)** | Always constant |
| Dequeue | **O(1)** | Except `list.pop(0)` / `arr.shift()` which are O(n) |
| Peek (front/rear) | **O(1)** | Read only, no traversal |
| Search | **O(n)** | Must scan all elements |
| Space | **O(n)** | Scales with number of elements |

---

## 🌍 Real-World Use Cases

```
1. 🖨️  Print Spooler       → Documents queued for printing (FIFO order)
2. 🌐  Web Server Requests → HTTP requests handled in order of arrival
3. 🎮  Game Event Loop     → User inputs processed in sequence
4. 📦  Order Processing    → E-commerce orders fulfilled FIFO
5. 📡  BFS (Graph Search)  → Level-by-level traversal uses a queue
6. 🏥  Hospital Triage     → Priority queue for emergency patients
7. 🔄  CPU Scheduling      → OS queues processes for execution
8. 💬  Message Queues      → Kafka, RabbitMQ — async communication
```

---

## 💡 Common Interview Problems

### Problem 1 — Implement a Stack using Queues

```python
# Using two queues to simulate a stack (LIFO using FIFO)
from collections import deque

class MyStack:
    def __init__(self):
        self.q = deque()

    def push(self, x):
        self.q.append(x)
        # rotate so the new element is at the front
        for _ in range(len(self.q) - 1):
            self.q.append(self.q.popleft())

    def pop(self):
        return self.q.popleft()

    def top(self):
        return self.q[0]

    def empty(self):
        return not self.q

# Test
s = MyStack()
s.push(1); s.push(2); s.push(3)
print(s.top())  # 3
print(s.pop())  # 3
print(s.top())  # 2
```

### Problem 2 — BFS using Queue

```python
from collections import deque

def bfs(graph, start):
    visited = set([start])
    queue   = deque([start])
    order   = []

    while queue:
        node = queue.popleft()        # dequeue front
        order.append(node)

        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor) # enqueue neighbors

    return order

graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [], 'E': [], 'F': []
}

print(bfs(graph, 'A'))  # ['A', 'B', 'C', 'D', 'E', 'F']
```

### Problem 3 — Sliding Window Maximum (Deque)

```python
from collections import deque

def maxSlidingWindow(nums, k):
    result = []
    dq = deque()  # stores indices

    for i in range(len(nums)):
        # remove elements outside the window
        while dq and dq[0] < i - k + 1:
            dq.popleft()

        # remove smaller elements (they'll never be max)
        while dq and nums[dq[-1]] < nums[i]:
            dq.pop()

        dq.append(i)

        if i >= k - 1:
            result.append(nums[dq[0]])  # front is always the max

    return result

print(maxSlidingWindow([1,3,-1,-3,5,3,6,7], 3))
# Output: [3, 3, 5, 5, 6, 7]
```

---

## 📋 Quick Revision Sheet

```
╔══════════════════════════════════════════════════════════════╗
║                    QUEUE — QUICK RECAP                       ║
╠══════════════════════════════════════════════════════════════╣
║  Principle  →  FIFO  (First In, First Out)                  ║
║  Analogy    →  Ticket counter, Print spooler                ║
║  Add at     →  REAR  (enqueue / push / append)              ║
║  Remove at  →  FRONT (dequeue / pop / popleft)              ║
╠══════════════════════════════════════════════════════════════╣
║  C++        →  #include <queue>   → queue<T> q              ║
║  Python     →  from collections import deque                ║
║  JavaScript →  Use custom class for O(1) performance        ║
╠══════════════════════════════════════════════════════════════╣
║  All ops    →  O(1) except search O(n)                      ║
║  Best for   →  BFS, scheduling, buffering, event loops      ║
╠══════════════════════════════════════════════════════════════╣
║  Variants   →  Circular · Deque · Priority Queue            ║
╚══════════════════════════════════════════════════════════════╝
```

---

<div align="center">

### 🚀 Keep Going — One Queue at a Time

*Part of the [DSA Journey » From Zero ➤ Hero](https://github.com/RAGHURAMOFFICIAL07) archive*

`#CodeWithRaghuRam` • `#BeyondCertifications` • `#IndustryOriented`

</div>
