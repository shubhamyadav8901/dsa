#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/strings/valid_anagram.cpp"

#include <string>
#include <random>
#include <algorithm>
#include <cstddef>

std::string generate_large_string(std::size_t size, int seed = 42) {
    std::string output;
    output.reserve(size);
    std::mt19937 rng(seed);

    for (std::size_t i = 0; i < size; i++) {
        output += 'a' + (rng() % 26);
    }

    return output;
}

std::string generate_anagram(const std::string& input, int seed = 42) {
    std::string output = input;
    std::mt19937 rng(seed);

    std::shuffle(output.begin(), output.end(), rng);
    return output;
}

int main() {
    // Tests first. Read the Constraints section as a checklist - every
    // sentence in it is a case waiting to be written, including the size
    // bound. A scale test is required this time.
    //
    CHECK_TRUE(is_anagram("anagram", "nagaram"));
    CHECK_FALSE(is_anagram("rat", "car"));
    CHECK_TRUE(is_anagram("a", "a"));
    CHECK_FALSE(is_anagram("a", "z"));
    CHECK_FALSE(is_anagram("abc", "a"));

    std::string test = generate_large_string(5 * 10'000);
    CHECK_TRUE(is_anagram(test, generate_anagram(test)));
    CHECK_FALSE(is_anagram(generate_large_string(5 * 10'000),
                           generate_large_string(5 * 10'000, 43)));

    DSA_REPORT();
}
