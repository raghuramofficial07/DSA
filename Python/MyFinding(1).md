<p align="center">

 <img width="841" height="296" alt="Screenshot 2025-06-22 at 10 51 31 AM" src="https://github.com/user-attachments/assets/f2531045-c913-49c7-8033-4c9fd25afbba" />

<p align="center">
<img src="https://img.shields.io/badge/Python-black?logo=python&logoColor=white">
<img src="https://img.shields.io/badge/Recursion-black?logo=code&logoColor=white">
<img src="https://img.shields.io/badge/Binary%20Trees-black?logo=git&logoColor=white">
<img src="https://img.shields.io/badge/Algorithm%20Patterns-black?logo=bookstack&logoColor=white">
</p>
 
# Python Short-Circuit Evaluation in Recursive Tree Algorithms
 
------------------------------------------------------------------------
 
## » Table of Contents
 
1.  Introduction\
2.  Core Statement\
3.  Python Evaluation Order\
4.  Short-Circuit Behavior\
5.  Expanded Logical Form\
6.  Application in Binary Tree Algorithms\
7.  Key Concepts\
8.  Quick Reference Table\
9.  Summary
 
------------------------------------------------------------------------
 
## » Introduction
 
In many recursive tree algorithms, Python allows multiple recursive
calls to be combined using logical operators such as `and`.
 
Example:
 
``` python
return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
```
 
Python executes **two separate recursive calls** and combines their
results using a boolean operator.
 
------------------------------------------------------------------------
 
## » Core Statement
 
``` python
return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
```
 
  Recursive Call                   Purpose
  -------------------------------- ------------------------
  `isSameTree(p.left, q.left)`     Compare left subtrees
  `isSameTree(p.right, q.right)`   Compare right subtrees
 
------------------------------------------------------------------------
 
## » Python Evaluation Order
 
Python evaluates expressions **left → right**.
 
Execution flow:
 
``` python
self.isSameTree(p.left, q.left)
        ↓
evaluate result
        ↓
if True → evaluate second call
if False → stop evaluation
```
 
------------------------------------------------------------------------
 
## » Short-Circuit Behavior
 
Python uses **short-circuit evaluation**.
 
  Left Expression   Right Executed   Result
  ----------------- ---------------- ----------------------------
  False             No               False
  True              Yes              Result of right expression
 
Example:
 
``` python
False and someFunction()
```
 
The second function will **not execute**.
 
------------------------------------------------------------------------
 
## » Expanded Logical Form
 
Equivalent expanded code:
 
``` python
left_match = self.isSameTree(p.left, q.left)
 
if not left_match:
    return False
 
right_match = self.isSameTree(p.right, q.right)
 
return right_match
```
 
------------------------------------------------------------------------
 
## » Application in Binary Tree Algorithms
 
For two trees to be identical:
 
1.  Node values must match\
2.  Left subtrees must match\
3.  Right subtrees must match
 
Logical form:
 
    SameTree =
    (left subtree identical)
    AND
    (right subtree identical)
 
------------------------------------------------------------------------
 
## » Key Concepts
 
  Concept                    Explanation
  -------------------------- -------------------------------------------
  Recursive boolean return   Each call returns True or False
  Logical combination        Boolean operators combine subtree results
  Short-circuit evaluation   Prevents unnecessary recursion
  Left-to-right evaluation   Python evaluates expressions sequentially
 
------------------------------------------------------------------------
 
## » Summary
 
Python allows recursive boolean results to be combined directly:
 
``` python
return solve(left_subtree) and solve(right_subtree)
```
 
This pattern appears frequently in tree algorithms such as:
 
-   Same Tree
-   Symmetric Tree
-   Balanced Binary Tree
-   Subtree Comparison
 
------------------------------------------------------------------------
 
## » Author Footer
 
**Created By:** Vemparala Sri Satya RaghuRam\
**License:** MIT\
**Platform:** Swift (iOS UIKit)
 
<p align="left">
<img src="https://img.shields.io/badge/%23BeyondCertifications-black?logo=tag&logoColor=white&labelColor=black&color=black">
<img src="https://img.shields.io/badge/%23IndustryOriented-black?logo=tag&logoColor=white&labelColor=black&color=black">
<img src="https://img.shields.io/badge/%23CodeWithRaghuRam-black?logo=tag&logoColor=white&labelColor=black&color=black">
</p>
