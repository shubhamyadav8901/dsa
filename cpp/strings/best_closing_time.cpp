// Minimum Penalty for a Shop  (LeetCode 2483 · Medium)
// Pattern: prefix pass
//
// Time:  O(n)
// Space: O(1)

#include <iostream>
#include <string>
#include <cstddef>

int best_closing_time(const std::string& customers) {
    int best_score = 0;
    int best_hour = 0;
    int score = 0;

    // penalty(j) = total Y − (Y − N in hours 0..j−1).
    // penalty(j) = total_Y − score(j), so the max score gives the min penalty.
    for (size_t i = 0; i < customers.size(); i++) {
        score += customers[i] == 'Y' ? 1 : -1;
        if (score > best_score) {
            best_score = score;
            best_hour = static_cast<int>(i) + 1;
        }
    }
    return best_hour;
}

#ifndef DSA_TEST
int main() {
    std::cout << best_closing_time("YYNY") << "\n";
    return 0;
}
#endif
