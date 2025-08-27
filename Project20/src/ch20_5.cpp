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

void printContainer(auto &cont)
{
    for (auto const &v : cont) {
        std::cout << v << " || ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> values(10);
    int value{1};

    std::generate(std::begin(values), std::end(values), [&value] {
        value *= 2;
        return value;
    });
    for (auto const &i : values) {
        std::cout << i << " | ";
    }
    std::cout << std::endl;
    std::cout << "value : " << value << '\n';

    std::vector<int> myVector;
    populateContainer(myVector);

    std::cout << "The vector contains: " << std::endl;
    for (auto const &i : myVector) {
        std::cout << i << " || ";
    }
    std::cout << '\n';
    const int num{100};
    std::transform(std::begin(myVector), std::end(myVector),
                   std::begin(myVector), [&num](int i) { return i + num; });
    std::cout << "The vector contains: " << std::endl;
    printContainer(myVector);
}