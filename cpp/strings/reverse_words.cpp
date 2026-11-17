// Reverse Words in a String  (LeetCode 151 · Medium)
// Pattern: string run scanning
//
// Time:  O(n)
// Space: O(1)

#include <iostream>
#include <string>

std::string reverse_words(const std::string& s) {
    std::string result;
    result.reserve(s.length());

    int i = static_cast<int>(s.size()) - 1;
    while (i >= 0) {
        if (s[i] == ' ') {
            --i;
            continue;
        }

        int j = i;
        while (j >= 0 && s[j] != ' ')
            --j;

        if (!result.empty()) {
            result.append(" ");
        }

        result.append(s, j + 1, i - j);
        i = j;
    }

    return result;
}

#ifndef DSA_TEST
int main() {
    std::cout << "[" << reverse_words("  hello world  ") << "]\n";
    return 0;
}
#endif
