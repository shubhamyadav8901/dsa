# Longest Substring Without Repeating Characters  (LeetCode 3 · Medium)

<https://leetcode.com/problems/longest-substring-without-repeating-characters/>

## Problem

Given a string `s`, return the length of the longest contiguous substring in
which no character appears more than once.

## Constraints

- `0 <= s.length <= 5 * 10^4`
- `s` consists of English letters, digits, symbols and spaces

## Examples

```
"abcabcbb"  ->  3    ("abc")
"bbbbb"     ->  1    ("b")
"pwwkew"    ->  3    ("wke" - "pwke" is a subsequence, not a substring)
```

## Think

The algorithm was derived in session 7. What remains:

1. The window needs a "what's inside me?" structure. Hash set or fixed-size
   array? Which constraint decides it - and how big would the array be?
2. Read the size constraint carefully. Which input does it allow that none of
   the examples show?
3. State time and space in the header before saying `check`.

<!-- No hints and no algorithm below this line. -->

---

## My attempt

## After solving

- Pattern:
- Time / space:
- What I got wrong first:
