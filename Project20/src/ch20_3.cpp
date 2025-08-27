#include <algorithm>
#include <concepts>
#include <iostream>
#include <iterator>
#include <list>
#include <utility>
#include <vector>

void populateContainer(auto &cont)
    requires requires(decltype(cont) c, int v) {
        { c.push_back(v) } -> std::same_as<void>;
    };

int main()
{
    std::vector<int> myVector;
    std::list<int> myList;

    std::cout << "Populate the vector: \n";
    populateContainer(myVector);
    std::cout << "Populate the list: \n";
    populateContainer(myList);

    if (std::equal(std::cbegin(myVector), std::cend(myVector),
                   std::cbegin(myList), std::cend(myList))) {
        std::cout << "The two containers have equals elements" << std::endl;
    } else {
        auto miss{std::mismatch(std::cbegin(myVector), std::cend(myVector),
                                std::cbegin(myList), std::cend(myList))};
        std::cout << "The following initial elements are the same in "
                  << "the vector and the list: \n";
        for (auto i{std::cbegin(myVector)}; i != miss.first; ++i) {
            std::cout << *i << '\t';
        }
        std::cout << std::endl;
    }

    if (std::lexicographical_compare(std::cbegin(myVector), std::cend(myVector),
                                     std::cbegin(myList), std::cend(myList))) {
        std::cout << "The vector is lexicographically first." << std::endl;
    } else {
        std::cout << "The list is lexicographically first." << std::endl;
    }
}

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