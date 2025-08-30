#include <chrono>
#include <iostream>
#include <ratio>

int main()
{
    std::chrono::duration<long, std::ratio<60>> d1{123};
    std::cout << d1.count() << std::endl;

    auto d2{std::chrono::duration<double>::max()};
    std::cout << d2.count() << std::endl;

    std::chrono::duration<long, std::ratio<60>> d3{10};
    std::chrono::duration<long> d4{14};

    if (d3 > d4)
        std::cout << "d3 > d4\n";
    else
        std::cout << "d3 <= d4\n";
    ++d4;
    d4 *= 2;

    std::chrono::duration<double, std::ratio<60>> d5{d3 + d4};
    std::chrono::duration<long, std::ratio<1>> d6{d3 + d4};
    std::cout << std::format(
        "{} minutes + {} seconds = {} minutes or {} seconds\n", d3.count(),
        d4.count(), d5.count(), d6.count());

    std::chrono::duration<long> d7{30};

    std::chrono::duration<double, std::ratio<60>> d8{d7};
    std::cout << std::format("{} seconds = {} minutes\n", d7.count(),
                             d8.count());

    auto t{std::chrono::hours{1} + std::chrono::minutes{23} +
           std::chrono::seconds{45}};
    std::cout << std::format("{} seconds\n", std::chrono::seconds{t}.count());
}