#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/arrays/find_duplicates.cpp"

#include <algorithm>
#include <cstddef>
#include <numeric>
#include <vector>

// The answer may come back in any order, so tests compare it sorted.
std::vector<int> sorted_duplicates(std::vector<int>& nums) {
    std::vector<int> result = find_duplicates(nums);
    std::sort(result.begin(), result.end());
    return result;
}

int main() {
    // Boilerplate (tutor)

    // catches: the examples from the statement
    std::vector<int> example1 = {4, 3, 2, 7, 8, 2, 3, 1};
    CHECK_EQ(sorted_duplicates(example1), (std::vector<int>{2, 3}));
    std::vector<int> example2 = {1, 1, 2};
    CHECK_EQ(sorted_duplicates(example2), (std::vector<int>{1}));
    std::vector<int> example3 = {1};
    CHECK_EQ(sorted_duplicates(example3), (std::vector<int>{}));

    // value n twice (slot n - 1). catches: value n mapped one slot too far
    // (out of bounds under ASan)
    std::vector<int> top_twice = {2, 2};
    CHECK_EQ(sorted_duplicates(top_twice), (std::vector<int>{2}));

    // n = 10^5, every value in [1, 50,000] twice, back half first:
    // 50,000 50,000 49,999 49,999 ... 1 1 then nothing else. Both copies of
    // each value are adjacent, and half the reads hit slots already
    // negated. catches: a missing abs, and a duplicate reported 0 or 2 times
    const std::size_t n = 100'000;
    std::vector<int> pairs(n);
    for (std::size_t i = 0; i < n; ++i)
        pairs[i] = static_cast<int>((n - 1 - i) / 2) + 1;
    std::vector<int> expected_pairs(n / 2);
    std::iota(expected_pairs.begin(), expected_pairs.end(), 1);
    CHECK_EQ(pairs.size(), n);
    CHECK_EQ(sorted_duplicates(pairs), expected_pairs);

    // n = 10^5, a permutation: no duplicates. catches: reporting a value
    // whose slot was negated by a different value
    std::vector<int> permutation(n);
    std::iota(permutation.rbegin(), permutation.rend(), 1);
    std::vector<int> permutation_copy = permutation;
    CHECK_EQ(permutation.size(), n);
    CHECK_EQ(sorted_duplicates(permutation), (std::vector<int>{}));
    // check the restore loop
    CHECK_EQ(permutation, permutation_copy);

    // Special cases (mine)
    // special case for an encountered issue
    std::vector<int> v1 = {2, 1, 1};
    std::vector<int> v1_copy = v1;
    CHECK_EQ(sorted_duplicates(v1), (std::vector<int>{1}));

    // check the restore loop
    CHECK_EQ(v1, v1_copy);

    DSA_REPORT();
}
