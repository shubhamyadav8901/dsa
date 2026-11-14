# Sqrt(x)  (LeetCode 69 · Easy)

<https://leetcode.com/problems/sqrtx/>

## Problem

Given a non-negative integer `x`, return the square root of `x` rounded down
to the nearest integer. You may not use any built-in exponent function or
`sqrt`.

## Constraints

- `0 <= x <= 2^31 - 1`

## Examples

```
x = 4   ->  2
x = 8   ->  2     (sqrt(8) = 2.828...)
x = 0   ->  0
```

## Think

The approach was derived in session 10: binary search on `[0, x]` for the
last `m` with `ok(m) = m * m <= x`. What remains:

1. `x` can be `2^31 - 1`. What is the largest `mid * mid` your loop could
   compute, and does it fit in the type you are using?
2. Which values of `x` are worth their own test? The constraint has two ends.
3. When the loop ends, which of `lo` / `hi` holds the answer, and why?

<!-- No hints and no algorithm below this line. -->

---

## My attempt

## After solving

- Pattern:
- Time / space:
- What I got wrong first:
