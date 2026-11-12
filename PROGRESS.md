# PROGRESS

The tutor reads this file at the start of every session to decide what comes
next. Keep it honest — an inflated tracker produces a useless study plan.

- **Session count:** 9
- **Current phase:** Phase 1 — Core Patterns
- **Current topic:** Binary search on a sorted array (done) → next: binary search on the answer space. Session 10 opens with the Group Anagrams transfer
- **Last session date:** 2026-11-13

---

## Problem Log

Status values: `Not Started` · `Learning` · `Attempted` · `Solved` ·
`Needs Revision` · `Mastered`

`Mastered` requires solving an *unseen variant* unaided — not recalling this
one.

| # | Problem | Topic | Difficulty | Status | Attempts | Lang | Pattern | Complexity | Notes |
|---|---------|-------|------------|--------|----------|------|---------|------------|-------|
| 15 | [Search Insert Position](https://leetcode.com/problems/search-insert-position/) (LC 35) | binary_search | Easy | Solved | 1 | C++ ✓ / Py — / Java — | Binary search; `lo` at exit is the insertion point | O(log n) / O(1) | Independent, no hints. Used the overflow-safe midpoint unprompted. Explained via the invariant why `lo` is the insertion point. Header first said O(n) time; first scale loop only exercised the found path — replaced with a search of every gap. |
| 14 | [Binary Search](https://leetcode.com/problems/binary-search/) (LC 704) | binary_search | Easy | Solved | 1 | C++ ✓ / Py — / Java — | Binary search, inclusive `[lo, hi]` | O(log n) / O(1) | Derived the invariant, `mid + 1` and `lo <= hi` from the guessing game. Chose signed `lo`/`hi` and explained why `size_t` wraps. Tests mapped every target position; some used ±10,000 under a strict `<` constraint. Every-element loop added. |
| 13 | [Contiguous Array](https://leetcode.com/problems/contiguous-array/) (LC 525) | arrays | Medium | Solved | 1 | C++ ✓ / Py — / Java — | Prefix sum (0 → −1) + map of **first** index | O(n) / O(n) | Independent Medium with Hint 1 only. Chose first-occurrence unaided and explained why overwriting gives the shortest span. Scale test was accidentally 150,000 long (`vector(n)` instead of `reserve`). |
| 12 | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) (LC 560) | arrays | Medium | Solved | 1 | C++ ✓ / Py — / Java — | Prefix sum + map of **counts**, seeded `{0: 1}` | O(n) / O(n) | Guided. Derived the complement form after a sign slip. Header first said O(1) space; lookup used `[]` (inserting on every miss), then `find` + `[]`, then a single `find`. All-zeros test pins the maximum answer, 200,010,000. |
| 11 | [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) (LC 26) | arrays | Easy | Solved | 1 | C++ ✓ / Py — / Java — | Two pointers, same direction (read/write) | O(n) / O(1) | Transfer drill: recognised as Move Zeroes and named the changed keep condition. First version was correct but convoluted (an `else` that did not advance `j`); rewritten as a single loop. Generators first used `random_device` seeds. |
| 10 | [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) (LC 209) | sliding_window | Medium | Solved | 2 | C++ ✓ / Py — / Java — | Variable window, shrink while **valid** | O(n) / O(1) | Independent Medium, correct first try; inverted LC 3's shrink condition unaided. First version used a sentinel equal to a legal answer (100,000), rescued by `<=` plus a flag; replaced with `nums.size() + 1`. Scale test hit three constraint bounds at once. |
| 9 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) (LC 3) | sliding_window | Medium | Solved | 2 | C++ ✓ / Py — / Java — | Variable window, shrink while **invalid** | O(n) / O(1) | First Medium. Derived O(n³) → O(n²) → O(n) step by step. Header first said O(n) space for a fixed 256-slot array; window length recomputed by scanning instead of `j - i + 1`; `unsigned char` cast applied to 2 of 3 index sites before the fix. |
| 8 | Contains Duplicate II — sliding-window version | sliding_window | Easy | Solved | 2 | C++ ✓ / Py — / Java — | Fixed-size sliding window over a hash set | O(n) / O(min(n, k)) | Derived the window from "which indices can matter?". First version needed a `k == 0` guard; reordering to insert-then-evict removed it. Avoided the `i - k` unsigned wrap unaided. Run against the map version on all 18 checks, and 400k random cases under ASan. |
| 7 | [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/) (LC 219) | hashing | Easy | Solved | 1 | C++ ✓ / Py — / Java — | Hash map value → latest index | O(n) / O(n) | Independent, correct first try — transferred Two Sum's map unaided. Tests pinned the `<=` boundary at scale (k = gap−1, gap, gap+1) and k=0 with adjacent duplicates. Included `<map>` instead of `<unordered_map>`. |
| 6 | [Two Sum](https://leetcode.com/problems/two-sum/) (LC 1) | hashing | Easy | Solved | 1 | C++ ✓ / Py — / Java — | Hash map complement lookup, check-before-insert | O(n) / O(n) | Guided: derived the complement and the key/value choice step by step. Scale generator guarantees a single pair by construction. One test was outside the constraints (target 2×10⁹); a duplicate-answer test was dropped during a fix and re-added. |
| 5 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) (LC 125) | strings | Easy | Solved | 2 | C++ ✓ / Py — / Java — | Two pointers, opposite ends, with skip-filtering | O(n) / O(1) | Independent problem. First version read out of bounds on `"a!"`: `size_t end` wrapped past 0. Found and explained it from one hint. Also shipped a check that could not fail (`CHECK_TRUE` on a string literal). Verified on 300k random strings under ASan. |
| 4 | [Reverse String](https://leetcode.com/problems/reverse-string/) (LC 344) | strings | Easy | Solved | 1 | C++ ✓ / Py — / Java — | Two pointers, opposite ends | O(n) / O(1) | Hand-written `swap_chars(char&, char&)`. By-value experiment failed 4/5 — the n=1 case passed, since reversing one element is a no-op. |
| 3 | [Valid Anagram](https://leetcode.com/problems/valid-anagram/) (LC 242) | strings | Easy | Solved | 1 | C++ ✓ / Py — / Java — | Binary search on a sorted array | LC 704 (guided from a guessing game), LC 35 independently | Sorted/monotonic data and a "where is X?" question. Invariant: the target, if present, is in `[lo, hi]`. Loop `while lo <= hi`, step past `mid`. At exit `lo = hi + 1` is the insertion point. Signed indices; `lo + (hi − lo) / 2` |
| Prefix sums | LC 560 (guided), then LC 525 independently with a value transform | Subarray sums when a window can't work (negatives break monotonicity). `sum(l..r) = P[r+1] − P[l]`; for "sum equals k", look up `P − k` in a map seeded with the empty prefix. The map's value depends on the goal: count (how many), first index (longest), latest index (closest) |
| Sliding window, variable size | LC 3 (derived from brute force), then LC 209 unaided with the condition inverted | Contiguous subarray/substring, longest or shortest satisfying a condition. Right edge always advances; left edge advances only as far as it must. O(n) because each index enters and leaves once. Longest → shrink while invalid; shortest → shrink while valid. Needs a condition that is monotonic as the window grows (positive numbers in 209) |
| Sliding window, fixed size | Contains Duplicate II, derived from "which earlier indices can matter for position i?" | "Within distance k", "every window of size k". One element enters and one leaves per step, so update the window's summary in O(1) instead of rebuilding it in O(k) |
| Hash map for O(1) "have I seen X, and where?" | Two Sum (guided), then transferred unaided to Contains Duplicate II | The brute force's inner loop is *searching for one specific value* (a complement, a repeat). Store what you've seen, keyed by the value you'll look up, mapping to what you need back |
| Two pointers, opposite ends (converging) | Reverse String, then applied independently to Valid Palindrome | Symmetric comparison or in-place reversal. Pointers start at both ends and move inward; stop when they meet — decide the `<` vs `<=` on purpose |
| Frequency counting with a fixed-size array | O(n) / O(1) | Correct first try, single count array. Tests included a 50k scale test with fixed seeds. Verified on 400k random pairs vs a sorting reference. |
| 2 | [Move Zeroes](https://leetcode.com/problems/move-zeroes/) (LC 283) | arrays | Easy | **Mastered** | 2 | C++ ✓ / Py — / Java — | Two pointers (read/write scan) | O(n) / O(1) | Tests written before code, incl. n=1 and INT_MIN. First version was O(n²): `j` was reset per iteration, re-walking the same zeroes. Verified on 300k random arrays vs `stable_partition`. **Mastered S8** via transfer to LC 26. |
| 1 | Second Largest (drill) | basics | Easy | Solved | 4 | C++ ✓ / Py — / Java — | Single-pass running extremum | O(n) / O(1) | Correct on 200k random differential test. Reached the algorithm unaided; all 3 bugs were untested input regions, not logic slips. |

Lang column format: `C++ ✓ / Py — / Java —`

---

## Weak Areas

Concepts where I repeatedly make mistakes. The tutor prioritises these over new
material.

| Concept | Evidence | Times seen | Status |
|---------|----------|------------|--------|
| Testing complexity, not just correctness | S2: O(n²) passed all tests. S3 and S4: scale tests at the constraint bound, unprompted, every problem | 1 | **Closed** — habit established across three problems |
| Relying on transitive includes | `<climits>` ×2, `<algorithm>` ×4, `<unordered_map>` ×3 (once `<map>` instead), `<vector>` ×2 | 11 | Active — solution files are now usually clean; test files are where it recurs |
| Tests outside the constraints | S5: target 2×10⁹. S8: a 150,000-element vector. S9: ±10,000 under a strict `<` | 3 | Active — check `<` vs `<=` when turning a bound into a test |
| Hedging between two patterns | S7: answered two with "fixed array / hash". S9: one answer each | 1 | **Closed** |
| Leaving the complexity header as `O(?)` | Four problems filled only when asked. S7 and S8: filled before `check` every time | 4 | **Closed** — habit established across five problems |
| Complexity *values* (the header is written; the number is wrong) | S7: O(n) space for a fixed array. S8: O(1) for a growing map. S9: drill 4/4 on space — then O(n) *time* on LC 35 | 3 | Improving — space now right under questioning; check the value against the loop before `check` |
| Unsigned arithmetic near zero | S4: crashed on `end--` past 0. S5: found both bugs in an Attack drill. S6: `nums[i - k]` guarded by `i >= k` in own code, unprompted | 1 | **Closed** — proven in own code |
| Mapping a spotted trigger to the right pattern | S4: swapped two mappings. S5: 4/4 on cold statements, each tied to a solved problem | 1 | **Closing** — one clean pass |
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
| Magic sentinel inside the legal value range | S1: `-1`, then `INT_MIN`. S7: `result = 100'000`, itself a legal answer | 3 | A sentinel must be impossible as real data — derive it from the input (`n + 1`) or use a flag. Two patches covering for each other is the tell |
| Non-deterministic test data | S8: generators seeded with `std::random_device` — a failure could not be reproduced | 1 | Fixed seeds, passed as parameters. Sessions 3–6 did this right |
| Constructing a vector with a size when meaning to reserve | S8: `std::vector<int> v(n)` then `insert`, giving n extra zeros and a test outside the constraints | 1 | `vector(n)` creates n elements; `reserve(n)` creates none. Assert the size of generated input |
| A fix applied to some sites but not all | S7: `unsigned char` cast on 2 of 3 `arr[...]` indexes | 1 | Apply a fix by searching for every site, or read the value once into a correctly typed variable |
| Reading only the value constraints, never the size constraint | `1 <= n <= 10^4` means "write a test at scale", and it was skipped | 1 | Size bounds are a performance test. Time it, don't assume it |
| Stale comments left after a refactor | `// TODO` in three files; S6: a commented-out `// if (k == 0) return false;` | 4 | Delete the comment in the same edit that invalidates it — commented-out code included |
| Describing *what* instead of *when* | S2: defined "invariant" when asked for a pattern. S6: described what `const T&`/`T&`/`T`/`T*` do when asked when to use each | 2 | Answer the question asked: a decision question wants a decision |
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
| Binary search on a sorted array | LC 704 (guided from a guessing game), LC 35 independently | Sorted/monotonic data and a "where is X?" question. Invariant: the target, if present, is in `[lo, hi]`. Loop `while lo <= hi`, step past `mid`. At exit `lo = hi + 1` is the insertion point. Signed indices; `lo + (hi − lo) / 2` |
| Prefix sums | LC 560 (guided), then LC 525 independently with a value transform | Subarray sums when a window can't work (negatives break monotonicity). `sum(l..r) = P[r+1] − P[l]`; for "sum equals k", look up `P − k` in a map seeded with the empty prefix. The map's value depends on the goal: count (how many), first index (longest), latest index (closest) |
| Sliding window, variable size | LC 3 (derived from brute force), then LC 209 unaided with the condition inverted | Contiguous subarray/substring, longest or shortest satisfying a condition. Right edge always advances; left edge advances only as far as it must. O(n) because each index enters and leaves once. Longest → shrink while invalid; shortest → shrink while valid. Needs a condition that is monotonic as the window grows (positive numbers in 209) |
| Sliding window, fixed size | Contains Duplicate II, derived from "which earlier indices can matter for position i?" | "Within distance k", "every window of size k". One element enters and one leaves per step, so update the window's summary in O(1) instead of rebuilding it in O(k) |
| Hash map for O(1) "have I seen X, and where?" | Two Sum (guided), then transferred unaided to Contains Duplicate II | The brute force's inner loop is *searching for one specific value* (a complement, a repeat). Store what you've seen, keyed by the value you'll look up, mapping to what you need back |
| Two pointers, opposite ends (converging) | Reverse String, then applied independently to Valid Palindrome | Symmetric comparison or in-place reversal. Pointers start at both ends and move inward; stop when they meet — decide the `<` vs `<=` on purpose |
| Frequency counting with a fixed-size array | Valid Anagram — approach derived unaided, including the single-array refinement | Counting over a small, known alphabet. `c - 'a'` turns a character into an index, so no hash map is needed and space stays O(1) |
| Two pointers, same direction (read ahead / write behind) | Move Zeroes — approach derived unaided, including the invariant | Rearranging an array in place while preserving order. Both pointers move forward only, never reset — that is what makes it O(n) |

---

## Spaced Revision Queue

Scheduled by session number. See the schedule in `AGENTS.md`.

| Item | Drill | Last seen | Due | Why queued |
|------|-------|-----------|-----|------------|
| Valid Anagram → group anagrams | Transfer | — | **10 — opens the session** | Deferred repeatedly; promised as the first thing in S10 |
| What the map stores: latest index / count / first index | Recall | 8 | 10 | Chose right unaided in S8; check it survives |
| Sentinel inside the legal range | Attack | 7 | 10 | Third occurrence across sessions |
| Binary search boundaries: why `mid + 1`, why `<=`, what `lo` means at exit | Recall | 9 | 11 | New pattern; boundaries are where it breaks |
| Window invariants — what the window holds, why erase-by-value is safe | Recall | 6 | 11 | Check it survives |
| Second Largest from a blank file | Re-implement | 1 | 13 | Only once memory has actually decayed |

## Readiness Assessment

Scored 0–5. `0` = not started, `3` = works with hints, `5` = interview-ready
under time pressure. Not to be inflated.

| Dimension | Score | Evidence |
|-----------|-------|----------|
| Conceptual understanding | 4 | Derived the amortized O(1) geometric sum unaided; solid on memory layout |
| Pattern recognition | 4 | One pattern seen. Far too early to judge |
| Problem-solving ability | 4 | Produced brute-force *and* optimal unprompted, and picked the better one for the right reason |
| Complexity analysis | 4 | O(n)/O(1) correct and justified; conflated selection sort with sorting-in-general, then self-corrected |
| Implementation (C++) | 4 | Working code, but 3 iterations to correct; sentinel handling needed guidance |
| Debugging | 3 | Identified the faulty branch when pointed at the loop, but did not find any failing input unaided |
| Communication | 3 | Terse, accurate answers; asked "what is a sentinel?" instead of bluffing — good instinct |
| Performance under time pressure | 0 | Not assessed — no timed work yet |

**Overall (S9):** Binary search derived from a guessing game in a few
questions, including the boundary decisions that usually cause bugs. LC 35 was
solved independently and the exit condition explained from the invariant.
Hedging is closed; the space drill went 4/4. What still slips is mechanical and
mostly in test files: an include, and a test outside a strict `<` bound. One
complexity value was wrong in a header (O(n) for a binary search).

**Previous (S8):** First Mastered problem (Move Zeroes, via transfer).
Prefix sums landed in one session: the monotonicity argument for why a window
fails, the complement form on prefix sums, and an independent Medium solved
with one hint — including choosing first-occurrence over latest without help
and explaining the difference. The complexity header is now a settled habit.
The new weakness is the *value* of space complexity for auxiliary structures,
wrong twice in opposite directions. Test hygiene slipped twice (non-fixed
seeds, a vector constructed with a size) after being solid for several sessions.

**Previous (S7):** First two Mediums, one fully independent and correct first
try. The variable window was derived from brute force through three ladder
steps, and the shrink condition was inverted for LC 209 without a hint — that
is pattern understanding, not recall. The complexity header is now written
before `check` (one value wrong). Recurring mechanical slips remain: missing
includes (eight) and a sentinel that collided with a legal answer (third
time). Amortized reasoning needed a nudge and is queued.

**Previous (S6):** Sliding window derived rather than taught: two questions
("which indices can matter?", "what enters and leaves?") and the pattern fell
out. The unsigned-wrap weakness is now closed in own code. The complexity
header is the one habit that keeps needing a reminder — it took three asks
this session, and in an interview that line is the first thing expected.

**Previous (S5):** Phase 1 underway. Recognition is the headline: 4/4 on cold
statements, and hashing transferred from Two Sum to Contains Duplicate II
without prompting. Test design keeps getting more deliberate — boundary tests
at scale, generators that guarantee the problem's own preconditions. The
recurring slips are all mechanical: includes (six now) and the complexity
header. They are cheap to fix and should not survive into interview practice.

**Previous (S4):** Phase 0 all but done. Debugging moved up: the Valid
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
| 9 | 2026-11-13 | Binary search: log₂ n from halving, sortedness as monotonicity, the inclusive invariant, `mid + 1` and `lo <= hi`, signed indices, overflow-safe midpoint, `lo` as the insertion point | LC 704 (guided), LC 35 (independent) | Both solved. Lesson: a scale test that only exercises one code path can't catch bugs in the other — search every gap, not just every element. Drills: space 4/4, recognition committed to one answer each. |
| 8 | 2026-11-12 | Prefix sums: why negatives break the window (monotonicity), `P[r+1] − P[l]`, complement lookup on prefix sums, the empty-prefix entry, what the map should store | LC 26 (transfer), LC 560 (guided), LC 525 (independent, Hint 1) | All solved. Move Zeroes → Mastered. Drills: amortized argument correct. Lesson: the map's value (count / first / latest) follows from what is being optimised. |
| 7 | 2026-11-09 | Sliding window (variable): grow right, shrink left; amortized O(n) for a `while` inside a `for`; longest-vs-shortest shrink conditions | LC 3 (guided, first Medium), LC 209 (independent Medium) | Both solved. Lesson: a sentinel equal to a legal answer needs two patches to work — remove the collision and both disappear. Drills: 4/4 on parameter-type decisions; hedged two recognition answers. |
| 6 | 2026-10-06 | Sliding window (fixed): which indices matter, enter/leave per step, window invariants, why reordering removed the `k == 0` special case. Function pointers, briefly, to run one test suite against two implementations | Contains Duplicate II, sliding-window version | Solved, O(min(n, k)) space. Refined to drop the special case. Drills: hash worst case right (missed rehashing), quadratic `erase` loop recognised as Move Zeroes. |
| 5 | 2026-09-30 | Hashing: direct addressing → hash function + buckets, collisions, why table size and key patterns interact, load factor and rehashing, average O(1) vs worst O(n) | Two Sum (LC 1, guided), Contains Duplicate II (LC 219, independent) | Both solved first try. Transfer succeeded unaided. Lesson: a test generator must guarantee the problem's preconditions, or a failure can't be trusted. |
| 4 | 2026-09-24 | References & pointers: value vs `&` vs `*`, hidden O(n) copies in by-value parameters, `const T&` as the default | Reverse String (LC 344), Valid Palindrome (LC 125, independent) | Both solved, O(n)/O(1). Palindrome crashed on `size_t` wrap-around; found and explained from one hint. Lesson: a test only catches a bug that would change its output. |
| 3 | 2026-09-24 | Strings: contiguous like vectors, `s = s + c` vs `s += c`, substr/compare costs, `c - 'a'` as an index, immutability in Java/Python | Valid Anagram (LC 242) | Solved first try, O(n)/O(1). Test file used `reserve` and `+=` unprompted, twenty minutes after learning why. |
| 2 | 2026-09-23 | Arrays in memory: address arithmetic, why indexing is O(1), insert/erase costs, vector size vs capacity, amortized O(1) | Move Zeroes (LC 283) | Solved, O(n)/O(1). Wrote tests before code. Key lesson: passing tests prove correctness, never complexity — the O(n²) version passed all 10. |
| 1 | 2026-09-23 | Big-O: counting, growth, O(1)/O(n)/O(n²), constants dropped | Second Largest (drill) | Solved in C++, 4 attempts. Complexity stated correctly unaided. Key lesson: a green suite proves only that the imagined cases pass. |
