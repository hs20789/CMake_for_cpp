#include <any>
#include <iostream>

int main()
{
    std::any empty;
    std::any anInt{3};
    using std::literals::string_literals::operator""s;
    std::any aString{"An std::string"s};

    std::cout << "empty.has_value = " << empty.has_value() << '\n';
    std::cout << "anInt.has_velue = " << anInt.has_value() << '\n';

    std::cout << "anInt wrapped type = " << anInt.type().name() << '\n';
    std::cout << "aString wrapped type = " << aString.type().name() << '\n';

    int theInt{std::any_cast<int>(anInt)};
    std::cout << theInt << '\n';
    try {
        int test{std::any_cast<int>(aString)};
        std::cout << test << '\n';
    } catch (std::bad_any_cast const &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}