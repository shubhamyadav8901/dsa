// Contains Duplicate II  (LeetCode 219 · Easy)
// Statement: problems/0219-contains-duplicate-ii.md
//
// Time:  O(n)
// Space: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstddef>
#include <cmath>

bool contains_nearby_duplicate(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> map;

    for (std::size_t i = 0; i < nums.size(); i++) {
        auto it = map.find(nums[i]);
        if (it != map.end() && std::abs(static_cast<int>(i) - it->second) <= k)
            return true;
        map[nums[i]] = i;
    }
    return false;
}

// Sliding-window version: same answer, but the set never holds more than k
// values.
// Time:  O(n)
// Space: O(k)
// if k > n then Space: O(n)

bool contains_nearby_duplicate_window(const std::vector<int>& nums, int k) {
    std::unordered_set<int> window;
    std::size_t i = 0;

    while (i < static_cast<size_t>(k) && i < nums.size()) {
        if (window.count(nums[i])) return true;
        window.insert(nums[i++]);
    }

    for (i = k; i < nums.size(); i++) {
        if (window.count(nums[i])) return true;
        window.insert(nums[i]);
        window.erase(nums[i - k]);
    }

    return false;
}

#ifndef DSA_TEST
int main() {
    std::cout << std::boolalpha << contains_nearby_duplicate({1, 2, 3, 1}, 3)
              << "  (expect true)\n";
    return 0;
}
#endif
