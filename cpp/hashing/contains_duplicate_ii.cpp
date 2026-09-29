// Contains Duplicate II  (LeetCode 219 · Easy)
// Statement: problems/0219-contains-duplicate-ii.md
//
// Time:  O(n)
// Space: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
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

#ifndef DSA_TEST
int main() {
    std::cout << std::boolalpha << contains_nearby_duplicate({1, 2, 3, 1}, 3)
              << "  (expect true)\n";
    return 0;
}
#endif
