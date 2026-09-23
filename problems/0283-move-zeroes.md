# Move Zeroes  (LeetCode 283 · Easy)

<https://leetcode.com/problems/move-zeroes/>

## Problem

Given an array of integers, move every `0` to the end of the array while
keeping the relative order of the non-zero elements unchanged.

Do it **in place** — you may not allocate a second array.

## Constraints

- `1 <= n <= 10^4`
- `-2^31 <= v[i] <= 2^31 - 1`
- must modify the array in place
- extra space must be O(1)

## Examples

```
Input:  [0, 1, 0, 3, 12]
Output: [1, 3, 12, 0, 0]
```

```
Input:  [0]
Output: [0]
```

```
Input:  [1, 2, 3]
Output: [1, 2, 3]
```

## Think

Before any code:

1. What is the most obvious approach? If you were doing this by hand on paper,
   what would you do?
2. Yesterday you established what erasing from the middle of an array costs.
   If your obvious approach erases or inserts inside the array, what is the
   total cost when it does that `n` times?
3. "Keep the relative order of the non-zero elements" - which approaches does
   that constraint immediately rule out?
4. What is the smallest amount of information you would need to remember while
   sweeping through the array once?
5. Which inputs would embarrass a solution to this problem?

<!-- No hints and no algorithm below this line. -->

---

## My attempt

## After solving

- Pattern:
- Time / space:
- What I got wrong first:
