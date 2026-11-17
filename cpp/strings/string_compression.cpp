// String Compression  (LeetCode 443 · Medium)
// Pattern: string run scanning
//
// Time:  O(n)
// Space: O(1)

#include <iostream>
#include <vector>
#include <string>

int compress(std::vector<char>& chars) {
    int i = 0;
    int k = 0;
    int n = static_cast<int>(chars.size());

    while (i < n) {
        int j = i;
        while (j < n && chars[j] == chars[i])
            ++j;
        chars[k++] = chars[i];
        int count = j - i;
        if (count > 1) {
            std::string s = std::to_string(count);
            for (char c : s) {
                chars[k++] = c;
            }
        }
        i = j;
    }

    return k;
}

#ifndef DSA_TEST
int main() {
    std::vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int length = compress(chars);
    for (int i = 0; i < length; ++i)
        std::cout << chars[i];
    std::cout << "\n";
    return 0;
}
#endif
