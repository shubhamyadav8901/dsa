"""hello_dsa.py - the shape every Python solution file in this repo follows.

1. The solution functions come first.
2. A playground block sits at the bottom under `if __name__ == "__main__":`.
   - `make run FILE=py/basics/hello_dsa.py` runs that block.
   - A test file imports this module, which skips the block automatically.
     Python gives you for free what C++ needs an #ifndef for.
"""


def sum_to_n_loop(n: int) -> int:
    """Adds 1 + 2 + ... + n one step at a time."""
    total = 0
    for i in range(1, n + 1):
        total += i
    return total


def sum_to_n_formula(n: int) -> int:
    """Same answer, computed in a fixed number of operations."""
    return n * (n + 1) // 2


if __name__ == "__main__":
    N = 10
    print(f"sum_to_n_loop({N})    = {sum_to_n_loop(N)}")
    print(f"sum_to_n_formula({N}) = {sum_to_n_formula(N)}")
    print("\nBoth print the same number. They do not do the same amount of work.")
