#include <iostream>
#include <regex>
#include <string>

int main()
{
    std::regex reg{R"([\w]+)"};
    while (true) {
        std::cout << "Enter a string to split (q=quit): ";
        std::string str;
        if (!std::getline(std::cin, str) || str == "q")
            break;
        std::sregex_iterator const end;
        for (std::sregex_iterator iter{std::cbegin(str), std::cend(str), reg};
             iter != end; ++iter) {
            std::cout << std::format("\"{}\"", (*iter)[0].str()) << std::endl;
        }
    }
}