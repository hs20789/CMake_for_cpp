module;

#include <format>
#include <iostream>
#include <string>
#include <vector>

export module employee_p4;

namespace HR {
    struct Employee {
        enum class Rank { manager, senior, general };
        std::string firstName;
        std::string lastName;
        int employeeNumber;
        int salary;
        Rank rank;
    };

    export struct DB {
        std::vector<Employee> employees;
        int numOfEmployee;
    };

    export void displayAll(DB const &database); //
    void display(Employee const &employee);     //
    export void addEmployee(DB &database);

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

void HR::displayAll(DB const &database) {
    for (HR::Employee const &emp : database.employees) {
        std::cout << "--------------------------------------------------\n";
        std::cout << std::format("Total Employees: {}\n",
                                 database.numOfEmployee);
        display(emp);
    }
}

void HR::addEmployee(HR::DB &database) {
    std::string firstName, lastName;
    int employeeNumber{}, salary{};
    HR::Employee::Rank rank;
    std::cout << "Enter employee First Name: ";
    std::cin >> firstName;
    std::cout << "Enter employee Last Name: ";
    std::cin >> lastName;
    std::cout << "Enter employee Number: ";
    std::cin >> employeeNumber;
    std::cout << "Enter employee Salary: ";
    std::cin >> salary;
    std::cout << "Enter employee Rank (0: Manager, 1: Senior, 2: General): ";
    int rankInput{};
    std::cin >> rankInput;
    rank = static_cast<HR::Employee::Rank>(rankInput);

    HR::Employee newEmployee{.firstName = firstName,
                             .lastName = lastName,
                             .employeeNumber = employeeNumber,
                             .salary = salary,
                             .rank = rank};
    database.employees.push_back(newEmployee);
    database.numOfEmployee++;
}
