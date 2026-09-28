# Two Sum  (LeetCode 1 · Easy)

<https://leetcode.com/problems/two-sum/>

## Problem

Given an array of integers `nums` and an integer `target`, return the indices
of the two elements that add up to `target`.

You may not use the same element twice. Exactly one valid answer exists.

For this repo's version, return the two indices as `{i, j}` with `i < j`, so
tests have a single correct answer to compare against.

## Constraints

- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- exactly one valid answer exists

## Examples

```
nums = [2, 7, 11, 15], target = 9   ->  [0, 1]
nums = [3, 2, 4],      target = 6   ->  [1, 2]
nums = [3, 3],         target = 6   ->  [0, 1]
```

## Think

1. What is the brute-force approach, and what does it cost?
2. For each element, what exactly is the brute force *searching for*? Name the
   value in terms of `target` and `nums[i]`.
3. What would you need to remember about the elements you have already seen
   to make that search O(1)?
4. If you use a hash map, what is the key and what is the value? Why that way
   round and not the other?
5. `[3, 3]` with target 6 has an answer. `[3]` alone with target 6 would not -
   you cannot use index 0 twice. How does your approach make sure it never
   pairs an element with itself?
6. What does your approach cost in time and space? What did you trade?

<!-- No hints and no algorithm below this line. -->

---

## My attempt

## After solving

- Pattern:
- Time / space:
- What I got wrong first:
