module;

#include <format>
#include <string>

export module Director_ch10_prac;

import Employee_ch10_prac;

export namespace HR
{
    export class Director : public Employee
    {
      public:
        // 사원을 감독으로 승진 시키는 변환 생성자
        Director(Employee const &emp) : Employee(emp) {}
        using Employee::Employee;
        std::string toString() const override
        {
            return std::format("Director is {}.", Employee::toString());
        }
    };
} // namespace HR