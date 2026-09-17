# DSA — Learning Environment

A workspace for learning Data Structures & Algorithms from scratch, with an AI
tutor that is instructed **not to solve problems for me**.

Primary language: **C++** (compiled as C++20). Python and Java are available as
reinforcement once a problem is already solved in C++.

## Start here

```
start DSA
```

Say that to the assistant. It reads `PROGRESS.md` and `ROADMAP.md` and picks
the next topic — never a random one. The first session is **Big-O + arrays +
basic problem solving**.

Verify the environment works first:

```sh
make test
```

You should see three `PASS` lines — one per language.

## Layout

```
.
├── AGENTS.md      the tutor contract — how the assistant must behave
├── CLAUDE.md      imports AGENTS.md so the rules auto-load
├── ROADMAP.md     Phase 0 → Phase 10, the order to learn in
├── PROGRESS.md    problem log, weak areas, revision queue, readiness
├── NOTES.md       my own notes, in my own words
├── Makefile       build + test runner
├── cpp/           C++ solutions, one folder per topic   ← primary
├── py/            Python solutions (reinforcement)
├── java/          Java solutions (reinforcement)
├── tests/         tests mirroring the same topic folders
├── problems/      problem statements, NNNN-slug.md
└── templates/     starting points for new solutions and tests
```

## Commands

```sh
make help                                # list everything
make run FILE=cpp/basics/hello_dsa.cpp   # compile + run one file
make run FILE=py/basics/hello_dsa.py     # works for .cpp, .py and .java
make test                                # every test, all three languages
make test L=cpp                          # one language  (cpp | py | java)
make test T=arrays                       # one topic
make test L=cpp T=arrays                 # both filters
make clean                               # delete build output
```

Every language runs even if an earlier one fails, so a broken C++ test never
hides a broken Python test. A misspelled `L=` or `T=` is rejected with the list
of valid values rather than silently passing.

C++ builds with `-std=c++20 -Wall -Wextra -g -fsanitize=address,undefined`.
The sanitizers are deliberate: they turn silent out-of-bounds reads and
signed-overflow bugs into loud, located crashes while you are still learning
where those happen.

## How a problem flows

1. The statement lands in `problems/NNNN-slug.md`, ending at `## Think`.
2. You think, out loud, before writing code. The tutor asks; it does not tell.
3. Copy `templates/solution.cpp` to `cpp/<topic>/<name>.cpp` and implement.
4. Copy `templates/test.cpp` to `tests/cpp/<topic>/<name>_test.cpp`.
5. `make test L=cpp T=<topic>` until green.
6. State the time and space complexity — before being told.
7. `PROGRESS.md` gets updated. Only then is it "Solved".

Optionally, afterwards: re-implement in Python or Java to see what the other
language's containers hide or expose.

## File conventions

| | Solution | Test |
|---|---|---|
| C++ | `cpp/<topic>/<snake_case>.cpp` | `tests/cpp/<topic>/<snake_case>_test.cpp` |
| Python | `py/<topic>/<snake_case>.py` | `tests/py/<topic>/test_<snake_case>.py` |
| Java | `java/<topic>/<PascalCase>.java` | `tests/java/<topic>/<PascalCase>Test.java` |

**The playground `main`.** Every solution file can be run on its own for
experimenting, without that interfering with its test:

- **C++** — the `main()` is wrapped in `#ifndef DSA_TEST`. The test file
  `#define`s `DSA_TEST` and then `#include`s the `.cpp`, so the playground
  `main` vanishes and the test's `main` is the only one left. One file per
  problem, no headers to keep in sync.
- **Python** — `if __name__ == "__main__":`. Importing the module skips it.
- **Java** — the test class has its own `main`; the solution's is simply never
  called. The runner strips the trailing `Test` from the class name to find the
  solution file, so `TwoSumTest.java` compiles against `java/<topic>/TwoSum.java`.

## Writing tests

No frameworks. `tests/cpp/dsa_test.hpp` and `tests/java/Check.java` are ~60
lines each and meant to be read; Python uses the standard library's `unittest`.

```cpp
CHECK_EQ(twoSum({2, 7, 11, 15}, 9), (std::vector<int>{0, 1}));
CHECK_TRUE(isPalindrome("racecar"));
DSA_REPORT();   // prints the summary, returns the exit code
```

Braced expected values need the extra parentheses — the preprocessor splits
macro arguments on commas.

```java
Check.eq(TwoSum.twoSum(new int[]{2, 7, 11, 15}, 9), new int[]{0, 1}, "basic case");
System.exit(Check.report("TwoSumTest"));
```

Every test should include the smallest input, an empty input, and the one edge
case you expect to get wrong.

## Requirements

Everything here is already installed on this machine and needs no `pip` or
Maven:

| | Found | Used for |
|---|---|---|
| Apple clang | 21.0.0 (C++20/23) | `make run`, `make test L=cpp` |
| Python | 3.13.5 | `make test L=py` (stdlib `unittest`) |
| JDK | 21 | `make test L=java` |
| GNU make | 3.81 | everything |

## The point

Not "complete 500 LeetCode problems". The loop is:

> Understand → Think → Attempt → Fail → Get Hint → Solve → Explain → Revisit → Master
