// Valid Palindrome  (LeetCode 125 · Easy)
// Statement: problems/0125-valid-palindrome.md
//
// Time:  O(n)
// Space: O(1)

#include <iostream>
#include <string>
#include <cstddef>

bool isSmallLetter(char c) {
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    return false;
}

bool isCapitalLetter(char c) {
    if (c >= 'A' && c <= 'Z') {
        return true;
    }
    return false;
}

bool isDigit(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

bool isAlphaNumeric(char c) {
    //  capital alphabets    small alphabets       digits
    if (isSmallLetter(c) || isCapitalLetter(c) || isDigit(c)) {
        return true;
    }
    return false;
}

char getFinal(char c) {
    if (isDigit(c) || isSmallLetter(c)) return c;

    return c + ('a' - 'A');
}

bool is_palindrome(const std::string& s) {
    size_t start = 0;
    size_t end = s.size() - 1;

    while (start < end) {
        while (start < s.size() && !isAlphaNumeric(s[start]))
            start++;
        while (end > 0 && !isAlphaNumeric(s[end]))
            end--;

        if (start >= end) break;

        if (getFinal(s[start]) != getFinal(s[end])) return false;
        start++;
        end--;
    }

    return true;
}

#ifndef DSA_TEST
int main() {
    std::cout << std::boolalpha
              << is_palindrome("A man, a plan, a canal: Panama")
              << "  (expect true)\n";
    return 0;
}
#endif
