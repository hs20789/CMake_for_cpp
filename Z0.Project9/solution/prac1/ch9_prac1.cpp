#include <format>
#include <iostream>

import ch9_m1;

using namespace std;

int main()
{
    std::cout << "1. ============================================================="
                 "=======================\n\n";
    Person person{"John", "Doe"};
    cout << format("{} {}", person.getFirstName(), person.getLastName())
         << endl;
    std::cout << "2. ============================================================="
                 "=======================\n\n";

    Person persons[3];
    std::cout << "3. ============================================================="
                 "=======================\n\n";

    // Test copy constructor.
    Person copy{person};
    std::cout << "4. ============================================================="
                 "=======================\n\n";

    // Test assignment operator.
    Person otherPerson{"Jane", "Doe"};
    copy = otherPerson;
    std::cout << "5. ============================================================="
                 "=======================\n\n";

    // Test move construction.
    Person movedToPerson{std::move(copy)};
    std::cout << "6. ============================================================="
                 "=======================\n\n";

    // Test move assignment.
    movedToPerson = std::move(person);
    std::cout << "7. ============================================================="
                 "=======================\n\n";
}
