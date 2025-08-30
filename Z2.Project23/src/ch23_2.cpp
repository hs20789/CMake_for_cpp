#include <iostream>
#include <random>

int main()
{
    std::random_device rnd;
    std::cout << "Entropy: " << rnd.entropy() << std::endl;
    std::cout << "Min value: " << rnd.min() << '\n';
    std::cout << "Max value: " << rnd.max() << '\n';
    std::cout << "Random Number: " << rnd() << '\n';
    std::cout << "Random Number2: " << rnd() << '\n';
}