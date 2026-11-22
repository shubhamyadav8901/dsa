#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/arrays/majority_element.cpp"

#include <cstddef>
#include <vector>

int main() {
    // Boilerplate (tutor)

    // catches: the examples from the statement
    CHECK_EQ(majority_element({3, 2, 3}), 3);
    CHECK_EQ(majority_element({2, 2, 1, 1, 1, 2, 2}), 2);

    // n = 1, at both value extremes. catches: a loop or seed that assumes
    // two elements, and a candidate seeded with 0 instead of a real element
    CHECK_EQ(majority_element({-1'000'000'000}), -1'000'000'000);
    CHECK_EQ(majority_element({1'000'000'000}), 1'000'000'000);

    // n = 5 * 10^4: 24,999 distinct non-majority values first, then the
    // majority 25,001 times. The candidate changes many times before the
    // majority arrives. catches: trusting an early candidate, and an
    // O(n^2) count-every-element solution timing out
    const std::size_t n = 50'000;
    std::vector<int> late_majority;
    late_majority.reserve(n);
    for (int value = 1; value <= 24'999; ++value)
        late_majority.push_back(value);
    late_majority.insert(late_majority.end(), 25'001, -7);
    CHECK_EQ(late_majority.size(), n);
    CHECK_EQ(majority_element(late_majority), -7);

    // n = 5 * 10^4 - 1, majority at every even index:
    // m x m x ... m (25,000 m, 24,999 others). The count never exceeds 1.
    // catches: a candidate replaced while its count is still positive
    std::vector<int> alternating;
    alternating.reserve(n - 1);
    for (std::size_t i = 0; i < n - 1; ++i)
        alternating.push_back(i % 2 == 0 ? 42 : static_cast<int>(i));
    CHECK_EQ(alternating.size(), n - 1);
    CHECK_EQ(majority_element(alternating), 42);

    // Special cases (mine)
    // not required

    DSA_REPORT();
}
