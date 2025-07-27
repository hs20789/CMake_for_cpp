module;

#include <string>

export module employee_p2;

namespace HR {
    export struct Employee {
        enum class Rank {
            manager,
            senior,
            general
        };
        std::string firstName;
        std::string lastName;
        int employeeNumber;
        int salary;
        Rank rank;
    };
} // namespace HR