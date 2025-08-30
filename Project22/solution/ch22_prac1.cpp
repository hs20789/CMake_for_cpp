#include <chrono>
#include <format>
#include <iostream>

int main()
{
    std::chrono::duration<double> d1{42}; // 42초
    std::chrono::duration<double, std::ratio<60>> d2{1.5};

    auto result{d1 + d2};

    std::cout
        << std::format(
               "result of second: {} seconds",
               std::chrono::duration_cast<std::chrono::seconds>(result).count())
        << std::endl;
    std::cout << std::format(
                     "result of minutes: {} minutes",
                     std::chrono::duration_cast<
                         std::chrono::duration<double, std::ratio<60>>>(result)
                         .count())
              << std::endl;
}
