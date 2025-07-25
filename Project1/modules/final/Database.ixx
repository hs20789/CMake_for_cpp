module;

#include <string>
#include <vector>
import employee;

export module database;

namespace Records {
    // 직원 번호의 시작값
    int const FirstEmployeeNumber{1'000};

    export class Database {
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