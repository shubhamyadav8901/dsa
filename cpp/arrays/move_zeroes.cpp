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
    size_t j = 0;

    // increment i until 0
    // start j from i and increment until non zero
    // swap -> increment i, increment j until non zero
    // repeat

    for (size_t i = 0; i < v.size() && j < v.size(); i++) {
        if (v.at(i) != 0) {
            j++;
            continue;
        }

        while (j < v.size() && v.at(j) == 0) {
            j++;
        }

        if (j >= v.size()) break;

        std::swap(v.at(i), v.at(j));
    }
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
