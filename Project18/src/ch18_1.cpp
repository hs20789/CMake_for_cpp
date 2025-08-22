#include <iostream>
#include <vector>

int main()
{
    std::vector<int, std::allocator<int>> vec{1, 2, 3};

    for (auto const &v : vec) {
        std::cout << v << "  ";
    }
    std::cout << std::endl;
}