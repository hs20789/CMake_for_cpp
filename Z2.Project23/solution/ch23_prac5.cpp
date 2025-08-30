#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <random>

int main()
{
    unsigned int const Start{1};
    unsigned int const End{999};
    unsigned int const Iterations{1'000'000};

    std::random_device seeder;
    auto seed{seeder.entropy() != 0 ? seeder() : std::time(nullptr)};
    std::mt19937 engine{static_cast<std::mt19937::result_type>(seed)};
    std::normal_distribution<double> distribution{500, 50};
    auto generator{std::bind(distribution, engine)};

    std::map<int, int> histogram;

    for (unsigned int i{}; i < Iterations; ++i) {
        int randomNumber{static_cast<int>(generator())};
        ++(histogram[randomNumber]);
    }
    std::ofstream of1{"Z2.Project23/solution/res1.csv"};
    for (unsigned int i{Start}; i <= End; ++i) {
        of1 << i << ", " << histogram[i] << '\n';
    }
    std::exponential_distribution<double> distribution2{0.5};
    auto generator2{std::bind(distribution2, engine)};
    std::map<int, int> histogram2;

    for (unsigned int i{}; i < Iterations; ++i) {
        int randomNumber(static_cast<int>(generator2()));
        ++(histogram2[randomNumber]);
    }
    std::ofstream of2{"Z2.Project23/solution/res2.csv"};
    for (unsigned int i{Start}; i <= End; ++i) {
        of2 << i << ", " << histogram2[i] << '\n';
    }
}