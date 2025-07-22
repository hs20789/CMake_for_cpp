export module employee;

#include <string>   // <- import <string>; 대신 사용!

export struct Employee {
    std::string firstInitial;
    std::string lastInitial;
    int employeeNumber;
    int salary;
};
