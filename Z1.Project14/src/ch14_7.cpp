#include <exception>
#include <format>
#include <iostream>
void g() { throw std::invalid_argument{"Some Exception"}; }

void f()
{
    try {
        g();
    } catch (std::invalid_argument const &e) {
        std::cout << "Caught in f: " << e.what() << std::endl;
        throw;
    }
}

int main()
{
    try {
        f();
    } catch (std::invalid_argument const &e) {
        std::cout << "Caught in main(): " << e.what() << std::endl;
    }
}