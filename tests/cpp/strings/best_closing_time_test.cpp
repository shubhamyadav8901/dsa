#define DSA_TEST  // hides the playground main() in the solution file
#include "tests/cpp/dsa_test.hpp"

#include "cpp/strings/best_closing_time.cpp"

#include <cstddef>
#include <string>

int main() {
    // Boilerplate (tutor)

    // catches: the examples from the statement. "YYYY" -> 4 also catches
    // a loop that never tries closing at hour n
    CHECK_EQ(best_closing_time("YYNY"), 2);
    CHECK_EQ(best_closing_time("NNNNN"), 0);
    CHECK_EQ(best_closing_time("YYYY"), 4);

    // n = 1. catches: hour n (= 1) not considered, and the penalty of hour
    // 0 counted on the wrong side
    CHECK_EQ(best_closing_time("Y"), 1);
    CHECK_EQ(best_closing_time("N"), 0);

    // n = 10^5, 50,000 Ys then 50,000 Ns: penalty 0 only at hour 50,000.
    // catches: an off-by-one between "open at hour j" and "closed at hour
    // j", and an O(n^2) solution timing out
    std::string half_and_half(50'000, 'Y');
    half_and_half.append(50'000, 'N');
    CHECK_EQ(half_and_half.size(), std::size_t{100'000});
    CHECK_EQ(best_closing_time(half_and_half), 50'000);

    // n = 10^5, "YN" repeated: every odd hour ties at the minimum, every
    // even hour is one worse. catches: returning the latest tied hour
    // instead of the earliest (expects 1, not 99,999)
    std::string alternating;
    alternating.reserve(100'000);
    for (int i = 0; i < 50'000; ++i)
        alternating += "YN";
    CHECK_EQ(alternating.size(), std::size_t{100'000});
    CHECK_EQ(best_closing_time(alternating), 1);

    // Special cases (mine)
    // case for my bug of max = -1
    CHECK_EQ(best_closing_time("NY"), 0);
    CHECK_EQ(best_closing_time("YN"), 1);

    DSA_REPORT();
}
