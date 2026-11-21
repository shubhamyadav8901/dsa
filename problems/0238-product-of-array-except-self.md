# Product of Array Except Self  (LeetCode 238 · Medium)

<https://leetcode.com/problems/product-of-array-except-self/>

## Problem

Given an integer array `nums`, return an array `answer` such that
`answer[i]` is the product of all the elements of `nums` **except**
`nums[i]`.

You must write an algorithm that runs in O(n) time and **without using the
division operation**.

Follow-up: can you do it with O(1) extra space? The output array does not
count as extra space.

## Constraints

- `2 <= nums.length <= 10^5`
- `-30 <= nums[i] <= 30`
- The product of any prefix or suffix of `nums` fits in a 32-bit integer

## Examples

```
[1, 2, 3, 4]         ->  [24, 12, 8, 6]
[-1, 1, 0, -3, 3]    ->  [0, 0, 9, 0, 0]
```

## Think

1. "Total product divided by `nums[i]`" would be O(n). Apart from the rule
   against division, which input breaks it?
2. What does `left[i]` mean here, and what is "nothing on that side" for a
   product?
3. You need `left` and `right` at every index. Could one of them be written
   straight into the output array, and the other kept in a single variable?

<!-- No hints and no algorithm below this line. -->

---

## My attempt

## After solving

- Pattern:
- Time / space:
- What I got wrong first:
