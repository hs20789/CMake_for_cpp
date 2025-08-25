#include <iostream>
#include <map>
#include <string>
#include <exception>

int main()
{
    std::map<std::string, int> myArray;
    myArray["Key 1"] = 11;
    myArray["Key 2"] = 22;
    myArray["Key 3"] = 33;

    try {
        std::cout << myArray["Key 1"] << std::endl;
        std::cout << myArray["Key 2"] << std::endl;

        std::map<std::string, int> &c{myArray};
        std::cout << c["Key 3"] << std::endl;
        std::cout << c["Key 4"] << std::endl;
    } catch (std::invalid_argument const &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

/*AssociativeArray<int> myArray;
    myArray["Key 1"] = 11;
    myArray["Key 2"] = 22;
    myArray["Key 3"] = 33;

    try {
        cout << myArray["Key 1"] << endl;
        cout << myArray["Key 2"] << endl;

        // Test const operator[]
        const AssociativeArray<int> &c{myArray};
        cout << c["Key 3"] << endl;
        cout << c["Key 4"] << endl;
    } catch (const invalid_argument &ex) {
        cout << "Caught exception: " << ex.what() << endl;
    }
    */