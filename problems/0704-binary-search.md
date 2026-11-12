# Binary Search  (LeetCode 704 · Easy)

<https://leetcode.com/problems/binary-search/>

## Problem

Given an array of integers `nums` sorted in **ascending** order and a
`target`, return the index of `target`, or `-1` if it is not present.

You must write an algorithm with O(log n) runtime.

## Constraints

- `1 <= nums.length <= 10^4`
- `-10^4 < nums[i], target < 10^4`
- all values in `nums` are **distinct**
- `nums` is sorted in ascending order

## Examples

```
nums = [-1, 0, 3, 5, 9, 12], target = 9   ->  4
nums = [-1, 0, 3, 5, 9, 12], target = 2   ->  -1
```

## Think

The invariant and the updates were derived in session 9. What remains:

1. Which targets would embarrass a binary search? Think about where the
   target sits relative to the array, not just whether it is present.
2. What type should `lo` and `hi` be? Defend the choice.
3. A scale test should prove O(log n). How would you check that, not just that
   the answer is right?

<!-- No hints and no algorithm below this line. -->

---

## My attempt

## After solving

- Pattern:
- Time / space:
- What I got wrong first:
