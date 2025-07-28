#include <compare>
#include <format>
#include <iostream>
#include <print>
#include <string>

int main() {
    std::string str1, str2;
    std::print("Enter str1: ");
    getline(std::cin, str1);
    std::print("Enter str2: ");
    getline(std::cin, str2);
    std::print("str1: {}\nstr2: {}\n", str1, str2);

    auto result{str1 <=> str2};
    if (std::is_lteq(result)) {
        std::print("str1 precedes str2 in dictionary order\n");
        std::print("Dictionary Order:\n{} -> {}\n", str1, str2);
    } else {
        std::print("str2 pecedes str1 in dictionary order\n");
        std::print("Dictionary Order:\n{1} -> {0}\n", str1, str2);
    }
}

/*
import <iostream>;
import <string>;
import <compare>;

using namespace std;

int main()
{
        // Ask a first string.
        string s1;
        getline(cin, s1);

        // Ask a second string.
        string s2;
        getline(cin, s2);

        // Print the strings in alphabetical order using <=>.
        if (is_lt(s1 <=> s2)) {
                cout << s1 << endl << s2 << endl;
        } else {
                cout << s2 << endl << s1 << endl;
        }
}

*/