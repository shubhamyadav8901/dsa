# ROADMAP — Beginner to Interview-Ready

Work top to bottom. Do not skip ahead because a later topic looks interesting;
every phase assumes the ones above it.

Legend: `[ ]` not started · `[~]` in progress · `[x]` solid · `[!]` weak, needs revisit

Each topic maps to a folder: `cpp/<folder>/` for solutions,
`tests/cpp/<folder>/` for tests.

---

## Phase 0 — Programming Fundamentals → `basics/`

The vocabulary everything else is written in.

- [x] Big-O notation — what it measures and what it ignores
- [x] Counting operations; growth when `n` doubles
- [~] Time vs space complexity — stated correctly once, needs repetition
- [ ] Arrays — memory layout, why indexing is O(1)
- [ ] Strings — and why they are not just arrays
- [ ] Functions, parameters, return values
- [ ] References (`&`) — pass by value vs pass by reference
- [ ] Pointers — addresses, dereferencing, `nullptr`
- [ ] STL: `vector`
- [ ] STL: `string`
- [ ] STL: `pair`
- [ ] STL: `map` vs `unordered_map`
- [ ] STL: `set` vs `unordered_set`
- [ ] STL: `stack`
- [ ] STL: `queue`, `deque`
- [ ] STL: `priority_queue`
- [ ] Sorting: `std::sort`
- [ ] Custom comparators (lambdas)
- [ ] Iterators — enough to read STL code

**Exit criteria:** you can state the complexity of a loop nest by inspection,
and pick the right STL container for a described need without looking it up.

## Phase 1 — Core Patterns → `arrays/ strings/ hashing/ two_pointers/ sliding_window/ binary_search/`

Where most interview problems actually live.

- [ ] Array traversal patterns
- [ ] Prefix sums
- [ ] Frequency counting
- [ ] Hashing — the idea, then `unordered_map`/`unordered_set`
- [ ] Two pointers — opposite ends
- [ ] Two pointers — fast/slow
- [ ] Sliding window — fixed size
- [ ] Sliding window — variable size
- [ ] Binary search on a sorted array
- [ ] Binary search on the answer space
- [ ] Sorting-based techniques
- [ ] String manipulation patterns

**Exit criteria:** given an unseen easy/medium array problem, you can name a
candidate pattern within a minute and justify the choice.

## Phase 2 — Linear Data Structures → `linked_list/ stack/ queue/`

- [ ] Singly linked list — build it by hand
- [ ] Traversal, insertion, deletion
- [ ] Reversal (iterative and recursive)
- [ ] Fast/slow pointers — cycle detection, middle node
- [ ] Doubly linked list
- [ ] Stack — concept, then implementation, then `std::stack`
- [ ] Queue — concept, implementation, `std::queue`
- [ ] Deque
- [ ] Monotonic stack
- [ ] Monotonic queue

**Exit criteria:** you can implement a linked list from scratch and explain when
a monotonic stack is the right tool.

## Phase 3 — Recursion → `recursion/ backtracking/`

The phase most people rush. Do not.

- [ ] Recursion fundamentals — base case, recursive case
- [ ] The call stack, drawn by hand
- [ ] Recursion trees
- [ ] Recurrence relations → complexity
- [ ] Recursion on arrays and strings
- [ ] Subsets / power set
- [ ] Subsequences
- [ ] Permutations
- [ ] Combination problems
- [ ] Backtracking template — choose, explore, un-choose
- [ ] Pruning

**Exit criteria:** you can draw the recursion tree for a backtracking problem
and read its complexity off the drawing.

## Phase 4 — Trees → `trees/ bst/`

- [ ] Binary tree structure and terminology
- [ ] Traversals: preorder, inorder, postorder
- [ ] Recursive vs iterative traversal
- [ ] Level-order traversal (BFS)
- [ ] DFS on trees
- [ ] Height and depth
- [ ] Diameter
- [ ] Path problems
- [ ] Lowest common ancestor
- [ ] Balanced trees — the property, and checking it
- [ ] BST — the invariant
- [ ] BST search, insert, delete
- [ ] BST validation
- [ ] Inorder traversal of a BST, and why it is sorted

**Exit criteria:** you reach for "what does this need from its children?" as the
default framing for a tree problem.

## Phase 5 — Heaps → `heap/`

- [ ] Heap property and the array representation
- [ ] Sift up / sift down, build-heap
- [ ] `priority_queue` and custom comparators
- [ ] Top-K problems
- [ ] K-way merge
- [ ] Two-heap median pattern

**Exit criteria:** you know why a heap beats sorting for Top-K, with the
complexities to prove it.

## Phase 6 — Graphs → `graphs/`

- [ ] Representations: adjacency list vs matrix
- [ ] Building a graph from input
- [ ] BFS
- [ ] DFS
- [ ] Connected components
- [ ] Grid problems as graphs
- [ ] Cycle detection — undirected
- [ ] Cycle detection — directed
- [ ] Topological sort (Kahn's, and DFS-based)
- [ ] Bipartite check / graph colouring
- [ ] Union-Find (DSU) with path compression and union by rank
- [ ] Shortest path in an unweighted graph
- [ ] Dijkstra
- [ ] Bellman-Ford, and why it tolerates negative edges
- [ ] Minimum spanning tree — Kruskal
- [ ] Minimum spanning tree — Prim

**Exit criteria:** you recognise a disguised graph problem (grids, word chains,
dependencies) without being told.

## Phase 7 — Greedy → `greedy/`

- [ ] What makes greedy valid — and how it fails
- [ ] Exchange argument proofs
- [ ] Interval problems
- [ ] Activity selection
- [ ] Scheduling
- [ ] Greedy with sorting
- [ ] Greedy vs DP — telling them apart

**Exit criteria:** you can construct a counterexample to a wrong greedy
strategy, not just feel uneasy about it.

## Phase 8 — Dynamic Programming → `dynamic_programming/`

Taught slowly and in this exact order. Every problem starts as recursion.

- [ ] Identifying overlapping subproblems
- [ ] Optimal substructure
- [ ] Recursion → memoization (top-down)
- [ ] Memoization → tabulation (bottom-up)
- [ ] Tabulation → space optimisation
- [ ] 1D DP — Fibonacci, climbing stairs, house robber
- [ ] 2D DP
- [ ] Grid DP — unique paths, min path sum
- [ ] 0/1 Knapsack
- [ ] Unbounded knapsack / coin change
- [ ] Subsequence DP
- [ ] LIS — O(n²), then O(n log n)
- [ ] LCS and its family
- [ ] String DP — edit distance
- [ ] Partition DP
- [ ] Interval DP — matrix chain multiplication
- [ ] DP on trees
- [ ] DP with bitmasks (intro)

**Exit criteria:** for a new DP problem you can state the state definition, the
transition, and the base case *before* writing code.

## Phase 9 — Advanced → `trie/ bit_manipulation/ advanced/`

- [ ] Trie — structure, insert, search, prefix search
- [ ] Trie applications — autocomplete, word search
- [ ] Bit manipulation — AND/OR/XOR/shifts
- [ ] Bit tricks — check/set/clear/count bits
- [ ] XOR problems
- [ ] Subsets via bitmask
- [ ] Prefix sum / Fenwick tree (BIT)
- [ ] Segment tree — build, query, update
- [ ] Lazy propagation (awareness)
- [ ] Advanced graph algorithms (SCC, bridges, articulation points)
- [ ] Advanced DP variants

**Exit criteria:** these are recognition-level, not fluency-level. Know when
they apply.

## Phase 10 — Interview Preparation

- [ ] Pattern recognition drills — problem → pattern, no coding
- [ ] Mixed problem sets with no topic label
- [ ] Timed sessions (30–45 min)
- [ ] Mock interviews with scoring
- [ ] Company-style question sets
- [ ] Systematic revision of every `[!]` item above
- [ ] Weak-area drilling
- [ ] Explaining solutions aloud, cleanly, in under 2 minutes

**Exit criteria:** an unseen medium solved and explained in 35 minutes,
repeatedly, not once.
