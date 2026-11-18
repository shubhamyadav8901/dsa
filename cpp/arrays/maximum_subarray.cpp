// Maximum Subarray  (LeetCode 53 · Medium)
// Pattern: best ending here
//
// Time:  O(n)
// Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>

int max_subarray(const std::vector<int>& nums) {
    int best_ending_here = nums[0];
    int best = best_ending_here;

    for (size_t i = 1; i < nums.size(); i++) {
        best_ending_here = std::max(best_ending_here + nums[i], nums[i]);
        if (best_ending_here > best) best = best_ending_here;
    }
    return best;
}

#ifndef DSA_TEST
int main() {
    std::cout << max_subarray({-2, 1, -3, 4, -1, 2, 1, -5, 4}) << "\n";
    return 0;
}
#endif
