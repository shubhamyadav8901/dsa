#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/basics/second_largest.cpp"

int main() {
    // The four examples from the problem statement.
    CHECK_EQ(second_largest({3, 1, 4, 1, 5}), 4);
    CHECK_EQ(second_largest({7, 7, 7}), -1);
    CHECK_EQ(second_largest({2, 2, 9}), 2);
    CHECK_EQ(second_largest({10}), -1);
    CHECK_EQ(second_largest({3, 1, 4, 1, 6, 5}), 5);
    CHECK_EQ(second_largest({6, 1, 4, 1, 5}), 5);
    CHECK_EQ(second_largest({-6, -1, -4, -1, -5}), -4);
    CHECK_EQ(second_largest({-1, INT_MIN}), INT_MIN);

    // --- your cases -------------------------------------------------------
    // Add at least two of your own before you call this done. Re-read the
    // constraints and ask: which legal input would embarrass this code?
    //
    // CHECK_EQ(second_largest({...}), ...);

    DSA_REPORT();
}
