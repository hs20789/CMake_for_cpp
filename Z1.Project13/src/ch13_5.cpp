#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::cout << "Enter tokens."
              << "Control+D followed by Enter to end." << std::endl;
    std::ostringstream outStream;
    while (std::cin) {
        std::string nextToken;
        std::cout << "Next token: ";
        std::cin >> nextToken;
        if (!std::cin || nextToken == "done") {
            break;
        }
        outStream << nextToken << "\t";
    }
    std::cout << "The end result is : " << outStream.str();
    std::cout << '\n';
    std::cin.get();
    std::string text{"123 456"};
    std::istringstream iss{text};
    int a{}, b{};
    iss >> a >> b;
    std::cout << a << b << std::endl;
}
