#include <iostream>
#include <locale>
#include <string>

int main()
{
    std::string str{__FILE__};
    std::cout << str << std::endl;
    auto num{__cplusplus};
    std::cout << num << std::endl;

    wchar_t myWideCharacter{L'm'};
    std::wcout << L"I am a wide-character string literal." << std::endl;

    std::wcout.imbue(std::locale{"en_US"});
    std::wcout << 32767 << std::endl;
}