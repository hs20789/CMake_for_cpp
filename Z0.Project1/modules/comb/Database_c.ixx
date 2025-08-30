module;

#include <stdexcept>
#include <string>
#include <vector>
import Employee_c;

export module Database_c;

namespace Records {
    // 직원 번호의 시작값
    int const FirstEmployeeNumber{1'000};

    export class Database
    {
      public:
        // 직원 정보 업데이트 멤버 함수
        Employee &addEmployee(std::string const &fisrtName,
                              std::string const &lastName);
        Employee &getEmployee(int employeeNumber);
        Employee &getEmployee(std::string const &firstName,
                              std::string const &lastName);
        // 직원 정보 출력 멤버 함수
        void displayAll() const;
        void displayCurrent() const;
        void displayFormer() const;

      private:
        std::vector<Employee> m_employees;             // 직원 정보 벡터
        int m_nextEmployeeNumber{FirstEmployeeNumber}; // 다음 직원 번호
    };

} // namespace Records

namespace Records {
    // 직원 정보 업데이트 멤버 함수
    Employee &Database::addEmployee(std::string const &fisrtName,
                                    std::string const &lastName)
    {
        Employee theEmployee{fisrtName, lastName};
        theEmployee.setEmployeeNumber(m_nextEmployeeNumber++);
        theEmployee.hire();
        m_employees.push_back(theEmployee);
        return m_employees.back(); // 벡터의 마지막 요소의 참조를 반환
    }
    // 직원 검색 멤버 함수 - 직원 번호
    Employee &Database::getEmployee(int employeeNumber)
    {
        for (auto &employee : m_employees) {
            if (employee.getEmployeeNumber() == employeeNumber)
                return employee;
        }
        throw std::logic_error{"No employee found."};
    }
    // 직원 검색 멤버 함수 - 이름
    Employee &Database::getEmployee(std::string const &firstName,
                                    std::string const &lastName)
    {
        for (auto &employee : m_employees) {
            if (employee.getFirstName() == firstName &&
                employee.getLastName() == lastName)
                return employee;
        }
        throw std::logic_error{"No employee found."};
    }
    // 직원 정보 출력 멤버 함수
    void Database::displayAll() const
    {
        for (const auto &employee : m_employees) {
            employee.display();
        }
    }
    void Database::displayCurrent() const
    {
        for (const auto &employee : m_employees) {
            if (employee.isHired())
                employee.display();
        }
    }
    void Database::displayFormer() const
    {
        for (const auto &employee : m_employees) {
            if (!employee.isHired())
                employee.display();
        }
    }

} // namespace Records