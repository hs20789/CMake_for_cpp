#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

int main()
{
    std::random_device seeder;
    auto const seed{seeder.entropy() ? seeder() : time(nullptr)};
    std::mt19937 engine{static_cast<std::mt19937::result_type>(seed)};

    std::uniform_int_distribution<int> distribution{1, 99};
    std::cout << distribution(engine) << '\n';

    auto generator{std::bind(distribution, engine)};
    std::vector<int> values(10);

    std::generate(std::begin(values), std::end(values), generator);

    for (auto const &i : values)
        std::cout << i << " || ";
    std::cout << std::endl;
}