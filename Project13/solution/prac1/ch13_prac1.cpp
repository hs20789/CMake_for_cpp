#include <compare>
#include <fstream>
#include <iostream>
#include <sstream>

import ch13_m1;

int main()
{
    Person person1{"Jeong", "HeonSu"};
    person1.output();
    person1.output(std::cout);
    std::ostringstream oss;
    person1.output(oss);
    std::cout << oss.str() << std::endl;
    std::fstream fs{
        "C:/Users/HeonSu/source/repos/CMake_for_cpp/Project13/solution/test.txt",
        std::ios_base::out};
    person1.output(fs);

    Person person2{"James", "Dinn", "Boss"};
    person2.output();
    person2.output(std::cout);
    std::ostringstream oss2;
    person2.output(oss2);
    std::cout << oss.str() << std::endl;
    person2.output(fs);
}