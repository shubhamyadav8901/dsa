#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/arrays/move_zeroes.cpp"

// move_zeroes modifies its argument, so this helper takes a copy, runs the
// function on it, and hands the result back for comparison.
std::vector<int> moved(std::vector<int> v) {
    move_zeroes(v);
    return v;
}

int main() {
    // Write your test cases here BEFORE you write the solution.
    // Re-read the Constraints section of problems/0283-move-zeroes.md.
    // Every sentence in it is a test case waiting to be written.
    //
    CHECK_EQ(moved({0, 1, 0, 3, 12}), (std::vector<int>{1, 3, 12, 0, 0}));
    CHECK_EQ(moved({0, 0, 0, 0, 0, 0, 0, 0}), (std::vector<int>{0, 0, 0, 0, 0, 0, 0, 0}));
    CHECK_EQ(moved({1, 1, 2, 3, 12}), (std::vector<int>{1, 1, 2, 3, 12}));
    CHECK_EQ(moved({-1, 0, 2, -3, 0}), (std::vector<int>{-1, 2, -3, 0, 0}));
    CHECK_EQ(moved({-1, 2, -3, 0, 0, 0}), (std::vector<int>{-1, 2, -3, 0, 0, 0}));
    CHECK_EQ(moved({INT_MIN, 0, INT_MAX, 0, -1, 1, INT_MAX, 0, INT_MIN}),
             (std::vector<int>{INT_MIN, INT_MAX, -1, 1, INT_MAX, INT_MIN, 0, 0}));
    DSA_REPORT();
}
