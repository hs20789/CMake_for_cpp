export module employee;

#include <string>   // <- import <string>; ��� ���!

export struct Employee {
    std::string firstInitial;
    std::string lastInitial;
    int employeeNumber;
    int salary;
};
