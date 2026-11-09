// Longest Substring Without Repeating Characters  (LeetCode 3 · Medium)
// Statement: problems/0003-longest-substring-without-repeating-characters.md
//
// Time:  O(n)
// Space: O(1)

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

int length_of_longest_substring(const std::string& s) {
    std::vector<int> arr(256, 0);
    size_t i = 0;
    int longest_length = 0;

    for (size_t j = 0; j < s.length(); j++) {
        while (arr[static_cast<unsigned char>(s[j])] != 0) {
            arr[static_cast<unsigned char>(s[i++])] -= 1;
        }
        arr[static_cast<unsigned char>(s[j])] += 1;

        int window_length = j - i + 1;
        if (window_length > longest_length) longest_length = window_length;
    }
    return longest_length;
}

#ifndef DSA_TEST
int main() {
    std::cout << length_of_longest_substring("abcabcbb") << "  (expect 3)\n";
    return 0;
}
#endif
