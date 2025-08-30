#include <chrono>
#include <iostream>
#include <ratio>

int main()
{
    std::chrono::duration<long> d;
    std::cout << d.min() << std::endl;

    std::chrono::duration<long, std::ratio<1>> d1;
    std::chrono::duration<long, std::ratio<60>> d2;
    std::chrono::duration<double, std::ratio<1, 60>> d3;
    std::chrono::duration<long long, std::milli> d4;
}