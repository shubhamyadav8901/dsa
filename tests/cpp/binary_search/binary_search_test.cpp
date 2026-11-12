#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/binary_search/binary_search.cpp"

#include <vector>
#include <numeric>
#include <cstddef>

int main() {
    // Tests first. Comment what each one is for.

    // examples
    CHECK_EQ(search({-1, 0, 3, 5, 9, 12}, 9), 4);
    CHECK_EQ(search({-1, 0, 3, 5, 9, 12}, 2), -1);

    // target at index 0
    CHECK_EQ(search({-1, 0, 3, 5, 9, 12}, -1), 0);

    // nums length 1
    CHECK_EQ(search({0}, 0), 0);

    // target at last index
    CHECK_EQ(search({-1, 0, 3, 5, 9, 12}, 12), 5);

    // target not in arr and smaller then smallest
    CHECK_EQ(search({-1, 0, 3, 5, 9, 12}, -2), -1);

    // target not in arr and larger then largest
    CHECK_EQ(search({-1, 0, 3, 5, 9, 12}, 13), -1);

    // target not in arr
    CHECK_EQ(search({-1, 0, 3, 5, 9, 12}, 1), -1);
    CHECK_EQ(search({-1}, 13), -1);

    // nums with upper and lower bound values
    CHECK_EQ(search({-9'999, 0, 3, 5, 9, 12, 9'999}, 13), -1);
    CHECK_EQ(search({-9'999, 0, 3, 5, 9, 12, 9'999}, 12), 5);

    // upper and lower bound targets
    CHECK_EQ(search({-9'999, 0, 3, 5, 9, 12, 9'999}, -9'999), 0);
    CHECK_EQ(search({-9'999, 0, 3, 5, 9, 12, 9'999}, 9'999), 6);
    CHECK_EQ(search({-9'998, 0, 3, 5, 9, 12, 9'998}, -9'999), -1);
    CHECK_EQ(search({-9'998, 0, 3, 5, 9, 12, 9'998}, 9'999), -1);

    // nums length 10'000
    std::vector<int> vec1(10'000);
    std::iota(vec1.begin(), vec1.end(), 0);

    std::vector<int> vec2(10'000);
    std::iota(vec2.begin(), vec2.end(), -9'999);

    CHECK_EQ(search(vec1, 0), 0);
    CHECK_EQ(search(vec2, 0), 9'999);

    // every element test
    for (size_t i = 0; i < vec1.size(); i++) {
        CHECK_EQ(search(vec1, vec1[i]), static_cast<int>(i));
    }

    DSA_REPORT();
}
