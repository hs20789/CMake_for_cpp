// #include <iostream>
// #include <print>
// #include <string>
// #include <vector>

// // 원본 스트링, 서브스트링, 대체스트링을 정의한 집합체
// struct MyStr {
//     std::string originStr;
//     std::string findStr;
//     std::string replaceStr;
// };
// // UI: 사용자로부터 원본 스트링과 그 안에서 찾을 서브스트링, 이를 대체할
// // 서브스트링을 입력받는 함수
// void inputStr(MyStr &myStr);
// // 위의 세 스트링을 입력으로 받아서 검색 대상을 원하는 값으로 교체한 스트링을
// // 리턴하는 함수
// void replaceFunc(MyStr &myStr);

// int main() {
//     MyStr myStr{}; // 값 초기화

//     inputStr(myStr);
//     std::print("After Input:\nOriginal String: {}\n", myStr.originStr);

//     replaceFunc(myStr);
//     std::print("After Replacement:\nOriginal String: {}\n", myStr.originStr);
// }

// void inputStr(MyStr &myStr) {
//     std::print("Enter Original String: ");
//     getline(std::cin, myStr.originStr);

//     std::print("Enter Find String: ");
//     getline(std::cin, myStr.findStr);
// }

// void replaceFunc(MyStr &myStr) {
//     std::string::size_type pos{};
//     while (true) {
//         pos = myStr.originStr.find(myStr.findStr);
//         if (pos == std::string::npos)
//             break;
//         myStr.originStr.replace(pos, myStr.findStr.size(), myStr.replaceStr);
//     }
// }

#include <iostream>
#include <string>
#include <string_view>

using namespace std;

// The parameters are string_view to avoid unnecessary copying.
// Note: string_view is passed by value, not by const reference.
string replace(string_view haystack, string_view needle,
               string_view replacement) {
    // Make a copy of the haystack.
    string result{haystack};

    // Find all needles and replace them with the replacement string.
    auto position{result.find(needle)};
    while (position != string::npos) {
        result.replace(position, needle.length(), replacement);
        position = result.find(needle, position + needle.size() - 1);
    }

    return result;
}

int main() {
    // Ask for the source string (= haystack).
    string haystack;
    cout << "Enter source string: ";
    getline(cin, haystack);

    // Ask for the string to find (= needle).
    string needle;
    cout << "Enter string to find: ";
    getline(cin, needle);

    // Ask for the replacement string.
    string replacement;
    cout << "Enter replacement string: ";
    getline(cin, replacement);

    // Call the replace function.
    string result{replace(haystack, needle, replacement)};

    // Print out all the strings for verification.
    cout << "Haystack: " << haystack << endl;
    cout << "Needle: " << needle << endl;
    cout << "Replacment: " << replacement << endl;
    cout << "Result: " << result << endl;
}
