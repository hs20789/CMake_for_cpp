import HR_ch10_prac;
#include <__msvc_ostream.hpp>
#include <iostream>
#include <memory>
#include <vector>

int main()
{
    HR::Person person1{"Otis", "Lowe"};
    HR::Employee employee1{123, "Otis", "Lowe"};
    HR::Director director1{777, "Jeong", "HeonSu", "JH"};

    HR::Person person2{"Otis", "Lowe"};
    HR::Employee employee2{123, "Otis", "Lowe"};

    std::cout << person1.toString() << std::endl;
    std::cout << employee1.toString() << std::endl;
    std::cout << director1.toString() << std::endl;
    std::cout << person2.toString() << std::endl;
    std::cout << employee2.toString() << std::endl;

    std::cout << "======================================================\n\n\n";

    std::vector<std::unique_ptr<HR::Person>> persons;
    persons.push_back(std::make_unique<HR::Employee>(123, "John", "Doe"));
    persons.push_back(std::make_unique<HR::Manager>(456, "Otis", "Lowe"));
    persons.push_back(std::make_unique<HR::Director>(46, "Fran", "Stone"));
    persons.push_back(std::make_unique<HR::Employee>(33, "Harper", "Jones"));

    for (const auto &person : persons)
        std::cout << person->toString() << std::endl;

    std::cout << "======================================================\n\n\n";
    std::cout << "======================================================\n\n\n";
    std::cout << "======================================================\n\n\n";

    HR::Employee employee{123, "Carlie", "Dudley"};
    std::cout << employee.toString() << std::endl;

    // Promote employee to manager.
    HR::Manager manager{employee};
    std::cout << manager.toString() << std::endl;

    std::cout << employee2.toString() << std::endl;
    HR::Director director2{employee2};
    std::cout << director2.toString() << std::endl;
}
