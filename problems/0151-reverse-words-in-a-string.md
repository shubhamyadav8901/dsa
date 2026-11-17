# Reverse Words in a String  (LeetCode 151 · Medium)

<https://leetcode.com/problems/reverse-words-in-a-string/>

## Problem

Given a string `s`, reverse the order of the **words**.

A word is a maximal sequence of non-space characters. Words in `s` are
separated by at least one space.

Return a string of the words in reverse order, joined by **exactly one**
space. The result must have no leading or trailing spaces, even if `s` does,
and no repeated spaces between words.

## Constraints

- `1 <= s.length <= 10^4`
- `s` contains English letters (upper and lower case), digits, and spaces `' '`
- There is **at least one** word in `s`

## Examples

```
"the sky is blue"     ->  "blue is sky the"
"  hello world  "     ->  "world hello"
"a good   example"    ->  "example good a"
```

## Think

1. What does the run-scanning loop give you for each word, and where would
   you put each word as you find it?
2. You find words left to right but need them right to left. Name two ways to
   deal with that, and what each costs in extra space.
3. "Exactly one space between words, none at the ends": where does the
   separator go, and how do you avoid a trailing or leading one?
4. What does `s.substr(pos, len)` cost? Does that change your total
   complexity?

<!-- No hints and no algorithm below this line. -->

---

## My attempt

## After solving

- Pattern:
- Time / space:
- What I got wrong first:
