// Search Insert Position  (LeetCode 35 · Easy)
// Statement: problems/0035-search-insert-position.md
//
// Time:  O(log n)
// Space: O(1)

#include <iostream>
#include <vector>

int search_insert(const std::vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

#ifndef DSA_TEST
int main() {
    std::cout << search_insert({1, 3, 5, 6}, 2) << "  (expect 1)\n";
    return 0;
}
#endif
