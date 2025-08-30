#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

void trim(std::string &str);

int main()
{
    std::string str{"          HIHIHIHI ALOHA      "};
    std::cout << std::format("Before Trim: |{}|\n", str);

    trim(str);
    std::cout << std::format("After Trim: |{}|\n", str);
}

void trim(std::string &str)
{
    auto notspace = [](unsigned char ch) { return !std::isspace(ch); };
    str.erase(std::begin(str),
              std::find_if(std::cbegin(str), std::cend(str), notspace));

    str.erase(std::find_if(std::rbegin(str), std::rend(str), notspace).base(),
              std::end(str));
}
