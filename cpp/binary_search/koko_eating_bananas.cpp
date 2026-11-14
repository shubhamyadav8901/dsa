// Koko Eating Bananas  (LeetCode 875 · Medium)
// Statement: problems/0875-koko-eating-bananas.md
//
// m = max_element(piles)
// Time:  O(n log m)
// Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>

bool can_eat(const std::vector<int>& piles, int h, int k) {
    long long hours = 0;
    for (auto pile : piles) {
        hours += pile / k;
        hours += (pile % k != 0);
    }
    return hours <= h;
}

int min_eating_speed(const std::vector<int>& piles, int h) {
    int lo = 1, hi = *std::max_element(piles.begin(), piles.end());
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (can_eat(piles, h, mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

#ifndef DSA_TEST
int main() {
    std::cout << min_eating_speed({3, 6, 7, 11}, 8) << "  (expect 4)\n";
    return 0;
}
#endif
