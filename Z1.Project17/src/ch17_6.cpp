#include <format>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

void printRange(std::string_view message, auto &range)
{
    std::cout << message;
    for (auto const &value : range) {
        std::cout << value << "  ";
    }
    std::cout << std::endl;
}

int main()
{
    // std::ranges::views의 범위 어댑터 객체 사용

    std::vector values{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printRange("Original sequence: ", values);

    auto result1{values | std::views::filter([](auto const &value) {
                     return value % 2 == 0;
                 })};
    printRange("Only even values: ", result1);

    auto result2{result1 | std::views::transform(
                               [](auto const &value) { return value * 2.0; })};
    printRange("Values doubled: ", result2);

    auto result3{result2 | std::views::drop(2)};
    printRange("First two dropped: ", result3);

    auto result4{result3 | std::views::reverse};
    printRange("Sequence reversed: ", result4);

    auto skipResult{
        values |
        std::views::filter([](auto const &value) { return value % 2 == 0; }) |
        std::views::transform([](auto const &value) { return value * 2.0; }) |
        std::views::drop(2) | std::views::reverse};
    printRange("SkipResult: ", skipResult);

    auto result5{values | std::views::filter([](auto const &value) {
                     return value % 2 == 0;
                 }) |
                 std::views::take(3) | std::views::transform([](auto const &v) {
                     return std::format(R"("{}")", v);
                 })};
    printRange("Result: ", result5);
}