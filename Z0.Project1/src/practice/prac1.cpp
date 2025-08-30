import employee_p1;

#include <format>
#include <iostream>

int main() {
    HR::Employee anEmployee{.firstName = "Jeong",
                            .lastName = "HeonSu",
                            .employeeNumber = 1,
                            .salary = 90'000};

    std::cout << std::format("Employee: {} {}\n", anEmployee.firstName,
                             anEmployee.lastName);
    std::cout << std::format("Number: {}\n", anEmployee.employeeNumber);
    std::cout << std::format("Salary: ${}\n", anEmployee.salary);
}
