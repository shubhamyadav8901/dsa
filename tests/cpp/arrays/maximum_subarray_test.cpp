#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/arrays/maximum_subarray.cpp"

#include <vector>
#include <numeric>

int main() {
    // For each test, a comment naming the bug it would catch.

    // examples
    CHECK_EQ(max_subarray({-2, 1, -3, 4, -1, 2, 1, -5, 4}), 6);
    CHECK_EQ(max_subarray({5, 4, -1, 7, 8}), 23);

    // nums.length = 1
    CHECK_EQ(max_subarray({1}), 1);

    // all negatives to check the sentinel
    CHECK_EQ(max_subarray({-6, -3, -1, -4, -3}), -1);

    // smoke test for extreme values
    CHECK_EQ(max_subarray({-10'000, 10'000, 0}), 10'000);
    CHECK_EQ(max_subarray({-10'000}), -10'000);

    // smoke test for nums.length = 100'000
    std::vector<int> v1;
    v1.insert(v1.end(), 10'000, 1);
    v1.insert(v1.end(), 10'000, -1);
    v1.insert(v1.end(), 10'000, 2);
    v1.insert(v1.end(), 10'000, -2);
    v1.insert(v1.end(), 10'000, 3);
    v1.insert(v1.end(), 10'000, -3);
    v1.insert(v1.end(), 10'000, 4);
    v1.insert(v1.end(), 10'000, -4);
    v1.insert(v1.end(), 10'000, 5);
    v1.insert(v1.end(), 10'000, -5);
    CHECK_EQ(v1.size(), 100'000u);
    CHECK_EQ(max_subarray(v1), 50'000);

    // case for largest possible sum
    std::vector<int> v2(100'000, 10'000);
    CHECK_EQ(max_subarray(v2), 1'000'000'000);

    // case for smallest possible sum
    std::vector<int> v3(100'000, -10'000);
    CHECK_EQ(max_subarray(v3), -10'000);

    DSA_REPORT();
}
