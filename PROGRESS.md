# PROGRESS

The tutor reads this file at the start of every session to decide what comes
next. Keep it honest — an inflated tracker produces a useless study plan.

- **Session count:** 2
- **Current phase:** Phase 0 — Programming Fundamentals
- **Current topic:** Arrays in memory (done) → next: strings, then references & pointers
- **Last session date:** 2026-09-23

---

## Problem Log

Status values: `Not Started` · `Learning` · `Attempted` · `Solved` ·
`Needs Revision` · `Mastered`

`Mastered` requires solving an *unseen variant* unaided — not recalling this
one.

| # | Problem | Topic | Difficulty | Status | Attempts | Lang | Pattern | Complexity | Notes |
|---|---------|-------|------------|--------|----------|------|---------|------------|-------|
| 2 | [Move Zeroes](https://leetcode.com/problems/move-zeroes/) (LC 283) | arrays | Easy | Solved | 2 | C++ ✓ / Py — / Java — | Two pointers (read/write scan) | O(n) / O(1) | Tests written before code, incl. n=1 and INT_MIN. First version was O(n²): `j` was reset per iteration, re-walking the same zeroes. Verified on 300k random arrays vs `stable_partition`. |
| 1 | Second Largest (drill) | basics | Easy | Solved | 4 | C++ ✓ / Py — / Java — | Single-pass running extremum | O(n) / O(1) | Correct on 200k random differential test. Reached the algorithm unaided; all 3 bugs were untested input regions, not logic slips. |

Lang column format: `C++ ✓ / Py — / Java —`

---

## Weak Areas

Concepts where I repeatedly make mistakes. The tutor prioritises these over new
material.

| Concept | Evidence | Times seen | Status |
|---------|----------|------------|--------|
| Testing complexity, not just correctness | All 10 Move Zeroes tests passed on an O(n²) implementation; every input was tiny | 1 | **New — the current priority** |
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
| Stale comments left after a refactor | `// TODO` and an approach comment describing the discarded version | 2 | Delete the comment in the same edit that invalidates it |

---

## Patterns Learned

A pattern is listed here only once I have recognised it unprompted in a problem
I had not seen before.

| Pattern | Recognised on | Trigger — when to reach for it |
|---------|---------------|--------------------------------|
| Single-pass running extremum (track best + second-best in variables) | Second Largest — derived unaided, before being shown anything | "Find the best/worst k items" where k is tiny and fixed. Beats sorting: O(n) vs O(n log n) |
| Two pointers, same direction (read ahead / write behind) | Move Zeroes — approach derived unaided, including the invariant | Rearranging an array in place while preserving order. Both pointers move forward only, never reset — that is what makes it O(n) |

---

## Spaced Revision Queue

Scheduled by session number. See the schedule in `AGENTS.md`.

| Item | Drill | Last seen | Due | Why queued |
|------|-------|-----------|-----|------------|
| Second Largest — pattern name, not just the invariant | Recall | 2 | 3 | Named the invariant correctly but could not name the pattern |
| An O(n²) implementation disguised as O(n) | Attack | — | 3 | Directly targets the new top weakness |
| Constraints → test list, including a scale test | Constraints-to-tests | 2 | 3, 5 | The size bound went untested; the value bound did not |
| Move Zeroes → remove-element / dedupe-sorted-array | Transfer | — | 5 | Confirms the read/write two-pointer generalises |
| `std::sort` is O(n log n) | Recall | 1 | 4 | First answer was O(n²); confirm the correction stuck |
| Amortized O(1) — why doubling gives it | Recall | 2 | 5 | Derived it correctly once; check it survives |
| Second Largest from a blank file | Re-implement | 1 | 13 | Only once memory has actually decayed |

## Readiness Assessment

Scored 0–5. `0` = not started, `3` = works with hints, `5` = interview-ready
under time pressure. Not to be inflated.

| Dimension | Score | Evidence |
|-----------|-------|----------|
| Conceptual understanding | 4 | Derived the amortized O(1) geometric sum unaided; solid on memory layout |
| Pattern recognition | 2 | One pattern seen. Far too early to judge |
| Problem-solving ability | 4 | Produced brute-force *and* optimal unprompted, and picked the better one for the right reason |
| Complexity analysis | 3 | O(n)/O(1) correct and justified; conflated selection sort with sorting-in-general, then self-corrected |
| Implementation (C++) | 3 | Working code, but 3 iterations to correct; sentinel handling needed guidance |
| Debugging | 2 | Identified the faulty branch when pointed at the loop, but did not find any failing input unaided |
| Communication | 3 | Terse, accurate answers; asked "what is a sentinel?" instead of bluffing — good instinct |
| Performance under time pressure | 0 | Not assessed — no timed work yet |

**Overall:** end of Phase 0 fundamentals. Reasoning is strong and moving
faster than expected — two patterns derived unaided in two sessions, and the
amortized-cost derivation was real work. Verification is catching up: tests
now get written first and attack the value constraints, but not yet the size
constraints. Next gap to close is proving the complexity of what was actually
written, rather than of what was described.

---

## Session Log

| # | Date | Topic | Problems | Outcome |
|---|------|-------|----------|---------|
| 2 | 2026-09-23 | Arrays in memory: address arithmetic, why indexing is O(1), insert/erase costs, vector size vs capacity, amortized O(1) | Move Zeroes (LC 283) | Solved, O(n)/O(1). Wrote tests before code. Key lesson: passing tests prove correctness, never complexity — the O(n²) version passed all 10. |
| 1 | 2026-09-23 | Big-O: counting, growth, O(1)/O(n)/O(n²), constants dropped | Second Largest (drill) | Solved in C++, 4 attempts. Complexity stated correctly unaided. Key lesson: a green suite proves only that the imagined cases pass. |
