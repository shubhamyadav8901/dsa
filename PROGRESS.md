# PROGRESS

The tutor reads this file at the start of every session to decide what comes
next. Keep it honest — an inflated tracker produces a useless study plan.

- **Session count:** 14
- **Current phase:** Phase 1 — Core Patterns
- **Current topic:** Array traversal: prefix + suffix passes (done) → next: index-as-hash (LC 448), then voting, 2D traversal; then the Phase 1 wrap-up — a mixed cold-recognition set, plus `pair` and ordered `map`/`set`; then Phase 2 (linked lists)
- **Last session date:** 2026-11-22

---

## Problem Log

Status values: `Not Started` · `Learning` · `Attempted` · `Solved` ·
`Needs Revision` · `Mastered`

`Mastered` requires solving an *unseen variant* unaided — not recalling this
one.

| # | Problem | Topic | Difficulty | Status | Attempts | Lang | Pattern | Complexity | Notes |
|---|---------|-------|------------|--------|----------|------|---------|------------|-------|
| 26 | [Minimum Penalty for a Shop](https://leetcode.com/problems/minimum-penalty-for-a-shop/) (LC 2483) | strings | Medium | Solved | 1 | C++ ✓ / Py — / Java — | One pass, running score (prefix form) | O(n) / O(1) | Independent, no hints. Found the single-pass score (Y − N over open hours) unaided instead of two passes. Seeded `max = -1`, below closing-at-0's real score of 0: `"NY"` returned 2. The tutor's random test found it, not the boilerplate; fixed, and added `"NY"`/`"YN"`. Missed `<cstddef>`; implicit `size_t` → `int`. |
| 25 | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) (LC 238) | arrays | Medium | Solved | 1 | C++ ✓ / Py — / Java — | Prefix + suffix passes | O(n) / O(1) extra | Guided. Identity 1 for an empty side derived with a *because*; O(1)-extra plan (left pass into the output, right pass in one variable) proposed unaided and coded first try. `int i = nums.size() - 2` (convert after subtracting). Special cases: "none" without a reason. |
| 24 | [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) (LC 152) | arrays | Medium | Solved | 1 | C++ ✓ / Py — / Java — | Best ending here, carrying max *and* min | O(n) / O(1) | Independent with **Hints 1 and 2**. Saw by hand that the LC 53 rule fails on `[-2, 3, -4]` before coding. First version allocated a vector per iteration; the rewrite to `std::max({…})`/`std::min({…})` read the already-updated best and went red on the all-negative tests; fixed by saving the previous value. |
| 23 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) (LC 53) | arrays | Medium | Solved | 1 | C++ ✓ / Py — / Java — | Best ending here (Kadane) | O(n) / O(1) | Guided. Derived `end[i] = max(end[i-1] + a[i], a[i])` from a hand-filled table, and why a negative prefix is dropped. Avoided the `best = 0` sentinel unprompted. Bounded the sums to [−10⁴, 10⁹] for `int`. Missed `<cstddef>`; a scale test used values ±50,000 (outside constraints), then `vector(n)` + inserts doubled it to 200,000. |
| 22 | [String Compression](https://leetcode.com/problems/string-compression/) (LC 443) | strings | Medium | Solved | 1 | C++ ✓ / Py — / Java — | Run scanning + write-behind pointer | O(n) / O(1) | Independent, no hints, first try. Transferred run scanning and `i = j` unprompted. Explained why the write index can't pass unread input (a run never writes more than it occupies) and why `to_string` is O(1) here (≤ 4 digits), both with a *because* on the first ask. Tests included a digit run followed by a count digit, and a 4-digit count. |
| 21 | [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/) (LC 151) | strings | Medium | Solved | 1 | C++ ✓ / Py — / Java — | Run scanning, from the end | O(n) / O(1) beyond output | Guided. Planned direct appends with O(1) extra, then wrote a `temp` + `reverse` version (O(n) for one long word, header said O(1), flush duplicated after the loop); rewritten to the plan. The "10^4" test was a copy of example 3; a "check space complexity" comment on a test that cannot see space. Test file missed `<string>`; an unused `<algorithm>` was left behind. |
| 20 | [Sort Array by Increasing Frequency](https://leetcode.com/problems/sort-array-by-increasing-frequency/) (LC 1636) | arrays | Easy | Solved | 1 | C++ ✓ / Py — / Java — | Count, then sort with a capturing multi-key comparator | O(n log n) / O(n) | Independent, no hints. Chose a 201-slot offset array over a hash map from the constraints. Magic `100`/`201` named on request. Length-100 test was all one value (could not fail for any ordering bug); replaced with both extremes at a tied frequency. Header said O(1) space for a copied input; corrected, reason given when asked. |
| 19 | [Merge Intervals](https://leetcode.com/problems/merge-intervals/) (LC 56) | arrays | Medium | Solved | 1 | C++ ✓ / Py — / Java — | Sort by start, then one sweep with a current block | O(n log n) / O(n) | Guided. Wrote the overlap test with `\|\|` instead of `&&`; fixed from one counterexample. `max` for the end derived unaided. Comparator took vectors by value (copies per comparison). The asked-for test that fails without `max` was missing — a mutation passed all 11 checks. Dropped an unneeded end tie-breaker; the *why* took a second ask. |
| 18 | [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/) (LC 875) | binary_search | Medium | Solved | 1 | C++ ✓ / Py — / Java — | Binary search on the answer space — **first** true | O(n log m) / O(1) | Independent, no hints; returned `lo` as the mirror of Sqrt(x)'s `hi`. `int hours` fits only because the search never tries speeds far below the answer; justified it with the wrong reason (division) before switching to `long long`. |
| 17 | [Sqrt(x)](https://leetcode.com/problems/sqrtx/) (LC 69) | binary_search | Easy | Solved | 1 | C++ ✓ / Py — / Java — | Binary search on the answer space — **last** true | O(log x) / O(1) | Guided. Anticipated the `mid * mid` overflow; used `long` (4 bytes on Windows) before `long long`. Header left as `O(?)`. A 21.5M-iteration loop made the suite slow; a range above the last square could not catch an off-by-one. Final tests: every x to 10⁶, r² ± 1 up to 46,340. |
| 16 | [Group Anagrams](https://leetcode.com/problems/group-anagrams/) (LC 49) | hashing | Medium | Solved | 1 | C++ ✓ / Py — / Java — | Canonical key (letter counts) + hash map | O(nk) / O(nk) | Transfer drill combining Valid Anagram and Two Sum, no hints. Count-signature key with letters as separators, O(k) per string. Copied each string by value in the loop at first. |
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
| 3 | [Valid Anagram](https://leetcode.com/problems/valid-anagram/) (LC 242) | strings | Easy | **Mastered** | 1 | C++ ✓ / Py — / Java — | Binary search on the answer space | Sqrt(x) guided from "write out ok(0), ok(1), …", then Koko independently | No sorted array, but a yes/no question about a candidate answer that flips exactly once (T…TF…F or F…FT…T). Search the range of answers; return `hi` for the last T, `lo` for the first T. Watch the type of whatever the predicate computes |
| Binary search on a sorted array | LC 704 (guided from a guessing game), LC 35 independently | Sorted/monotonic data and a "where is X?" question. Invariant: the target, if present, is in `[lo, hi]`. Loop `while lo <= hi`, step past `mid`. At exit `lo = hi + 1` is the insertion point. Signed indices; `lo + (hi − lo) / 2` |
| Prefix sums | LC 560 (guided), then LC 525 independently with a value transform | Subarray sums when a window can't work (negatives break monotonicity). `sum(l..r) = P[r+1] − P[l]`; for "sum equals k", look up `P − k` in a map seeded with the empty prefix. The map's value depends on the goal: count (how many), first index (longest), latest index (closest) |
| Sliding window, variable size | LC 3 (derived from brute force), then LC 209 unaided with the condition inverted | Contiguous subarray/substring, longest or shortest satisfying a condition. Right edge always advances; left edge advances only as far as it must. O(n) because each index enters and leaves once. Longest → shrink while invalid; shortest → shrink while valid. Needs a condition that is monotonic as the window grows (positive numbers in 209) |
| Sliding window, fixed size | Contains Duplicate II, derived from "which earlier indices can matter for position i?" | "Within distance k", "every window of size k". One element enters and one leaves per step, so update the window's summary in O(1) instead of rebuilding it in O(k) |
| Hash map for O(1) "have I seen X, and where?" | Two Sum (guided), then transferred unaided to Contains Duplicate II | The brute force's inner loop is *searching for one specific value* (a complement, a repeat). Store what you've seen, keyed by the value you'll look up, mapping to what you need back |
| Two pointers, opposite ends (converging) | Reverse String, then applied independently to Valid Palindrome | Symmetric comparison or in-place reversal. Pointers start at both ends and move inward; stop when they meet — decide the `<` vs `<=` on purpose |
| Frequency counting with a fixed-size array | O(n) / O(1) | Correct first try, single count array. Tests included a 50k scale test with fixed seeds. Verified on 400k random pairs vs a sorting reference. **Mastered S10** via transfer to LC 49. |
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
| Relying on transitive includes | `<climits>` ×3, `<algorithm>` ×5, `<unordered_map>` ×3 (once `<map>` instead), `<vector>` ×2, `<cmath>` ×1. S11: none missing across four files, `<cstddef>` added unprompted. S12: `<string>` missing from a test file; an unused `<algorithm>` left after a rewrite. S13: `<cstddef>` for `size_t` (LC 53); LC 152 clean. S14: `<cstddef>` again (LC 2483); LC 238 clean | 17 | Active — `<cstddef>` for `size_t` is now the usual miss |
| Integer type widths | S10: `long` used twice for 64-bit arithmetic; it is 4 bytes on Windows | 2 | New — use `long long` (or `int64_t`) whenever the value needs 64 bits |
| Tests that cannot fail for the bug they target | S9: every-element loop never reached `return lo`. S10: a range above the last perfect square, every answer identical. S11: no test failed without `max` (LC 56) even though one was asked for; a length-100 test of one repeated value (LC 1636). S12: a "10^4" test that was a 16-character copy of an example; a comment claiming a test checked space complexity; bug-naming comments took two asks. Then named the real bug behind the case/digit tests, and passed the Attack drill (`{2,2,2}`) | 5 | Active — S13: comments still named categories ("all negative", "smoke") until given wording. **Test split agreed S13:** tutor writes boilerplate (examples, bounds, max size); learner writes special cases with a `catches:` comment |
| Seeding "best so far" with a value no candidate has | S13: avoided it (`nums[0]`). S14: `max = -1` in LC 2483 when closing at hour 0 scores 0 | 1 | New — seed from an actual candidate's value |
| Right conclusion, wrong reason | S10: "Koko's int is safe because we divide first" — division bounds each term, not the total. S11: `lo < hi` fails "because the invariant doesn't hold" — it holds; one element is left unclassified | 2 | Active — check the reason against a counterexample |
| Tests outside the constraints | S5: target 2×10⁹. S8: a 150,000-element vector. S9: ±10,000 under a strict `<`. S13: `iota` from −50,000 under `abs(nums[i]) <= 10^4`, then a 200,000-element vector | 5 | Active — check `<` vs `<=` when turning a bound into a test |
| Hedging between two patterns | S7: answered two with "fixed array / hash". S9: one answer each | 1 | **Closed** |
| Leaving the complexity header as `O(?)` | Four problems filled only when asked. S7 and S8: filled before `check` every time | 4 | **Closed** — habit established across five problems |
| Complexity *values* (the header is written; the number is wrong) | S7: O(n) space for a fixed array. S8: O(1) for a growing map. S9: drill 4/4 on space — then O(n) *time* on LC 35. S11: O(1) space for a by-value copy (LC 1636), O(n) for the same thing an hour earlier (LC 56). S12: O(1) for the `temp` version of LC 151 — found the O(n) input when asked | 5 | Improving — space now right under questioning; check the value against the loop before `check` |
| Unsigned arithmetic near zero | S4: crashed on `end--` past 0. S5: found both bugs in an Attack drill. S6: `nums[i - k]` guarded by `i >= k` in own code, unprompted | 1 | **Closed** — proven in own code |
| Mapping a spotted trigger to the right pattern | S4: swapped two mappings. S5: 4/4 on cold statements, each tied to a solved problem | 1 | **Closing** — one clean pass |
| Code drifting from the described approach | Described an O(n) monotonic scan, wrote an O(n²) resetting one, and did not notice. S12: described direct appends with O(1) extra, wrote `temp` + `reverse` | 2 | Active — re-read the code against the sentence that described it before `check` |
| Choosing test cases that attack your own code | S1: skipped own cases, 3 bugs survived. S2: wrote 6 cases unprompted incl. negatives and INT_MIN, missed only n=1 | 3 | **Improving fast** — keep drilling |
| Representing absence (sentinels vs flags) | Chose `second = largest`, then `-1`, then `INT_MIN`; each collided with legal data. S11 Attack drill: found `{INT_MAX}` and named the rule unaided | 3 | Improving — Attack passed; one more clean pass to close |
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
| Constructing a vector with a size when meaning to reserve | S8: `std::vector<int> v(n)` then `insert`, giving n extra zeros and a test outside the constraints. S13: the same, 100,000 + 100,000; found from a size assert | 2 | `vector(n)` creates n elements; `reserve(n)` creates none. Assert the size of generated input |
| A fix applied to some sites but not all | S7: `unsigned char` cast on 2 of 3 `arr[...]` indexes | 1 | Apply a fix by searching for every site, or read the value once into a correctly typed variable |
| Reading only the value constraints, never the size constraint | `1 <= n <= 10^4` means "write a test at scale", and it was skipped | 1 | Size bounds are a performance test. Time it, don't assume it |
| Stale comments left after a refactor | `// TODO` in three files; S6: a commented-out `// if (k == 0) return false;` | 4 | Delete the comment in the same edit that invalidates it — commented-out code included |
| Answering *what* when asked *why* | S2, S6, then S10 twice: listed what each map stored without why; said `hi` holds the answer without why. S11: "it would work without the tie-breaker"; changed O(1) → O(n) with no reason. S12: "the total is n" for the nested-while bound. Against that: three drills and both LC 443 questions answered with a *because* on the first ask. S14: recognition drill gave three answers with no *because*; (c)'s then restated monotonicity; "none" for special cases without a reason | 8 | Active — when a question says "why", the answer needs "because" |
| Decrementing an unsigned index past zero | `end--` on a `size_t` holding 0 wrapped to SIZE_MAX, then indexed | 1 | Check `start >= end` *before* moving pointers, or use a signed index when it can go below 0 |
| A test that asserts something other than the function's result | `CHECK_TRUE("ABCDEedcba")` — a literal is a non-null pointer, always true | 1 | For every test, ask: what bug would make this fail? |
| Updating two state variables in sequence when both need the old values | LC 152: `worst` computed from the already-updated `best` | 1 | Compute every new value from the old ones first (save the old value, or compute candidates into locals), then assign |
| Using a symbol without including its header | `INT_MIN` without `<climits>`, `std::shuffle` without `<algorithm>` | 3 | Every symbol needs its own header, every time |

---

## Patterns Learned

A pattern is listed here only once I have recognised it unprompted in a problem
I had not seen before.

| Pattern | Recognised on | Trigger — when to reach for it |
|---------|---------------|--------------------------------|
| Prefix + suffix passes | LC 238 guided (O(1)-extra plan unaided); LC 2483 independently, collapsed to one pass with a running score | "For each index, something about everything except me" or "everything before vs after a split point". One sweep carries the left summary, one the right; start each side at the operation's identity (0 for sums, 1 for products). When the total is fixed, before/after collapses into one running score |
| Best ending here (Kadane) | LC 53 guided from a hand-filled `end[i]` table; LC 152 with Hints 1–2 (carry max and min) | Best contiguous piece (sum, product, streak). Every piece ends somewhere, so compute the best piece ending at each i from the one ending at i − 1: extend it or start fresh. Answer = max over i. Seed from `nums[0]`, not 0. Carry whatever a later element could flip into the best — the minimum, when negatives multiply |
| Run scanning (groups of neighbouring characters) | LC 151 guided (mirrored from the end); LC 443 independently with a write-behind pointer | Words between delimiters, runs of equal characters, digit groups. Outer loop finds a group's start, inner loop extends `j` to one past its end, handle `[i, j)`, then `i = j`. O(n) because `i = j` means no index is scanned twice — `++i` there is O(n²) *and* wrong. Handle each group when found, so no flush after the loop |
| Sort with a custom comparator (then sweep) | LC 56 guided; LC 1636 independently, including a capturing multi-key comparator | Order matters and the input is unordered: after sorting, only neighbours can interact (intervals), or the output *is* an order defined by a rule. Comparator returns true only if a goes strictly before b — `<=` is undefined behaviour. Ties: add a second key, or `stable_sort` for input order. Cost: O(n log n) × one comparison, so take arguments by `const&` |
| Single-pass running extremum (track best + second-best in variables) | Second Largest — derived unaided, before being shown anything | "Find the best/worst k items" where k is tiny and fixed. Beats sorting: O(n) vs O(n log n) |
| Binary search on the answer space | Sqrt(x) guided from "write out ok(0), ok(1), …", then Koko independently | No sorted array, but a yes/no question about a candidate answer that flips exactly once (T…TF…F or F…FT…T). Search the range of answers; return `hi` for the last T, `lo` for the first T. Watch the type of whatever the predicate computes |
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
| Recognise a monotonic yes/no question in a cold statement — with the *because* | Recall (recognition) | 14 | 15 | S14: 3/3 patterns, but no reasons until asked; (c)'s reason restated the definition |
| Second Largest from a blank file | Re-implement | 1 | 16 | Deferred from S13 (too long for a warm-up) |
| Sentinel inside the legal range | Attack | 11 | 14 | Passed S11; one more to close |
| Intervals after sorting (e.g. LC 57 Insert Interval / LC 435) | Transfer | 11 | 15 | Merge Intervals was guided — check it generalises |
| A test that can't fail for its bug — in *own* tests: name the bug per test, no prompt | Constraints-to-tests | 12 | 15 | Attack passes; own tests still don't |
| Run scanning on an unseen problem (e.g. LC 1446 / LC 38) | Transfer | 12 | 15 | Check it generalises past words and equal-character runs |
| Simultaneous update — spot a state pair updated in sequence | Attack | 14 | 17 | S14: found `{1, 2}` → 3; blamed the symptom line, not the line reading the new value |
| Best ending here on an unseen problem (e.g. LC 121 / LC 918) | Transfer | 13 | 16 | LC 152 needed two hints |

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

**Overall (S14):** Prefix + suffix passes were picked up from one worked
table: the left recurrence, the identity for an empty side, and the O(1)-extra
plan all came unaided, and LC 238 was correct first try. The independent
Medium (LC 2483) went further, finding a single running-score pass without
hints. It shipped with a seed bug, starting best at -1 below a real candidate,
that the boilerplate tests missed and a random test caught. Recognition was
3/3 on patterns, but every *because* had to be asked for. Includes:
`<cstddef>` again. Agreed this session: the tutor writes boilerplate tests,
and a `make test N=` filter was added.

**Previous (S13):** Kadane was derived, not shown: a hand-filled `end[i]`
table gave the recurrence, and the reason for dropping a negative prefix came
with a *because* on the first ask, as did the `best = 0` trap and the `int`
bound. The independent Medium (LC 152) needed Hints 1 and 2, which is
reasonable for its twist, and the learner predicted by hand that the LC 53
rule would fail before writing code. Test hygiene slipped again: a scale test
outside the value constraints, then the `vector(n)` + insert mistake from
S8. A test split was agreed, so boilerplate tests are now the tutor's.
Recognition: 2/3 cold, mislabelling a binary-search-on-answer problem as a
sliding window.

**Previous (S12):** String run scanning landed in one step and transferred
immediately: LC 443, an independent Medium, was solved first try with no
hints, and both "why" questions about it got a correct *because* on the first
ask — as did all three warm-up drills, including the Attack on a test suite
that could not fail. The gap is between plan and code and around tests: LC
151's first version did not match the approach just described, its header
space was wrong, a "max size" test was a copy of an example, and a comment
claimed a test checked space. Includes slipped once after a clean session.

**Previous (S11):** Sorting with custom comparators landed quickly: the
strict-ordering contract and the `<=` contradiction were answered in one step,
and LC 1636 was solved independently first try with a capturing multi-key
comparator and an offset array chosen from the constraints. No missing
includes for the first time. What keeps recurring is rigour around the
answer, not the answer itself: a requested failing test was absent (a mutation
passed every check), a scale test could not fail, one space value
contradicted the previous problem's, and "why" questions still get a "what"
first.

**Previous (S10):** Second Mastered (Valid Anagram, via Group Anagrams).
Binary search on the answer space landed fast: the T…TF…F picture was derived
in one question, and Koko — an independent Medium — was solved with the
correct mirror boundary. Reasoning is ahead of rigour: the conclusion was
right but the justification wrong (Koko's overflow), two "why" questions were
answered with "what", and test edge-cases needed shaping twice (a slow suite,
a range that could not fail). Includes still slip every session.

**Previous (S9):** Binary search derived from a guessing game in a few
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
| 14 | 2026-11-22 | Array traversal — prefix + suffix passes: "everything except me" = left side + right side, the O(1) left recurrence, identity for an empty side, output array as one pass's storage; collapsing before/after into one running score | LC 238 (guided), LC 2483 (independent) | Both solved, no hints. Drills: recognition 3/3 patterns with reasons only on request; paired-state Attack found the input. Lesson: seed "best" from a real candidate. |
| 13 | 2026-11-21 | Array traversal — best ending here: the `end[i]` table, extend vs start fresh, why a negative prefix is dropped, seeding from `nums[0]`, bounding sums for `int`; carrying max *and* min when negatives multiply; computing a state pair from the old values | LC 53 (guided), LC 152 (independent, Hints 1–2) | Both solved. Drills: comparator 2/2; recognition 2/3 cold (3/3 after a nudge). Lesson: assert the size of generated test input; update paired state from the old values. Test split agreed — tutor writes boilerplate tests. |
| 12 | 2026-11-18 | String run scanning: find a group's start, extend to one past its end, jump `i = j`; why the nested while is O(n); half-open `[i, j)` ranges; separator before every word but the first; writing behind the read index in place | LC 151 (guided), LC 443 (independent) | Both solved. Drills 3/3 with *because* (test Attack, `lo < hi`, window invariants). Lesson: re-read the code against the plan you stated; a comment on a test must name a bug the test can actually see. |
| 11 | 2026-11-16 | Sorting with custom comparators: the comparator as "should a go before b?", strict ordering and why `<=` is undefined behaviour, equivalent elements and stability, tie-break keys, lambda captures; sorting so only neighbours interact | LC 56 (guided), LC 1636 (independent) | Both solved. Drills: sentinel Attack passed; BS boundaries 2/3 — `lo < hi` needed a trace. Lesson: run the mutation you asked a test to catch. |
| 10 | 2026-11-15 | Binary search on the answer space: monotonic predicates, first T vs last T, returning `lo` or `hi`, overflow in the predicate, `long` vs `long long` | LC 49 (transfer), LC 69 (guided), LC 875 (independent) | All solved. Valid Anagram → Mastered. Lessons: a test must be able to fail for the bug it targets; a slow suite stops getting run; check a reason against a counterexample. |
| 9 | 2026-11-13 | Binary search: log₂ n from halving, sortedness as monotonicity, the inclusive invariant, `mid + 1` and `lo <= hi`, signed indices, overflow-safe midpoint, `lo` as the insertion point | LC 704 (guided), LC 35 (independent) | Both solved. Lesson: a scale test that only exercises one code path can't catch bugs in the other — search every gap, not just every element. Drills: space 4/4, recognition committed to one answer each. |
| 8 | 2026-11-12 | Prefix sums: why negatives break the window (monotonicity), `P[r+1] − P[l]`, complement lookup on prefix sums, the empty-prefix entry, what the map should store | LC 26 (transfer), LC 560 (guided), LC 525 (independent, Hint 1) | All solved. Move Zeroes → Mastered. Drills: amortized argument correct. Lesson: the map's value (count / first / latest) follows from what is being optimised. |
| 7 | 2026-11-09 | Sliding window (variable): grow right, shrink left; amortized O(n) for a `while` inside a `for`; longest-vs-shortest shrink conditions | LC 3 (guided, first Medium), LC 209 (independent Medium) | Both solved. Lesson: a sentinel equal to a legal answer needs two patches to work — remove the collision and both disappear. Drills: 4/4 on parameter-type decisions; hedged two recognition answers. |
| 6 | 2026-10-06 | Sliding window (fixed): which indices matter, enter/leave per step, window invariants, why reordering removed the `k == 0` special case. Function pointers, briefly, to run one test suite against two implementations | Contains Duplicate II, sliding-window version | Solved, O(min(n, k)) space. Refined to drop the special case. Drills: hash worst case right (missed rehashing), quadratic `erase` loop recognised as Move Zeroes. |
| 5 | 2026-09-30 | Hashing: direct addressing → hash function + buckets, collisions, why table size and key patterns interact, load factor and rehashing, average O(1) vs worst O(n) | Two Sum (LC 1, guided), Contains Duplicate II (LC 219, independent) | Both solved first try. Transfer succeeded unaided. Lesson: a test generator must guarantee the problem's preconditions, or a failure can't be trusted. |
| 4 | 2026-09-24 | References & pointers: value vs `&` vs `*`, hidden O(n) copies in by-value parameters, `const T&` as the default | Reverse String (LC 344), Valid Palindrome (LC 125, independent) | Both solved, O(n)/O(1). Palindrome crashed on `size_t` wrap-around; found and explained from one hint. Lesson: a test only catches a bug that would change its output. |
| 3 | 2026-09-24 | Strings: contiguous like vectors, `s = s + c` vs `s += c`, substr/compare costs, `c - 'a'` as an index, immutability in Java/Python | Valid Anagram (LC 242) | Solved first try, O(n)/O(1). Test file used `reserve` and `+=` unprompted, twenty minutes after learning why. |
| 2 | 2026-09-23 | Arrays in memory: address arithmetic, why indexing is O(1), insert/erase costs, vector size vs capacity, amortized O(1) | Move Zeroes (LC 283) | Solved, O(n)/O(1). Wrote tests before code. Key lesson: passing tests prove correctness, never complexity — the O(n²) version passed all 10. |
| 1 | 2026-09-23 | Big-O: counting, growth, O(1)/O(n)/O(n²), constants dropped | Second Largest (drill) | Solved in C++, 4 attempts. Complexity stated correctly unaided. Key lesson: a green suite proves only that the imagined cases pass. |
