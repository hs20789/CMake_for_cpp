#include <iostream>
#include <regex>
#include <string>

int main()
{
    std::regex r{R"((\d{4})/(0?[1-9]|1[0-2])/(0?[1-9]|[1-2][0-9]|3[0-1]))"};
    while (true) {
        std::cout << "Enter a data(year/month/day) (q=quit): ";
        std::string str;
        if (!getline(std::cin, str) || str == "q")
            break;
        if (std::smatch m; std::regex_match(str, m, r)) {
            int year{std::stoi(m[1])};
            int month{std::stoi(m[2])};
            int day{std::stoi(m[3])};
            std::cout << std::format("\tValid date: year={}, month={}, day={}.",
                                     year, month, day)
                      << std::endl;
            std::cout << "\tFull Format: " << m[0] << std::endl;
        } else
            std::cout << "\tInvalid date!" << std::endl;
    }
}