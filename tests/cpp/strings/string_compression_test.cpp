#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/strings/string_compression.cpp"

#include <vector>

int main() {
    // compress() changes its argument and returns a length, so check both:
    // the returned length, and the first `length` characters of the vector.

    // examples
    std::vector<char> v1{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    CHECK_EQ(compress(v1), 6);
    v1.resize(6);
    CHECK_EQ(v1, (std::vector<char>{'a', '2', 'b', '2', 'c', '3'}));

    // chars.length = 1
    std::vector<char> v2{'a'};
    CHECK_EQ(compress(v2), 1);
    v2.resize(1);
    CHECK_EQ(v2, (std::vector<char>{'a'}));

    std::vector<char> v3{'a', 'b', 'b', 'b', 'b', 'b', 'b',
                         'b', 'b', 'b', 'b', 'b', 'b'};
    CHECK_EQ(compress(v3), 4);
    v3.resize(4);
    CHECK_EQ(v3, (std::vector<char>{'a', 'b', '1', '2'}));

    // more than 9 repeats
    std::vector<char> v4{'b', 'b', 'b', 'b', 'b', 'b', 'b',
                         'b', 'b', 'b', 'b', 'b', 'b'};
    CHECK_EQ(compress(v4), 3);
    v4.resize(3);
    CHECK_EQ(v4, (std::vector<char>{'b', '1', '3'}));

    // smoke test for chars.length = 2000
    std::vector<char> v5(2000, 'a');
    CHECK_EQ(compress(v5), 5);
    v5.resize(5);
    CHECK_EQ(v5, (std::vector<char>{'a', '2', '0', '0', '0'}));

    // lowercase, uppercase, digit and symbol
    std::vector<char> v6{'a', 'A', 'A', '1', '1', '1', '&', '&'};
    CHECK_EQ(compress(v6), 7);
    v6.resize(7);
    CHECK_EQ(v6, (std::vector<char>{'a', 'A', '2', '1', '3', '&', '2'}));

    DSA_REPORT();
}
