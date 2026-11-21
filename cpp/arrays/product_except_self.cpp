// Product of Array Except Self  (LeetCode 238 · Medium)
// Pattern: prefix + suffix pass
//
// Time:  O(n)
// Space: O(1) extra (output excluded)

#include <iostream>
#include <vector>
#include <cstddef>

std::vector<int> product_except_self(const std::vector<int>& nums) {
    std::vector<int> result(nums.size());

    result[0] = 1;
    for (size_t i = 1; i < nums.size(); i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }

    int right = 1;
    for (int i = static_cast<int>(nums.size()) - 2; i >= 0; i--) {
        right *= nums[i + 1];
        result[i] = right * result[i];
    }

    return result;
}

#ifndef DSA_TEST
int main() {
    for (int value : product_except_self({1, 2, 3, 4}))
        std::cout << value << " ";
    std::cout << "\n";
    return 0;
}
#endif
