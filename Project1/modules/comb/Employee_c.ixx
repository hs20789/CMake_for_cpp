module;

#include <iostream>
#include <string>

export module Employee_c;

namespace Records {
    // 신입 직원에 대한 기본 급여
    int const DefaultStartingSalary{30'000};
    // 직원 승진과 좌천시 적용할 기본 액수 - 외부 접근을 위해 export 필요
    export int const DefaultRaiseAndDemeritAmount{1'000};

    // 직원 클래스
    export class Employee {
        // 멤버 함수를 public으로 설정하여 외부에서 접근 가능하도록 함
        // 멤버 함수로 private 멤버 데이터에 접근할 수 있음
      public:
        Employee(std::string const &fisrtName,
                 std::string const &lastName); // 생성자
        void promote(int raiseAmount =
                         DefaultRaiseAndDemeritAmount); // 승진 멤버 public 함수
        void demote(int demeritAmount =
                        DefaultRaiseAndDemeritAmount); // 좌천 멤버 public 함수
        void hire();          // 직원 채용 및 재고용 멤버 public 함수
        void fire();          // 직원 해고 멤버 public 함수
        void display() const; // 직원 정보 출력 멤버 public 함수

        // getter / setter 멤버 public 함수
        void setFirstName(std::string const &fistName);
        std::string const &getFirstName() const;

        void setLastName(std::string const &lastName);
        std::string const &getLastName() const;

        void setEmployeeNumber(int employeeNumber);
        int getEmployeeNumber() const;

        void setSalary(int salary);
        int getSalary() const;

        bool isHired() const;

        // 멤버 데이터를 private로 설정하여 외부에서 직접 접근하지 못하도록 함
      private:
        std::string m_firstName;             // 직원 이름
        std::string m_lastName;              // 직원 성
        int m_employeeNumber{-1};            // 직원 번호
        int m_salary{DefaultStartingSalary}; // 직원 급여
        bool m_hired{false};                 // 직원 채용 여부
    };

} // namespace Records



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