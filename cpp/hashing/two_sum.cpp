// Two Sum  (LeetCode 1 · Easy)
// Statement: problems/0001-two-sum.md
//
// Returns {i, j} with i < j and nums[i] + nums[j] == target.
//
// Time:  O(n)
// Space: O(n)
// Traded space for the speed-up

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstddef>

std::vector<int> two_sum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map;

    for (size_t i = 0; i < nums.size(); i++) {
        auto found = map.find(target - nums[i]);
        if (found != map.end())
            return std::vector<int>{found->second, static_cast<int>(i)};
        map[nums[i]] = i;
    }
    return {};
}

#ifndef DSA_TEST
int main() {
    auto answer = two_sum({2, 7, 11, 15}, 9);
    for (int i : answer)
        std::cout << i << " ";
    std::cout << " (expect 0 1)\n";
    return 0;
}
#endif
