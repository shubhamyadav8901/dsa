# Subarray Sum Equals K  (LeetCode 560 · Medium)

<https://leetcode.com/problems/subarray-sum-equals-k/>

## Problem

Given an integer array `nums` (values may be negative) and an integer `k`,
return the **number** of contiguous non-empty subarrays whose sum equals `k`.

## Constraints

- `1 <= nums.length <= 2 * 10^4`
- `-1000 <= nums[i] <= 1000`
- `-10^7 <= k <= 10^7`

## Examples

```
nums = [1, 1, 1],    k = 2   ->  2    ([1,1] twice)
nums = [1, 2, 3],    k = 3   ->  2    ([1,2] and [3])
nums = [1, -1, 1],   k = 1   ->  3    ([1], [1], [1,-1,1])
```

## Think

The approach was derived in session 8: for each right end, count earlier
prefix sums equal to `P[r + 1] - k`. What remains:

1. In Two Sum the map stored value -> **index**. Here you are counting, and
   the same prefix sum can occur several times. What should the map store?
2. What must already be in the map **before the first element**, and which
   subarrays are missed without it? Test it on `nums = [3], k = 3`.
3. Do you need to store the whole `P` array, or just a running total?
4. Can any intermediate value overflow `int`? Use the constraints to decide.

<!-- No hints and no algorithm below this line. -->

---

## My attempt

## After solving

- Pattern:
- Time / space:
- What I got wrong first:
