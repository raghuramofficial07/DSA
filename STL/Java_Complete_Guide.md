<div align="center">
  <img src="https://github.com/user-attachments/assets/501c98ee-809c-4376-b32d-6d38ae07c489" alt="Raghuram DSA Notes Banner" width="100%"/>
  <br/>
  <img src="https://img.shields.io/badge/Trees-161b22?style=for-the-badge&labelColor=161b22&color=161b22"/>
  <img src="https://img.shields.io/badge/Graphs-161b22?style=for-the-badge&labelColor=161b22&color=161b22"/>
  <img src="https://img.shields.io/badge/DP-161b22?style=for-the-badge&labelColor=161b22&color=161b22"/>
  <img src="https://img.shields.io/badge/Recursion-161b22?style=for-the-badge&labelColor=161b22&color=161b22"/>
  <img src="https://img.shields.io/badge/Sorting-161b22?style=for-the-badge&labelColor=161b22&color=161b22"/>
</div>

# ☕ Java — Complete Guide (Collections Framework + Build Methods)

## Table of Contents
1. [Introduction](#introduction)
2. [Java Collections Framework (Java's "STL")](#java-collections-framework)
3. [Core Interfaces](#core-interfaces)
4. [List Implementations](#list-implementations)
5. [Set Implementations](#set-implementations)
6. [Map Implementations](#map-implementations)
7. [Queue & Deque Implementations](#queue--deque-implementations)
8. [Iterators](#iterators)
9. [Streams API](#streams-api)
10. [Generics](#generics)
11. [Build Methods](#build-methods)
12. [Quick Reference Cheat Sheet](#quick-reference-cheat-sheet)

---

## Introduction

Java doesn't have an "STL" in the C++ sense, but it has an equivalent — the **Java Collections Framework (JCF)**, part of `java.util`. It provides a unified architecture for storing and manipulating groups of objects: interfaces, implementations, and algorithms (sorting, searching, shuffling).

```java
import java.util.*;
```

---

## Java Collections Framework

The framework is organized around **interfaces** (contracts) and **classes** (implementations).

```
Iterable
   └── Collection
         ├── List
         ├── Set
         │     └── SortedSet → NavigableSet
         └── Queue
               └── Deque
Map (separate hierarchy)
   └── SortedMap → NavigableMap
```

| Interface | Purpose | Allows Duplicates | Ordered |
|---|---|---|---|
| `List` | Indexed sequence | Yes | Yes (insertion) |
| `Set` | Unique elements | No | Depends on impl |
| `Queue` | FIFO processing | Yes | Yes |
| `Deque` | Double-ended queue | Yes | Yes |
| `Map` | Key-value pairs | Keys: No, Values: Yes | Depends on impl |

---

## Core Interfaces

### Collection Interface — Common Methods
```java
add(E e)          remove(Object o)     contains(Object o)
size()             isEmpty()            clear()
iterator()          addAll(Collection)   removeAll(Collection)
retainAll(Collection)  toArray()         stream()
```

---

## List Implementations

### `ArrayList` — Dynamic Array
```java
List<Integer> list = new ArrayList<>();
list.add(10);
list.add(20);
list.get(0);          // O(1)
list.remove(0);        // O(n)
list.set(0, 99);        // O(1)
Collections.sort(list);
```
- Backed by a resizable array
- **Get/Set:** O(1) | **Insert/Remove (middle):** O(n) | **Insert/Remove (end):** O(1) amortized

### `LinkedList` — Doubly Linked List
```java
List<Integer> ll = new LinkedList<>();
LinkedList<Integer> deque = new LinkedList<>();
deque.addFirst(1);
deque.addLast(2);
```
- Implements both `List` and `Deque`
- **Insert/Remove (ends):** O(1) | **Get by index:** O(n)

### `Vector` / `Stack` (Legacy, Synchronized)
```java
Stack<Integer> stack = new Stack<>();
stack.push(1);
stack.pop();
stack.peek();
```
> Prefer `ArrayDeque` over `Stack` in modern code — it's faster and not synchronized-by-default.

---

## Set Implementations

### `HashSet` — Unordered, Hash Table Backed
```java
Set<Integer> set = new HashSet<>();
set.add(5);
set.contains(5);   // O(1) average
```

### `LinkedHashSet` — Preserves Insertion Order
```java
Set<Integer> lhs = new LinkedHashSet<>();
```

### `TreeSet` — Sorted (Red-Black Tree)
```java
TreeSet<Integer> ts = new TreeSet<>();
ts.add(5); ts.add(1); ts.add(3);
ts.first();      // smallest
ts.last();       // largest
ts.floor(4);     // largest <= 4
ts.ceiling(4);   // smallest >= 4
ts.higher(3);    // smallest > 3
ts.lower(3);     // largest < 3
```
- **All operations:** O(log n)

---

## Map Implementations

### `HashMap`
```java
Map<String, Integer> map = new HashMap<>();
map.put("a", 1);
map.get("a");                     // O(1) average
map.getOrDefault("b", 0);
map.containsKey("a");
map.putIfAbsent("c", 3);
map.merge("a", 1, Integer::sum);   // increment pattern
for (Map.Entry<String, Integer> e : map.entrySet())
    System.out.println(e.getKey() + "=" + e.getValue());
```

### `LinkedHashMap` — Insertion Order Preserved
```java
Map<String, Integer> lhm = new LinkedHashMap<>();
```
Useful for building an **LRU Cache** (`removeEldestEntry` override).

### `TreeMap` — Sorted by Key
```java
TreeMap<Integer, String> tm = new TreeMap<>();
tm.firstKey(); tm.lastKey();
tm.floorKey(5); tm.ceilingKey(5);
```
- **All operations:** O(log n)

---

## Queue & Deque Implementations

### `PriorityQueue` — Heap (Min-Heap by default)
```java
PriorityQueue<Integer> pq = new PriorityQueue<>();
pq.add(5); pq.add(1); pq.add(3);
pq.poll();   // removes & returns smallest -> 1

// Max-heap
PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

// Custom comparator
PriorityQueue<int[]> pq2 = new PriorityQueue<>((a, b) -> a[0] - b[0]);
```

### `ArrayDeque` — Fast Stack/Queue (Preferred)
```java
ArrayDeque<Integer> dq = new ArrayDeque<>();
dq.addFirst(1); dq.addLast(2);
dq.pollFirst(); dq.pollLast();
dq.offer(5);   // as a queue
dq.push(5);    // as a stack
```

---

## Iterators

```java
Iterator<Integer> it = list.iterator();
while (it.hasNext()) {
    int val = it.next();
    if (val == 3) it.remove();   // safe removal during iteration
}

// Enhanced for-loop
for (int val : list) { ... }

// ListIterator (bidirectional, List only)
ListIterator<Integer> lit = list.listIterator();
```

---

## Streams API

```java
List<Integer> nums = Arrays.asList(5, 3, 8, 1, 9);

nums.stream()
    .filter(n -> n > 3)
    .map(n -> n * 2)
    .sorted()
    .forEach(System.out::println);

int sum = nums.stream().mapToInt(Integer::intValue).sum();
List<Integer> squared = nums.stream().map(n -> n * n).collect(Collectors.toList());
Map<Boolean, List<Integer>> partitioned = nums.stream()
    .collect(Collectors.partitioningBy(n -> n % 2 == 0));
```

---

## Generics

```java
class Box<T> {
    private T value;
    public void set(T value) { this.value = value; }
    public T get() { return value; }
}

// Bounded type parameter
class NumberBox<T extends Number> { ... }

// Wildcards
void printList(List<?> list) { ... }
void addNumbers(List<? super Integer> list) { ... }
```

---

## Build Methods

### 1. Manual Compilation (`javac` / `java`)
```bash
javac Main.java          # compiles Main.java -> Main.class
java Main                # runs the compiled class

# Multiple files
javac *.java
java -cp . Main

# Package into a JAR
jar cfe MyApp.jar Main *.class
java -jar MyApp.jar
```

### 2. Apache Maven (XML-based, `pom.xml`)
```xml
<project>
  <modelVersion>4.0.0</modelVersion>
  <groupId>com.example</groupId>
  <artifactId>myapp</artifactId>
  <version>1.0</version>
  <properties>
    <maven.compiler.source>17</maven.compiler.source>
    <maven.compiler.target>17</maven.compiler.target>
  </properties>
  <dependencies>
    <dependency>
      <groupId>org.junit.jupiter</groupId>
      <artifactId>junit-jupiter</artifactId>
      <version>5.10.0</version>
      <scope>test</scope>
    </dependency>
  </dependencies>
</project>
```
```bash
mvn compile          # compiles source
mvn test             # runs tests
mvn package           # builds JAR into target/
mvn clean install    # cleans, builds, installs to local repo
mvn exec:java -Dexec.mainClass="com.example.Main"
```

### 3. Gradle (Groovy/Kotlin DSL, `build.gradle`)
```groovy
plugins {
    id 'java'
    id 'application'
}
application {
    mainClass = 'com.example.Main'
}
dependencies {
    testImplementation 'org.junit.jupiter:junit-jupiter:5.10.0'
}
```
```bash
gradle build          # compiles, tests, packages
gradle run            # runs the application
gradle test           # runs tests
./gradlew build       # using the wrapper (recommended)
```

### 4. Build Tool Comparison

| Tool | Config File | Style | Best For |
|---|---|---|---|
| `javac`/`java` | none | manual | learning, tiny scripts |
| Maven | `pom.xml` | XML, declarative | enterprise, convention-driven |
| Gradle | `build.gradle(.kts)` | Groovy/Kotlin, flexible | Android, large modular projects |
| Ant | `build.xml` | XML, procedural | legacy projects |

---

## Quick Reference Cheat Sheet

| Need | Use |
|---|---|
| Dynamic array | `ArrayList` |
| Fast insert/remove at ends | `ArrayDeque` / `LinkedList` |
| Unique unordered elements | `HashSet` |
| Sorted unique elements | `TreeSet` |
| Key-value fast lookup | `HashMap` |
| Sorted key-value | `TreeMap` |
| Min/Max extraction | `PriorityQueue` |
| Stack behavior | `ArrayDeque` (push/pop) |
| Insertion-order map | `LinkedHashMap` |

---

## DSA Suitability Comparison

| Language | Suitability | Why |
|---|---|---|
| C++ | 95% | Richest STL, fastest raw execution, direct memory control — the standard choice for competitive programming (Codeforces, ICPC) |
| **Java** | **80%** | Solid Collections Framework, good performance, but more boilerplate under time pressure |
| Python | 68% | Easiest to read/write, great for learning concepts, but slower execution and no built-in max-heap |

> Java sits in the middle — its Collections Framework covers nearly everything the STL does, and JIT-compiled performance is close to C++, but the verbosity of writing `PriorityQueue<int[]>` with a custom comparator (vs. one line in C++) costs time in timed practice.

---
*End of Java Guide.*
