#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/arrays/find_disappeared_numbers.cpp"

#include <cstddef>
#include <numeric>
#include <vector>

// The function takes a non-const reference, so a braced temporary cannot be
// passed; every input needs a named variable.

int main() {
    // Boilerplate (tutor)

    // catches: the examples from the statement
    std::vector<int> example1 = {4, 3, 2, 7, 8, 2, 3, 1};
    CHECK_EQ(find_disappeared_numbers(example1), (std::vector<int>{5, 6}));
    std::vector<int> example2 = {1, 1};
    CHECK_EQ(find_disappeared_numbers(example2), (std::vector<int>{2}));

    // n = 1, nothing missing. catches: a result that is not empty when every
    // value is present
    std::vector<int> single = {1};
    CHECK_EQ(find_disappeared_numbers(single), (std::vector<int>{}));

    // 1 is the missing value (slot 0 never marked). catches: an off-by-one
    // that reads slot i as value i instead of i + 1
    std::vector<int> missing_one = {2, 2};
    CHECK_EQ(find_disappeared_numbers(missing_one), (std::vector<int>{1}));

    // n = 10^5, every value is n. catches: value n not mapped to slot n - 1
    // (out of bounds under ASan), and a wrong order or size in a large result
    const std::size_t n = 100'000;
    std::vector<int> all_n(n, static_cast<int>(n));
    std::vector<int> expected_all_n(n - 1);
    std::iota(expected_all_n.begin(), expected_all_n.end(), 1);
    CHECK_EQ(all_n.size(), n);
    CHECK_EQ(find_disappeared_numbers(all_n), expected_all_n);

    // n = 10^5, a reversed permutation: nothing missing. Every value in the
    // second half has already been negated by the time it is read. catches:
    // reading a[i] without abs (a negative index, out of bounds under ASan)
    std::vector<int> reversed(n);
    std::iota(reversed.rbegin(), reversed.rend(), 1);
    CHECK_EQ(reversed.size(), n);
    CHECK_EQ(find_disappeared_numbers(reversed), (std::vector<int>{}));

    // Special cases (mine)
    // unmodified input
    std::vector<int> v1 = {1, 2, 3, 2, 1, 2, 1};
    std::vector<int> v1_copy = v1;
    CHECK_EQ(find_disappeared_numbers(v1), (std::vector<int>{4, 5, 6, 7}));
    CHECK_EQ(v1, v1_copy);

    DSA_REPORT();
}
