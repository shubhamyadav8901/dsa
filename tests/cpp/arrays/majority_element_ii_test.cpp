#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/arrays/majority_element_ii.cpp"

#include <algorithm>
#include <cstddef>
#include <numeric>
#include <vector>

// The answer may come back in any order, so tests compare it sorted.
std::vector<int> sorted_majorities(const std::vector<int>& nums) {
    std::vector<int> result = majority_element_ii(nums);
    std::sort(result.begin(), result.end());
    return result;
}

int main() {
    // Boilerplate (tutor)

    // catches: the examples from the statement
    CHECK_EQ(sorted_majorities({3, 2, 3}), (std::vector<int>{3}));
    CHECK_EQ(sorted_majorities({1}), (std::vector<int>{1}));
    CHECK_EQ(sorted_majorities({1, 2}), (std::vector<int>{1, 2}));

    // n = 1 at the lowest value. catches: a candidate seeded with 0 or a
    // made-up value instead of a real element
    CHECK_EQ(sorted_majorities({-1'000'000'000}),
             (std::vector<int>{-1'000'000'000}));

    // n = 5 * 10^4: (a, b, c) repeated, then a, b. Counts are 16,667,
    // 16,667 and 16,666, and n / 3 = 16,666. catches: >= instead of > at
    // the threshold (c must be excluded), and an O(n^2) solution timing out
    const std::size_t n = 50'000;
    std::vector<int> three_way;
    three_way.reserve(n);
    for (int round = 0; round < 16'666; ++round) {
        three_way.push_back(-5);
        three_way.push_back(1'000'000'000);
        three_way.push_back(0);
    }
    three_way.push_back(-5);
    three_way.push_back(1'000'000'000);
    CHECK_EQ(three_way.size(), n);
    CHECK_EQ(sorted_majorities(three_way),
             (std::vector<int>{-5, 1'000'000'000}));

    // n = 5 * 10^4, all distinct: nothing qualifies, but the voting pass
    // still ends holding candidates. catches: returning candidates without
    // counting them
    std::vector<int> distinct(n);
    std::iota(distinct.begin(), distinct.end(), 1);
    CHECK_EQ(distinct.size(), n);
    CHECK_EQ(sorted_majorities(distinct), (std::vector<int>{}));

    // Special cases (mine)

    // catches: single-candidate voting (forwards, backwards, or per parity),
    // which only guarantees a >1/2 majority, so a >1/3 value can be cancelled
    // out
    CHECK_EQ(sorted_majorities({1, 1, 1, 1, 2, 3, 4, 5, 6}),
             (std::vector<int>{1}));
    CHECK_EQ(sorted_majorities({2, 1, 3, 1, 4, 1, 5, 1, 6}),
             (std::vector<int>{1}));
    CHECK_EQ(sorted_majorities({1, 2, 1, 3, 1, 4, 1, 5, 6}),
             (std::vector<int>{1}));

    // catches: both slots seeded with the same value, so one value is
    // reported twice
    CHECK_EQ(sorted_majorities({2, 2}), (std::vector<int>{2}));

    DSA_REPORT();
}
