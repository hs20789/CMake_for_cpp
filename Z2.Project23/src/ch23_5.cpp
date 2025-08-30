#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <random>

int main()
{
    unsigned int const Start{1};
    unsigned int const End{99};
    unsigned int const Iterations{1'000'000};

    // 균등 메르센 트위스터
    std::random_device seeder;
    auto const seed{seeder()};
    std::mt19937 engine{static_cast<std::mt19937::result_type>(seed)};
    std::normal_distribution<double> distribution{50, 10};
    auto generator{std::bind(distribution, engine)};

    std::map<int, int> histogram;
    for (unsigned int i{}; i < Iterations; ++i) {
        int randomNumber{static_cast<int>(generator())};
        ++(histogram[randomNumber]);
    }
    std::ofstream of{"Z2.Project23/docs/res2.csv"};
    for (unsigned int i{Start}; i <= End; ++i) {
        of << i << ", " << histogram[i] << std::endl;
    }
}