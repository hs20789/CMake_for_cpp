#include <iostream>
#include <regex>
#include <string>

int main()
{
    std::regex r{R"(//\s*(.+)$)"};
    while (true) {
        std::cout << "Enter a string with optional code comments (q=quit): ";
        std::string str;
        if (!getline(std::cin, str) || str == "q")
            break;
        if (std::smatch m; std::regex_search(str, m, r))
            std::cout << std::format("\tFound comment '{}'", m[1].str())
                      << std::endl;
        else
            std::cout << "\tNo comment found!" << std::endl;
    }
}