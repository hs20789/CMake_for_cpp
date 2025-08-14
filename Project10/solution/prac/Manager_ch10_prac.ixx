module;

#include <format>
#include <string>

export module Manager_ch10_prac;

import Employee_ch10_prac;

export namespace HR
{
    class Manager : public Employee
    {
      public:
        // 사원을 매니저로 승진 시키기 위한 변환 생성자
        Manager(Employee const &emp) : Employee(emp) {};
        using Employee::Employee;
        std::string toString() const override
        {
            return std::format("Manager is {}.", Employee::toString());
        }
    };

} // namespace HR