# Minimum Penalty for a Shop  (LeetCode 2483 · Medium)

<https://leetcode.com/problems/minimum-penalty-for-a-shop/>

## Problem

You are given a shop's customer log as a string `customers` of `'N'` and
`'Y'`: `customers[i] == 'Y'` means customers come at hour `i`, `'N'` means
none come.

If the shop closes at hour `j` (`0 <= j <= n`), it is open for hours
`0 .. j-1` and closed for hours `j .. n-1`. The penalty is:

- `+1` for every hour the shop is **open** and no customers come, and
- `+1` for every hour the shop is **closed** and customers come.

Return the **earliest** hour at which the shop must close to get the
minimum penalty.

## Constraints

- `1 <= customers.length <= 10^5`
- `customers` consists only of `'Y'` and `'N'`

## Examples

```
"YYNY"   ->  2
"NNNNN"  ->  0
"YYYY"   ->  4
```

## Think

Independent problem - no guiding questions. Ask for Hint 1 / 2 / 3 if stuck.

<!-- No hints and no algorithm below this line. -->

---

## My attempt

## After solving

- Pattern:
- Time / space:
- What I got wrong first:
