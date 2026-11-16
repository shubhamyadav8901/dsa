// Sort Array by Increasing Frequency  (LeetCode 1636 · Easy)
// Pattern: sorting with custom comparator
//
// Time:  O(n log n)
// Space: O(n)

#include <iostream>
#include <vector>
#include <algorithm>

// map [-100,100] onto indices [0, 200]
constexpr int kOffset = 100;

std::vector<int> frequency_sort(std::vector<int> nums) {
    int num_count[2 * kOffset + 1] = {0};
    for (int num : nums) {
        num_count[num + kOffset]++;
    }

    std::sort(nums.begin(), nums.end(), [&num_count](int a, int b) {
        if (num_count[a + kOffset] != num_count[b + kOffset])
            return num_count[a + kOffset] < num_count[b + kOffset];
        return a > b;
    });
    return nums;
}

#ifndef DSA_TEST
int main() {
    for (int value : frequency_sort({1, 1, 2, 2, 2, 3}))
        std::cout << value << " ";
    std::cout << "\n";
    return 0;
}
#endif
