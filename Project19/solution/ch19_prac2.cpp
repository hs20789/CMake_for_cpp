#include <format>
#include <functional>
#include <iostream>
#include <string>
#include <string_view>

void func(int num, std::string_view str)
{
    std::cout << std::format("func({}, {}).", num, str) << std::endl;
}

int main()
{
    std::string myString{"ABC"};
    //
    auto f1{[&myString](int num) { func(num, myString); }};
    f1(16);

    auto f2{[](std::string str, int num) { func(num, std::move(str)); }};
    f2("TEST", 256);
}