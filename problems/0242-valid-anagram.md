# Valid Anagram  (LeetCode 242 · Easy)

<https://leetcode.com/problems/valid-anagram/>

## Problem

Given two strings `a` and `b`, return `true` if `b` is an anagram of `a`.

An anagram uses exactly the same characters with exactly the same counts, in
any order.

## Constraints

- `1 <= a.length, b.length <= 5 * 10^4`
- `a` and `b` consist of lowercase English letters only

## Examples

```
a = "anagram", b = "nagaram"   ->  true
a = "rat",     b = "car"       ->  false
a = "a",       b = "ab"        ->  false
```

## Think

1. What has to be true about the lengths before anything else is worth
   checking?
2. `'a'` is the number 97. What does `c - 'a'` give you, and what can you
   index with it?
3. Your space complexity depends on a constant. Which one - and what
   assumption in the constraints makes it a constant?
4. Which inputs would embarrass a solution to this problem? The size bound is
   one of them.

<!-- No hints and no algorithm below this line. -->

---

## My attempt

## After solving

- Pattern:
- Time / space:
- What I got wrong first:
