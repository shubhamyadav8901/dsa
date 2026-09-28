#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/hashing/two_sum.cpp"

#include <vector>
#include <random>
#include <cstddef>

std::vector<int> generate_large_vector_with_single_solution(
    long target, std::vector<int> two_sum_indexes, int seed) {
    std::vector<int> result(10'000, 0);

    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> dist(target, 1'000'000'000);

    result[two_sum_indexes[0]] = dist(rng);
    result[two_sum_indexes[1]] = target - result[two_sum_indexes[0]];

    for (std::size_t i = 0; i < 10'000; i++) {
        if (i != static_cast<size_t>(two_sum_indexes[0]) &&
            i != static_cast<size_t>(two_sum_indexes[1])) {
            result[i] = dist(rng);
            while (result[i] == result[two_sum_indexes[0]])
                result[i] = dist(rng);
        }
    }

    return result;
}

int main() {
    // Tests first. Every constraint is a case - including the size bound,
    // the value extremes, duplicates, and negatives.
    //
    CHECK_EQ(two_sum({2, 7, 11, 15}, 9), (std::vector<int>{0, 1}));
    CHECK_EQ(two_sum({1, 2}, 3), (std::vector<int>{0, 1}));
    CHECK_EQ(two_sum({-1, -3}, -4), (std::vector<int>{0, 1}));
    CHECK_EQ(two_sum({2, 7, 11, 15}, 26), (std::vector<int>{2, 3}));
    CHECK_EQ(two_sum({10, 1, 0, 4, -1, 2, 3}, 0), (std::vector<int>{1, 4}));
    CHECK_EQ(two_sum({5, 1, 5}, 10), (std::vector<int>{0, 2}));

    CHECK_EQ(two_sum({1'000'000'000, 1, 2, 3, 0}, 1'000'000'000),
             (std::vector<int>{0, 4}));
    CHECK_EQ(two_sum({1'000'000'000, 1, 2, -3, -1'000'000'000, 44, -67}, 0),
             (std::vector<int>{0, 4}));

    auto two_sum_indexes = std::vector<int>{555, 5555};
    CHECK_EQ(two_sum(generate_large_vector_with_single_solution(
                         5000, two_sum_indexes, 42),
                     5000),
             two_sum_indexes);

    two_sum_indexes = std::vector<int>{0, 9'999};
    CHECK_EQ(two_sum(generate_large_vector_with_single_solution(
                         5'000'000, two_sum_indexes, 41),
                     5'000'000),
             two_sum_indexes);

    two_sum_indexes = std::vector<int>{0, 5'555};
    CHECK_EQ(two_sum(generate_large_vector_with_single_solution(
                         999'999'995, two_sum_indexes, 43),
                     999'999'995),
             two_sum_indexes);

    DSA_REPORT();
}
