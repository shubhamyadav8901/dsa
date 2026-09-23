// vector_growth.cpp - what push_back actually costs.
//
// Run me:  make run FILE=cpp/basics/vector_growth.cpp
//
// size     = how many elements are in the vector
// capacity = how many it can hold before it must move to a bigger block
//
// Watch which pushes force a reallocation, and how often that happens.

#include <iostream>
#include <vector>

#ifndef DSA_TEST
int main() {
    std::vector<int> v;

    std::cout << "push   size   capacity   what happened\n";

    std::size_t previous_capacity = v.capacity();
    long long total_elements_copied = 0;

    for (int push = 1; push <= 20; ++push) {
        v.push_back(push);

        const bool reallocated = v.capacity() != previous_capacity;
        if (reallocated) {
            // Everything already in the vector had to move to the new block.
            total_elements_copied += static_cast<long long>(v.size()) - 1;
        }

        std::cout << "  " << push << "      " << v.size() << "        " << v.capacity()
                  << "         "
                  << (reallocated ? "REALLOCATED - copied everything" : "wrote into spare room")
                  << "\n";

        previous_capacity = v.capacity();
    }

    std::cout << "\nAfter 20 push_backs: " << total_elements_copied
              << " element copies caused by reallocation.\n";
    return 0;
}
#endif
