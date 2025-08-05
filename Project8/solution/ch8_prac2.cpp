#include <print>
#include <memory>

import Person2;

int main()
{
    auto person1{std::make_unique<Person>()};
    std::print("person1: {} {}\n\n", person1->getFirstName(),
               person1->getLastName());

    auto phoneBook{std::make_unique<Person[]>(3)};
    for (int i{}; i < 3; i++) {
        std::print("person{}: {} {}\n\n", i+1, phoneBook[i].getFirstName(),
                   phoneBook[i].getLastName());
    }
}

