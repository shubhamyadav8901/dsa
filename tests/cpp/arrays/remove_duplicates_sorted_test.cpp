#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/arrays/remove_duplicates_sorted.cpp"

#include <vector>
#include <random>
#include <algorithm>

// Runs remove_duplicates on a copy and returns just the first k elements,
// so one CHECK_EQ compares both k and the contents.
std::vector<int> deduped(std::vector<int> nums) {
    int k = remove_duplicates(nums);
    return std::vector<int>(nums.begin(), nums.begin() + k);
}

std::vector<int> generate_vector(int min, int max, int seed = 43) {
    std::vector<int> result;
    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> dist(1, 5);

    int current = min;
    result.push_back(current);

    while (current < max) {
        current += dist(rng);
        if (current <= max) {
            result.push_back(current);
        }
    }
    return result;
}

std::vector<int> expand_vector(const std::vector<int>& v, size_t targetSize,
                               int seed = 43) {
    if (v.empty()) return {};

    std::vector<int> result = v;

    std::mt19937 rng(seed);
    std::uniform_int_distribution<size_t> dist(0, v.size() - 1);

    while (result.size() < targetSize)
        result.push_back(v[dist(rng)]);

    std::sort(result.begin(), result.end());

    return result;
}

int main() {
    // Tests first. Comment what each one is for.

    // examples
    CHECK_EQ(deduped({1, 1, 2}), (std::vector<int>{1, 2}));
    CHECK_EQ(deduped({0, 0, 1, 1, 1, 2, 2, 3, 3, 4}),
             (std::vector<int>{0, 1, 2, 3, 4}));

    // length 1
    CHECK_EQ(deduped({1}), (std::vector<int>{1}));

    // negative values
    CHECK_EQ(deduped({-4, -3, -3, -2, -2, -1, -1}),
             (std::vector<int>{-4, -3, -2, -1}));

    // upper & lower range
    CHECK_EQ(deduped({-100, -100, -50, 0, 0, 50, 50, 100}),
             (std::vector<int>{-100, -50, 0, 50, 100}));

    // length 3 * 10^4
    auto out_vec = generate_vector(-100, 100, 1);
    auto in_vec = expand_vector(out_vec, 3 * 10'000, 1);
    CHECK_EQ(deduped(in_vec), out_vec);

    out_vec = generate_vector(-100, 100, 3);
    in_vec = expand_vector(out_vec, 3 * 10'000, 3);
    CHECK_EQ(deduped(in_vec), out_vec);

    DSA_REPORT();
}
