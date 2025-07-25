#include <iostream>

import database;
import employee;

int main() {
    Records::Database myDB;
    Records::Employee &emp1{myDB.addEmployee("Greg", "Wallis")};
    emp1.fire();

    Records::Employee &emp2{myDB.addEmployee("Marc", "White")};
    emp2.setSalary(100'000);

    Records::Employee &emp3{myDB.addEmployee("John", "Doe")};
    emp3.setSalary(10'000);
    emp3.promote();

    std::cout << "All Employees:\n";
    myDB.displayAll();

    std::cout << "\n\nCurrent Employees:\n";
    myDB.displayCurrent();

    std::cout << "\n\nFormer Employees:\n";
    myDB.displayFormer();
}