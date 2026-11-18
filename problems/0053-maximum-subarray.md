# Maximum Subarray  (LeetCode 53 · Medium)

<https://leetcode.com/problems/maximum-subarray/>

## Problem

Given an integer array `nums`, find the **non-empty** contiguous subarray with
the largest sum, and return its sum.

## Constraints

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

## Examples

```
[-2, 1, -3, 4, -1, 2, 1, -5, 4]  ->  6     ([4, -1, 2, 1])
[1]                              ->  1
[5, 4, -1, 7, 8]                 ->  23
```

## Think

1. Brute force: how many subarrays are there, and what does summing each one
   cost? What does a running sum per start index save?
2. `end[i]` depends only on `end[i - 1]`. Do you need the whole `end` array?
3. What should the answer be when every element is negative? Which starting
   value for "best so far" gets that wrong?
4. How large can a subarray sum get under the constraints? Does it fit in an
   `int`?

<!-- No hints and no algorithm below this line. -->

---

## My attempt

## After solving

- Pattern:
- Time / space:
- What I got wrong first:
