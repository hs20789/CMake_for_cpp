#include <exception>
#include <filesystem>
#include <format>
#include <fstream>
#include <iostream>

import SpreadsheetCell_15;

int main()
{
    SpreadsheetCell c1{1587};
    SpreadsheetCell c2{c1};
    std::filesystem::path path_{"C:/Users/HeonSu/source/repos/CMake_for_cpp/Project15/docs"};
    path_.append("test1.txt");
    std::ofstream ofs{path_};
    ofs << std::format("Value of c1: {}\nValue of c2: {}", c1.getValue(),
                       c2.getString())
        << std::endl;
    ofs << "This is End of section1" << std::endl;

    ofs << c1 << "\n" << c2 << "\nThis is End of section2" << std::endl;
    std::cout << c1 << '\n' << c2 << std::endl;
}