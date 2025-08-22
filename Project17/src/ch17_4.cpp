#include <algorithm>
#include <concepts>
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

int main()
{
    std::vector<int> data{14, 1, 22, 4, 3, 8};
    std::ranges::sort(data);

    for (auto it{std::cbegin(data)}; it != std::cend(data); ++it) {
        std::cout << *it << "  ";
    }
    std::cout << '\n';
    //
}
