#include <array>
#include <concepts>
#include <iostream>
#include <span>
#include <vector>

double average(std::span<const double> container)
{
    double sum{};
    for (auto const &v : container) {
        sum += v;
    }
    return sum / container.size();
}

template <typename T>
    requires std::integral<T> ||
             std::floating_point<T> // Type constraints: see Chapter 12
double average(std::span<const T> values)
{
    double sum{0.0};
    for (auto &value : values) {
        sum += value;
    }
    return sum / values.size();
}

int main()
{
    std::vector values1{1.1, 2.2, 3.3, 4.4};
    std::cout << average(values1) << std::endl;

    std::array<double, 4> values2{1.1, 2.2, 3.3, 4.4};
    std::cout << average(values2) << std::endl;
    std::cout << average({values2.data() + 2, 2}) << std::endl;
}