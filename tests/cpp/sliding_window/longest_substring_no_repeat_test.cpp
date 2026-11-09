#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/sliding_window/longest_substring_no_repeat.cpp"

int main() {
    // Tests first. Constraints are the checklist - including the smallest
    // length the constraints allow, the full character set, and the size
    // bound. Comment what each test is *for*.

    // question examples
    CHECK_EQ(length_of_longest_substring("abcabcbb"), 3);
    CHECK_EQ(length_of_longest_substring("bbbbb"), 1);
    CHECK_EQ(length_of_longest_substring("pwwkew"), 3);

    // length 0 string
    CHECK_EQ(length_of_longest_substring(""), 0);

    // length 1 string
    CHECK_EQ(length_of_longest_substring("a"), 1);

    // longest substring at start
    CHECK_EQ(length_of_longest_substring("abcdefghxyzxyzxyz"), 11);

    // longest substring at end
    CHECK_EQ(length_of_longest_substring("xyzxyzxyzabcdefgh"), 11);

    // longest substring in middle
    CHECK_EQ(length_of_longest_substring("xyzxyzxyzabcdefghabcabcabc"), 11);

    std::string chars =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "!@#$%^&*()-_=+[]{};:',.<>/?\\|`~ \"";

    std::string s;
    s.reserve(50000);
    while (s.size() < 50000) {
        s += chars;
    }
    s.resize(50000);

    // length (5 * 10^4) string containing all valid characters
    CHECK_EQ(length_of_longest_substring(s), 95);

    DSA_REPORT();
}
