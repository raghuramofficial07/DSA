# Java `Set` Interface — Complete Notes

## 1. What is `Set` in Java?

`Set` is an interface in the **`java.util`** package, part of the **Java Collections Framework (JCF)**. It represents a collection that **stores unique elements only** — no duplicates allowed.

```java
import java.util.*;

Set<Integer> set = new HashSet<>();
set.add(1);
set.add(2);
set.add(2); // ignored, duplicate
System.out.println(set); // [1, 2]
```

`Set` extends the `Collection` interface, so it inherits general collection behavior but adds the uniqueness constraint.

---

## 2. Main Implementations of `Set`

| Implementation | Ordering | Underlying Structure | Null Allowed | Time Complexity (add/remove/contains) |
|---|---|---|---|---|
| `HashSet` | No guaranteed order | Hash table | One `null` | O(1) average |
| `LinkedHashSet` | Insertion order | Hash table + linked list | One `null` | O(1) average |
| `TreeSet` | Sorted (natural or custom comparator) | Red-Black Tree | No `null` (throws NPE) | O(log n) |
| `EnumSet` | Natural order of enum | Bit vector | No `null` | O(1) |
| `CopyOnWriteArraySet` | Insertion order | Backed by `CopyOnWriteArrayList` | Yes | O(n) — thread-safe, for concurrent reads |

**This is the key point for your STL question** — see Section 6.

---

## 3. Core Methods (from `Collection` + `Set`-specific behavior)

| Method | Description | Complexity (HashSet) |
|---|---|---|
| `add(E e)` | Adds element if not already present. Returns `true`/`false`. | O(1) avg |
| `remove(Object o)` | Removes element if present. Returns `true`/`false`. | O(1) avg |
| `contains(Object o)` | Checks membership. | O(1) avg |
| `size()` | Number of elements. | O(1) |
| `isEmpty()` | Checks if set has no elements. | O(1) |
| `clear()` | Removes all elements. | O(n) |
| `iterator()` | Returns an `Iterator` for traversal. | O(1) to get |
| `addAll(Collection c)` | Union — adds all elements from another collection. | O(m) |
| `removeAll(Collection c)` | Difference — removes all elements present in `c`. | O(m) |
| `retainAll(Collection c)` | Intersection — keeps only elements also in `c`. | O(n) |
| `toArray()` | Converts set to array. | O(n) |
| `stream()` | Java 8+ stream for functional operations. | O(1) to get stream |

### Examples

```java
Set<String> s = new HashSet<>();
s.add("apple");
s.add("banana");
s.add("apple");        // ignored
System.out.println(s.contains("banana")); // true
s.remove("apple");
System.out.println(s.size());             // 1

for (String fruit : s) {
    System.out.println(fruit);
}

// Set algebra
Set<Integer> a = new HashSet<>(List.of(1, 2, 3));
Set<Integer> b = new HashSet<>(List.of(2, 3, 4));

Set<Integer> union = new HashSet<>(a);
union.addAll(b);                 // {1,2,3,4}

Set<Integer> intersection = new HashSet<>(a);
intersection.retainAll(b);        // {2,3}

Set<Integer> difference = new HashSet<>(a);
difference.removeAll(b);          // {1}
```

---

## 4. `HashSet` vs `LinkedHashSet` vs `TreeSet`

```java
Set<Integer> hs = new HashSet<>(List.of(5, 3, 1, 4, 2));
System.out.println(hs); // e.g. [1, 2, 3, 4, 5] or unpredictable order — NOT guaranteed

Set<Integer> lhs = new LinkedHashSet<>(List.of(5, 3, 1, 4, 2));
System.out.println(lhs); // [5, 3, 1, 4, 2] — insertion order preserved

Set<Integer> ts = new TreeSet<>(List.of(5, 3, 1, 4, 2));
System.out.println(ts); // [1, 2, 3, 4, 5] — sorted
```

`TreeSet` also gives extra navigation methods (implements `NavigableSet`):
```java
TreeSet<Integer> ts = new TreeSet<>(List.of(10, 20, 30, 40));
ts.first();          // 10
ts.last();           // 40
ts.higher(20);       // 30 (strictly greater)
ts.lower(20);        // 10 (strictly less)
ts.ceiling(25);      // 30 (>= 25)
ts.floor(25);        // 20 (<= 25)
ts.headSet(30);      // [10, 20] (elements < 30)
ts.tailSet(30);      // [30, 40] (elements >= 30)
```

### `pollFirst()` and `pollLast()` — read-and-remove

These are the two methods most people miss. Unlike `first()`/`last()`, which only **read** the min/max and throw `NoSuchElementException` on an empty set, `pollFirst()`/`pollLast()` **read AND remove** the min/max in one atomic call, and return `null` instead of throwing if the set is empty.

| Method | Action | Empty-set behavior |
|---|---|---|
| `first()` | Peek smallest, no removal | Throws `NoSuchElementException` |
| `last()` | Peek largest, no removal | Throws `NoSuchElementException` |
| `pollFirst()` | Remove & return smallest | Returns `null` |
| `pollLast()` | Remove & return largest | Returns `null` |

```java
TreeSet<Integer> ts = new TreeSet<>(List.of(30, 10, 40, 20));

Integer min = ts.pollFirst(); // 10, set becomes [20, 30, 40]
Integer max = ts.pollLast();  // 40, set becomes [20, 30]

TreeSet<Integer> empty = new TreeSet<>();
System.out.println(empty.pollFirst()); // null — no exception thrown
```

**Why they're useful:**
- **Draining a sorted set in order** — repeatedly calling `pollFirst()` in a loop gives you elements in ascending order while emptying the set, without needing a separate iterator + remove call.
  ```java
  while (!ts.isEmpty()) {
      System.out.println(ts.pollFirst()); // prints in ascending order, one at a time
  }
  ```
- **Min/Max-based greedy algorithms** — e.g., repeatedly pairing the smallest and largest remaining elements (a common interview pattern: "pair up elements to minimize/maximize some cost").
  ```java
  while (ts.size() > 1) {
      int smallest = ts.pollFirst();
      int largest = ts.pollLast();
      // process the pair...
  }
  ```
- **Simulating a min-heap / max-heap with duplicate removal** — `PriorityQueue` doesn't dedupe, but if you also need uniqueness, `TreeSet` + `pollFirst()`/`pollLast()` gives you a sorted, duplicate-free structure with heap-like pop behavior. (Trade-off: O(log n) like a heap, but with the added uniqueness guarantee `PriorityQueue` lacks.)
- **Null-safe draining** — since these return `null` on empty instead of throwing, they're natural for `while ((x = ts.pollFirst()) != null)` style loops without needing a try/catch or an `isEmpty()` check first.

**STL comparison:** C++'s `std::set` has no single combined "pop" method either — you'd write `auto it = s.begin(); int val = *it; s.erase(it);` to get the same read-and-remove effect. Java's `pollFirst()`/`pollLast()` are effectively that same pattern wrapped into one atomic call — a small but genuinely convenient improvement over STL here.

---

## 5. Why `Set` Is Useful

1. **Deduplication**
   ```java
   List<Integer> list = List.of(1, 2, 2, 3, 3, 3);
   Set<Integer> unique = new HashSet<>(list); // {1, 2, 3}
   ```
2. **Fast membership checks** — O(1) avg with `HashSet` vs O(n) for `List.contains()`.
3. **Set algebra** (union/intersection/difference) — built-in via `addAll`/`retainAll`/`removeAll`.
4. **Sorted uniqueness** — `TreeSet` when you need both dedup + order, without manual sorting.
5. **"Visited" tracking** in graph/tree algorithms (BFS/DFS).
6. **Maintaining insertion order** with dedup via `LinkedHashSet` (e.g., preserving first-seen order while removing dupes).

---

## 6. Is `Set` "STL Category"? — Java vs C++ STL Comparison

Yes — this maps very directly onto C++ STL, and interviewers like it when you can draw the parallel:

| C++ STL | Java Equivalent | Ordering | Backing Structure |
|---|---|---|---|
| `std::unordered_set` | `HashSet` | None guaranteed | Hash table |
| `std::set` | `TreeSet` | Sorted | Red-Black Tree |
| — (no direct equivalent) | `LinkedHashSet` | Insertion order | Hash table + linked list |
| `std::unordered_map` | `HashMap` | None guaranteed | Hash table |
| `std::map` | `TreeMap` | Sorted by key | Red-Black Tree |
| `std::vector` | `ArrayList` | Insertion order (indexed) | Dynamic array |
| `std::deque` | `ArrayDeque` | Insertion order | Resizable array (circular buffer) |
| `std::stack` | `Deque` (used as stack) or `Stack` (legacy) | LIFO | Array/linked list |
| `std::queue` | `LinkedList` / `ArrayDeque` (as `Queue`) | FIFO | Linked list / array |
| `std::priority_queue` | `PriorityQueue` | Heap order | Binary heap |

**Bottom line:** Java's Collections Framework is Java's version of STL containers. `HashSet` ≈ `unordered_set`, `TreeSet` ≈ `set`. Knowing this mapping is genuinely useful if you're coming from a C++ background — the concepts transfer almost 1:1.

---

## 7. Are These Asked in Interviews? Yes — Extremely Common

### Where `Set` shows up:

**a) Duplicate detection**
```java
public boolean containsDuplicate(int[] nums) {
    Set<Integer> seen = new HashSet<>();
    for (int n : nums) {
        if (!seen.add(n)) return true; // add() returns false if already present
    }
    return false;
}
```

**b) Two Sum (O(n) instead of O(n^2))**
```java
public boolean hasPairWithSum(int[] arr, int target) {
    Set<Integer> seen = new HashSet<>();
    for (int num : arr) {
        if (seen.contains(target - num)) return true;
        seen.add(num);
    }
    return false;
}
```

**c) Longest substring without repeating characters** — sliding window + `HashSet`.

**d) Graph/tree traversal** — `visited` set in BFS/DFS to avoid revisiting nodes.

**e) Finding intersection of two arrays** — classic `retainAll`-based question.

**f) Anagram checks** — often better with `HashMap<Character, Integer>` for counts, but `Set` shows up in variations (e.g., "unique characters only").

### What interviewers look for:
- Do you pick `HashSet` (fast, unordered) vs `TreeSet` (sorted, slower) appropriately for the problem?
- Do you know `add()` returns a `boolean` — useful for one-line duplicate checks (as shown above)?
- Do you understand **why** `HashSet` requires proper `equals()`/`hashCode()` overrides for custom objects to work correctly?
- Do you know the Big-O trade-offs (`HashSet` O(1) vs `TreeSet` O(log n))?

### Common gotcha interviewers test:
```java
class Point {
    int x, y;
    Point(int x, int y) { this.x = x; this.y = y; }
    // If you don't override equals() and hashCode(),
    // two Points with the same x,y are treated as DIFFERENT objects in a HashSet!
}
```
This is a favorite interview trap — Java's default `equals()`/`hashCode()` compare object references, not values, unless you override them.

---

## 8. Set vs List vs Map — Quick Decision Guide

| Need | Use |
|---|---|
| Ordered, duplicates allowed, indexed access | `ArrayList` / `LinkedList` |
| Unique values only, fastest lookup, order doesn't matter | `HashSet` |
| Unique values, preserve insertion order | `LinkedHashSet` |
| Unique values, need sorted order or range queries | `TreeSet` |
| Key to value pairs, fastest lookup | `HashMap` |
| Key to value, sorted by key | `TreeMap` |
| Key to value, preserve insertion order | `LinkedHashMap` |

---

## 9. Quick Reference Cheat Sheet

```java
Set<Integer> s = new HashSet<>(List.of(1, 2, 3));
s.add(4);                 // {1,2,3,4}
s.contains(3);             // true
s.remove(1);                // {2,3,4}
s.size();                   // 3
List<Integer> list = new ArrayList<>(s); // convert to List
s.clear();                   // {}
```

**One-liners for interviews:**
```java
// Remove duplicates from a List
Set<Integer> unique = new HashSet<>(list);

// Check if all elements in array are unique
boolean allUnique = new HashSet<>(Arrays.asList(arr)).size() == arr.length;

// Union / Intersection / Difference
Set<T> union = new HashSet<>(a); union.addAll(b);
Set<T> intersection = new HashSet<>(a); intersection.retainAll(b);
Set<T> difference = new HashSet<>(a); difference.removeAll(b);
```
