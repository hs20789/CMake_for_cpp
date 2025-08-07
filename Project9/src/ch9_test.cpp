#include <iostream>
#include <vector>

import Spreadsheet_ch9_test;

Spreadsheet createObject();

using s = std::size_t;

int main()
{
    std::vector<Spreadsheet> vec;
    for (s i{}; i < 4; i++) {
        std::cout << "Iteration " << i+1 << std::endl;
        vec.push_back(Spreadsheet{100, 100});
        std::cout << std::endl;
    }
    Spreadsheet s{2, 3};
    s = createObject();

    

    Spreadsheet s2{3, 2};
    s2 = s;


    std::cout << "============================================================="
                 "=============\n\n";

    Spreadsheet s3 = createObject();
}

Spreadsheet createObject() { return Spreadsheet{3, 2}; }
