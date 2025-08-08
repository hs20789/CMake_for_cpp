#include <iostream>
#include <vector>

import Spreadsheet_ch9_test;

Spreadsheet createObject();

using s = std::size_t;

struct Noisy
{
    Noisy() { std::cout << "Default constructor\n"; }
    ~Noisy() { std::cout << "Destructor\n"; }
    Noisy(const Noisy &) { std::cout << "Copy constructor\n"; }
    Noisy(Noisy &&) noexcept { std::cout << "Move constructor\n"; }
    Noisy &operator=(Noisy &&src) { std::cout << "Move operator\n"; }
};

Noisy create_noisy_nrvo()
{
    Noisy n;
    return n; // NRVO 대상
}


int main()
{
    // Spreadsheet s{Spreadsheet{2, 3}};

    // Spreadsheet s2 = Spreadsheet{10, 10};

    std::cout << "--- NRVO Test ---\n";
    Noisy obj{create_noisy_nrvo()};
    Noisy obj2 = create_noisy_nrvo();
    std::cout << "--- End of Test ---\n";
}
Spreadsheet createObject() { return Spreadsheet{3, 2}; }
