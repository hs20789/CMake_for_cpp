#include <format>
#include <functional>
#include <iostream>
#include <span>
#include <vector>

void findMatches(std::span<int const> values1, std::span<int const> values2,
                 auto matcher, auto handler)
{
    if (values1.size() != values2.size()) {
        return;
    } // Both vectors must be same size.

    for (size_t i{0}; i < values1.size(); ++i) {
        if (matcher(values1[i], values2[i])) {
            handler(i, values1[i], values2[i]);
        }
    }
}

void printMatch(size_t position, int value1, int value2)
{
    std::cout << std::format("Match found at position {} ({}, {})", position,
                             value1, value2)
              << std::endl;
}

int main()
{
    std::vector values1{2, 500, 6, 9, 10, 101, 1};
    std::vector values2{4, 4, 2, 9, 0, 300, 1};

    findMatches(
        values1, values2,
        [](int value1, int value2) { return value1 > 100 && value2 > 100; },
        printMatch);
}
