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

bool intEqual(int value1, int value2) { return value1 == value2; }

class Handler
{
  public:
    void handleMatch(size_t position, int value1, int value2)
    {
        std::cout << std::format("Match found at position {} ({}, {}).",
                                 position, value1, value2)
                  << std::endl;
    }
};

int main()
{
    Handler h;
    std::vector values1{22, 11, 33, 44, 55};
    std::vector values2{11, 22, 33, 44, 55};
    findMatches(values1, values2, intEqual,
                [&h](size_t position, int value1, int value2) {
                    h.handleMatch(position, value1, value2);
                });
}