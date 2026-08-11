<div align="center">
  <img src="https://github.com/user-attachments/assets/501c98ee-809c-4376-b32d-6d38ae07c489" alt="Raghuram DSA Notes Banner" width="100%"/>
  <br/>
  <img src="https://img.shields.io/badge/Trees-161b22?style=for-the-badge&labelColor=161b22&color=161b22"/>
  <img src="https://img.shields.io/badge/Graphs-161b22?style=for-the-badge&labelColor=161b22&color=161b22"/>
  <img src="https://img.shields.io/badge/DP-161b22?style=for-the-badge&labelColor=161b22&color=161b22"/>
  <img src="https://img.shields.io/badge/Recursion-161b22?style=for-the-badge&labelColor=161b22&color=161b22"/>
  <img src="https://img.shields.io/badge/Sorting-161b22?style=for-the-badge&labelColor=161b22&color=161b22"/>
</div>

# 🐍 Python — Complete Guide (Built-ins, Standard Library + Build Methods)

## Table of Contents
1. [Introduction](#introduction)
2. [Built-in Data Structures (Python's "STL")](#built-in-data-structures)
3. [The `collections` Module](#the-collections-module)
4. [The `heapq` Module](#the-heapq-module)
5. [The `itertools` Module](#the-itertools-module)
6. [The `functools` Module](#the-functools-module)
7. [The `bisect` Module](#the-bisect-module)
8. [Comprehensions & Generators](#comprehensions--generators)
9. [Build & Packaging Methods](#build--packaging-methods)
10. [Quick Reference Cheat Sheet](#quick-reference-cheat-sheet)

---

## Introduction

Python doesn't ship a separate "STL" — its **built-in types** (`list`, `tuple`, `dict`, `set`) plus the **standard library** (`collections`, `heapq`, `itertools`, `functools`, `bisect`) together serve that role. No import needed for built-ins; standard library modules are imported explicitly.

```python
from collections import deque, defaultdict, Counter, OrderedDict
import heapq, itertools, functools, bisect
```

---

## Built-in Data Structures

### `list` — Dynamic Array
```python
lst = [1, 2, 3]
lst.append(4)          # O(1) amortized
lst.insert(0, 0)         # O(n)
lst.pop()                # O(1) - removes last
lst.pop(0)               # O(n) - removes first
lst.remove(2)            # O(n) - removes by value
lst.sort()                # O(n log n), in-place
lst.sort(key=lambda x: -x, reverse=True)
sorted(lst)               # returns new sorted list
lst[::-1]                 # reversed copy
lst.index(3)               # find index
```

### `tuple` — Immutable Sequence
```python
t = (1, 2, 3)
a, b, c = t                # unpacking
t2 = t + (4,)               # concatenation creates new tuple
```

### `dict` — Hash Map (insertion-ordered since 3.7)
```python
d = {"a": 1, "b": 2}
d["c"] = 3
d.get("x", 0)                 # default value
d.setdefault("d", 0)
d.pop("a")
for k, v in d.items(): ...
{k: v for k, v in d.items() if v > 1}     # dict comprehension
```

### `set` / `frozenset` — Unique Unordered Elements
```python
s = {1, 2, 3}
s.add(4)
s.discard(2)          # no error if missing
s.remove(2)             # raises KeyError if missing
s1 & s2                  # intersection
s1 | s2                  # union
s1 - s2                  # difference
s1 ^ s2                  # symmetric difference
frozenset([1, 2, 3])     # immutable, hashable set
```

### `str` — Immutable Sequence of Characters
```python
"hello".upper()
"hello world".split()
"-".join(["a", "b", "c"])
"  hi  ".strip()
f"{name} is {age} years old"     # f-strings
```

---

## The `collections` Module

### `deque` — Double-Ended Queue
```python
from collections import deque
dq = deque([1, 2, 3])
dq.appendleft(0)     # O(1)
dq.append(4)          # O(1)
dq.popleft()           # O(1)
dq.pop()                # O(1)
dq.rotate(1)             # rotate right by 1
```
> Use `deque` instead of `list` for queue behavior — `list.pop(0)` is O(n), `deque.popleft()` is O(1).

### `Counter` — Frequency Map
```python
from collections import Counter
c = Counter("mississippi")
c.most_common(2)         # [('i', 4), ('s', 4)]
c["z"]                     # 0 (no KeyError)
c.update("abc")
```

### `defaultdict` — Auto-Initializing Dict
```python
from collections import defaultdict
graph = defaultdict(list)
graph["A"].append("B")     # no KeyError, auto-creates []

count = defaultdict(int)
count["x"] += 1
```

### `OrderedDict` — Explicit Ordering Operations
```python
from collections import OrderedDict
od = OrderedDict()
od.move_to_end("a")
od.popitem(last=False)      # pop first item -- useful for LRU cache
```

### `namedtuple` — Lightweight Immutable Record
```python
from collections import namedtuple
Point = namedtuple("Point", ["x", "y"])
p = Point(1, 2)
p.x, p.y
```

---

## The `heapq` Module

Python only provides a **min-heap** via a plain list.
```python
import heapq
heap = [5, 1, 8, 3]
heapq.heapify(heap)          # O(n), in-place
heapq.heappush(heap, 2)       # O(log n)
heapq.heappop(heap)            # O(log n), returns smallest

# Max-heap trick: negate values
maxheap = []
heapq.heappush(maxheap, -5)
-heapq.heappop(maxheap)

heapq.nlargest(3, heap)
heapq.nsmallest(3, heap)
```

---

## The `itertools` Module

```python
import itertools

itertools.permutations([1,2,3])        # all orderings
itertools.combinations([1,2,3], 2)       # choose 2, unordered
itertools.product([1,2], [3,4])            # cartesian product
itertools.groupby(data, key=func)           # group consecutive
itertools.accumulate([1,2,3,4])              # running totals -> 1,3,6,10
itertools.chain([1,2], [3,4])                  # flatten iterables
itertools.count(start=0, step=1)                # infinite counter
itertools.cycle([1,2,3])                          # infinite repeat
```

---

## The `functools` Module

```python
from functools import lru_cache, reduce, cmp_to_key, partial

@lru_cache(maxsize=None)
def fib(n):
    return n if n < 2 else fib(n-1) + fib(n-2)

reduce(lambda a, b: a + b, [1, 2, 3, 4])      # 10

sorted(items, key=cmp_to_key(lambda a, b: a - b))

add5 = partial(lambda a, b: a + b, 5)
```

---

## The `bisect` Module

Binary search on sorted lists — Python's equivalent to `lower_bound`/`upper_bound`.
```python
import bisect
arr = [1, 3, 4, 7]
bisect.bisect_left(arr, 4)      # index of first position >= 4
bisect.bisect_right(arr, 4)      # index of first position > 4
bisect.insort(arr, 5)             # insert while keeping sorted, O(n)
```

---

## Comprehensions & Generators

```python
squares = [x*x for x in range(10)]
evens = [x for x in range(20) if x % 2 == 0]
pairs = {(x, y) for x in range(3) for y in range(3)}
squared_dict = {x: x*x for x in range(5)}

def gen():
    for i in range(5):
        yield i * i

g = (x*x for x in range(1000000))     # generator expression, lazy
```

---

## Build & Packaging Methods

### 1. Virtual Environments
```bash
python -m venv venv
source venv/bin/activate      # Linux/macOS
venv\Scripts\activate           # Windows
deactivate
```

### 2. `pip` — Installing & Freezing Dependencies
```bash
pip install requests
pip install -r requirements.txt
pip freeze > requirements.txt
pip install -e .                 # editable/development install
```

### 3. `setup.py` (Classic Packaging)
```python
from setuptools import setup, find_packages

setup(
    name="myapp",
    version="0.1.0",
    packages=find_packages(),
    install_requires=["requests>=2.0"],
    entry_points={
        "console_scripts": ["myapp=myapp.cli:main"],
    },
)
```
```bash
python setup.py sdist bdist_wheel     # builds distributable packages
pip install .                          # install locally
```

### 4. `pyproject.toml` (Modern Standard, PEP 621)
```toml
[build-system]
requires = ["setuptools>=61.0"]
build-backend = "setuptools.build_meta"

[project]
name = "myapp"
version = "0.1.0"
dependencies = ["requests>=2.0"]

[project.scripts]
myapp = "myapp.cli:main"
```
```bash
python -m build          # builds sdist + wheel into dist/
pip install .
```

### 5. Poetry (All-in-One Dependency + Build Tool)
```bash
poetry new myapp
poetry add requests
poetry install
poetry build
poetry publish
```
`pyproject.toml` with Poetry:
```toml
[tool.poetry]
name = "myapp"
version = "0.1.0"

[tool.poetry.dependencies]
python = "^3.11"
requests = "^2.31"
```

### 6. Running & Compiling
```bash
python main.py                 # direct interpretation
python -m myapp                 # run as module
python -O main.py                # optimized bytecode (.pyc)
python -m py_compile main.py      # precompile to .pyc
```

### Build Tool Comparison

| Tool | Config File | Purpose |
|---|---|---|
| `venv` | none | isolated environments |
| `pip` | `requirements.txt` | dependency install |
| `setuptools` | `setup.py` / `pyproject.toml` | classic packaging |
| `pyproject.toml` (PEP 517/621) | `pyproject.toml` | modern standard build config |
| Poetry | `pyproject.toml` | dependency + build + publish, all-in-one |

---

## Quick Reference Cheat Sheet

| Need | Use |
|---|---|
| Dynamic array | `list` |
| Fast queue (both ends) | `collections.deque` |
| Unique elements | `set` |
| Key-value lookup | `dict` |
| Frequency counting | `collections.Counter` |
| Default-valued dict | `collections.defaultdict` |
| Min-heap | `heapq` |
| Binary search on sorted list | `bisect` |
| Memoization | `functools.lru_cache` |
| Combinatorics | `itertools` |

---

## DSA Suitability Comparison

| Language | Suitability | Why |
|---|---|---|
| C++ | 95% | Richest STL, fastest raw execution, direct memory control — the standard choice for competitive programming (Codeforces, ICPC) |
| Java | 80% | Solid Collections Framework, good performance, but more boilerplate under time pressure |
| **Python** | **68%** | Easiest to read/write, great for learning concepts, but slower execution and no built-in max-heap |

> Python is the best language for *learning* DSA concepts — `heapq`, `collections.deque`, and comprehensions keep code short and readable — but its interpreter overhead can be a real handicap in strict time-limit problems, and simulating a max-heap requires negating values.

---
*End of Python Guide.*
