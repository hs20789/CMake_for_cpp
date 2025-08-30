module;

#include <string>

export module employee_p1;

namespace HR {
    export struct Employee {
        std::string firstName;
        std::string lastName;
        int employeeNumber;
        int salary;
    };
} // namespace HR