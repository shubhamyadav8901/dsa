// Contiguous Array  (LeetCode 525 · Medium)
// Statement: problems/0525-contiguous-array.md
//
// Time:  O(n)
// Space: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstddef>

int find_max_length(const std::vector<int>& nums) {
    size_t result = 0;
    int prefix_sum = 0;
    std::unordered_map<int, size_t> mp;
    mp[0] = 0;

    for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            prefix_sum += -1;
        } else {
            prefix_sum += 1;
        }

        auto it = mp.find(prefix_sum);
        if (it != mp.end()) {
            if (i + 1 - it->second > result) result = i + 1 - it->second;
        } else
            mp[prefix_sum] = i + 1;
    }
    return static_cast<int>(result);
}

#ifndef DSA_TEST
int main() {
    std::cout << find_max_length({0, 1, 1, 1, 1, 1, 0, 0, 0})
              << "  (expect 6)\n";
    return 0;
}
#endif
