#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/hashing/group_anagrams.cpp"

#include <algorithm>
#include <string>
#include <vector>

using Groups = std::vector<std::vector<std::string>>;

// The problem allows any order, both for the groups and inside each group.
// normalized() sorts both, so two correct answers always compare equal.
Groups normalized(Groups groups) {
    for (auto& group : groups)
        std::sort(group.begin(), group.end());
    std::sort(groups.begin(), groups.end());
    return groups;
}

int main() {
    // Tests first. Comment what each one is for. Compare through normalized():

    // examples
    CHECK_EQ(
        normalized(group_anagrams({"eat", "tea", "tan", "ate", "nat", "bat"})),
        normalized(Groups{{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}}));

    CHECK_EQ(normalized(group_anagrams({""})), normalized(Groups{{""}}));
    CHECK_EQ(normalized(group_anagrams({"a"})), normalized(Groups{{"a"}}));

    // length 1
    CHECK_EQ(normalized(group_anagrams({"abcxyz"})),
             normalized(Groups{{"abcxyz"}}));
    CHECK_EQ(normalized(group_anagrams({"x"})), normalized(Groups{{"x"}}));

    // str length 0
    CHECK_EQ(normalized(group_anagrams({"", "ab", "ba"})),
             normalized(Groups{{""}, {"ab", "ba"}}));

    // str length 100
    std::string s1, s2;
    for (int i = 0; i < 25; i++) {
        s1 += "abcd";
    }
    for (int i = 0; i < 20; i++) {
        s2 += "vwxyz";
    }
    CHECK_EQ(normalized(group_anagrams(
                 {s1, s2, "eat", "tea", "tan", "ate", "nat", "bat"})),
             normalized(Groups{
                 {s1}, {s2}, {"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}}));

    // length 10^4
    std::vector<std::string> vec1(10'000, s1);
    CHECK_EQ(normalized(group_anagrams(vec1)), normalized(Groups{vec1}));

    // same set of characters but different counts (to check the key logic)
    CHECK_EQ(normalized(group_anagrams({"aab", "abb"})),
             normalized(Groups{{"aab"}, {"abb"}}));

    DSA_REPORT();
}
