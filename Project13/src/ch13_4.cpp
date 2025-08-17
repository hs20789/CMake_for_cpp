#include <format>
#include <iostream>

int main()
{
    char c;
    std::cin >> c;
    std::cout << std::format("Retrieved {} before putback('e').", c)
              << std::endl;
    std::cin.putback('e');
    std::cin >> c;
    std::cout << std::format("Retrieved {} after putback ('e').\n", c);
    std::cin.get();

    char buffer[10]{};
    std::cin.getline(buffer, 10);
    std::cout << buffer << std::endl;
}