#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/arrays/sort_by_frequency.cpp"
#include <vector>

int main() {
    // Braced expected values need extra parentheses:

    // examples
    CHECK_EQ(frequency_sort({1, 1, 2, 2, 2, 3}),
             (std::vector<int>{3, 1, 1, 2, 2, 2}));

    CHECK_EQ(frequency_sort({2, 3, 1, 3, 2}),
             (std::vector<int>{1, 3, 3, 2, 2}));

    CHECK_EQ(frequency_sort({-1, 1, -6, 4, 5, -6, 1, 4, 1}),
             (std::vector<int>{5, -1, 4, 4, -6, -6, 1, 1, 1}));

    // nums.length = 1, nums[i] = -100, 100
    CHECK_EQ(frequency_sort({1}), (std::vector<int>{1}));
    CHECK_EQ(frequency_sort({0}), (std::vector<int>{0}));
    CHECK_EQ(frequency_sort({-1}), (std::vector<int>{-1}));
    CHECK_EQ(frequency_sort({100}), (std::vector<int>{100}));
    CHECK_EQ(frequency_sort({-100}), (std::vector<int>{-100}));

    // nums.length = 100
    std::vector<int> vec(50, -100);
    vec.insert(vec.end(), 50, 100);
    std::vector<int> res_vec(50, 100);
    res_vec.insert(res_vec.end(), 50, -100);
    CHECK_EQ(frequency_sort(vec), res_vec);

    DSA_REPORT();
}
