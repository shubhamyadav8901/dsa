# Merge Intervals  (LeetCode 56 · Medium)

<https://leetcode.com/problems/merge-intervals/>

## Problem

Given an array of `intervals` where `intervals[i] = [start_i, end_i]`, merge
all overlapping intervals and return an array of the non-overlapping intervals
that cover all the intervals in the input.

Intervals that only touch (`[1, 4]` and `[4, 5]`) count as overlapping.

## Constraints

- `1 <= intervals.length <= 10^4`
- `intervals[i].length == 2`
- `0 <= start_i <= end_i <= 10^4`

## Examples

```
[[1,3],[2,6],[8,10],[15,18]]  ->  [[1,6],[8,10],[15,18]]
[[1,4],[4,5]]                 ->  [[1,5]]
[[4,7],[1,4]]                 ->  [[1,7]]
```

## Think

1. Brute force: how would you decide whether *any* two intervals overlap, and
   what does merging everything cost that way?
2. Given two intervals `a` and `b`, write the exact condition for "they
   overlap". Does it depend on which one starts first?
3. If the input were already in some order, which neighbours could possibly
   overlap? What order would make that true?
4. In `[[1,10],[2,3],[4,5]]`, what does the merged interval's end have to be,
   and why is "the end of the last interval I looked at" the wrong answer?

<!-- No hints and no algorithm below this line. -->

---

## My attempt

## After solving

- Pattern:
- Time / space:
- What I got wrong first:
