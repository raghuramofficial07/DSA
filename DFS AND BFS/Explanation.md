<img width="841" alt="Screenshot 2025-06-22 at 10 51 31 AM" src="https://github.com/user-attachments/assets/501c98ee-809c-4376-b32d-6d38ae07c489" />

# 🔍 BFS vs DFS — Complete Study Guide

-----

## 📌 What is BFS (Breadth-First Search)?

**Breadth-First Search** is a graph/tree traversal algorithm that explores nodes **level by level** — it visits all neighbors of the current node before moving deeper.

Think of it like **ripples in water** — spreading outward in all directions equally.

### 🎥 BFS in Action

<img width="600" height="495" alt="image" src="https://github.com/user-attachments/assets/977827e9-7d20-436c-ac96-87eaa85a1457" />


> **Watch:** BFS floods the grid outward like water — every cell at distance N is visited before any cell at distance N+1. The blue wave expands uniformly in all directions from the start, guaranteeing the shortest path to the destination.

-----

### ✅ Key Properties of BFS

|Property                 |Value                        |
|-------------------------|-----------------------------|
|Data Structure Used      |**Queue** (FIFO)             |
|Traversal Style          |Level by Level               |
|Guarantees Shortest Path?|✅ Yes (in unweighted graphs) |
|Memory Usage             |❌ High (stores all neighbors)|
|Time Complexity          |O(V + E)                     |
|Space Complexity         |O(V)                         |

-----

### 🧠 How BFS Works (Step by Step)

1. Start at the **source node**, mark it as visited.
1. Add it to the **Queue**.
1. While the queue is **not empty**:
- Dequeue the front node.
- Visit all its **unvisited neighbors**.
- Mark each neighbor as visited and **enqueue** them.
1. Repeat until all reachable nodes are visited.

-----

### 💻 BFS Implementation

#### Python

```python
from collections import deque

def bfs(graph, start):
    visited = set()
    queue = deque([start])
    visited.add(start)
    order = []

    while queue:
        node = queue.popleft()        # Dequeue front
        order.append(node)

        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor) # Enqueue neighbor

    return order

# Example Graph (Adjacency List)
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

print(bfs(graph, 'A'))
# Output: ['A', 'B', 'C', 'D', 'E', 'F']
```

#### Java

```java
import java.util.*;

public class BFS {
    public static void bfs(Map<Integer, List<Integer>> graph, int start) {
        Set<Integer> visited = new HashSet<>();
        Queue<Integer> queue = new LinkedList<>();

        queue.add(start);
        visited.add(start);

        while (!queue.isEmpty()) {
            int node = queue.poll();
            System.out.print(node + " ");

            for (int neighbor : graph.getOrDefault(node, new ArrayList<>())) {
                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    queue.add(neighbor);
                }
            }
        }
    }
}
```

#### C++

```cpp
#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& graph, int start, int n) {
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

-----

### 🎯 BFS Use Cases

- ✅ **Shortest path** in unweighted graphs (GPS, networking)
- ✅ **Level-order traversal** in binary trees
- ✅ **Web crawlers** (explore links level by level)
- ✅ **Social network** friend suggestions (degree of connection)
- ✅ **Flood fill** (paint bucket tool in image editors)
- ✅ **Peer-to-peer networks** (finding closest peers)

-----

-----

## 📌 What is DFS (Depth-First Search)?

**Depth-First Search** is a graph/tree traversal algorithm that explores as **deep as possible** along each branch before backtracking.

Think of it like exploring a **maze** — you go down one path until you hit a dead end, then backtrack and try another.

### 🎥 DFS in Action


<img width="600" height="489" alt="image" src="https://github.com/user-attachments/assets/e687a784-3987-4231-93bc-c9a1e05b78c8" />


> **Watch:** DFS snakes deep into the grid along one path before backtracking — notice the yellow trail diving far in one direction, hitting a dead end, then reversing course. Unlike BFS, it does NOT guarantee the shortest path.

-----

### ✅ Key Properties of DFS

|Property                 |Value                           |
|-------------------------|--------------------------------|
|Data Structure Used      |**Stack** (LIFO) / Recursion    |
|Traversal Style          |Deep before Wide                |
|Guarantees Shortest Path?|❌ No                            |
|Memory Usage             |✅ Low (stores current path only)|
|Time Complexity          |O(V + E)                        |
|Space Complexity         |O(V)                            |

-----

### 🧠 How DFS Works (Step by Step)

1. Start at the **source node**, mark it as visited.
1. Push it onto the **Stack** (or use recursion).
1. While stack is **not empty**:
- Pop the top node.
- Visit all its **unvisited neighbors**.
- Push each unvisited neighbor onto the **stack**.
1. Backtrack when no unvisited neighbors exist.
1. Repeat until all reachable nodes are visited.

-----

### 💻 DFS Implementation

#### Python — Recursive

```python
def dfs_recursive(graph, node, visited=None, order=None):
    if visited is None:
        visited = set()
    if order is None:
        order = []

    visited.add(node)
    order.append(node)

    for neighbor in graph[node]:
        if neighbor not in visited:
            dfs_recursive(graph, neighbor, visited, order)

    return order

# Example
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

print(dfs_recursive(graph, 'A'))
# Output: ['A', 'B', 'D', 'E', 'F', 'C']
```

#### Python — Iterative (using Stack)

```python
def dfs_iterative(graph, start):
    visited = set()
    stack = [start]
    order = []

    while stack:
        node = stack.pop()          # Pop from top
        if node not in visited:
            visited.add(node)
            order.append(node)

            for neighbor in reversed(graph[node]):
                if neighbor not in visited:
                    stack.append(neighbor)  # Push to stack

    return order
```

#### Java

```java
import java.util.*;

public class DFS {
    // Recursive
    public static void dfsRecursive(Map<Integer, List<Integer>> graph,
                                     int node, Set<Integer> visited) {
        visited.add(node);
        System.out.print(node + " ");

        for (int neighbor : graph.getOrDefault(node, new ArrayList<>())) {
            if (!visited.contains(neighbor)) {
                dfsRecursive(graph, neighbor, visited);
            }
        }
    }

    // Iterative
    public static void dfsIterative(Map<Integer, List<Integer>> graph, int start) {
        Set<Integer> visited = new HashSet<>();
        Stack<Integer> stack = new Stack<>();
        stack.push(start);

        while (!stack.isEmpty()) {
            int node = stack.pop();
            if (!visited.contains(node)) {
                visited.add(node);
                System.out.print(node + " ");

                for (int neighbor : graph.getOrDefault(node, new ArrayList<>())) {
                    if (!visited.contains(neighbor)) {
                        stack.push(neighbor);
                    }
                }
            }
        }
    }
}
```

#### C++

```cpp
#include <bits/stdc++.h>
using namespace std;

// Recursive
void dfsRecursive(vector<vector<int>>& graph, int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsRecursive(graph, neighbor, visited);
        }
    }
}

// Iterative
void dfsIterative(vector<vector<int>>& graph, int start, int n) {
    vector<bool> visited(n, false);
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
}
```

-----

### 🎯 DFS Use Cases

- ✅ **Detecting cycles** in a graph
- ✅ **Topological sorting** (task scheduling, build systems)
- ✅ **Maze solving** (finding any path)
- ✅ **Connected components** detection
- ✅ **Backtracking problems** (N-Queens, Sudoku solver)
- ✅ **Tree traversals** (pre-order, in-order, post-order)

-----

-----

## ⚡ BFS vs DFS — Head-to-Head Comparison

|Feature        |BFS                           |DFS                              |
|---------------|------------------------------|---------------------------------|
|Data Structure |Queue (FIFO)                  |Stack (LIFO) / Recursion         |
|Traversal Order|Level by level                |Deep first, then backtrack       |
|Shortest Path  |✅ Guaranteed (unweighted)     |❌ Not guaranteed                 |
|Memory         |❌ More (all neighbors stored) |✅ Less (only current path)       |
|Speed          |Slower for deep graphs        |Faster for deep graphs           |
|Best For       |Shortest path, level traversal|Cycle detection, topological sort|
|Space (worst)  |O(W) — W = width of tree      |O(H) — H = height of tree        |

-----

## 🧩 Visual Mental Model

```
Graph:
       A
      / \
     B   C
    / \   \
   D   E   F

BFS Order: A → B → C → D → E → F   (Level by Level)
DFS Order: A → B → D → E → F → C   (Deep then Backtrack)
```

**BFS** fills the matrix like **spreading water** — outward, evenly.  
**DFS** fills the matrix like **a snake** — going deep in one direction before turning.

-----

## 📝 Quick Revision Cheat Sheet

```
BFS  →  Queue  →  Shortest Path  →  Wide Spread  →  More Memory
DFS  →  Stack  →  Any Path       →  Deep Dive    →  Less Memory
```

-----

*Study Tip: Visualize BFS as concentric circles expanding from the source.  
Visualize DFS as a person walking deep into a maze, hitting walls, and backtracking.*
