#include <iostream>
#include <ranges>
#include <string>

int main()
{
    auto values{std::views::iota(10, 101)};
    auto result{
        values |
        std::views::transform([](auto const &value) { return value * value; }) |
        std::views::filter([](auto const &value) { return value % 5 != 0; }) |
        std::views::transform(
            [](auto const &value) { return std::to_string(value); })};

    for (auto const &v : result) {
        std::cout << v << " / ";
    }
    std::cout << std::endl;
}