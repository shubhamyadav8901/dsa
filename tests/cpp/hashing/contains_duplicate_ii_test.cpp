#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/hashing/contains_duplicate_ii.cpp"

#include <vector>
#include <random>
#include <set>
#include <cstddef>
#include <iostream>

std::vector<int> generate_large_vector_with_single_dulplicates(
    std::vector<size_t> duplicate_indexes, int seed) {
    std::set<int> s;

    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> dist(-1'000'000'000, 1'000'000'000);

    int duplicate = dist(rng);

    int random_number;
    while (s.size() < 1'00'000) {
        do {
            random_number = dist(rng);
        } while (random_number == duplicate);
        s.insert(random_number);
    }

    std::vector<int> result(s.begin(), s.end());
    result[duplicate_indexes[0]] = duplicate;
    result[duplicate_indexes[1]] = duplicate;

    return result;
}

// Every check below runs against both implementations, so the map version and
// the sliding-window version are held to exactly the same answers.
//
// `fn` is a *pointer to a function*: the same idea as a pointer to a vector
// from session 4, except what it points at is code. Calling f(...) runs
// whichever implementation the loop is currently on.
struct Implementation {
    const char* name;
    bool (*fn)(const std::vector<int>&, int);
};

int main() {
    auto large_vector = generate_large_vector_with_single_dulplicates(
        std::vector<size_t>{50'000, 99'999}, 42);

    const Implementation implementations[] = {
        {"map", contains_nearby_duplicate},
        {"window", contains_nearby_duplicate_window},
    };

    for (const Implementation& impl : implementations) {
        const auto f = impl.fn;
        const int failures_before = dsa::checks_failed;

        CHECK_TRUE(f({1, 2, 5, 6, 9, 0, 5, 2}, 10));
        CHECK_TRUE(f({1, 2, 5, 6, 9, 0, 5, 2}, 4));
        CHECK_FALSE(f({1, 2, 5, 6, 9, 0, 5, 2}, 2));

        CHECK_TRUE(f({-1, -2, -5, -6, -9, -0, -5, -2}, 10));
        CHECK_TRUE(f({-1, -2, -5, -6, -9, -0, -5, -2}, 4));
        CHECK_FALSE(f({1, -2, -5, -6, -9, -0, -5, -2}, 2));

        CHECK_TRUE(f({-1, 2, -5, -6, 9, -0, -5, -2}, 10));
        CHECK_TRUE(f({-1, 2, 5, -6, -9, -0, 5, 2}, 4));
        CHECK_FALSE(f({1, -2, 5, -6, 9, -0, -5, -2}, 2));

        CHECK_TRUE(
            f({-1, -2, -1000'000'000, -6, -9, 1'000'000'000, -0, -5, -2}, 10));
        CHECK_TRUE(f({-1, -2, -1'000'000'000, -6, -9, -0, -1'000'000'000, -2},
                     1'00'000));
        CHECK_FALSE(
            f({1000'000'000, -2, -5, 1'000'000'000, -9, -0, -5, -2}, 2));

        CHECK_FALSE(
            f({1000'000'000, -2, -5, 1'000'000'000, -9, -0, -5, -2}, 0));
        CHECK_FALSE(f({1000'000'000, 1'000'000'000, -9, -0, -5, -2}, 0));

        CHECK_FALSE(f({0}, 0));

        CHECK_FALSE(f(large_vector, 49'998));
        CHECK_TRUE(f(large_vector, 49'999));
        CHECK_TRUE(f(large_vector, 50'000));

        if (dsa::checks_failed > failures_before) {
            std::cout << "  ^ failures above are from the " << impl.name
                      << " version\n";
        }
    }

    DSA_REPORT();
}
