// Move Zeroes  (LeetCode 283 · Easy)
// Statement: problems/0283-move-zeroes.md
//
// Modify v in place: all zeroes to the end, relative order of the
// non-zero elements preserved. O(1) extra space.
//
// Invariant (write it before you write the loop):
//   after processing the first k elements, ...
//
// Time:  O(?)
// Space: O(?)

#include <iostream>
#include <vector>

void move_zeroes(std::vector<int>& v) {
    // TODO
}

#ifndef DSA_TEST
int main() {
    std::vector<int> v = {0, 1, 0, 3, 12};
    move_zeroes(v);
    for (int x : v)
        std::cout << x << " ";
    std::cout << "\n";
    return 0;
}
#endif
