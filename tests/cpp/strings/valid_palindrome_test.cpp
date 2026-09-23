#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/strings/valid_palindrome.cpp"

#include <string>
#include <random>
#include <cstddef>
#include <algorithm>

std::string generate_large_string(std::size_t size, int seed = 42) {
    std::string output;
    output.reserve(size);
    std::mt19937 rng(seed);

    for (std::size_t i = 0; i < size; i++) {
        output += (32 + (rng() % 95));
    }

    return output;
}

int main() {
    CHECK_EQ(getFinal('A'), 'a');
    CHECK_EQ(getFinal('a'), 'a');
    CHECK_EQ(getFinal('0'), '0');
    CHECK_EQ(getFinal('Z'), 'z');
    CHECK_EQ(getFinal('z'), 'z');
    CHECK_EQ(getFinal('9'), '9');

    CHECK_TRUE(is_palindrome("racecar"));
    CHECK_FALSE(is_palindrome("race a car"));
    CHECK_TRUE(is_palindrome("A man, a plan, a canal: Panama"));

    CHECK_TRUE(is_palindrome("A"));
    CHECK_TRUE(is_palindrome("z"));
    CHECK_FALSE(is_palindrome("ab"));
    CHECK_FALSE(is_palindrome("abcde"));
    CHECK_TRUE(is_palindrome("!"));
    CHECK_TRUE(is_palindrome("!@#$%^&*()"));
    CHECK_TRUE(is_palindrome("abc123454321cba"));
    CHECK_TRUE(is_palindrome("ABC123454321cba"));
    CHECK_TRUE(is_palindrome("abc@12(345#43)2&1cba^"));
    CHECK_FALSE(is_palindrome("1899&#*)abdgcASJCNK1%1&*#"));
    CHECK_TRUE(is_palindrome("ABCDEedcba"));

    std::string test = generate_large_string(1'00'000);
    std::string reversed_test = test;
    std::reverse(reversed_test.begin(), reversed_test.end());

    CHECK_TRUE(is_palindrome(test + reversed_test));

    test = generate_large_string(2'00'000);
    CHECK_FALSE(is_palindrome(test));

    CHECK_TRUE(is_palindrome("a!"));
    CHECK_TRUE(is_palindrome("aa"));

    DSA_REPORT();
}
