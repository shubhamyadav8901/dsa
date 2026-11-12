#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/binary_search/search_insert.cpp"

#include <vector>
#include <numeric>
#include <cstddef>
#include <algorithm>

int main() {
    // examples
    CHECK_EQ(search_insert({1, 3, 5, 6}, 5), 2);
    CHECK_EQ(search_insert({1, 3, 5, 6}, 2), 1);
    CHECK_EQ(search_insert({1, 3, 5, 6}, 7), 4);

    CHECK_EQ(search_insert({-1, 0, 3, 5, 9, 12}, 9), 4);
    CHECK_EQ(search_insert({-1, 0, 3, 5, 9, 12}, 2), 2);

    // target at index 0
    CHECK_EQ(search_insert({-1, 0, 3, 5, 9, 12}, -1), 0);

    // nums length 1
    CHECK_EQ(search_insert({0}, 0), 0);

    // target at last index
    CHECK_EQ(search_insert({-1, 0, 3, 5, 9, 12}, 12), 5);

    // target not in arr and smaller then smallest
    CHECK_EQ(search_insert({-1, 0, 3, 5, 9, 12}, -2), 0);

    // target not in arr and larger then largest
    CHECK_EQ(search_insert({-1, 0, 3, 5, 9, 12}, 13), 6);

    // target not in arr
    CHECK_EQ(search_insert({-1, 0, 3, 5, 9, 12}, 1), 2);
    CHECK_EQ(search_insert({-1}, 13), 1);

    // nums with upper and lower bound values
    CHECK_EQ(search_insert({-10'000, 0, 3, 5, 9, 12, 10'000}, 13), 6);
    CHECK_EQ(search_insert({-10'000, 0, 3, 5, 9, 12, 10'000}, 12), 5);

    // upper and lower bound targets
    CHECK_EQ(search_insert({-10'000, 0, 3, 5, 9, 12, 10'000}, -10'000), 0);
    CHECK_EQ(search_insert({-10'000, 0, 3, 5, 9, 12, 10'000}, 10'000), 6);
    CHECK_EQ(search_insert({-9'998, 0, 3, 5, 9, 12, 9'998}, -10'000), 0);
    CHECK_EQ(search_insert({-9'998, 0, 3, 5, 9, 12, 9'998}, 10'000), 7);

    // nums length 10'000
    std::vector<int> vec1(10'000);
    std::iota(vec1.begin(), vec1.end(), 0);

    std::vector<int> vec2(10'000);
    std::iota(vec2.begin(), vec2.end(), -10'000);

    CHECK_EQ(search_insert(vec1, 0), 0);
    CHECK_EQ(search_insert(vec2, 0), 10'000);

    std::vector<int> vec3(10'000);
    std::iota(vec3.begin(), vec3.end(), -5'000);
    std::transform(vec3.begin(), vec3.end(), vec3.begin(),
                   [](int x) { return x * 2; });

    // every gap test
    int j = -9'999;
    for (size_t i = 0; i < vec3.size(); i++, j += 2) {
        CHECK_EQ(search_insert(vec3, j), static_cast<int>(i) + 1);
    }

    DSA_REPORT();
}
