// Reverse String  (LeetCode 344 · Easy)
// Statement: problems/0344-reverse-string.md
//
// No std::swap, no std::reverse - write swap_chars yourself.
//
// Time:  O(n)
// Space: O(1)

#include <iostream>
#include <vector>
#include <cstddef>

// Choose the parameter types. That choice is the whole exercise.
void swap_chars(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

void reverse_string(std::vector<char>& s) {
    std::size_t start = 0;
    std::size_t end = s.size() - 1;

    while (start < end) {
        swap_chars(s[start], s[end]);
        start++;
        end--;
    }
}

#ifndef DSA_TEST
int main() {
    std::vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    reverse_string(s);
    for (char c : s)
        std::cout << c;
    std::cout << "  (expect olleh)\n";
    return 0;
}
#endif
