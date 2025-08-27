#include <format>
#include <iostream>
#include <vector>

int main()
{
    std::vector<double> doubleVector(10);
    double max{-(std::numeric_limits<double>::infinity())};

    for (size_t i{}; i < doubleVector.size(); ++i) {
        std::cout << std::format("Enter score {}: ", i + 1);
        std::cin >> doubleVector[i];
        max = doubleVector[i] > max ? doubleVector[i] : max;
    }

    max /= 100.0;
    for (auto &element : doubleVector) {
        element /= max;
        std::cout << element << "  ";
    }
    std::cout << std::endl;
}