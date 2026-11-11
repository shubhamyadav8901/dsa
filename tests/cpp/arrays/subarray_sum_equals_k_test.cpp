#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/arrays/subarray_sum_equals_k.cpp"

#include <vector>

int main() {
    // Tests first. Comment what each one is for. Negatives, k = 0, and
    // subarrays that start at index 0 all deserve their own case.

    // examples
    CHECK_EQ(subarray_sum({1, 1, 1}, 2), 2);
    CHECK_EQ(subarray_sum({1, 2, 3}, 3), 2);
    CHECK_EQ(subarray_sum({1, -1, 1}, 1), 3);

    // negatives && subarrays starting at index 0
    CHECK_EQ(subarray_sum({-1, -5, -3, -2, -1, -3}, -6), 3);

    // length 1
    CHECK_EQ(subarray_sum({3}, 1), 0);
    CHECK_EQ(subarray_sum({3}, 3), 1);

    // upper and lower limit of nums[i] && k = 0
    CHECK_EQ(subarray_sum({1000, -1000, 1, -1, 1000}, 0), 4);

    // upper and lower limit of k
    CHECK_EQ(subarray_sum({1, 2, 3}, -10'000'000), 0);
    CHECK_EQ(subarray_sum({1, 2, 3}, 10'000'000), 0);

    // length 2 * 10'000 & upper/lower limit of k
    std::vector<int> vec1(2 * 10'000, 500);
    std::vector<int> vec2(2 * 10'000, -500);

    CHECK_EQ(subarray_sum(vec1, 10'000'000), 1);
    CHECK_EQ(subarray_sum(vec2, -10'000'000), 1);

    // length 2 * 10'000 & all 0's
    std::vector<int> vec3(2 * 10'000, 0);
    CHECK_EQ(subarray_sum(vec3, 0), 200010000);

    DSA_REPORT();
}
