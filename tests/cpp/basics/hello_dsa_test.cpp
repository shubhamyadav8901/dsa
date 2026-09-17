#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/basics/hello_dsa.cpp"

int main() {
    CHECK_EQ(sum_to_n_loop(0), 0);
    CHECK_EQ(sum_to_n_loop(1), 1);
    CHECK_EQ(sum_to_n_loop(10), 55);

    CHECK_EQ(sum_to_n_formula(0), 0);
    CHECK_EQ(sum_to_n_formula(1), 1);
    CHECK_EQ(sum_to_n_formula(10), 55);

    // The two implementations must agree everywhere, not just on nice inputs.
    for (int n = 0; n <= 200; ++n) {
        CHECK_EQ(sum_to_n_loop(n), sum_to_n_formula(n));
    }

    DSA_REPORT();
}
