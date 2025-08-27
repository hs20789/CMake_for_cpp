#include <iostream>
#include <string>

import Person_ch11;

int main()
{
    Person person1{"kole", "Webb"};
    std::cout << person1.getFirstName() << ", " << person1.getLastName()
              << std::endl;
}
