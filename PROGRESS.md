# PROGRESS

The tutor reads this file at the start of every session to decide what comes
next. Keep it honest — an inflated tracker produces a useless study plan.

- **Session count:** 1
- **Current phase:** Phase 0 — Programming Fundamentals
- **Current topic:** Big-O (done) → next: arrays in memory, then STL `vector`
- **Last session date:** 2026-09-23

---

## Problem Log

Status values: `Not Started` · `Learning` · `Attempted` · `Solved` ·
`Needs Revision` · `Mastered`

`Mastered` requires solving an *unseen variant* unaided — not recalling this
one.

| # | Problem | Topic | Difficulty | Status | Attempts | Lang | Pattern | Complexity | Notes |
|---|---------|-------|------------|--------|----------|------|---------|------------|-------|
| 1 | Second Largest (drill) | basics | Easy | Solved | 4 | C++ ✓ / Py — / Java — | Single-pass running extremum | O(n) / O(1) | Correct on 200k random differential test. Reached the algorithm unaided; all 3 bugs were untested input regions, not logic slips. |

Lang column format: `C++ ✓ / Py — / Java —`

---

## Weak Areas

Concepts where I repeatedly make mistakes. The tutor prioritises these over new
material.

| Concept | Evidence | Times seen | Status |
|---------|----------|------------|--------|
| Choosing test cases that attack your own code | Skipped writing own cases; 3 separate bugs each survived because no test covered that input region | 3 | Active — the priority weakness |
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

---

## Patterns Learned

A pattern is listed here only once I have recognised it unprompted in a problem
I had not seen before.

| Pattern | Recognised on | Trigger — when to reach for it |
|---------|---------------|--------------------------------|
| Single-pass running extremum (track best + second-best in variables) | Second Largest — derived unaided, before being shown anything | "Find the best/worst k items" where k is tiny and fixed. Beats sorting: O(n) vs O(n log n) |

---

## Spaced Revision Queue

Scheduled by session number. See the schedule in `AGENTS.md`.

| Item | Drill | Last seen | Due | Why queued |
|------|-------|-----------|-----|------------|
| Second Largest — pattern, invariant, complexity from memory | Recall | 1 | 2 | 60-second check that the idea outlived the session |
| A subtly wrong second-largest / running-max implementation | Attack | — | 2 | Targets the dominant weakness directly, on code that isn't theirs |
| Constraints → test list, no solution | Constraints-to-tests | — | 2, 4 | The constraint "may be negative" went untested three times |
| Second largest → k-th largest, or second *smallest* | Transfer | — | 4 | Proves the pattern generalised rather than being memorised |
| `std::sort` is O(n log n) | Recall | 1 | 4 | First answer was O(n²); confirm the correction stuck |
| Second Largest from a blank file | Re-implement | 1 | 13 | Only once memory has actually decayed — ~3 weeks out |

## Readiness Assessment

Scored 0–5. `0` = not started, `3` = works with hints, `5` = interview-ready
under time pressure. Not to be inflated.

| Dimension | Score | Evidence |
|-----------|-------|----------|
| Conceptual understanding | 3 | Counted operations correctly first try; understood constants-dropped without pushback |
| Pattern recognition | 1 | One pattern seen. Far too early to judge |
| Problem-solving ability | 3 | Produced brute-force *and* optimal unprompted, and picked the better one for the right reason |
| Complexity analysis | 3 | O(n)/O(1) correct and justified; conflated selection sort with sorting-in-general, then self-corrected |
| Implementation (C++) | 2 | Working code, but 3 iterations to correct; sentinel handling needed guidance |
| Debugging | 1 | Identified the faulty branch when pointed at the loop, but did not find any failing input unaided |
| Communication | 3 | Terse, accurate answers; asked "what is a sentinel?" instead of bluffing — good instinct |
| Performance under time pressure | 0 | Not assessed — no timed work yet |

**Overall:** early Phase 0. Reasoning is ahead of verification: the algorithmic
instinct is genuinely good, but nothing is "done" until the learner can attack
their own code. That gap is the whole focus of session 2.

---

## Session Log

| # | Date | Topic | Problems | Outcome |
|---|------|-------|----------|---------|
| 1 | 2026-09-23 | Big-O: counting, growth, O(1)/O(n)/O(n²), constants dropped | Second Largest (drill) | Solved in C++, 4 attempts. Complexity stated correctly unaided. Key lesson: a green suite proves only that the imagined cases pass. |
