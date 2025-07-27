#include <array>
#include <iostream>

import employee_p3;

int main() {
    HR::Employee emp1{.firstName = "Jeong",
                      .lastName = "HeonSu",
                      .employeeNumber = 1,
                      .salary = 90'000,
                      .rank = HR::Employee::Rank::manager};

    HR::Employee emp2{.firstName = "James",
                      .lastName = "Dinn",
                      .employeeNumber = 2,
                      .salary = 50'000,
                      .rank = HR::Employee::Rank::senior};

    HR::Employee emp3{.firstName = "Bread",
                      .lastName = "Jin",
                      .employeeNumber = 3,
                      .salary = 30'000,
                      .rank = HR::Employee::Rank::general};

    std::array<HR::Employee, 3> employees{emp1, emp2, emp3};
    HR::displayAll(employees);
}