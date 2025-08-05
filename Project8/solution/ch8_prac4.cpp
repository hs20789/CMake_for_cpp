#include <iostream>
#include <memory>

import Person4;

//int main()
//{
//    auto person{std::make_unique<Person>("Jeong", "HeonSu")};
//    std::cout << "person: " << person->getFirstName() << ' '
//              << person->getLastName() << '\n';
//    std::cout << "person\'s initial: " << person->getInitial() << '\n';
//}



using namespace std;

int main()
{
    Person person{"John", "Doe"};
    cout << format("The initials of {} {} are {}.", person.getFirstName(),
                   person.getLastName(), person.getInitial())
         << endl;

    Person person2{"Marc", "Gregoire", "Mg"};
    cout << format("The initials of {} {} are {}.", person2.getFirstName(),
                   person2.getLastName(), person2.getInitial())
         << endl;

    Person persons[3];

    // Test copy constructor.
    Person copy{person};

    // Test assignment operator.
    Person otherPerson{"Jane", "Doe"};
    copy = otherPerson;
}
