<div align="center">

<img width="841" alt="Screenshot 2025-06-22 at 10 51 31 AM" src="https://github.com/user-attachments/assets/501c98ee-809c-4376-b32d-6d38ae07c489" />


<br/>

![Trees](https://img.shields.io/badge/Trees-0d1117?style=for-the-badge&logoColor=58a6ff&labelColor=161b22&color=161b22)
![Graphs](https://img.shields.io/badge/Graphs-0d1117?style=for-the-badge&logoColor=58a6ff&labelColor=161b22&color=161b22)
![DP](https://img.shields.io/badge/Dynamic%20Programming-0d1117?style=for-the-badge&labelColor=161b22&color=161b22)
![Recursion](https://img.shields.io/badge/Recursion-0d1117?style=for-the-badge&labelColor=161b22&color=161b22)
![Sorting](https://img.shields.io/badge/Sorting-0d1117?style=for-the-badge&labelColor=161b22&color=161b22)

</div>

---

# 🌳 LeetCode 104 — Maximum Depth of Binary Tree

> **Difficulty:** Easy | **Topic:** Tree, DFS, BFS, Recursion

---

## 📌 Problem Statement

Given the `root` of a binary tree, return its **maximum depth**.

> **Maximum depth** = the number of nodes along the **longest path** from the root node down to the **farthest leaf node**.

### Example

```
        3
       / \
      9  20
         / \
        15   7
```

**Output:** `3`
*(Path: 3 → 20 → 15  or  3 → 20 → 7)*

---

## 🧠 Intuition

Think of it as asking each node:
> *"Hey, how tall is your tallest subtree?"*

Each node answers:
> *"I'll ask my left and right children, take the bigger answer, and add 1 for myself."*

Base case: An empty node (`null`) has depth **0**.

---

## 💡 My Mental Model — How Recursion Actually Works Here

**The recursion dives to the bottom first.**
The function doesn't compute anything on the way *down* — it just keeps calling itself deeper and deeper until it hits `null`. Only then does the real work begin.

**The `+1` is added on the way *back up*, not on the way down.**
When the deepest call hits `null` and returns `0`, the call just above it receives that `0`, adds `+1` for itself, and returns `1` to *its* caller. This bubbles all the way back up to the root — each returning frame adds `+1` for the node it represents.

**The call stack IS the memory.**
There's no external variable tracking the depth. Instead, each recursive call *lives on the call stack* and holds its own partial result. Because the stack follows **LIFO (Last In, First Out)**, the deepest call resolves first and hands its result back to the frame below it. The function essentially uses its own stack frames as storage — the "memory" is the recursion itself.

**`max()` acts as the running tracker.**
At every node, `max(left, right)` picks the deeper side. This comparison gets returned upward, so the largest depth discovered at the bottom continuously propagates back as the current best answer — carried forward through each `return` up the chain until it reaches the root.

**In short:**
```
DOWN  → traverse to the bottom (no computation, just diving)
UP    → unwind the stack, adding +1 at each level (LIFO order)
max() → at each step, keep only the deeper side
root  → receives the final accumulated depth as the answer
```

> Think of it like dropping a measuring tape to the floor — you only read the number *after* it hits the bottom and you pull it back up.

---

## ✅ Approach 1 — Recursive DFS (Most Intuitive)

### How it works

- If the node is `null` → return `0`
- Recursively get depth of left subtree
- Recursively get depth of right subtree
- Return `max(left, right) + 1`

### Code (Python)

```python
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        left_depth  = self.maxDepth(root.left)
        right_depth = self.maxDepth(root.right)

        return max(left_depth, right_depth) + 1
```

### One-liner version

```python
def maxDepth(self, root):
    if not root:
        return 0
    return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))
```

### Dry Run on Example

```
maxDepth(3)
├── maxDepth(9)
│   ├── maxDepth(None) → 0
│   └── maxDepth(None) → 0
│   └── returns max(0,0)+1 = 1
└── maxDepth(20)
    ├── maxDepth(15)
    │   ├── maxDepth(None) → 0
    │   └── maxDepth(None) → 0
    │   └── returns 1
    └── maxDepth(7)
        └── returns 1
    └── returns max(1,1)+1 = 2
└── returns max(1,2)+1 = 3  ✅
```

### Complexity

| | Value |
|---|---|
| ⏱ Time | `O(n)` — every node visited once |
| 🧠 Space | `O(h)` — call stack height `h` (worst case `O(n)` for skewed tree, `O(log n)` for balanced) |

---

## ✅ Approach 2 — Iterative BFS (Level Order)

### How it works

- Use a **queue** to process nodes level by level
- Each time you finish a full level → increment depth counter
- When the queue is empty → return the depth count

### Code (Python)

```python
from collections import deque

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        queue = deque([root])
        depth = 0

        while queue:
            depth += 1                          # entering a new level
            for _ in range(len(queue)):         # process all nodes at this level
                node = queue.popleft()
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

        return depth
```

### Dry Run on Example

```
Level 1: queue = [3]         → depth = 1
Level 2: queue = [9, 20]     → depth = 2
Level 3: queue = [15, 7]     → depth = 3
Queue empty → return 3  ✅
```

### Complexity

| | Value |
|---|---|
| ⏱ Time | `O(n)` — every node visited once |
| 🧠 Space | `O(w)` — `w` is max width of tree (worst case `O(n)` for a full tree) |

---

## ✅ Approach 3 — Iterative DFS (Stack)

### How it works

- Use an **explicit stack** storing `(node, current_depth)` pairs
- Track the maximum depth seen

### Code (Python)

```python
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        stack = [(root, 1)]
        max_depth = 0

        while stack:
            node, depth = stack.pop()
            max_depth = max(max_depth, depth)

            if node.left:
                stack.append((node.left, depth + 1))
            if node.right:
                stack.append((node.right, depth + 1))

        return max_depth
```

### Complexity

| | Value |
|---|---|
| ⏱ Time | `O(n)` |
| 🧠 Space | `O(h)` — stack holds at most `h` nodes |

---

## 📊 Approach Comparison

| Approach | Time | Space | Best When |
|---|---|---|---|
| Recursive DFS | O(n) | O(h) | Default choice, cleanest code |
| Iterative BFS | O(n) | O(w) | Need level-by-level processing |
| Iterative DFS | O(n) | O(h) | Want DFS without recursion |

> 💡 For interviews, **Recursive DFS** is preferred for its clarity. Mention BFS as an alternative when space matters for wide trees.

---

## 🔑 Key Patterns & Concepts

```
1. RECURSION ON TREES
   → Always define: what does null return? (base case)
   → Then: combine left and right answers

2. POST-ORDER traversal
   → Process left → right → current node
   → This problem naturally uses post-order

3. DFS vs BFS on trees
   → DFS: depth-first → natural for depth problems
   → BFS: level-first → counts levels = depth

4. CALL STACK = implicit DFS stack
   → Recursive solution uses the call stack as DFS stack
```

---

## ⚠️ Edge Cases

| Case | Input | Output |
|---|---|---|
| Empty tree | `root = null` | `0` |
| Single node | `root = [1]` | `1` |
| Left-skewed tree | `1 → 2 → 3 → 4` | `4` |
| Right-skewed tree | `1 → → 2 → → 3` | `3` |
| Perfect binary tree | Full balanced tree of depth 4 | `4` |

---

## 🔗 Related Problems

| Problem | Connection |
|---|---|
| **111. Minimum Depth of Binary Tree** | Same idea, but find shortest path to a leaf |
| **102. Binary Tree Level Order Traversal** | BFS approach reused here |
| **543. Diameter of Binary Tree** | Uses depth at each node |
| **110. Balanced Binary Tree** | Checks if left/right depths differ by ≤ 1 |
| **1448. Count Good Nodes in Binary Tree** | DFS passing info down the tree |

---

## 💬 Interview Tips

- **Start with the recursive solution** — it's the most natural.
- **Always handle `null` (base case) first** before touching `.left` or `.right`.
- **Mention the space complexity tradeoff** between BFS and DFS.
- If asked *"Can you do it without recursion?"* → present the iterative DFS or BFS.
- Common follow-up: *"What if it's an N-ary tree?"* → same idea, just loop over all children.

### N-ary Tree Version (Bonus)

```python
def maxDepth(self, root: 'Node') -> int:
    if not root:
        return 0
    if not root.children:
        return 1
    return 1 + max(self.maxDepth(child) for child in root.children)
```

---

*Notes by VSR • LeetCode Problem 104*
