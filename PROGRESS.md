# PROGRESS

The tutor reads this file at the start of every session to decide what comes
next. Keep it honest — an inflated tracker produces a useless study plan.

- **Session count:** 4
- **Current phase:** Phase 0 — Programming Fundamentals
- **Current topic:** References & pointers (done) → next: hashing concept, then `unordered_map` / `unordered_set`
- **Last session date:** 2026-09-24

---

## Problem Log

Status values: `Not Started` · `Learning` · `Attempted` · `Solved` ·
`Needs Revision` · `Mastered`

`Mastered` requires solving an *unseen variant* unaided — not recalling this
one.

| # | Problem | Topic | Difficulty | Status | Attempts | Lang | Pattern | Complexity | Notes |
|---|---------|-------|------------|--------|----------|------|---------|------------|-------|
| 5 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) (LC 125) | strings | Easy | Solved | 2 | C++ ✓ / Py — / Java — | Two pointers, opposite ends, with skip-filtering | O(n) / O(1) | Independent problem. First version read out of bounds on `"a!"`: `size_t end` wrapped past 0. Found and explained it from one hint. Also shipped a check that could not fail (`CHECK_TRUE` on a string literal). Verified on 300k random strings under ASan. |
| 4 | [Reverse String](https://leetcode.com/problems/reverse-string/) (LC 344) | strings | Easy | Solved | 1 | C++ ✓ / Py — / Java — | Two pointers, opposite ends | O(n) / O(1) | Hand-written `swap_chars(char&, char&)`. By-value experiment failed 4/5 — the n=1 case passed, since reversing one element is a no-op. |
| 3 | [Valid Anagram](https://leetcode.com/problems/valid-anagram/) (LC 242) | strings | Easy | Solved | 1 | C++ ✓ / Py — / Java — | Two pointers, opposite ends (converging) | Reverse String, then applied independently to Valid Palindrome | Symmetric comparison or in-place reversal. Pointers start at both ends and move inward; stop when they meet — decide the `<` vs `<=` on purpose |
| Frequency counting with a fixed-size array | O(n) / O(1) | Correct first try, single count array. Tests included a 50k scale test with fixed seeds. Verified on 400k random pairs vs a sorting reference. |
| 2 | [Move Zeroes](https://leetcode.com/problems/move-zeroes/) (LC 283) | arrays | Easy | Solved | 2 | C++ ✓ / Py — / Java — | Two pointers (read/write scan) | O(n) / O(1) | Tests written before code, incl. n=1 and INT_MIN. First version was O(n²): `j` was reset per iteration, re-walking the same zeroes. Verified on 300k random arrays vs `stable_partition`. |
| 1 | Second Largest (drill) | basics | Easy | Solved | 4 | C++ ✓ / Py — / Java — | Single-pass running extremum | O(n) / O(1) | Correct on 200k random differential test. Reached the algorithm unaided; all 3 bugs were untested input regions, not logic slips. |

Lang column format: `C++ ✓ / Py — / Java —`

---

## Weak Areas

Concepts where I repeatedly make mistakes. The tutor prioritises these over new
material.

| Concept | Evidence | Times seen | Status |
|---------|----------|------------|--------|
| Testing complexity, not just correctness | S2: O(n²) passed all tests. S3 and S4: scale tests at the constraint bound, unprompted, every problem | 1 | **Closed** — habit established across three problems |
| Relying on transitive includes | `<climits>` twice, `<algorithm>` twice — compiles by luck | 4 | Active — now enforced in AGENTS.md Rule 6 |
| Unsigned arithmetic near zero | Warned about `s.size() - 1` in Reverse String; the next problem crashed on `end--` past 0 | 1 | **New — active** |
| Mapping a spotted trigger to the right pattern | S4 recognition drill: found the correct trigger words in (a) and (c), attached them to swapped patterns | 1 | New — drill again next session |
| Code drifting from the described approach | Described an O(n) monotonic scan, wrote an O(n²) resetting one, and did not notice | 1 | New — re-read the code against the sentence that described it |
| Choosing test cases that attack your own code | S1: skipped own cases, 3 bugs survived. S2: wrote 6 cases unprompted incl. negatives and INT_MIN, missed only n=1 | 3 | **Improving fast** — keep drilling |
| Representing absence (sentinels vs flags) | Chose `second = largest`, then `-1`, then `INT_MIN`; each collided with legal data | 3 | Improving — flag chosen correctly once explained |
| Reading constraints as a test checklist | "values may be negative" was stated 3 times before it was tested | 1 | Watch |

---

## Common Mistakes

Recurring errors, so they become checkable habits rather than surprises.

| Mistake | Example | Times | Fix / habit to build |
|---------|---------|-------|----------------------|
| Treating a green suite as proof of correctness | 3 separate passing runs, each hiding a real bug | 3 | Before saying "done", name the input you'd be embarrassed by — then write it |
| Fixing before reproducing | Fixed the code without first committing a red test | 2 | Red test, then fix. Always that order |
| Only updating state in one branch | `second` updated solely inside `if (i > largest)` | 1 | Ask: "does every case that *should* change this variable actually reach an assignment?" |
| Magic sentinel inside the legal value range | `-1`, then `INT_MIN` | 2 | A sentinel must be impossible as real data — otherwise use a flag |
| Reading only the value constraints, never the size constraint | `1 <= n <= 10^4` means "write a test at scale", and it was skipped | 1 | Size bounds are a performance test. Time it, don't assume it |
| Stale comments left after a refactor | `// TODO` left in three solution files after the code was written | 3 | Delete the comment in the same edit that invalidates it |
| Decrementing an unsigned index past zero | `end--` on a `size_t` holding 0 wrapped to SIZE_MAX, then indexed | 1 | Check `start >= end` *before* moving pointers, or use a signed index when it can go below 0 |
| A test that asserts something other than the function's result | `CHECK_TRUE("ABCDEedcba")` — a literal is a non-null pointer, always true | 1 | For every test, ask: what bug would make this fail? |
| Using a symbol without including its header | `INT_MIN` without `<climits>`, `std::shuffle` without `<algorithm>` | 3 | Every symbol needs its own header, every time |

---

## Patterns Learned

A pattern is listed here only once I have recognised it unprompted in a problem
I had not seen before.

| Pattern | Recognised on | Trigger — when to reach for it |
|---------|---------------|--------------------------------|
| Single-pass running extremum (track best + second-best in variables) | Second Largest — derived unaided, before being shown anything | "Find the best/worst k items" where k is tiny and fixed. Beats sorting: O(n) vs O(n log n) |
| Two pointers, opposite ends (converging) | Reverse String, then applied independently to Valid Palindrome | Symmetric comparison or in-place reversal. Pointers start at both ends and move inward; stop when they meet — decide the `<` vs `<=` on purpose |
| Frequency counting with a fixed-size array | Valid Anagram — approach derived unaided, including the single-array refinement | Counting over a small, known alphabet. `c - 'a'` turns a character into an index, so no hash map is needed and space stays O(1) |
| Two pointers, same direction (read ahead / write behind) | Move Zeroes — approach derived unaided, including the invariant | Rearranging an array in place while preserving order. Both pointers move forward only, never reset — that is what makes it O(n) |

---

## Spaced Revision Queue

Scheduled by session number. See the schedule in `AGENTS.md`.

| Item | Drill | Last seen | Due | Why queued |
|------|-------|-----------|-----|------------|
| Cold problem statements → which of the four patterns | Recall (recognition) | 4 | 5 | Swapped two mappings this session |
| Code that indexes with a decremented `size_t` | Attack | 4 | 5 | Crashed on it the problem after being warned |
| Code that is correct but quadratic | Attack | 3 | 5 | Caught it in one step — verify on a subtler case |
| Move Zeroes → remove-element / dedupe-sorted-array | Transfer | — | 5 | Confirms the read/write two-pointer generalises |
| Amortized O(1), and why `s = s + c` is quadratic | Recall | 3 | 5 | Derived twice; check it survives |
| `const T&` vs `T&` vs `T` vs `T*` — when each | Recall | 4 | 6 | New concept this session |
| Valid Anagram → grouping anagrams, or unicode input | Transfer | — | 6 | Tests whether the fixed-array assumption is understood |
| Second Largest from a blank file | Re-implement | 1 | 13 | Only once memory has actually decayed |

## Readiness Assessment

Scored 0–5. `0` = not started, `3` = works with hints, `5` = interview-ready
under time pressure. Not to be inflated.

| Dimension | Score | Evidence |
|-----------|-------|----------|
| Conceptual understanding | 4 | Derived the amortized O(1) geometric sum unaided; solid on memory layout |
| Pattern recognition | 3 | One pattern seen. Far too early to judge |
| Problem-solving ability | 4 | Produced brute-force *and* optimal unprompted, and picked the better one for the right reason |
| Complexity analysis | 4 | O(n)/O(1) correct and justified; conflated selection sort with sorting-in-general, then self-corrected |
| Implementation (C++) | 4 | Working code, but 3 iterations to correct; sentinel handling needed guidance |
| Debugging | 3 | Identified the faulty branch when pointed at the loop, but did not find any failing input unaided |
| Communication | 3 | Terse, accurate answers; asked "what is a sentinel?" instead of bluffing — good instinct |
| Performance under time pressure | 0 | Not assessed — no timed work yet |

**Overall (S4):** Phase 0 all but done. Debugging moved up: the Valid
Palindrome crash was diagnosed from a single hint and explained precisely —
type, value, line, and why the loop kept running. Two things to watch: a
warning given in one problem (unsigned underflow) was not carried into the
next, and pattern *mapping* slipped once even though trigger spotting did not.

**Previous (S3):** Phase 0 nearly complete. Three patterns derived unaided in three
sessions, and the verification gap that dominated sessions 1–2 has largely
closed: tests now come first, attack the constraints, and include scale. The
remaining weaknesses are small and mechanical (headers, stale comments) rather
than conceptual. Debugging stays low only because nothing has needed debugging
since session 2 — it is untested, not proven. Pattern *triggers* are the next
thing to drill: the names are landing, the recognition sentences are not.

---

## Session Log

| # | Date | Topic | Problems | Outcome |
|---|------|-------|----------|---------|
| 4 | 2026-09-24 | References & pointers: value vs `&` vs `*`, hidden O(n) copies in by-value parameters, `const T&` as the default | Reverse String (LC 344), Valid Palindrome (LC 125, independent) | Both solved, O(n)/O(1). Palindrome crashed on `size_t` wrap-around; found and explained from one hint. Lesson: a test only catches a bug that would change its output. |
| 3 | 2026-09-24 | Strings: contiguous like vectors, `s = s + c` vs `s += c`, substr/compare costs, `c - 'a'` as an index, immutability in Java/Python | Valid Anagram (LC 242) | Solved first try, O(n)/O(1). Test file used `reserve` and `+=` unprompted, twenty minutes after learning why. |
| 2 | 2026-09-23 | Arrays in memory: address arithmetic, why indexing is O(1), insert/erase costs, vector size vs capacity, amortized O(1) | Move Zeroes (LC 283) | Solved, O(n)/O(1). Wrote tests before code. Key lesson: passing tests prove correctness, never complexity — the O(n²) version passed all 10. |
| 1 | 2026-09-23 | Big-O: counting, growth, O(1)/O(n)/O(n²), constants dropped | Second Largest (drill) | Solved in C++, 4 attempts. Complexity stated correctly unaided. Key lesson: a green suite proves only that the imagined cases pass. |
