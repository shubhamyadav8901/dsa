# PROGRESS

The tutor reads this file at the start of every session to decide what comes
next. Keep it honest — an inflated tracker produces a useless study plan.

- **Session count:** 7
- **Current phase:** Phase 1 — Core Patterns
- **Current topic:** Sliding window, variable size (done) → next: prefix sums — opens with "209 needed positive numbers; what breaks with negatives?"
- **Last session date:** 2026-11-09

---

## Problem Log

Status values: `Not Started` · `Learning` · `Attempted` · `Solved` ·
`Needs Revision` · `Mastered`

`Mastered` requires solving an *unseen variant* unaided — not recalling this
one.

| # | Problem | Topic | Difficulty | Status | Attempts | Lang | Pattern | Complexity | Notes |
|---|---------|-------|------------|--------|----------|------|---------|------------|-------|
| 10 | [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) (LC 209) | sliding_window | Medium | Solved | 2 | C++ ✓ / Py — / Java — | Variable window, shrink while **valid** | O(n) / O(1) | Independent Medium, correct first try; inverted LC 3's shrink condition unaided. First version used a sentinel equal to a legal answer (100,000), rescued by `<=` plus a flag; replaced with `nums.size() + 1`. Scale test hit three constraint bounds at once. |
| 9 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) (LC 3) | sliding_window | Medium | Solved | 2 | C++ ✓ / Py — / Java — | Variable window, shrink while **invalid** | O(n) / O(1) | First Medium. Derived O(n³) → O(n²) → O(n) step by step. Header first said O(n) space for a fixed 256-slot array; window length recomputed by scanning instead of `j - i + 1`; `unsigned char` cast applied to 2 of 3 index sites before the fix. |
| 8 | Contains Duplicate II — sliding-window version | sliding_window | Easy | Solved | 2 | C++ ✓ / Py — / Java — | Fixed-size sliding window over a hash set | O(n) / O(min(n, k)) | Derived the window from "which indices can matter?". First version needed a `k == 0` guard; reordering to insert-then-evict removed it. Avoided the `i - k` unsigned wrap unaided. Run against the map version on all 18 checks, and 400k random cases under ASan. |
| 7 | [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/) (LC 219) | hashing | Easy | Solved | 1 | C++ ✓ / Py — / Java — | Hash map value → latest index | O(n) / O(n) | Independent, correct first try — transferred Two Sum's map unaided. Tests pinned the `<=` boundary at scale (k = gap−1, gap, gap+1) and k=0 with adjacent duplicates. Included `<map>` instead of `<unordered_map>`. |
| 6 | [Two Sum](https://leetcode.com/problems/two-sum/) (LC 1) | hashing | Easy | Solved | 1 | C++ ✓ / Py — / Java — | Hash map complement lookup, check-before-insert | O(n) / O(n) | Guided: derived the complement and the key/value choice step by step. Scale generator guarantees a single pair by construction. One test was outside the constraints (target 2×10⁹); a duplicate-answer test was dropped during a fix and re-added. |
| 5 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) (LC 125) | strings | Easy | Solved | 2 | C++ ✓ / Py — / Java — | Two pointers, opposite ends, with skip-filtering | O(n) / O(1) | Independent problem. First version read out of bounds on `"a!"`: `size_t end` wrapped past 0. Found and explained it from one hint. Also shipped a check that could not fail (`CHECK_TRUE` on a string literal). Verified on 300k random strings under ASan. |
| 4 | [Reverse String](https://leetcode.com/problems/reverse-string/) (LC 344) | strings | Easy | Solved | 1 | C++ ✓ / Py — / Java — | Two pointers, opposite ends | O(n) / O(1) | Hand-written `swap_chars(char&, char&)`. By-value experiment failed 4/5 — the n=1 case passed, since reversing one element is a no-op. |
| 3 | [Valid Anagram](https://leetcode.com/problems/valid-anagram/) (LC 242) | strings | Easy | Solved | 1 | C++ ✓ / Py — / Java — | Sliding window, variable size | LC 3 (derived from brute force), then LC 209 unaided with the condition inverted | Contiguous subarray/substring, longest or shortest satisfying a condition. Right edge always advances; left edge advances only as far as it must. O(n) because each index enters and leaves once. Longest → shrink while invalid; shortest → shrink while valid. Needs a condition that is monotonic as the window grows (positive numbers in 209) |
| Sliding window, fixed size | Contains Duplicate II, derived from "which earlier indices can matter for position i?" | "Within distance k", "every window of size k". One element enters and one leaves per step, so update the window's summary in O(1) instead of rebuilding it in O(k) |
| Hash map for O(1) "have I seen X, and where?" | Two Sum (guided), then transferred unaided to Contains Duplicate II | The brute force's inner loop is *searching for one specific value* (a complement, a repeat). Store what you've seen, keyed by the value you'll look up, mapping to what you need back |
| Two pointers, opposite ends (converging) | Reverse String, then applied independently to Valid Palindrome | Symmetric comparison or in-place reversal. Pointers start at both ends and move inward; stop when they meet — decide the `<` vs `<=` on purpose |
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
| Relying on transitive includes | `<climits>` ×2, `<algorithm>` ×2, `<unordered_map>` ×2 (once the wrong header, `<map>`), `<vector>` ×2 (S7, once in a test file) | 8 | Active — enforced in Rule 6, still recurring every session |
| Hedging between two patterns | S7 recognition: answered (b) and (d) with "fixed array / hash" | 1 | New — commit to one, name the deciding constraint (is the key range small and known?) |
| Leaving the complexity header as `O(?)` | Four problems filled only when asked. S7: filled before `check` on both problems — one value wrong (O(n) space for a fixed array) | 4 | **Improving** — the habit landed; accuracy next |
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
| Move Zeroes → dedupe-sorted-array | Transfer | — | **8 — opens the session** | Deferred twice; promised as the first thing in S8 |
| Amortized analysis — why a `while` inside a `for` can still be O(n) | Recall | 7 | 8 | First answer ("bounded by j") gave O(n²); needed the "total moves of i" nudge |
| Cold statements, including fixed-array vs hash decisions | Recall (recognition) | 7 | 9 | Hedged on two; check the key-range rule stuck |
| Valid Anagram → group anagrams (now a hashing problem) | Transfer | — | 9 | Combines frequency counting with a hash map key |
| Sentinel inside the legal range | Attack | 7 | 9 | Third occurrence across sessions |
| Window invariants — what the window holds, why erase-by-value is safe | Recall | 6 | 9 | Check it survives a few sessions |
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

**Overall (S7):** First two Mediums, one fully independent and correct first
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
| 7 | 2026-11-09 | Sliding window (variable): grow right, shrink left; amortized O(n) for a `while` inside a `for`; longest-vs-shortest shrink conditions | LC 3 (guided, first Medium), LC 209 (independent Medium) | Both solved. Lesson: a sentinel equal to a legal answer needs two patches to work — remove the collision and both disappear. Drills: 4/4 on parameter-type decisions; hedged two recognition answers. |
| 6 | 2026-10-06 | Sliding window (fixed): which indices matter, enter/leave per step, window invariants, why reordering removed the `k == 0` special case. Function pointers, briefly, to run one test suite against two implementations | Contains Duplicate II, sliding-window version | Solved, O(min(n, k)) space. Refined to drop the special case. Drills: hash worst case right (missed rehashing), quadratic `erase` loop recognised as Move Zeroes. |
| 5 | 2026-09-30 | Hashing: direct addressing → hash function + buckets, collisions, why table size and key patterns interact, load factor and rehashing, average O(1) vs worst O(n) | Two Sum (LC 1, guided), Contains Duplicate II (LC 219, independent) | Both solved first try. Transfer succeeded unaided. Lesson: a test generator must guarantee the problem's preconditions, or a failure can't be trusted. |
| 4 | 2026-09-24 | References & pointers: value vs `&` vs `*`, hidden O(n) copies in by-value parameters, `const T&` as the default | Reverse String (LC 344), Valid Palindrome (LC 125, independent) | Both solved, O(n)/O(1). Palindrome crashed on `size_t` wrap-around; found and explained from one hint. Lesson: a test only catches a bug that would change its output. |
| 3 | 2026-09-24 | Strings: contiguous like vectors, `s = s + c` vs `s += c`, substr/compare costs, `c - 'a'` as an index, immutability in Java/Python | Valid Anagram (LC 242) | Solved first try, O(n)/O(1). Test file used `reserve` and `+=` unprompted, twenty minutes after learning why. |
| 2 | 2026-09-23 | Arrays in memory: address arithmetic, why indexing is O(1), insert/erase costs, vector size vs capacity, amortized O(1) | Move Zeroes (LC 283) | Solved, O(n)/O(1). Wrote tests before code. Key lesson: passing tests prove correctness, never complexity — the O(n²) version passed all 10. |
| 1 | 2026-09-23 | Big-O: counting, growth, O(1)/O(n)/O(n²), constants dropped | Second Largest (drill) | Solved in C++, 4 attempts. Complexity stated correctly unaided. Key lesson: a green suite proves only that the imagined cases pass. |
