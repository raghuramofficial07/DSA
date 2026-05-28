<div align="center">
  <img src="https://github.com/user-attachments/assets/501c98ee-809c-4376-b32d-6d38ae07c489" />
  <br/>
  <img src="https://img.shields.io/badge/Trees-161b22?style=flat&labelColor=161b22&color=161b22" />
  <img src="https://img.shields.io/badge/Graphs-161b22?style=flat&labelColor=161b22&color=161b22" />
  <img src="https://img.shields.io/badge/DP-161b22?style=flat&labelColor=161b22&color=161b22" />
  <img src="https://img.shields.io/badge/Recursion-161b22?style=flat&labelColor=161b22&color=161b22" />
  <img src="https://img.shields.io/badge/Sorting-161b22?style=flat&labelColor=161b22&color=161b22" />
</div>

---

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
| 04 | [Queue Implementation — All 3 Languages](#-queue-implementation--all-3-languages) |
| 05 | [Method Cheatsheet — All 3 Languages](#-method-cheatsheet--all-3-languages) |
| 06 | [Time & Space Complexity](#-time--space-complexity) |
| 07 | [Real-World Use Cases](#-real-world-use-cases) |
| 08 | [Common Interview Problems](#-common-interview-problems) |
| 09 | [Quick Revision Sheet](#-quick-revision-sheet) |

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

## 💻 Queue Implementation — All 3 Languages

> Same logic. Three languages. Pick yours.

---

### C++ — using `<queue>` STL

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue<int> q;

    // ── ENQUEUE ──────────────────────────────
    q.push(10);          // [10]
    q.push(20);          // [10, 20]
    q.push(30);          // [10, 20, 30]

    // ── ACCESS ───────────────────────────────
    cout << q.front();   // 10  ← front element
    cout << q.back();    // 30  ← rear element

    // ── DEQUEUE ──────────────────────────────
    q.pop();             // removes 10 → [20, 30]

    // ── SIZE & EMPTY ─────────────────────────
    cout << q.size();    // 2
    cout << q.empty();   // 0 (false)

    return 0;
}
```

---

### JavaScript — using custom class (O(1) operations)

```js
class Queue {
    #data = {};
    #head = 0;
    #tail = 0;

    // ── ENQUEUE ──────────────────────────────
    enqueue(value) {
        this.#data[this.#tail] = value;
        this.#tail++;
    }

    // ── DEQUEUE ──────────────────────────────
    dequeue() {
        if (this.isEmpty()) return undefined;
        const value = this.#data[this.#head];
        delete this.#data[this.#head];
        this.#head++;
        return value;
    }

    // ── PEEK / SIZE / EMPTY ───────────────────
    peek()    { return this.#data[this.#head]; }
    size()    { return this.#tail - this.#head; }
    isEmpty() { return this.size() === 0; }
}

// ── USAGE ────────────────────────────────────
const q = new Queue();
q.enqueue(10);           // [10]
q.enqueue(20);           // [10, 20]
q.enqueue(30);           // [10, 20, 30]

console.log(q.peek());   // 10  ← front
console.log(q.dequeue());// 10  → removes it
console.log(q.size());   // 2
```

> ⚠️ Don't use `arr.shift()` for queues — it's **O(n)**. The custom class above is **O(1)** for all ops.

---

### Python — using `collections.deque`

```python
from collections import deque

q = deque()

# ── ENQUEUE ──────────────────────────────────
q.append(10)          # [10]
q.append(20)          # [10, 20]
q.append(30)          # [10, 20, 30]

# ── ACCESS ───────────────────────────────────
print(q[0])           # 10  ← front element
print(q[-1])          # 30  ← rear element

# ── DEQUEUE ──────────────────────────────────
q.popleft()           # removes 10 → [20, 30]

# ── SIZE & EMPTY ─────────────────────────────
print(len(q))         # 2
print(not q)          # False (not empty)

# ── BONUS: double-ended ───────────────────────
q.appendleft(5)       # add to front → [5, 20, 30]
q.pop()               # remove from rear → [5, 20]
```

> ⚠️ Never use `list.pop(0)` — it's **O(n)**. Always use `deque.popleft()` which is **O(1)**.

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
from collections import deque

class MyStack:
    def __init__(self):
        self.q = deque()

    def push(self, x):
        self.q.append(x)
        for _ in range(len(self.q) - 1):
            self.q.append(self.q.popleft())

    def pop(self):
        return self.q.popleft()

    def top(self):
        return self.q[0]

    def empty(self):
        return not self.q

s = MyStack()
s.push(1); s.push(2); s.push(3)
print(s.top())  # 3
print(s.pop())  # 3
print(s.top())  # 2
```

---

### Problem 2 — BFS using Queue

```python
from collections import deque

def bfs(graph, start):
    visited = set([start])
    queue   = deque([start])
    order   = []

    while queue:
        node = queue.popleft()
        order.append(node)

        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

    return order

graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [], 'E': [], 'F': []
}

print(bfs(graph, 'A'))  # ['A', 'B', 'C', 'D', 'E', 'F']
```

---

### Problem 3 — Sliding Window Maximum (Deque)

```python
from collections import deque

def maxSlidingWindow(nums, k):
    result = []
    dq = deque()

    for i in range(len(nums)):
        while dq and dq[0] < i - k + 1:
            dq.popleft()

        while dq and nums[dq[-1]] < nums[i]:
            dq.pop()

        dq.append(i)

        if i >= k - 1:
            result.append(nums[dq[0]])

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
```md
> [!NOTE]
> ## Queue Understanding — Q & A

### Q. What is Queue class?

A. Queue is a blueprint/template used to create queue objects.

---

### Q. What does `const q = new Queue()` do?

A. It creates the actual queue object from the Queue class.

---

### Q. What does `this` refer to?

A. `this` refers to the current object using the method.

---

### Q. In `q.dequeue()`, what is `this`?

A. JavaScript automatically makes:

```js
this = q
```

---

### Q. What is `data`?

A. `data` is the storage structure acting like an array.

```js
{
  0: 10,
  1: 20,
  2: 30
}
```

---

### Q. What is `head`?

A. `head` is a moving pointer/index pointing to the current front element.

---

### Q. Is `head` the actual value?

A. No. It only stores the position/index of the front element.

---

### Q. What does `this.data[this.head]` mean?

A. It means:

```txt
Go to data storage
↓
Use head as index
↓
Get value at that position
```

---

### Q. Example?

```js
head = 0

data = {
  0:10,
  1:20,
  2:30
}

data[head]
↓
data[0]
↓
10
```

---

### Q. What does `delete this.data[this.head]` do?

A. It removes the current front item from storage.

---

### Q. What does `this.head++` do?

A. It moves the pointer to the next element.

---

### Q. How does `head` behave internally?

A. `head` traverses through the structure like an array pointer/cursor,
similar to traversal in linear search.

---

### Q. Why is this queue efficient?

A. Because elements are not shifted. Only the pointer moves forward.

---

<div align="center">

### 🚀 Keep Going — One Queue at a Time

*Part of the [DSA Journey » From Zero ➤ Hero](https://github.com/RAGHURAMOFFICIAL07) archive*

`#CodeWithRaghuRam` • `#BeyondCertifications` • `#IndustryOriented`

</div>
