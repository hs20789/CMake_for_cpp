#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> myVector;
    while (true) {
        std::cout << "Enter a number to add (0 to stop): ";
        int number;
        std::cin >> number;
        if (number == 0)
            break;
        myVector.emplace_back(number);
    }
    while (true) {
        std::cout << "Enter a number to lookup (0 to stop): ";
        int number;
        std::cin >> number;
        if (number == 0) {
            break;
        }
        auto endIt{std::cend(myVector)};
        if (auto it{std::find(std::cbegin(myVector), endIt, number)};
            it == endIt) {
            std::cout << "Could not find " << number << std::endl;
        } else {
            std::cout << "Found " << *it << std::endl;
        }
    }
    auto pred1{[](int num) { return num >= 100; }};
    auto endIt{std::cend(myVector)};
    if (auto it{std::find_if(std::cbegin(myVector), endIt, pred1)};
        it == endIt) {
        std::cout << "No perfect Scores!! Try Again!" << std::endl;
    } else {
        std::cout << "You have a perfect Scores! Good Job! Bye~" << std::endl;
    }
}
