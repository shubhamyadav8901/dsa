# String Compression  (LeetCode 443 · Medium)

<https://leetcode.com/problems/string-compression/>

## Problem

Given an array of characters `chars`, compress it **in place**:

For each group of **consecutive repeating** characters in `chars`:

- If the group's length is 1, write just the character.
- Otherwise, write the character followed by the group's length.

A length of 10 or more is written as **multiple** characters: a group of 12
`'a'`s becomes `'a', '1', '2'`.

Write the compressed result into the start of `chars` and return its new
length. Whatever is left in `chars` after that length does not matter.

You must use only constant extra space.

## Constraints

- `1 <= chars.length <= 2000`
- `chars[i]` is a lowercase English letter, an uppercase English letter, a
  digit, or a symbol

## Examples

```
["a","a","b","b","c","c","c"]   ->  6, chars starts ["a","2","b","2","c","3"]
["a"]                           ->  1, chars starts ["a"]
["a","b","b","b","b","b","b","b","b","b","b","b","b"]
                                ->  4, chars starts ["a","b","1","2"]
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
