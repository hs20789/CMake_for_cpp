module;


#include <format>
#include <iostream>
#include <string>

export module employee_p3;

namespace HR {
    export struct Employee {
        enum class Rank { manager, senior, general };
        std::string firstName;
        std::string lastName;
        int employeeNumber;
        int salary;
        Rank rank;
    };
    export void displayAll(auto const &employees);
    void display(Employee const &employee);

} // namespace HR

void HR::display(Employee const &employee) {
    std::cout << std::format("Employee: {} {}\n", employee.firstName,
                             employee.lastName);
    std::cout << std::format("Number: {}\n", employee.employeeNumber);
    std::cout << std::format("Salary: ${}\n", employee.salary);
    switch (employee.rank) {
    case Employee::Rank::manager:
        std::cout << "Rank: Manager\n";
        break;
    case Employee::Rank::senior:
        std::cout << "Rank: Senior\n";
        break;
    case Employee::Rank::general:
        std::cout << "Rank: General\n";
        break;
    default:
        std::cout << "Rank: Unknown\n";
        break;
    }
}

void HR::displayAll(auto const &employees) {
    for (HR::Employee const &emp : employees) {
        std::cout << "--------------------------------------------------\n";
        display(emp);
    }
}
