// Find All Duplicates in an Array  (LeetCode 442 · Medium)
// Pattern: index as hash
//
// Time:  O(n)
// Space: O(1) extra (excluding output)

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstddef>

std::vector<int> find_duplicates(std::vector<int>& nums) {
    std::vector<int> result;

    for (size_t i = 0; i < nums.size(); i++) {
        int slot = std::abs(nums[i]) - 1;
        if (nums[slot] < 0)
            result.push_back(slot + 1);
        else
            nums[slot] = -nums[slot];
    }

    // restore so the caller's vector is unchanged.
    for (size_t i = 0; i < nums.size(); i++) {
        nums[i] = std::abs(nums[i]);
    }

    return result;
}

#ifndef DSA_TEST
int main() {
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    for (int value : find_duplicates(nums))
        std::cout << value << " ";
    std::cout << "\n";
    return 0;
}
#endif
