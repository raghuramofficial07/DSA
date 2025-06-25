<!-- GitHub Project Banner -->
<p align="center">
  <img src="https://github.com/user-attachments/assets/501c98ee-809c-4376-b32d-6d38ae07c489" alt="Project Banner" width="100%">
</p>

# CodeBook .Md » Prepare.md

## » Topic Title
Understanding Loop Conditions in C++: `i != -1`, `i++`, `i--`, and Array Traversals

---

## » Table of Contents
1. Introduction  
2. Core Loop Concepts  
3. Forward Loops: Safe Practices  
4. Backward Loops: Using `i != -1`  
5. Unsafe Loop Patterns  
6. Code Examples with Explanation  
7. Static 2D Array Length Explained  
8. Concept Highlights  
9. Real-World Use Cases  
10. Quick Reference Table  
11. Author Footer  

---

## » Introduction
In C++, loops are essential for traversing arrays. However, using conditions like `i != -1` must be done carefully, especially with unsigned types. This file covers safe loop patterns, reverse traversals, and how to correctly calculate row/column sizes using `sizeof`.

---

## » Core Loop Concepts

- `i++` → forward iteration  
- `i--` → backward iteration  
- `i != -1` → reverse loop condition (works with signed integers only)  
- `i < length` → safest forward loop condition  
- `size_t` → unsigned integer used with STL containers like `vector`  

---

## » Forward Loops: Safe Practices

```cpp
int arr[] = {10, 20, 30, 40, 50};
int length = sizeof(arr) / sizeof(arr[0]);

for (int i = 0; i < length; i++) {
    cout << arr[i] << " ";
}
```

Uses `i < length` which keeps the loop within valid index boundaries.

---

## » Backward Loops: Using `i != -1`

```cpp
for (int i = length - 1; i != -1; i--) {
    cout << arr[i] << " ";
}
```

Safe only when `i` is a signed type like `int`. Not safe for unsigned types such as `size_t`.

---

## » Unsafe Loop Patterns

```cpp
// Unsafe: infinite loop
for (int i = 0; i != -1; i++) {
    cout << arr[i] << " ";
}

// Unsafe: infinite loop or crash
for (size_t i = length - 1; i != -1; i--) {
    cout << arr[i] << " ";
}
```

In the second case, `-1` becomes a large positive number due to unsigned wraparound, which breaks loop logic.

---

## » Code Examples with Explanation

### Example 1: Forward Loop

```cpp
for (int i = 0; i < length; i++) {
    // i goes from 0 to length - 1
}
```

---

### Example 2: Reverse Loop

```cpp
for (int i = length - 1; i >= 0; i--) {
    // stops at i = -1 (loop condition fails)
}
```

---

### Example 3: While loop (unsigned safe)

```cpp
size_t i = length;
while (i-- > 0) {
    cout << arr[i] << " ";
}
```

---

### Example 4: Row Length in 2D Vector

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> arr = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    int rowLength = arr[0].size();
    cout << "Length of first row: " << rowLength << endl;
    return 0;
}
```

`arr[0].size()` gives the number of elements in the first row.

---

## » Static 2D Array Length Explained

### Full Example

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[3][4] = {
        {10, 20, 30, 40},
        {50, 60, 70, 80},
        {90, 100, 110, 120}
    };

    int rowLength = sizeof(arr[0]) / sizeof(arr[0][0]);
    int numRows = sizeof(arr) / sizeof(arr[0]);

    cout << "Number of columns: " << rowLength << endl;
    cout << "Number of rows: " << numRows << endl;

    return 0;
}
```

### Textbook Explanation

- `sizeof(arr[0])` gives the total memory of the first row.
- `sizeof(arr[0][0])` gives the size of a single element.
- So, `sizeof(arr[0]) / sizeof(arr[0][0])` gives the number of columns.

- `sizeof(arr)` gives the total size of the entire 2D array.
- `sizeof(arr[0])` gives the size of one row.
- So, `sizeof(arr) / sizeof(arr[0])` gives the number of rows.

### Output

```
Number of columns: 4
Number of rows: 3
```

---

## » Concept Highlights

- Use `i != -1` only in reverse loops where `i` is of signed type.
- Never use `i != -1` with `size_t` or other unsigned types.
- Prefer `i < size` for forward iteration, and `i >= 0` or `i != -1` for reverse with caution.
- Use `sizeof(arr[0]) / sizeof(arr[0][0])` to calculate number of columns in a static 2D array.
- Use `sizeof(arr) / sizeof(arr[0])` to get the number of rows.

---

## » Real-World Use Cases

- Reversing rows in a matrix for image manipulation.
- Traversing grids or matrices in reverse during game logic.
- Reverse-searching strings or arrays for pattern matching.

---

## » Quick Reference Table

| Loop Type           | Condition                              | Safe? | Description                             |
|---------------------|-----------------------------------------|--------|-----------------------------------------|
| Forward (int)       | `i < length`                            | Yes    | Standard safe forward loop              |
| Backward (int)      | `i != -1` or `i >= 0`                   | Yes    | Safe if `i` is signed                   |
| Forward (size_t)    | `i < size`                              | Yes    | Safe for vectors/arrays                 |
| Backward (size_t)   | `i != -1`                               | No     | Unsafe due to unsigned wraparound       |
| Static Row Length   | `sizeof(arr[0]) / sizeof(arr[0][0])`   | Yes    | Gets number of columns                  |
| Static Row Count    | `sizeof(arr) / sizeof(arr[0])`         | Yes    | Gets number of rows                     |

---

## » Author Footer

```
Crafted with clarity by Vemparala Sri Satya RaghuRam  
#BeyondCertifications #IndustryOriented #CodeWithRaghuRam  
```

---
