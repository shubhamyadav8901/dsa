// dsa_test.hpp - a deliberately tiny test helper.
//
// There is no framework here on purpose: you should be able to read this file
// end to end and know exactly what happens when a check fails.
//
// Usage in a test file:
//
//     #define DSA_TEST                       // hides the solution's playground main()
//     #include "tests/cpp/dsa_test.hpp"
//     #include "cpp/arrays/two_sum.cpp"
//
//     int main() {
//         CHECK_EQ(twoSum({2, 7, 11, 15}, 9), (std::vector<int>{0, 1}));
//         DSA_REPORT();
//     }
//
// Note the extra parentheses around a braced expected value: the preprocessor
// splits macro arguments on commas, so {0, 1} must be wrapped.
#pragma once

#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

namespace dsa {

inline int checks_run = 0;
inline int checks_failed = 0;

// --- turning a value into something readable -------------------------------
inline std::string show(bool b) { return b ? "true" : "false"; }
inline std::string show(const std::string& s) { return "\"" + s + "\""; }
inline std::string show(const char* s) { return std::string("\"") + s + "\""; }

template <typename A, typename B>
std::string show(const std::pair<A, B>& p);
template <typename T>
std::string show(const std::vector<T>& v);

template <typename T>
std::string show(const T& value) {
    std::ostringstream out;
    out << value;
    return out.str();
}

template <typename A, typename B>
std::string show(const std::pair<A, B>& p) {
    return "(" + show(p.first) + ", " + show(p.second) + ")";
}

template <typename T>
std::string show(const std::vector<T>& v) {
    std::string out = "[";
    for (std::size_t i = 0; i < v.size(); ++i) {
        if (i > 0) out += ", ";
        out += show(v[i]);
    }
    return out + "]";
}

// --- the checks themselves --------------------------------------------------
inline void record_failure(const std::string& expr, const std::string& actual,
                           const std::string& expected, const char* file, int line) {
    ++checks_failed;
    std::cout << "  FAIL  " << expr << "\n"
              << "        expected: " << expected << "\n"
              << "        actual:   " << actual << "\n"
              << "        at " << file << ":" << line << "\n";
}

template <typename A, typename B>
void check_eq(const A& actual, const B& expected, const char* expr, const char* file, int line) {
    ++checks_run;
    if (actual == expected) return;
    record_failure(expr, show(actual), show(expected), file, line);
}

inline void check_true(bool condition, const char* expr, const char* file, int line) {
    ++checks_run;
    if (condition) return;
    record_failure(expr, "false", "true", file, line);
}

inline int report(const std::string& suite) {
    if (checks_failed == 0) {
        std::cout << "  PASS  " << suite << "  (" << checks_run << " checks)\n";
        return 0;
    }
    std::cout << "  FAILED " << suite << "  (" << checks_failed << " of " << checks_run
              << " checks failed)\n";
    return 1;
}

}  // namespace dsa

#define CHECK_EQ(actual, expected) \
    ::dsa::check_eq((actual), (expected), #actual " == " #expected, __FILE__, __LINE__)
#define CHECK_TRUE(condition) ::dsa::check_true((condition), #condition, __FILE__, __LINE__)
#define CHECK_FALSE(condition) \
    ::dsa::check_true(!(condition), "!(" #condition ")", __FILE__, __LINE__)
#define DSA_REPORT() return ::dsa::report(__FILE__)
