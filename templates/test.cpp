// Copy to: tests/cpp/<topic>/<snake_case_name>_test.cpp
// Run with: make test L=cpp T=<topic>

#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/<topic>/<snake_case_name>.cpp"

int main() {
    // Braced expected values need extra parentheses:
    //   CHECK_EQ(twoSum({2, 7, 11, 15}, 9), (std::vector<int>{0, 1}));

    CHECK_EQ(solve(), 0);

    // Always include: the smallest input, an empty input, and one edge case
    // you expect to get wrong.

    DSA_REPORT();
}
