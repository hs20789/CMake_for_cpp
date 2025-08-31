#include <iostream>
#include <string>
#include <variant>

void checkThis(auto const &v)
{
    std::cout << "Type Index: " << v.index() << '\n';
}

int main()
{
    std::variant<int, std::string, float> v;

    using std::literals::string_literals::operator""s;
    auto name{"Hi"s};

    v = 12;
    checkThis(v);
    v = 12.3f;
    checkThis(v);
    v = "I'm a King"s;
    checkThis(v);
    std::cout << std::boolalpha << std::holds_alternative<int>(v) << "\n";
    std::cout << std::holds_alternative<std::string>(v) << "\n";
}