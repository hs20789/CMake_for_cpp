#include <iostream>
#include <span>
#include <vector>

using Matcher = bool (*)(int, int);
using MatchHandler = void (*)(size_t, int, int);

void findMatches(std::span<int const> values1, std::span<int const> values2,
                 Matcher matcher, MatchHandler handler);

bool intEqual(int item1, int item2) { return item1 == item2; }
void printMatch(size_t position, int value1, int value2)
{
    std::cout << std::format("Match found at position {} ({}, {}).\n", position,
                             value1, value2);
}

int main()
{
    std::vector<int> values1{2, 5, 6, 9, 10, 1, 1};
    std::vector<int> values2{4, 4, 2, 9, 0, 3, 1};
    std::cout << "Calling findMatches() using intEqual(): \n";
    Matcher iE = intEqual;
    MatchHandler pM = printMatch;
    findMatches(values1, values2, iE, pM);
}

void findMatches(std::span<int const> values1, std::span<int const> values2,
                 Matcher matcher, MatchHandler handler)
{
    if (values1.size() != values2.size()) {
        return;
    }
    for (size_t i{}; i < values1.size(); ++i) {
        if (matcher(values1[i], values2[i])) {
            handler(i, values1[i], values2[i]);
        }
    }
}
