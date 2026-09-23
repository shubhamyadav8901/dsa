#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/strings/reverse_string.cpp"

#include <vector>
#include <random>
#include <algorithm>
#include <cstddef>

// reverse_string modifies its argument, so take a copy, run it, return it.
std::vector<char> reversed(std::vector<char> s) {
    reverse_string(s);
    return s;
}

std::vector<char> generate_large_vector(std::size_t size, int seed = 42) {
    std::vector<char> output;
    output.reserve(size);
    std::mt19937 rng(seed);

    for (std::size_t i = 0; i < size; i++) {
        output.push_back(static_cast<char>(32 + (rng() % 95)));
    }
    return output;
}

std::vector<char> generate_with_all_ascii() {
    std::vector<char> output;
    output.reserve(95);

    for (std::size_t i = 32; i < 127; i++) {
        output.push_back(static_cast<char>(i));
    }
    return output;
}

int main() {
    // Tests first. Constraints are the checklist - including n = 1, both
    // parities of length, and the size bound.
    //
    CHECK_EQ(reversed({'h', 'e', 'l', 'l', 'o'}),
             (std::vector<char>{'o', 'l', 'l', 'e', 'h'}));

    CHECK_EQ(reversed({'a'}), (std::vector<char>{'a'}));
    CHECK_EQ(reversed({'a', 'b'}), (std::vector<char>{'b', 'a'}));

    auto all_ascii = generate_with_all_ascii();
    auto reversed_ascii = all_ascii;
    std::reverse(reversed_ascii.begin(), reversed_ascii.end());
    CHECK_EQ(reversed(all_ascii), reversed_ascii);

    auto test = generate_large_vector(1'00'000);
    auto reversed_test = test;
    std::reverse(reversed_test.begin(), reversed_test.end());
    CHECK_EQ(reversed(test), reversed_test);

    DSA_REPORT();
}
