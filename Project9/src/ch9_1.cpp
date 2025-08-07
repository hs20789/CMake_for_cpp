#include <cstddef>
#include <format>
#include <iostream>
#include <memory>
#include <vector>

import Spreadsheet_ch9_3;

Spreadsheet createObject() { return Spreadsheet{3, 2}; }

using s = std::size_t;

int main()
{
    std::vector<Spreadsheet> vec;
    for (s i{}; i < 2; i++) {
        std::cout << "Iteration " << i << std::endl;
        vec.push_back(Spreadsheet{100, 100});
        std::cout << std::endl;
    }
    Spreadsheet s{2, 3};
    s = createObject();

    Spreadsheet s2{5, 6};
    s2 = s;
}
