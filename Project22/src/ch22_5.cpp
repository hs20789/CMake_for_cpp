#include <chrono>
#include <iostream>

int main()
{
    using namespace std::chrono;
    //
    time_point<steady_clock> tp1;
    steady_clock::time_point tp2;
    tp1 += minutes{10};

    auto d1{tp1.time_since_epoch()};
    duration<double> d2{d1};
    std::cout << d2.count() << " seconds" << std::endl;

    time_point<steady_clock, seconds> tpSeconds{42s};
    time_point<steady_clock, milliseconds> tpMilliseconds{tpSeconds};
    std::cout << tpMilliseconds.time_since_epoch().count() << " ms"
              << std::endl;

    time_point<steady_clock, milliseconds> tpMilliseconds2{42'424ms};
    time_point<steady_clock, seconds> tpSeconds2{
        time_point_cast<seconds>(tpMilliseconds2)};
    milliseconds ms{tpSeconds2.time_since_epoch()};
    std::cout << ms.count() << " ms" << std::endl;
}
