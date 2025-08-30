#include <cstdlib>
#include <ctime>
#include <iostream>

int getRandom(int min, int max)
{
    return static_cast<int>(rand() % (max + 1UL - min)) + min;
}

int main()
{

    srand(static_cast<unsigned int>(time(nullptr)));
    std::cout << rand() << std::endl;

    std::cout << getRandom(1, 150) << std::endl;
}