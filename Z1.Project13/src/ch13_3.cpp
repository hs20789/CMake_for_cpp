#include <iostream>
#include <sstream>
#include <string>

std::string readName(std::istream &stream);

int main()
{
    std::cout << "Enter numbers on separate lines to add.\n"
              << "Use Constrol+D followed by Enter to finish.\n";

    int sum{};

    if (!(std::cin.good())) {
        std::cerr << "Standard input is in a bas state!" << std::endl;
    }

    // while (!(std::cin.bad())) {
    //     int number{};
    //     std::cin >> number;
    //     if (std::cin.good()) {
    //         sum += number;
    //     } else if (std::cin.eof()) {
    //         break;
    //     } else if (std::cin.fail()) {
    //         std::cin.clear();
    //         std::string badToken;
    //         std::cin >> badToken;
    //         std::cerr << "WARNING: Bad input encountered: " << badToken
    //                   << std::endl;
    //     }
    // }
    std::cout << "The sum is " << sum << std::endl;
    std::string all = readName(std::cin);
    std::cout << all << std::endl;
}

std::string readName(std::istream &stream)
{
    std::string name;
    char next;
    while (stream.get(next)) {
        name += next;
    }
    return name;
}