// Remove Duplicates from Sorted Array  (LeetCode 26 · Easy)
// Statement: problems/0026-remove-duplicates-from-sorted-array.md
//
// Returns k; the first k elements of nums hold the unique values in order.
//
// Time:  O(n)
// Space: O(1)

#include <iostream>
#include <vector>
#include <cstddef>

int remove_duplicates(std::vector<int>& nums) {
    size_t i = 0;

    for (size_t j = 1; j < nums.size(); j++) {
        if (nums[i] != nums[j]) {
            nums[++i] = nums[j];
        }
    }

    return i + 1;
}

#ifndef DSA_TEST
int main() {
    std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k = remove_duplicates(nums);
    for (int i = 0; i < k; i++)
        std::cout << nums[i] << " ";
    std::cout << " (expect 0 1 2 3 4)\n";
    return 0;
}
#endif
