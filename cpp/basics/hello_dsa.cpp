// hello_dsa.cpp - the shape every C++ solution file in this repo follows.
//
// 1. The solution functions come first, with no main() around them.
// 2. A playground main() sits at the bottom, wrapped in #ifndef DSA_TEST.
//    - `make run FILE=cpp/basics/hello_dsa.cpp` compiles it and the main runs.
//    - The test file #defines DSA_TEST before including this file, so the
//      playground main disappears and the test's own main takes over.
//
// The two functions below compute the same thing at different costs - the
// question "how much work does this do?" is where Phase 0 starts.

#include <iostream>

// Adds 1 + 2 + ... + n one step at a time.
long long sum_to_n_loop(int n) {
    long long total = 0;
    for (int i = 1; i <= n; ++i) {
        total += i;
    }
    return total;
}

// Same answer, computed in a fixed number of operations.
long long sum_to_n_formula(int n) {
    return 1LL * n * (n + 1) / 2;
}

#ifndef DSA_TEST
int main() {
    const int n = 10;
    std::cout << "sum_to_n_loop(" << n << ")    = " << sum_to_n_loop(n) << "\n";
    std::cout << "sum_to_n_formula(" << n << ") = " << sum_to_n_formula(n)
              << "\n";
    std::cout << "\nBoth print the same number. They do not do the same amount "
                 "of work.\n";
    return 0;
}
#endif
