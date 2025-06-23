<!-- GitHub Project Banner -->
<p align="center">
  <img src="https://github.com/user-attachments/assets/501c98ee-809c-4376-b32d-6d38ae07c489" alt="Project Banner" width="100%">
</p>

# » Understanding 2D Arrays in C++ (Row-Major vs Column-Major)

---

## » Table of Contents
- Introduction
- What is a 2D Array?
- Row-Major vs Column-Major Explained
- Visualizing Memory Layout (Tabulated Format)
- Real-World Examples
- Key Concept Highlights
- Quick Reference Table
- Author Footer

---

## » Introduction
2D arrays in C++ are essentially arrays of arrays. They allow you to organize data in a grid or matrix-like structure. But **how that data is stored in memory** can affect performance and logic design.

This document explains how 2D arrays are stored **under the hood**, focusing on **row-major and column-major** layouts with simple visualizations.

---

## » What is a 2D Array?

In C++:
```cpp
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```
This 2D array has:

2 Rows
3 Columns
» Row-Major vs Column-Major Explained

🟩 Row-Major (used by C/C++):
Memory is filled row by row.
All elements of the first row are stored first, followed by the second row, and so on.
🟦 Column-Major (used by Fortran, MATLAB):
Memory is filled column by column.
All elements of the first column are stored first, followed by the second column, and so on.
» Visualizing Memory Layout (Tabulated Format)

Let’s take this 2D array:
```cpp
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```
🟩 Row-Major Storage (C++ Style):
```
Memory Order:
Index    Value
[0]      1
[1]      2
[2]      3
[3]      4
[4]      5
[5]      6
```
Visual Table of Access Order:
```
Memory Block	Value	Location
Block 0	1	matrix[0][0]
Block 1	2	matrix[0][1]
Block 2	3	matrix[0][2]
Block 3	4	matrix[1][0]
Block 4	5	matrix[1][1]
Block 5	6	matrix[1][2]
```
🟦 Column-Major Storage (Fortran/MATLAB Style):
```
Memory Order:
Index    Value
[0]      1
[1]      4
[2]      2
[3]      5
[4]      3
[5]      6
```
| Memory Block | Value | Location       |
| ------------ | ----- | -------------- |
| Block 0      | 1     | matrix\[0]\[0] |
| Block 1      | 4     | matrix\[1]\[0] |
| Block 2      | 2     | matrix\[0]\[1] |
| Block 3      | 5     | matrix\[1]\[1] |
| Block 4      | 3     | matrix\[0]\[2] |
| Block 5      | 6     | matrix\[1]\[2] |

» Real-World Example

Let’s say you're summing all elements row-by-row vs column-by-column.
```cpp
// Row-wise sum (fast in C++)
for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 3; ++j)
        sum += matrix[i][j];

// Column-wise sum (slightly slower in C++)
for (int j = 0; j < 3; ++j)
    for (int i = 0; i < 2; ++i)
        sum += matrix[i][j];
➡️ The row-wise loop accesses memory sequentially (good for caching).
➡️ The column-wise loop skips across memory (not cache friendly in C++).
```
» Key Concept Highlights

In C/C++, arrays are stored in row-major order.
That means matrix[0][0] → matrix[0][1] → ... is how memory is filled.
Access patterns matter — row-wise access is faster due to how memory is laid out.
In competitive coding or system-level programming, knowing this boosts performance.
» Quick Reference Table

Concept	C++ (Row-Major)	Fortran/MATLAB (Column-Major)
Fill order	Row by Row	Column by Column
Faster Access Style	Row-wise	Column-wise
Common in Languages	C, C++, Java	Fortran, MATLAB
Multidimensional View	Arrays of arrays	Flattened vector column-first

Column-Major Storage (Visualized as an Array Strip)
```
┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
| Block 0  | Block 1  | Block 2  | Block 3  | Block 4  | Block 5  |
|   1      |   4      |   2      |   5      |   3      |   6      |
| [0][0]   | [1][0]   | [0][1]   | [1][1]   | [0][2]   | [1][2]   |
└──────────┴──────────┴──────────┴──────────┴──────────┴──────────┘
```
Row-Major Storage (Visualized as an Array Strip)
```
┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
| Block 0  | Block 1  | Block 2  | Block 3  | Block 4  | Block 5  |
|   1      |   2      |   3      |   4      |   5      |   6      |
| [0][0]   | [0][1]   | [0][2]   | [1][0]   | [1][1]   | [1][2]   |
└──────────┴──────────┴──────────┴──────────┴──────────┴──────────┘

```


» Author Footer
```
📘 Author: Vemparala Sri Satya RaghuRam
📌 Focused on understanding internals of arrays, memory layout, and optimization
🧠 #BeyondCertifications #CodeWithRaghuRam #IndustryOriented
```
