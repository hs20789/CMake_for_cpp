#include <format>
#include <iostream>
import PhoneBook;
import ch18_m2;

using namespace std;

int main()
{
    PhoneBook phoneBook;
    phoneBook.addPhoneNum("John Doe"_p, "123-456-789");
    phoneBook.addPhoneNum("Jane Doe"_p, "789-456-123");
    phoneBook.addPhoneNum("John Doe"_p, "999-456-789");
    phoneBook.addPhoneNum("Marc Gregoire"_p, "258-369-147");
    phoneBook.removePhoneNum("Marc Gregoire"_p, "258-369-147");
    phoneBook.removePhoneNum("Marc G"_p, "258-369-147");

    cout << "John Doe's phone numbers:" << endl;
    for (const auto &number : phoneBook.getAllPhoneNum("John Doe"_p)) {
        cout << "\t" << number << endl;
    }
}
