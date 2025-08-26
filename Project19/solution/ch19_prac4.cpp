#include <format>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector values{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::erase_if(values, [](int value) { return value % 2 == 0; });

    for (auto const &v : values) {
        std::cout << v << " | ";
    }
    std::cout << std::endl;
}