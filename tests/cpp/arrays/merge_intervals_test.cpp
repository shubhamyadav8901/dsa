#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/arrays/merge_intervals.cpp"
#include <vector>

int main() {
    // Braced expected values need extra parentheses:
    // examples
    CHECK_EQ(merge_intervals({{1, 3}, {2, 6}, {8, 10}, {15, 18}}),
             (std::vector<std::vector<int>>{{1, 6}, {8, 10}, {15, 18}}));

    CHECK_EQ(merge_intervals({{1, 4}, {4, 5}}),
             (std::vector<std::vector<int>>{{1, 5}}));

    CHECK_EQ(merge_intervals({{4, 7}, {1, 4}}),
             (std::vector<std::vector<int>>{{1, 7}}));

    // intervals.length = 1
    CHECK_EQ(merge_intervals({{1, 4}}),
             (std::vector<std::vector<int>>{{1, 4}}));

    // start_i = 0, end_i = 0
    CHECK_EQ(merge_intervals({{0, 0}, {0, 4}, {4, 5}}),
             (std::vector<std::vector<int>>{{0, 5}}));
    CHECK_EQ(merge_intervals({{0, 0}, {1, 4}, {4, 5}}),
             (std::vector<std::vector<int>>{{0, 0}, {1, 5}}));

    // start_i = 10^4, end_i = 10^4
    CHECK_EQ(merge_intervals({{0, 4}, {4, 10'000}, {10'000, 10'000}}),
             (std::vector<std::vector<int>>{{0, 10'000}}));
    CHECK_EQ(merge_intervals({{0, 4}, {4, 5}, {10'000, 10'000}}),
             (std::vector<std::vector<int>>{{0, 5}, {10'000, 10'000}}));

    // start_i = 0, end_i = 10^4
    CHECK_EQ(merge_intervals({{0, 4}, {4, 5}, {4, 10'000}}),
             (std::vector<std::vector<int>>{{0, 10'000}}));
    CHECK_EQ(merge_intervals({{0, 4}, {4, 5}, {10, 10'000}}),
             (std::vector<std::vector<int>>{{0, 5}, {10, 10'000}}));

    // intervals.length = 10^4
    std::vector<std::vector<int>> vec1(10'000, {0, 0});
    CHECK_EQ(merge_intervals(vec1), (std::vector<std::vector<int>>{{0, 0}}));

    // interval inside current block
    CHECK_EQ(merge_intervals({{1, 5}, {2, 4}}),
             (std::vector<std::vector<int>>{{1, 5}}));

    DSA_REPORT();
}
