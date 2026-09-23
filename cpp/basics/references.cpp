// references.cpp - value vs reference vs pointer, made visible.
//
// Run me:  make run FILE=cpp/basics/references.cpp
//
// Predict each line of output BEFORE running.

#include <iostream>
#include <vector>

void by_value(std::vector<int> v) {  // gets a copy
    std::cout << "  by_value     sees address "
              << static_cast<const void*>(v.data()) << "\n";
    v[0] = 999;
}

void by_reference(
    std::vector<int>& v) {  // gets another name for the same vector
    std::cout << "  by_reference sees address "
              << static_cast<const void*>(v.data()) << "\n";
    v[0] = 999;
}

void by_pointer(std::vector<int>* p) {  // gets the address of the vector
    if (p == nullptr) {
        std::cout << "  by_pointer   was given nullptr - nothing to do\n";
        return;
    }
    std::cout << "  by_pointer   sees address "
              << static_cast<const void*>(p->data()) << "\n";
    (*p)[0] = 999;  // *p means "the thing p points at"
}

#ifndef DSA_TEST
int main() {
    std::vector<int> original = {1, 2, 3};
    std::cout << "main's vector lives at     "
              << static_cast<const void*>(original.data()) << "\n\n";

    by_value(original);
    std::cout << "after by_value:     original[0] = " << original[0] << "\n\n";

    original[0] = 1;
    by_reference(original);
    std::cout << "after by_reference: original[0] = " << original[0] << "\n\n";

    original[0] = 1;
    by_pointer(&original);  // &original means "the address of original"
    std::cout << "after by_pointer:   original[0] = " << original[0] << "\n\n";

    by_pointer(nullptr);
    return 0;
}
#endif
