// Merge Intervals  (LeetCode 56 · Medium)
// Pattern: sorting with custom comparator
// n = intervals.length
// Time:  O(n log n)
// Space: O(n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>

std::vector<std::vector<int>> merge_intervals(
    std::vector<std::vector<int>> intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [](const std::vector<int>& a, const std::vector<int>& b) {
                  return a[0] < b[0];
              });

    std::vector<std::vector<int>> result;
    result.reserve(intervals.size());

    std::vector<int> current_merged_block = intervals[0];

    for (size_t i = 1; i < intervals.size(); i++) {
        if (current_merged_block[1] >= intervals[i][0]) {
            current_merged_block[1] =
                std::max(current_merged_block[1], intervals[i][1]);
        } else {
            result.push_back(current_merged_block);
            current_merged_block = intervals[i];
        }
    }
    result.push_back(current_merged_block);
    return result;
}

#ifndef DSA_TEST
int main() {
    for (const auto& interval :
         merge_intervals({{1, 3}, {2, 6}, {8, 10}, {15, 18}}))
        std::cout << "[" << interval[0] << "," << interval[1] << "] ";
    std::cout << "\n";
    return 0;
}
#endif
