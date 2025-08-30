#include <memory>
#include <print>

import Person3;

int main()
{
    // 1. 복제 생성자 사용
    Person person1{"Jeong", "HeonSu"};
    auto person2{std::make_unique<Person>(person1)};
    std::print("Copy Constructor\nperson1: {} {}\nperson2: {} "
               "{}\n==========================================================="
               "============================\n",
               person1.getFirstName(), person1.getLastName(),
               person2->getFirstName(), person2->getLastName());

    // 2. 대입 연산자 사용
    Person person3{"Harry", "Potter"};
    auto person4{std::make_unique<Person>()};
    *person4 = person3;
    std::print("Assign Operator\nperson3: {} {}\nperson4: {} "
               "{}\n==========================================================="
               "============================\n",
               person3.getFirstName(), person3.getLastName(),
               person4->getFirstName(), person4->getLastName());

    

}