#include <algorithm>
#include <iostream>
#include <string>
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
    auto printContainer{[](auto const &cont) {
        for (auto &v : cont) {
            std::cout << v << " || ";
        }
        std::cout << std::endl;
    }};
    std::vector<int> vec;
    populateContainer(vec);
    std::cout << "Original vec: ";
    printContainer(vec);

    std::next_permutation(std::begin(vec), std::end(vec));
    std::cout << "After next_permutation: ";
    printContainer(vec);

    std::prev_permutation(std::begin(vec), std::end(vec));
    std::cout << "After prev_permutation: ";
    printContainer(vec);
}