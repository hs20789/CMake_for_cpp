#include <iostream>
import employee;

int main() {
    std::cout << "Testing the Employee Class.\n";
    Records::Employee emp{"Jane", "Doe"};
    emp.display();
    emp.setFirstName("Jeong");
    emp.setLastName("HeonSu");
    emp.setEmployeeNumber(71);
    emp.promote();
    emp.promote(50);
    emp.hire();
    emp.display();
    emp.fire();
    emp.display();

}