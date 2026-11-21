#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/arrays/product_except_self.cpp"

#include <cstddef>
#include <vector>

int main() {
    // Boilerplate (tutor)

    // catches: the examples from the statement
    CHECK_EQ(product_except_self({1, 2, 3, 4}),
             (std::vector<int>{24, 12, 8, 6}));
    CHECK_EQ(product_except_self({-1, 1, 0, -3, 3}),
             (std::vector<int>{0, 0, 9, 0, 0}));

    // n = 2, extreme values. catches: an index's own value leaking into
    // its answer, and a loop that assumes a middle element exists
    CHECK_EQ(product_except_self({2, 3}), (std::vector<int>{3, 2}));
    CHECK_EQ(product_except_self({-30, 30}), (std::vector<int>{30, -30}));

    // n = 10^5: 2 at the front, -1 in the middle, 3 at the back, 1s
    // elsewhere. Every position has a different answer. catches: a left or
    // right pass shifted by one at either end (index 0 and n-1 each miss a
    // different factor), and an O(n^2) solution timing out
    const std::size_t n = 100'000;
    const std::size_t middle = n / 2;
    std::vector<int> big(n, 1);
    big.front() = 2;
    big[middle] = -1;
    big.back() = 3;
    std::vector<int> expected(n, -6);
    expected.front() = -3;
    expected[middle] = 6;
    expected.back() = -2;
    CHECK_EQ(big.size(), n);
    CHECK_EQ(product_except_self(big), expected);

    // Special cases (mine)
    // none

    DSA_REPORT();
}
