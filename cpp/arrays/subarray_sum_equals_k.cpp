// Subarray Sum Equals K  (LeetCode 560 · Medium)
// Statement: problems/0560-subarray-sum-equals-k.md
//
// Time:  O(n)
// Space: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>

int subarray_sum(const std::vector<int>& nums, int k) {
    int prefix_sum = 0;
    std::unordered_map<int, int> mp;
    int result = 0;

    mp[prefix_sum] += 1;

    for (auto num : nums) {
        prefix_sum += num;

        auto it = mp.find(prefix_sum - k);
        if (it != mp.end()) result += it->second;

        mp[prefix_sum] += 1;
    }

    return result;
}

#ifndef DSA_TEST
int main() {
    std::cout << subarray_sum({1, -1, 1}, 1) << "  (expect 3)\n";
    return 0;
}
#endif
