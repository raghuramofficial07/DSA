
<!-- GitHub Project Banner -->
<p align="center">
  <img src="https://github.com/user-attachments/assets/501c98ee-809c-4376-b32d-6d38ae07c489" alt="Project Banner" width="100%">
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Recursion-black?logo=apple&logoColor=white&labelColor=black&color=black">
  <img src="https://img.shields.io/badge/Built%20by-RaghuRam-black?labelColor=black&color=black">
</p>

# » How Does Recursion Work in Include-Exclude Strategy?

## » Table of Contents
- Introduction
- Step-by-step Working
- Annotated Code Example
- Working Table (Line by Line)
- Beginner Q&A
- Return Statement Deep Dive
- Final Trace Output
- Author Footer

---

## » Introduction

This document explains the **include-exclude recursion strategy** using a simple C++ program to generate all subsets of a given list of numbers.

---

## » Annotated Code Example

```cpp
void subsets(int i, vector<int>& nums, vector<int>& ans, vector<vector<int>>& allSubsets) {
    // Line A
    if (i == nums.size()) {
        // Line B
        allSubsets.push_back(ans);  // We reached the end, save the current subset
        return;                     // Line C: Go back to the previous call
    }

    // Line D: Include current element
    ans.push_back(nums[i]);         // Add nums[i] to current subset
    subsets(i + 1, nums, ans, allSubsets);  // Line E: Go to next index (include path)

    ans.pop_back();                 // Line F: Remove last included item (backtrack)

    // Line G: Exclude current element
    subsets(i + 1, nums, ans, allSubsets);  // Line H: Go to next index (exclude path)
}
```

---

## » Working Table (Example: nums = [1, 2])

| Call Stack Depth | `i` | Current `ans` | Line Triggered | Action                            |
|------------------|-----|----------------|----------------|-----------------------------------|
| 0                | 0   | []             | D              | Include 1                         |
| 1                | 1   | [1]            | D              | Include 2                         |
| 2                | 2   | [1,2]          | A → C          | End of array, save [1,2]          |
| Backtrack        | 2   | [1]            | F              | Pop 2                             |
| 2                | 2   | [1]            | H              | Exclude 2 → save [1]              |
| Backtrack        | 1   | []             | F              | Pop 1                             |
| 1                | 1   | []             | H              | Exclude 1                         |
| 2                | 2   | [2]            | A → C          | Save [2]                          |
| Backtrack        | 2   | []             | F              | Pop 2                             |
| 2                | 2   | []             | H              | Save []                           |

---

## » Beginner Q&A

### ❓ Q: When does it stop?
**A:** When `i == nums.size()` — this is where Line A → Line B → Line C happens.

### ❓ Q: Why does it come back again after saving?
**A:** Because after `return` (Line C), it jumps back to where the function was **called** from. That’s either Line E or Line H.

### ❓ Q: Why do we do `i + 1` in exclude?
**A:** It means we’re moving forward in the array, just choosing to **not** include the current number.

### ❓ Q: How do both include and exclude work?
**A:** First we go down the **include** path (push + recursive call), then we **pop** and go down the **exclude** path. That’s recursion's dual decision tree.

---

## » Return Statement Deep Dive

### » What is Line C Doing?

```cpp
if (i == nums.size()) {
    allSubsets.push_back(ans);  // Line B
    return;                     // Line C
}
```

- `i == nums.size()` means we’ve looked at all elements.
- We store the current `ans` (subset).
- `return` sends control **back to the last function call**.

### » Flow After Return

If you came from Line E:
```cpp
ans.push_back(nums[i]);            // include
subsets(i + 1, nums, ans, allSubsets);  // ← returns here
```

Now, it continues to:
```cpp
ans.pop_back();                    // remove the included item
subsets(i + 1, nums, ans, allSubsets);  // explore exclude path
```

### » Final Working Trace

| Line     | Description                             |
|----------|-----------------------------------------|
| Line A   | Check if index reached the array's end  |
| Line B   | Save current subset                     |
| Line C   | Return to previous call                 |
| Line D   | Try including element                   |
| Line E   | Recursive call with inclusion           |
| Line F   | Backtrack: remove included element      |
| Line G   | Try excluding element                   |
| Line H   | Recursive call with exclusion           |

---

## » Author Footer

**Created By:** Vemparala Sri Satya RaghuRam   
**Platform:** C++ (Recursion)  

<p align="left">
  <img src="https://img.shields.io/badge/%23BeyondCertifications-black?logo=tag&logoColor=white&labelColor=black&color=black">
  <img src="https://img.shields.io/badge/%23IndustryOriented-black?logo=tag&logoColor=white&labelColor=black&color=black">
  <img src="https://img.shields.io/badge/%23CodeWithRaghuRam-black?logo=tag&logoColor=white&labelColor=black&color=black">
</p>
