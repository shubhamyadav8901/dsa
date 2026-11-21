# Find All Numbers Disappeared in an Array  (LeetCode 448 · Easy)

<https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/>

## Problem

Given an array `nums` of `n` integers where every `nums[i]` is in the range
`[1, n]`, return all the integers in `[1, n]` that do **not** appear in
`nums`, in increasing order.

Follow-up: can you do it in O(n) time with no extra space? The returned list
does not count as extra space.

## Constraints

- `n == nums.length`
- `1 <= n <= 10^5`
- `1 <= nums[i] <= n`

## Examples

```
[4, 3, 2, 7, 8, 2, 3, 1]  ->  [5, 6]
[1, 1]                    ->  [2]
```

## Think

1. What would a hash set (or a `vector<bool>` of size n + 1) cost here? What
   does the follow-up rule out?
2. The function takes `nums` by non-const reference and changes it. Who can
   see that change? Is that acceptable, and what are the alternatives?
3. After marking, how do you read the answer back out, and in what order does
   it come?

<!-- No hints and no algorithm below this line. -->

---

## My attempt

## After solving

- Pattern:
- Time / space:
- What I got wrong first:
