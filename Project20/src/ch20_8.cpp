#include <algorithm>
#include <iostream>
#include <vector>

void populateContainer(auto &cont)
    requires requires(decltype(cont) c, int v) {
        { c.push_back(v) } -> std::same_as<void>;
    }
{
    while (true) {
        std::cout << "Enter a number (0 to quit): ";
        int value;
        std::cin >> value;
        if (value == 0) {
            break;
        }
        cont.push_back(value);
    }
}

int main()
{
    auto printCont{[](auto const &cont) {
        for (auto &v : cont) {
            std::cout << v << " || ";
        }
        std::cout << std::endl;
    }};
    std::vector<int> values;
    populateContainer(values);

    std::cout << "Befor replace_if:\n";
    printCont(values);
    std::replace_if(
        std::begin(values), std::end(values), [](int i) { return i % 2 != 0; },
        0);
    std::cout << "After replace_if:\n";
    printCont(values);

    std::vector<std::string> myVector{"", "one", "", "two", "three", "four"};
    for (auto const &str : myVector) {
        std::cout << "\"" << str << "\"";
    }
    std::cout << std::endl;
    std::erase_if(myVector, [](std::string const &str) { return str.empty(); });
    for (auto const &str : myVector) {
        std::cout << "\"" << str << "\"";
    }
}