#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/strings/reverse_words.cpp"
#include <string>

int main() {
    // examples
    CHECK_EQ(reverse_words("the sky is blue"), std::string("blue is sky the"));
    CHECK_EQ(reverse_words("  hello world  "), std::string("world hello"));
    CHECK_EQ(reverse_words("a good   example"), std::string("example good a"));

    // s.length = 1
    CHECK_EQ(reverse_words("a"), std::string("a"));

    // spaces
    CHECK_EQ(reverse_words("    a    "), std::string("a"));
    CHECK_EQ(reverse_words("b  a  "), std::string("a b"));
    CHECK_EQ(reverse_words("   a   c"), std::string("c a"));

    // s.length = 10^4
    // smoke test running at the max size
    std::string s1;
    s1.reserve(10'001);
    for (int i = 0; i < 1'000; ++i)
        s1.append("the sky i ");

    std::string s1_res;
    s1_res.reserve(10'001);

    for (int i = 0; i < 1'000; ++i)
        s1_res.append("i sky the ");
    s1_res.pop_back();

    CHECK_EQ(reverse_words(s1), s1_res);

    // smoke test running at the max size
    std::string s2(10'000, 'a');
    CHECK_EQ(reverse_words(s2), s2);

    // upper case
    CHECK_EQ(reverse_words("THE SKY IS BLUE"), "BLUE IS SKY THE");

    // mixed case
    CHECK_EQ(reverse_words("ThE sKy IS bLuE"), "bLuE IS sKy ThE");

    // digits
    CHECK_EQ(reverse_words("123 456 789"), "789 456 123");

    // mixed
    CHECK_EQ(reverse_words("ThE123 sKy456 IS789 bLuE"),
             "bLuE IS789 sKy456 ThE123");

    DSA_REPORT();
}
