// Majority Element  (LeetCode 169 · Easy)
// Pattern: voting
//
// Time:  O(n)
// Space: O(1)

#include <iostream>
#include <vector>

int majority_element(const std::vector<int>& nums) {
    int candidate = nums[0];
    int count = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // No verification pass: the problem guarantees a majority exists,
    // so the surviving candidate is it.
    return candidate;
}

#ifndef DSA_TEST
int main() {
    std::cout << majority_element({2, 2, 1, 1, 1, 2, 2}) << "\n";
    return 0;
}
#endif
