#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/binary_search/koko_eating_bananas.cpp"

#include <vector>
#include <numeric>

int main() {
    // examples
    CHECK_EQ(min_eating_speed({3, 6, 7, 11}, 8), 4);
    CHECK_EQ(min_eating_speed({30, 11, 23, 4, 20}, 5), 30);
    CHECK_EQ(min_eating_speed({30, 11, 23, 4, 20}, 6), 23);

    // piles length 1 & h = piles.length & max value
    CHECK_EQ(min_eating_speed({3}, 1), 3);
    CHECK_EQ(min_eating_speed({3}, 1'000'000'000), 1);

    // piles.length = 10^4
    std::vector<int> vec1(10'000, 1'000'000'000);
    CHECK_EQ(min_eating_speed(vec1, 10'000), 1'000'000'000);

    std::vector<int> vec2(5'000);
    std::iota(vec2.begin(), vec2.end(), 1'000'000'000 - 5'000 + 1);
    CHECK_EQ(min_eating_speed(vec2, 10'000), 500'000'000);

    // all max test
    CHECK_EQ(min_eating_speed(vec1, 1'000'000'000), 10'000);

    DSA_REPORT();
}
