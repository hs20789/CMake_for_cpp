#include <iostream>
#include <string>

import ch15_m3;

int main()
{
    Person person{"John", "Doe"};

    std::string str{person};
    std::cout << str << std::endl;
    std::cout << person.getInitials() << std::endl;
}