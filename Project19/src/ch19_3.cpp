#include <functional>
#include <iostream>
#include <string>
#include <string_view>

void func(int num, std::string_view str)
{
    std::cout << std::format("func ({}, {})\n", num, str);
}

int main()
{
    std::function<void(int, std::string_view)> f1{func};
    f1(1, "test");
    auto f2{func};
    f2(2, "Set");
}
