// 모듈 구현 코드
#include <iostream>

module employee;

namespace Records {
    Employee::Employee(std::string const &firstName,
                       std::string const &lastName)
        : m_firstName{firstName}, m_lastName{lastName} {}
    // 승진
    void Employee::promote(int raiseAmount) {
        setSalary(getSalary() + raiseAmount);
    }
    // 좌천
    void Employee::demote(int demeritAmount) {
        setSalary(getSalary() - demeritAmount);
    }
    // 직원 채용
    void Employee::hire() { m_hired = true; }
    // 직원 해고
    void Employee::fire() { m_hired = false; }

    // 직원 정보 출력
    void Employee::display() const {
        std::cout << std::format("Employee: {}, {}\n", getLastName(),
                                 getFirstName());
        std::cout << "---------------------------------------------------------"
                     "----------\n";
        std::cout << (isHired() ? "Current Employee\n" : "Former Employee\n");
        std::cout << std::format("Salary: ${}\n\n", getSalary());
    }

    // 게터와 세터
    void Employee::setFirstName(std::string const &fistName) {
        m_firstName = fistName;
    }
    std::string const &Employee::getFirstName() const { return m_firstName; }

    void Employee::setLastName(std::string const &lastName) {
        m_lastName = lastName;
    }
    std::string const &Employee::getLastName() const { return m_lastName; }

    void Employee::setEmployeeNumber(int employeeNumber) {
        m_employeeNumber = employeeNumber;
    }
    int Employee::getEmployeeNumber() const { return m_employeeNumber; }

    void Employee::setSalary(int salary) {
        m_salary = salary < 0 ? 0 : salary; // 급여는 음수일 수 없음
    }
    int Employee::getSalary() const {
        return m_salary; // 급여 반환
    }

    bool Employee::isHired() const { return m_hired; }
} // namespace Records
// End of module implementation code
//
//
//
//
//