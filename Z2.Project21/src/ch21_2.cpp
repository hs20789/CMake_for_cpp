#include <iostream>
#include <print>
#include <regex>
#include <string>

int main()
{
    std::u8string str{u8"\u03C0 r\u00B2"};
    std::cout.write(reinterpret_cast<const char *>(str.data()), str.size());
    std::cout << std::endl;

    std::regex r{R"(\d{4}/(?:0?[1-9]|1[0-2])/(?:0?[1-9]|[1-2][0-9]|3[0-1]))"};
    while (true) {
        std::cout << "Enter a date (year/month/day) (q=quit): ";
        std::string str;
        if (!getline(std::cin, str) || str == "q")
            break;
        if (std::regex_match(str, r))
            std::cout << "Valid date." << std::endl;
        else
            std::cout << "Invalid date!." << std::endl;
    }
}