// Second Largest  (drill · Easy)
//
// Return the second largest DISTINCT value in the array, or -1 if there is
// no second distinct value.
//
// Constraints:
//   1 <= n <= 100000
//   values fit in int and may be negative
//   duplicates are allowed
//
// Your approach (one pass, two variables).
//
// Invariant to keep true on every iteration:
//   after processing the first k elements,
//     largest holds the maximum of those k
//     second  holds the largest value strictly less than largest, but ONLY
//             when found_second is true; otherwise its contents are meaningless
//
// Time:  O(n)  - one pass, no nested loop
// Space: O(1)  - three variables, independent of n

#include <iostream>
#include <vector>

int second_largest(const std::vector<int>& v) {
    int largest = v.at(0);
    int second = 0;
    bool found_second = false;

    for (int i : v) {
        if (i > largest) {
            found_second = true;
            second = largest;
            largest = i;
        }
        // Short-circuit: on the first candidate, `second` is never read.
        else if (i != largest && (!found_second || i > second)) {
            found_second = true;
            second = i;
        }
    }

    if (!found_second) return -1;
    return second;
}

#ifndef DSA_TEST
int main() {
    // Scratch space - try inputs by hand here.
    std::cout << second_largest({3, 1, 4, 1, 5}) << "  (expect 4)\n";
    return 0;
}
#endif
