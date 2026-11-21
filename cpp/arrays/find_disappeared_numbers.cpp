// Find All Numbers Disappeared in an Array  (LeetCode 448 · Easy)
// Pattern: index as hash
//
// Time:  O(n)
// Space: O(1) extra (output excluded)

#include <iostream>
#include <vector>
#include <cstddef>
#include <cstdlib>

std::vector<int> find_disappeared_numbers(std::vector<int>& nums) {
    std::vector<int> result;

    for (int num : nums) {
        int slot = std::abs(num) - 1;

        // the slot may already be negated
        if (nums[slot] > 0) nums[slot] = -nums[slot];
    }

    for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] > 0)
            result.push_back(static_cast<int>(i) + 1);
        else
            nums[i] = -nums[i];
    }

    return result;
}

#ifndef DSA_TEST
int main() {
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    for (int value : find_disappeared_numbers(nums))
        std::cout << value << " ";
    std::cout << "\n";
    return 0;
}
#endif
