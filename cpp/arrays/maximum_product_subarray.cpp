// Maximum Product Subarray  (LeetCode 152 · Medium)
// Pattern: best ending here
//
// Time:  O(n)
// Space: O(1)

#include <iostream>
#include <vector>
#include <cstddef>
#include <algorithm>

int max_product(const std::vector<int>& nums) {
    int best_ending_here = nums[0];
    int worst_ending_here = nums[0];
    int best = best_ending_here;

    for (size_t i = 1; i < nums.size(); i++) {
        int prev_best_ending_here = best_ending_here;
        best_ending_here = std::max(
            {nums[i], worst_ending_here * nums[i], best_ending_here * nums[i]});
        worst_ending_here = std::min({nums[i], worst_ending_here * nums[i],
                                      prev_best_ending_here * nums[i]});
        best = std::max(best, best_ending_here);
    }

    return best;
}

#ifndef DSA_TEST
int main() {
    std::cout << max_product({2, 3, -2, 4}) << "\n";
    return 0;
}
#endif
