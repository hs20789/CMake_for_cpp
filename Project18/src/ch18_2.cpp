#include <format>
#include <iostream>
#include <vector>

int main()
{
    std::vector<double> doubleVector;

    double max{-std::numeric_limits<double>::infinity()};
    double temp;
    for (size_t i{}; true; ++i) {
        std::cout << std::format("Enter score {} (-1 to stop): ", i + 1);
        std::cin >> temp;
        if (temp == -1) {
            break;
        }
        doubleVector.push_back(temp);
        if (temp > max) {
            max = temp;
        }
    }

    max /= 100.0;
    for (auto &element : doubleVector) {
        element /= max;
        std::cout << element << "  ";
    }
    std::cout << '\n';
}