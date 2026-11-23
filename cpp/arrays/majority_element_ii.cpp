// Majority Element II  (LeetCode 229 · Medium)
// Pattern: voting (cancellation)
//
// Time:  O(n)
// Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> majority_element_ii(const std::vector<int>& nums) {
    std::vector<int> result;
    int threshold = static_cast<int>(nums.size()) / 3;
    int candidate_1 = nums[0], candidate_2 = nums[0];
    int count_1 = 0, count_2 = 0;

    // At most two values can appear more than n/3 times (three of them would
    // need more than n elements), so two candidate slots are enough.
    for (int num : nums) {
        if (candidate_1 == num)
            count_1++;
        else if (candidate_2 == num)
            count_2++;
        else if (count_1 == 0) {
            candidate_1 = num;
            count_1++;
        } else if (count_2 == 0) {
            candidate_2 = num;
            count_2++;
        } else {
            // Removes three distinct values at once. That can happen at most
            // n/3 times, so a value with more than n/3 copies always keeps at
            // least one.
            count_1--;
            count_2--;
        }
    }

    // The survivors are only suspects. Unlike LC 169, no answer is guaranteed
    // (e.g. [1,2,3,4] leaves 4 standing), so each one has to be counted.
    if (std::count(nums.begin(), nums.end(), candidate_1) > threshold)
        result.push_back(candidate_1);
    // Both slots start on nums[0], so they can end holding the same value.
    if (candidate_2 != candidate_1 &&
        std::count(nums.begin(), nums.end(), candidate_2) > threshold)
        result.push_back(candidate_2);

    return result;
}

#ifndef DSA_TEST
int main() {
    for (int value : majority_element_ii({-5, 1'000'000'000}))
        std::cout << value << " ";
    std::cout << "\n";
    return 0;
}
#endif
