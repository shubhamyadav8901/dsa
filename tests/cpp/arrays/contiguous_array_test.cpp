#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/arrays/contiguous_array.cpp"

#include <vector>

int main() {
    // examples
    CHECK_EQ(find_max_length({0, 1}), 2);
    CHECK_EQ(find_max_length({0, 1, 0}), 2);
    CHECK_EQ(find_max_length({0, 1, 1, 1, 1, 1, 0, 0, 0}), 6);

    // case where multiple indexes have same prefix sum
    CHECK_EQ(find_max_length({1, 0, 0, 1, 1, 0}), 6);

    // length 1
    CHECK_EQ(find_max_length({1}), 0);
    CHECK_EQ(find_max_length({0}), 0);

    // all 0's & length 1'00'000
    std::vector<int> vec1(1'00'000, 0);
    CHECK_EQ(find_max_length(vec1), 0);

    // all 1's & length 1'00'000
    std::vector<int> vec2(1'00'000, 1);
    CHECK_EQ(find_max_length(vec2), 0);

    // length 1'00'000
    std::vector<int> vec_l(50'000, 1);
    std::vector<int> vec_r(50'000, 0);

    std::vector<int> vec3;
    vec3.insert(vec3.end(), vec_l.begin(), vec_l.end());
    vec3.insert(vec3.end(), vec_r.begin(), vec_r.end());

    CHECK_EQ(find_max_length(vec3), 1'00'000);

    DSA_REPORT();
}
