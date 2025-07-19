<!-- GitHub Project Banner -->
# » Topic Title: Understanding 2D and 3D Matrices using `vector` in C++

<p align="center">
  <img src="https://github.com/user-attachments/assets/501c98ee-809c-4376-b32d-6d38ae07c489" alt="Project Banner" width="100%">
</p>

---

## » Table of Contents
- Introduction
- 1D Vector Recap
- 2D Matrix with `vector<vector<int>>`
- 3D Matrix with `vector<vector<vector<int>>>`
- Code Examples (with Inline Comments)
- Concept Highlights
- Real-World Use Cases
- Quick Reference Table
- Author Footer

---

## » Introduction

In C++, vectors are dynamic arrays that can grow or shrink in size. When vectors are nested—meaning a `vector` inside another `vector`—we can build 2D or even 3D matrices.

This file explains how to:
- Create a 2D matrix
- Create a 3D matrix
- Understand the memory layout and access patterns
- Use beginner-friendly syntax

---

## » 1D Vector Recap

```cpp
vector<int> row(3);       // Creates a 1D vector of size 3 with values {0, 0, 0}
```

- Each element is default-initialized to `0`.
- You can also write: `vector<int> row = {1, 2, 3};`

---

## » 2D Matrix using `vector<vector<int>>`

```cpp
vector<vector<int>> matrix(3, vector<int>(3));
```

- This creates a 3×3 2D matrix filled with 0.
- It looks like:
  ```
  [
    [0, 0, 0],
    [0, 0, 0],
    [0, 0, 0]
  ]
  ```

### Accessing elements:
```cpp
matrix[1][2] = 5;  // Set row 1, column 2 to 5
```

---

## » 3D Matrix using `vector<vector<vector<int>>>`

```cpp
vector<vector<vector<int>>> matrix3D(3, vector<vector<int>>(3, vector<int>(3)));
```

- This creates a 3D matrix of size 3×3×3, i.e., 3 layers of 3×3 grids.
- Each element is default-initialized to `0`.
- Visually, think of it as 3 layers of 2D matrices:
  ```
  Layer 0:
  [0 0 0]
  [0 0 0]
  [0 0 0]

  Layer 1:
  [0 0 0]
  [0 0 0]
  [0 0 0]

  Layer 2:
  [0 0 0]
  [0 0 0]
  [0 0 0]
  ```

### Accessing elements:
```cpp
matrix3D[0][1][2] = 7; // Set layer 0, row 1, column 2 to 7
```

---

## » Code Examples (with Inline Comments)

### ✅ 2D Matrix Example:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> matrix(3, vector<int>(3));  // 3x3 matrix

    matrix[0][1] = 10;  // Set a value

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### ✅ 3D Matrix Example:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<vector<int>>> matrix3D(2, vector<vector<int>>(2, vector<int>(2)));

    matrix3D[0][1][1] = 9;

    for (int i = 0; i < 2; ++i) { // Depth
        cout << "Layer " << i << ":
";
        for (int j = 0; j < 2; ++j) { // Row
            for (int k = 0; k < 2; ++k) { // Column
                cout << matrix3D[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << "--------
";
    }

    return 0;
}
```

---

## » Concept Highlights

| Concept                     | Explanation                                                   |
|----------------------------|---------------------------------------------------------------|
| `vector<int>(n)`           | Creates a 1D array of size `n` filled with 0                  |
| `vector<vector<int>>(n)`   | A 2D matrix (n rows, each row is a vector<int>)               |
| `vector<vector<int>>(n, vector<int>(m))` | Creates a matrix with n rows and m columns     |
| `vector<vector<vector<int>>>` | A 3D matrix (depth × rows × cols)                        |
| `matrix[i][j]`             | Access element in row `i`, column `j`                         |
| `matrix[i][j][k]`          | Access element in depth `i`, row `j`, column `k`              |

---

## » Real-World Use Cases

- **2D Matrix**:
  - Image grids (pixels)
  - Game boards
  - Dynamic tabular data

- **3D Matrix**:
  - RGB image storage: height × width × channel
  - Voxel space in 3D games
  - Time-series spatial data

---

## » Quick Reference Table

| Syntax                                       | Meaning                                 |
|---------------------------------------------|-----------------------------------------|
| `vector<int> v(n)`                          | 1D vector of size `n`                   |
| `vector<vector<int>> v(n, vector<int>(m))`  | 2D matrix of `n` rows, `m` cols         |
| `vector<vector<vector<int>>> v(d, vector<vector<int>>(r, vector<int>(c)))` | 3D matrix of `d×r×c` |

---

## » Author Footer
```
Documented by: `Vemparala Sri Satya RaghuRam`  
Tags: `#BeyondCertifications`, `#IndustryOriented`, `#CodeWithRaghuRam`  
Format: `CodeBook .Md` — Structured Mono-Chrome Documentation Style
```

---
