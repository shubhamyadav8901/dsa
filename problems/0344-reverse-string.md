# Reverse String  (LeetCode 344 · Easy)

<https://leetcode.com/problems/reverse-string/>

## Problem

Reverse an array of characters **in place**.

For this repo's version, you may **not** use `std::swap` or `std::reverse`.
Write your own swap helper - that helper is the reference exercise.

## Constraints

- `1 <= s.length <= 10^5`
- every `s[i]` is a printable ASCII character
- O(1) extra memory

## Examples

```
["h","e","l","l","o"]      ->  ["o","l","l","e","h"]
["H","a","n","n","a","h"]  ->  ["h","a","n","n","a","H"]
```

## Think

1. Why must the function take the array by reference? What would the caller
   see if it took it by value?
2. Your swap helper takes two characters and exchanges them. What must its
   parameter types be - and what happens if you get them wrong? (Predict it,
   then try it.)
3. Where do your two pointers start, which way do they move, and when must
   they stop?
4. Does your stopping condition work for both odd and even lengths? What
   happens to the middle character of an odd-length array?

<!-- No hints and no algorithm below this line. -->

---

## My attempt

## After solving

- Pattern:
- Time / space:
- What I got wrong first:
