// array_memory.cpp - what an array physically is.
//
// Run me:  make run FILE=cpp/basics/array_memory.cpp
//
// Nothing here is an algorithm. This is the hardware fact that every
// complexity claim about arrays rests on.

#include <iostream>
#include <vector>

#ifndef DSA_TEST
int main() {
    std::vector<int> v = {10, 20, 30, 40, 50};

    std::cout << "sizeof(int) = " << sizeof(int) << " bytes\n\n";

    std::cout << "index   value        address\n";
    for (std::size_t i = 0; i < v.size(); ++i) {
        std::cout << "  " << i << "      " << v[i] << "          "
                  << static_cast<const void*>(&v[i]) << "\n";
    }

    std::cout << "\ngap between neighbouring elements, in bytes:\n";
    for (std::size_t i = 1; i < v.size(); ++i) {
        std::cout << "  &v[" << i << "] - &v[" << i - 1 << "] = "
                  << reinterpret_cast<const char*>(&v[i]) -
                         reinterpret_cast<const char*>(&v[i - 1])
                  << "\n";
    }

    // The address of any element is computable, never searched for.
    const int index = 3;
    const char* base = reinterpret_cast<const char*>(&v[0]);
    const char* computed = base + index * sizeof(int);

    std::cout << "\nbase address        = " << static_cast<const void*>(base)
              << "\n";
    std::cout << "base + 3*sizeof(int)= " << static_cast<const void*>(computed)
              << "\n";
    std::cout << "&v[3]               = " << static_cast<const void*>(&v[3])
              << "\n";
    std::cout << "same? "
              << (computed == reinterpret_cast<const char*>(&v[3]) ? "yes"
                                                                   : "no")
              << "\n";

    return 0;
}
#endif
