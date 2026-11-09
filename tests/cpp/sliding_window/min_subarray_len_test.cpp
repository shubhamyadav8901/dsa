#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/sliding_window/min_subarray_len.cpp"

#include <vector>

std::vector<int> get_large_vector(int length) {
    std::vector<int> vec(length, 0);
    for (int i = 0; i < length; i++)
        vec[i] = 10'000;

    return vec;
}

int main() {
    // question examples
    CHECK_EQ(min_subarray_len(7, {2, 3, 1, 2, 4, 3}), 2);
    CHECK_EQ(min_subarray_len(4, {1, 4, 4}), 1);
    CHECK_EQ(min_subarray_len(11, {1, 1, 1, 1, 1, 1}), 0);

    // length 1 array
    CHECK_EQ(min_subarray_len(4, {4}), 1);
    CHECK_EQ(min_subarray_len(4, {3}), 0);

    // target = 1 && nums[i] = 1
    CHECK_EQ(min_subarray_len(1, {4, 5, 1, 2}), 1);
    CHECK_EQ(min_subarray_len(1, {1}), 1);

    // target = 10^9
    CHECK_EQ(min_subarray_len(1'000'000'000, {3, 1, 2, 4, 3}), 0);

    // length 10^5 array & nums[i] = 10 ^ 4 & target = 10^9
    CHECK_EQ(min_subarray_len(1'000'000'000, get_large_vector(100'000)),
             100'000);
    CHECK_EQ(min_subarray_len(1, get_large_vector(100'000)), 1);

    DSA_REPORT();
}
