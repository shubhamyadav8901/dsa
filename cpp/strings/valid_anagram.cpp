// Valid Anagram  (LeetCode 242 · Easy)
// Statement: problems/0242-valid-anagram.md
//
// Time:  O(?)
// Space: O(?)

#include <iostream>
#include <string>

bool is_anagram(const std::string& a, const std::string& b) {
    // TODO
    if (a.size() != b.size()) return false;

    int counts[26] = {};

    for (char c : a) {
        counts[c - 'a']++;
    }

    for (char c : b) {
        counts[c - 'a']--;
    }

    for (int i : counts) {
        if (i) return false;
    }

    return true;
}

#ifndef DSA_TEST
int main() {
    std::cout << std::boolalpha << is_anagram("anagram", "nagaram")
              << "  (expect true)\n";
    return 0;
}
#endif
