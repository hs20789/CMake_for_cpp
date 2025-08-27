#include "../include/Employee.h"
#include <iostream>
#include <memory>

using namespace Records;

int main()
{
    int (Employee::*methodPtr)() const {&Employee::getSalary};
    Employee employee1{"John", "Doe"};
    std::cout << (employee1.*methodPtr)() << std::endl;

    Employee *employee2{new Employee{"Daind", "Han"}};
    std::cout << (employee2->*methodPtr)() << std::endl;

    using PtrToGet = int (Employee::*)() const;
    PtrToGet methodPtr2{&Employee::getSalary};
    Employee employee3{"Jom", "Doduk"};
    std::cout << (employee3.*methodPtr2)() << std::endl;

    auto methodPtr3{&Employee::getSalary};
    Employee employee4{"Haward", "Arch"};
    std::cout << (employee4.*methodPtr3)() << std::endl;
}