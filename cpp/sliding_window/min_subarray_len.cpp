// Minimum Size Subarray Sum  (LeetCode 209 · Medium)
// Statement: problems/0209-minimum-size-subarray-sum.md
//
// Time:  O(n)
// Space: O(1)

#include <iostream>
#include <vector>
#include <cstddef>

int min_subarray_len(int target, const std::vector<int>& nums) {
    size_t result = nums.size() + 1;
    int sum = 0;
    size_t i = 0;

    for (size_t j = 0; j < nums.size(); j++) {
        sum += nums[j];
        while (sum >= target) {
            size_t window_size = j - i + 1;
            if (window_size < result) {
                result = window_size;
            }
            sum -= nums[i++];
        }
    }

    if (result == nums.size() + 1) return 0;
    return static_cast<int>(result);
}

#ifndef DSA_TEST
int main() {
    std::cout << min_subarray_len(7, {2, 3, 1, 2, 4, 3}) << "  (expect 2)\n";
    return 0;
}
#endif
