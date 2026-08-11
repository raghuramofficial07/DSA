<div align="center">
  <img src="https://github.com/user-attachments/assets/501c98ee-809c-4376-b32d-6d38ae07c489" alt="Raghuram DSA Notes Banner" width="100%"/>
  <br/>
  <img src="https://img.shields.io/badge/Trees-161b22?style=for-the-badge&labelColor=161b22&color=161b22"/>
  <img src="https://img.shields.io/badge/Graphs-161b22?style=for-the-badge&labelColor=161b22&color=161b22"/>
  <img src="https://img.shields.io/badge/DP-161b22?style=for-the-badge&labelColor=161b22&color=161b22"/>
  <img src="https://img.shields.io/badge/Recursion-161b22?style=for-the-badge&labelColor=161b22&color=161b22"/>
  <img src="https://img.shields.io/badge/Sorting-161b22?style=for-the-badge&labelColor=161b22&color=161b22"/>
</div>

# ⚙️ C++ — Complete Guide (STL + Build Methods)

## Table of Contents
1. [Introduction](#introduction)
2. [STL Overview](#stl-overview)
3. [Sequence Containers](#sequence-containers)
4. [Associative Containers](#associative-containers)
5. [Unordered (Hash) Containers](#unordered-hash-containers)
6. [Container Adapters](#container-adapters)
7. [Iterators](#iterators)
8. [STL Algorithms](#stl-algorithms)
9. [Function Objects & Lambdas](#function-objects--lambdas)
10. [Build Methods](#build-methods)
11. [Quick Reference Cheat Sheet](#quick-reference-cheat-sheet)

---

## Introduction

The **Standard Template Library (STL)** is C++'s generic library of containers, algorithms, iterators, and function objects. It's the origin of the term "STL" that other languages' equivalents borrow.

```cpp
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
```

---

## STL Overview

| Component | Role |
|---|---|
| Containers | Store data (`vector`, `map`, `set`, ...) |
| Iterators | Traverse containers generically |
| Algorithms | Operate on ranges (`sort`, `find`, ...) |
| Function Objects | Customize behavior (comparators, predicates) |

---

## Sequence Containers

### `vector` — Dynamic Array
```cpp
vector<int> v = {1, 2, 3};
v.push_back(4);        // O(1) amortized
v.pop_back();            // O(1)
v.insert(v.begin(), 0);   // O(n)
v.erase(v.begin());        // O(n)
v[0];                        // O(1) access
v.size(); v.empty();
sort(v.begin(), v.end());
```

### `deque` — Double-Ended Queue
```cpp
deque<int> dq;
dq.push_front(1);   // O(1)
dq.push_back(2);      // O(1)
dq.pop_front();
```

### `list` — Doubly Linked List
```cpp
list<int> l;
l.push_back(1);
l.push_front(0);
l.splice(l.begin(), otherList);   // O(1) node transfer
```

### `array` — Fixed-Size Array (C++11)
```cpp
array<int, 5> arr = {1, 2, 3, 4, 5};
arr.size();      // compile-time fixed
```

### `forward_list` — Singly Linked List (C++11, minimal overhead)
```cpp
forward_list<int> fl = {1, 2, 3};
```

---

## Associative Containers

Balanced Red-Black Tree, keeps elements **sorted**. All operations: **O(log n)**.

### `set` / `multiset`
```cpp
set<int> s = {5, 1, 3};
s.insert(4);
s.erase(1);
s.find(3);                  // returns iterator
s.count(3);                 // 0 or 1 (set), can be >1 (multiset)
auto it = s.lower_bound(3);   // first element >= 3
auto it2 = s.upper_bound(3);   // first element > 3
```

### `map` / `multimap`
```cpp
map<string, int> m;
m["apple"] = 1;
m.insert({"banana", 2});
m.find("apple");
m.count("apple");
for (auto& [key, val] : m) { ... }     // structured bindings (C++17)
m.erase("apple");
```

---

## Unordered (Hash) Containers

Hash table backed. Average **O(1)**, worst-case O(n).

```cpp
unordered_set<int> us;
unordered_map<string, int> um;
unordered_multiset<int> ums;
unordered_multimap<string, int> umm;

um["key"] = 10;
um.reserve(100);       // pre-allocate buckets, avoid rehashing
```

| | Sorted? | Avg Lookup | Worst Lookup |
|---|---|---|---|
| `set`/`map` | Yes | O(log n) | O(log n) |
| `unordered_set`/`unordered_map` | No | O(1) | O(n) |

---

## Container Adapters

### `stack` — LIFO
```cpp
stack<int> st;
st.push(1);
st.pop();
st.top();
```

### `queue` — FIFO
```cpp
queue<int> q;
q.push(1);
q.pop();
q.front(); q.back();
```

### `priority_queue` — Heap (Max-Heap by default)
```cpp
priority_queue<int> pq;              // max-heap
pq.push(5); pq.top(); pq.pop();

// Min-heap
priority_queue<int, vector<int>, greater<int>> minHeap;

// Custom comparator
auto cmp = [](pair<int,int>& a, pair<int,int>& b) { return a.first > b.first; };
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq2(cmp);
```

---

## Iterators

```cpp
vector<int> v = {1, 2, 3};
for (auto it = v.begin(); it != v.end(); ++it) { ... }
for (auto it = v.rbegin(); it != v.rend(); ++it) { ... }   // reverse
for (int x : v) { ... }                                     // range-based

// Iterator categories: Input, Output, Forward, Bidirectional, Random Access
advance(it, 3);      // move iterator forward 3
distance(v.begin(), v.end());
```

---

## STL Algorithms

`<algorithm>` header — operates on iterator ranges.

```cpp
sort(v.begin(), v.end());
sort(v.begin(), v.end(), greater<int>());
reverse(v.begin(), v.end());
max_element(v.begin(), v.end());
min_element(v.begin(), v.end());
accumulate(v.begin(), v.end(), 0);          // <numeric>, sum
count(v.begin(), v.end(), 5);
find(v.begin(), v.end(), 5);
binary_search(v.begin(), v.end(), 5);         // requires sorted range
lower_bound(v.begin(), v.end(), 5);            // first >= 5
upper_bound(v.begin(), v.end(), 5);             // first > 5
unique(v.begin(), v.end());                       // removes consecutive dups
next_permutation(v.begin(), v.end());
fill(v.begin(), v.end(), 0);
transform(v.begin(), v.end(), v.begin(), [](int x){ return x*2; });
```

---

## Function Objects & Lambdas

```cpp
// Lambda syntax
auto add = [](int a, int b) { return a + b; };
sort(v.begin(), v.end(), [](int a, int b) { return a > b; });

// Capture by reference / value
int factor = 2;
auto scale = [factor](int x) { return x * factor; };
auto scaleRef = [&factor](int x) { return x * factor; };

// Standard function objects (<functional>)
greater<int>(); less<int>(); plus<int>(); function<int(int,int)> f = add;
```

---

## Build Methods

### 1. Direct Compilation (`g++` / `clang++`)
```bash
g++ main.cpp -o main            # basic compile
g++ -std=c++17 -O2 -Wall main.cpp -o main    # standard, optimize, warnings
./main

# Multiple files
g++ main.cpp helper.cpp -o app

# Compile then link separately
g++ -c main.cpp -o main.o
g++ -c helper.cpp -o helper.o
g++ main.o helper.o -o app

# Debug build
g++ -g -std=c++17 main.cpp -o main_debug
gdb ./main_debug
```

### 2. Makefiles
```makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

app: main.o helper.o
	$(CXX) $(CXXFLAGS) main.o helper.o -o app

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

helper.o: helper.cpp
	$(CXX) $(CXXFLAGS) -c helper.cpp

clean:
	rm -f *.o app
```
```bash
make          # builds using default target
make clean    # removes build artifacts
```

### 3. CMake (Cross-Platform, Industry Standard)
```cmake
cmake_minimum_required(VERSION 3.10)
project(MyApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(app main.cpp helper.cpp)

# With a library
add_library(mylib STATIC lib.cpp)
target_link_libraries(app mylib)
```
```bash
mkdir build && cd build
cmake ..
cmake --build .          # or: make
./app
```

### 4. Static vs Dynamic Linking
```bash
g++ -static main.cpp -o main_static      # static linking
g++ -shared -fPIC lib.cpp -o libmylib.so  # build shared library
g++ main.cpp -L. -lmylib -o app             # link against it
```

### Build Tool Comparison

| Tool | Config File | Best For |
|---|---|---|
| `g++`/`clang++` | none | small programs, quick compiles |
| Make | `Makefile` | small-medium projects, fine control |
| CMake | `CMakeLists.txt` | cross-platform, large/complex projects |
| Bazel | `BUILD` | very large monorepos (Google-scale) |

---

## Quick Reference Cheat Sheet

| Need | Use |
|---|---|
| Dynamic array | `vector` |
| Fast insert/remove at both ends | `deque` |
| Sorted unique elements | `set` |
| Sorted key-value | `map` |
| Fast unordered lookup | `unordered_map` / `unordered_set` |
| Heap / priority extraction | `priority_queue` |
| Stack behavior | `stack` |
| Queue behavior | `queue` |
| Binary search on sorted range | `lower_bound` / `upper_bound` |

---

## DSA Suitability Comparison

| Language | Suitability | Why |
|---|---|---|
| **C++** | **95%** | Richest STL, fastest raw execution, direct memory control — the standard choice for competitive programming (Codeforces, ICPC) |
| Java | 80% | Solid Collections Framework, good performance, but more boilerplate under time pressure |
| Python | 68% | Easiest to read/write, great for learning concepts, but slower execution and no built-in max-heap |

> C++ is generally the most suitable language for DSA — its STL containers (`priority_queue`, `set`, `unordered_map`) map almost 1:1 to textbook data structures, and its performance headroom matters most under tight time limits.

---
*End of C++ Guide.*
