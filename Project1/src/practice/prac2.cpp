import employee_p2;

#include <format>
#include <iostream>

int main() {
    HR::Employee anEmployee{.firstName = "Jeong",
                            .lastName = "HeonSu",
                            .employeeNumber = 1,
                            .salary = 90'000,
                            .rank = HR::Employee::Rank::senior};

    std::cout << std::format("Employee: {} {}\n", anEmployee.firstName,
                             anEmployee.lastName);
    std::cout << std::format("Number: {}\n", anEmployee.employeeNumber);
    std::cout << std::format("Salary: ${}\n", anEmployee.salary);
    switch (anEmployee.rank) {
    case HR::Employee::Rank::manager:
        std::cout << "Rank: Manager\n";
        break;
    case HR::Employee::Rank::senior:
        std::cout << "Rank: Senior\n";
        break;
    case HR::Employee::Rank::general:
        std::cout << "Rank: General\n";
        break;
    default:
        std::cout << "Rank: Unknown\n";
        break;
    }
}
