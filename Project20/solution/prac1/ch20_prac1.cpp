#include <algorithm>
#include <format>
#include <iostream>
#include <vector>

int main()
{
    int tempVal{};
    std::vector<int> vec;
    vec.resize(10);
    for (int i{}; i < 10; i++) {
        std::cout << std::format("Enter vector's {}st value: ", i);
        std::cin >> tempVal;
        std::fill(std::begin(vec) + i, (std::begin(vec) + i + 1), tempVal);
    }
    std::cout << "The result vec: ";
    for (auto const &v : vec) {
        std::cout << v << " || ";
    }
    std::cout << std::endl;
}