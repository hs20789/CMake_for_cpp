#include <format>
#include <iostream>
#include <memory>
#include <string>

import KeyValuePair;

int main()
{
    // 정석으로 만들기
    KeyValuePair<std::string, int> test1{"HeonSu", 123};
    std::cout << std::format("test1 => key: {}, value: {}\n", test1.getKey(),
                             test1.getValue());

    // CTAD
    KeyValuePair test2{264, 815};
    std::cout << std::format("test2 => key: {}, value: {}\n", test2.getKey(),
                             test2.getValue());

    auto test3{
        std::make_unique<KeyValuePair<std::string, double>>("David", 3.1415)};
    std::cout << std::format("test3 => key: {}, value: {}\n", test3->getKey(),
                             test3->getValue());

    using std::literals::string_literals::operator""s;
    KeyValuePair test4{815, "DongJu"s};
    std::cout << std::format("test4 => key: {}, value: {}\n", test4.getKey(),
                             test4.getValue());

    KeyValuePair<char const*, char const*> test5{"John", "Legends"};
    std::cout << std::format("test5 => key: {}, value: {}\n", test5.getKey(),
                             test5.getValue());
}