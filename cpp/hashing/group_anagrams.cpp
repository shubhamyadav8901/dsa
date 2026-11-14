// Group Anagrams  (LeetCode 49 · Medium)
// Statement: problems/0049-group-anagrams.md
//
// n = number of strings, k = length of the longest string.
// Time:  O(nk)
// Space: O(nk)

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::string count_to_string(const int (&count)[26]) {
    std::string result = "";
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            result += (i + 'a');
            result += std::to_string(count[i]);
        }
    }
    return result;
}

std::vector<std::vector<std::string>> group_anagrams(
    const std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> mp;
    for (const std::string& s : strs) {
        int arr[26]{};
        for (char c : s) {
            arr[c - 'a']++;
        }

        std::string string_count = count_to_string(arr);
        mp[string_count].push_back(s);
    }

    std::vector<std::vector<std::string>> result;
    for (const auto& [k, v] : mp) {
        result.push_back(v);
    }
    return result;
}

#ifndef DSA_TEST
int main() {
    for (const auto& group :
         group_anagrams({"eat", "tea", "tan", "ate", "nat", "bat"})) {
        for (const auto& s : group)
            std::cout << s << " ";
        std::cout << "| ";
    }
    std::cout << "\n";
    return 0;
}
#endif
