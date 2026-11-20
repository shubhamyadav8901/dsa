#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/arrays/maximum_product_subarray.cpp"

#include <vector>

int main() {
    // Boilerplate (tutor)

    // catches: the examples from the statement
    CHECK_EQ(max_product({2, 3, -2, 4}), 6);
    CHECK_EQ(max_product({-2, 0, -1}), 0);
    CHECK_EQ(max_product({-2, 3, -4}), 24);

    // n = 1, one per sign. catches: a loop or seed that assumes two
    // elements, and a best seeded with 0 or 1 instead of nums[0]
    CHECK_EQ(max_product({0}), 0);
    CHECK_EQ(max_product({1}), 1);
    CHECK_EQ(max_product({-1}), -1);

    // n = 2 * 10^4, answer 2^30 (the largest power of two that fits).
    // 2^15, -1, 2^15, -1, then 1s. The answer needs both -1s, so the
    // running product goes to -2^30 before it flips back. catches: not
    // tracking the smallest product (gives 2^15), and any overflow from a
    // wrong intermediate
    std::vector<int> big;
    big.reserve(20'000);
    big.insert(big.end(), 15, 2);
    big.push_back(-1);
    big.insert(big.end(), 15, 2);
    big.push_back(-1);
    big.insert(big.end(), 20'000 - big.size(), 1);
    CHECK_EQ(big.size(), 20'000u);
    CHECK_EQ(max_product(big), 1 << 30);

    // Special cases (mine)

    // all positive elements -> smoke
    CHECK_EQ(max_product({1, 2, 3, 4, 5}), 120);

    // catches: worst computed from the already-updated best

    // all negative elements, n odd -> smoke
    CHECK_EQ(max_product({-1, -2, -3, -4, -5}), 120);
    // all negative elements, n even -> smoke
    CHECK_EQ(max_product({-1, -2, -3, -4, -5, -6}), 720);

    // extreme values and position of 0
    // catches: no restart at nums[i] — products stay 0 after a zero
    CHECK_EQ(max_product({-10, 1, 0, -1, 10}), 10);
    CHECK_EQ(max_product({-10, 1, 0, -1}), 1);
    CHECK_EQ(max_product({-10, 0, -1}), 0);

    DSA_REPORT();
}
