// Binary Search  (LeetCode 704 · Easy)
// Statement: problems/0704-binary-search.md
//
// Time:  O(log n)
// Space: O(1)

#include <iostream>
#include <vector>

int search(const std::vector<int>& nums, int target) {
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

    return -1;
}

#ifndef DSA_TEST
int main() {
    std::cout << search({-1, 0, 3, 5, 9, 12}, 9) << "  (expect 4)\n";
    return 0;
}
#endif
