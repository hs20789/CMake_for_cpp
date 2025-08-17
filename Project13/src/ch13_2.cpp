#include <iostream>
#include <string>

void getReservationData();
void getReservationData2();

int main()
{
    std::string userInput;
    std::cout << "Enter userInput: ";
    std::cin >> userInput;
    std::cout << "User input was " << userInput << std::endl;
    std::cin.get();

    getReservationData();

    std::cout << "============================================================="
                 "====================================\n";

    getReservationData2();
}

void getReservationData()
{
    std::string guestName;
    int partySize{};

    char ch;
    std::cin >> std::noskipws;
    while (std::cin >> ch) {
        if (isdigit(ch)) {
            std::cin.unget();
            if (std::cin.fail()) {
                std::cout << "unget() failed" << std::endl;
            }
            break;
        }
        guestName += ch;
    }
    if (std::cin) {
        std::cin >> partySize;
    }
    if (!std::cin) {
        std::cerr << "Error getting party size." << std::endl;
        return;
    }

    std::cout << std::format("Thank you '{}', party of {}", guestName,
                             partySize)
              << std::endl;
    if (partySize > 10) {
        std::cout << "An Extra gratuity will apply\n";
    }
}

void getReservationData2()
{
    std::string guestName;
    int partySize{};

    std::cin >> std::noskipws;
    while (true) {
        char ch{static_cast<char>(std::cin.peek())};
        if (!std::cin) {
            break;
        }
        if (isdigit(ch)) {
            break;
        }
        std::cin >> ch;
        if (!std::cin) {
            break;
        }
        guestName += ch;
    }
    if (std::cin)
        std::cin >> partySize;
    if (!std::cin) {
        std::cerr << "Error getting party size.\n";
        return;
    }

    std::cout << std::format("Thank you '{}', party of {}", guestName,
                             partySize)
              << std::endl;
    if (partySize > 10) {
        std::cout << "An Extra gratuity will apply\n";
    }
}