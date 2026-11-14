#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/binary_search/sqrtx.cpp"
#include <cmath>
#include <climits>

int main() {
    // Tests first. Comment what each one is for.

    // examples
    CHECK_EQ(my_sqrt(4), 2);
    CHECK_EQ(my_sqrt(8), 2);

    // x = 0
    CHECK_EQ(my_sqrt(0), 0);

    // x = 2^31 - 1
    CHECK_EQ(my_sqrt(INT_MAX), floor(sqrt(INT_MAX)));

    // off by one
    CHECK_EQ(my_sqrt(1), 1);

    CHECK_EQ(my_sqrt(15), 3);
    CHECK_EQ(my_sqrt(16), 4);
    CHECK_EQ(my_sqrt(17), 4);

    // some x's
    for (int i = 0; i <= 1'000'000; i++) {
        CHECK_EQ(my_sqrt(i), floor(sqrt(i)));
    }

    // off by one for large squares
    for (int i = 46'000; i <= 46'340; i++) {
        CHECK_EQ(my_sqrt(i * i - 1), floor(sqrt(i * i - 1)));
        CHECK_EQ(my_sqrt(i * i), floor(sqrt(i * i)));
        CHECK_EQ(my_sqrt(i * i + 1), floor(sqrt(i * i + 1)));
    }
    DSA_REPORT();
}
