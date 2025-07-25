// 사용자 인터페이스를 구현
// 사용자가 직원 데이터베이스를 쉽게 사용할 수 있도록
// 메뉴 기반으로 구현
// main() 함수는 화면에 메뉴를 출력하고, 여기서
// 선택한 동작을 수행하는 과정을 무한히 반복한다.
// 각 동작은 대부분 별도의 함수로 정의한다.
// 직원 정보를 화면에 출력하는 것과 같은 간단한 동작은 case에 직접 구현한다.

#include <exception>
#include <format>
#include <iostream>
#include <stdexcept>
#include <string>

import Database_c;
import Employee_c;

int displayMenu();
void doHire(Records::Database &db);
void doFire(Records::Database &db);
void doPromote(Records::Database &db);

int main() {
    Records::Database employeeDB;
    bool done{false};

    while (!done) {
        int selection{displayMenu()};
        switch (selection) {
        case 0:
            done = true;
            break;
        case 1:
            doHire(employeeDB);
            break;
        case 2:
            doFire(employeeDB);
            break;
        case 3:
            doPromote(employeeDB);
            break;
        case 4:
            employeeDB.displayAll();
            break;
        case 5:
            employeeDB.displayCurrent();
            break;
        case 6:
            employeeDB.displayFormer();
            break;
        default:
        std:;
            std::cerr << "Unknown command\n";
        }
    }
}

// 메뉴를 화면에 출력하고 사용자의 선택을 반환하는 함수
int displayMenu() {
    int selection;
    std::cout << "Employee Database Menu\n";
    std::cout
        << "-------------------------------------------------------------\n";
    std::cout << "1) Hire a New Employee!\n";
    std::cout << "2) Fire an Employee!\n";
    std::cout << "3) Promote an Employee!\n";
    std::cout << "4) Display All Employees\n";
    std::cout << "5) Display Current Employees\n";
    std::cout << "6) Display Former Employees\n";
    std::cout << "0) Exit\n";
    std::cout << "-------------------------------------------------------------"
                 "\n ---> :";
    std::cin >> selection;
    return selection;
}

// 사용자로부터 신입 직원의 이름을 입력받아서 DB 업그레이드 함수
void doHire(Records::Database &db) {
    std::string firstName;
    std::string lastName;

    std::cout << "Enter the First Name of the New Employees: ";
    std::cin >> firstName;

    std::cout << "Enter the Last Name of the New Employees: ";
    std::cin >> lastName;

    auto &employee(db.addEmployee(firstName, lastName));
    std::cout << std::format("Hired employee {} {} with employee number {}.\n",
                             firstName, lastName, employee.getEmployeeNumber());
}
// 사용자로부터 해고할 직원의 이름을 입력받아서 DB 업그레이드 함수
void doFire(Records::Database &db) {
    int employeeNumber;
    std::cout << "Employee Number to Fire: ";
    std::cin >> employeeNumber;

    try {
        auto &emp{db.getEmployee(employeeNumber)};
        emp.fire();
        std::cout << std::format("Employee {} terminated.\n", employeeNumber);

    } catch (std::logic_error const &exception) {
        std::cerr << "Unable to terminate employee: {}\n", exception.what();
    }
}
// 사용자로부터 승진할 직원의 이름을 입력받아서 DB 업그레이드 함수
void doPromote(Records::Database &db) {
    int employeeNumber;
    std::cout << "Employee Number to Promote ";
    std::cin >> employeeNumber;

    int raiseAmount;
    std::cout << "How much of a raise? (Default: Enter 0, Default Amount: "
                 "1000) ---> ";
    std::cin >> raiseAmount;

    try {
        auto &emp{db.getEmployee(employeeNumber)};
        emp.promote(raiseAmount);
    } catch (std::logic_error const &exception) {
        std::cerr << std::format("Unable to promote employee: {}\n",
                                 exception.what());
    }
}