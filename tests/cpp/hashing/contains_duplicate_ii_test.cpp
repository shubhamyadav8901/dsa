#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/hashing/contains_duplicate_ii.cpp"

#include <vector>
#include <random>
#include <set>
#include <cstddef>

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

int main() {
    CHECK_TRUE(contains_nearby_duplicate({1, 2, 5, 6, 9, 0, 5, 2}, 10));
    CHECK_TRUE(contains_nearby_duplicate({1, 2, 5, 6, 9, 0, 5, 2}, 4));
    CHECK_FALSE(contains_nearby_duplicate({1, 2, 5, 6, 9, 0, 5, 2}, 2));

    CHECK_TRUE(contains_nearby_duplicate({-1, -2, -5, -6, -9, -0, -5, -2}, 10));
    CHECK_TRUE(contains_nearby_duplicate({-1, -2, -5, -6, -9, -0, -5, -2}, 4));
    CHECK_FALSE(contains_nearby_duplicate({1, -2, -5, -6, -9, -0, -5, -2}, 2));

    CHECK_TRUE(contains_nearby_duplicate({-1, 2, -5, -6, 9, -0, -5, -2}, 10));
    CHECK_TRUE(contains_nearby_duplicate({-1, 2, 5, -6, -9, -0, 5, 2}, 4));
    CHECK_FALSE(contains_nearby_duplicate({1, -2, 5, -6, 9, -0, -5, -2}, 2));

    CHECK_TRUE(contains_nearby_duplicate(
        {-1, -2, -1000'000'000, -6, -9, 1'000'000'000, -0, -5, -2}, 10));
    CHECK_TRUE(contains_nearby_duplicate(
        {-1, -2, -1'000'000'000, -6, -9, -0, -1'000'000'000, -2}, 1'00'000));
    CHECK_FALSE(contains_nearby_duplicate(
        {1000'000'000, -2, -5, 1'000'000'000, -9, -0, -5, -2}, 2));

    CHECK_FALSE(contains_nearby_duplicate(
        {1000'000'000, -2, -5, 1'000'000'000, -9, -0, -5, -2}, 0));
    CHECK_FALSE(contains_nearby_duplicate(
        {1000'000'000, 1'000'000'000, -9, -0, -5, -2}, 0));

    CHECK_FALSE(contains_nearby_duplicate({0}, 0));

    auto large_vector = generate_large_vector_with_single_dulplicates(
        std::vector<size_t>{50'000, 99'999}, 42);
    CHECK_FALSE(contains_nearby_duplicate(large_vector, 49'998));
    CHECK_TRUE(contains_nearby_duplicate(large_vector, 49'999));
    CHECK_TRUE(contains_nearby_duplicate(large_vector, 50'000));

    DSA_REPORT();
}
