// Sqrt(x)  (LeetCode 69 · Easy)
// Statement: problems/0069-sqrtx.md
//
// Time:  O(log x)
// Space: O(1)

#include <iostream>

int my_sqrt(int x) {
    int lo = 0, hi = x;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (static_cast<long long>(mid) * mid <= x) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return hi;
}

#ifndef DSA_TEST
int main() {
    std::cout << my_sqrt(8) << "  (expect 2)\n";
    return 0;
}
#endif
