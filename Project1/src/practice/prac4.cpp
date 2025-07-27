#include <array>
#include <iostream>

import employee_p4;

int main() {
    int selection{};
    HR::DB database{};
    while (true) {
        std::cout << "1. Add Employee\n"
                  << "2. Display All Employees\n"
                  << "3. Exit\n"
                  << "Select an option: ";
        std::cin >> selection;
        switch (selection) {
        case 1:
            HR::addEmployee(database);
            break;
        case 2:
            HR::displayAll(database);
            break;
        case 3:
            std::cout << "Exiting...\n";
            return 0;
        }
    }
}