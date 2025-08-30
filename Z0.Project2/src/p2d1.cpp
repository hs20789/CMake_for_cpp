#include <charconv>
#include <cstring>
#include <iostream>
#include <print>
#include <string>
#include <string_view>

// C 스타일 스트링
char *copyString(char const *str);
char *appendString(char const *str1, char const *str2, char const *str3);

// std::string_view 클래스
std::string_view extractExtension(std::string_view filename);
void handleExtension(std::string const &extension) {
    std::cout << extension << '\n';
}

int main() {
    char text1[]{"abcdef"};
    std::cout << std::format("sizeof(text1): {}\nstrlen(text1): {}\n",
                             sizeof(text1), strlen(text1));
    char const *text2{"abcdefghjkilmnopqrstuvwxyz"};
    std::cout << std::format("sizeof(text2): {}\nstrlen(text2): {}\n",
                             sizeof(text2), strlen(text2));

    // 로 스트링 리터럴
    char const *str{R"(Hello "World!"   
HI~)"};
    std::cout << str << '\n';

    // C++ std::string 클래스
    std::string str1{"12"};
    std::string str2{"34"};
    std::string str3{str1 + str2};
    // += 연산 또한 지원,, str3+=str1; str3+=str2;
    std::cout << std::format("str1: {}, str2: {}, str3: {}\n", str1, str2,
                             str3);
    std::string str1ToCompare{"12"};

    // std::string은 C++ 표준에 따라 반드시 깊은 복사가 일어난다.
    std::string str4{"hello"};
    str4 += ", there";
    std::string str5{str4}; // 복사 생성자
    if (str4 == str5) {
        str5[0] = 'H';
    }
    std::cout << std::format("str4: {}\nstr5: {}\n", str4, str5);

    //
    // C 스트링과 호환
    // C 스트링은 char*, char[]
    // C++ 스트링은 char*, char[](저수준) / std::string(고수준)
    //
    //
    using std::literals::string_literals::operator""s;

    auto str6{"Hello World"};
    auto str7{"Hello World"s};
    if constexpr (!std::is_same_v<decltype(str6), decltype(str7)>)
        std::cout
            << "str6{\"Hello World\"} is not same str7{\"Hello World\"s}\n";
    else
        std::cout << "str6{\"Hello World\"} is same str7{\"Hello World\"s}\n";

    // 스트링 연산
    // substr(pos, len): 인수로 지정한 시작 위치와 길이에 맞는 서브스트링을
    // 리턴한다. find(str): 인수로 지정한 서브스트링이 있는 지점을 리턴한다.
    // 없다면 std::string::npos를 리턴한다.
    // replace(pos, len, str): 스트링에서 인수로 지정한 위치와 길이에 해당하는
    // 부분을 str로 지정한 값으로 교체한다.
    // starts_with(str) / ends_with(str): C++20) 인수로 지정한 서브스트링으로
    // 시작하거나 끝나면 true를 리턴한다.
    std::string str8{"Hello!!"};
    std::string str9{"The World..."};
    std::cout << std::format("Before:\nst8: {}\nstr9: {}\n", str8, str9);
    auto position1{str8.find("!!")};
    auto position2{str9.find("World")};
    if (position1 != std::string::npos && position2 != std::string::npos) {
        str8.replace(position1, 2, str9.substr(position2, 6));
    }
    std::cout << std::format("After:\nstr8: {}\nstr9: {}\n", str8, str9);
    if (str8.starts_with("Hello")) {
        std::cout << str8 << '\n';
    }

    // 숫자 변환
    // 고수준 숫자 변환 (std::string 객체 수준에서 숫자와 상호 변환)
    // 숫자 -> std::string
    std::string str10{std::to_string(123456789)};
    std::string str11{std::to_string(3.142)};
    std::cout << "std::to_string 사용\n" << str10 + str11 << '\n';
    // c++ 20 부터는 std::format 사용 가능
    std::string str12{std::format("{}", 123456789)};
    std::string str13{std::format("{:.3f}", 3.142)};
    std::print("std:::format 사용\n{}\n", str12 + str13);
    // std::string -> 숫자
    std::string const str14{"  123USD  "};
    size_t index{0};
    int value{std::stoi(str14, &index)};
    std::print("Parsed Value: {}\n", value);
    std::print("First non-parased character: \'{}\'\n", str14[index]);

    // 저수준 숫자 변환 (char* 수준에서 숫자와 상호변환)
    // 숫자 -> 스트링
    size_t const BufferSize{50};
    // 리스트 초기화시 std::initializer_list 채택
    std::string str15(BufferSize, ' ');
    std::to_chars_result result{
        std::to_chars(str15.data(), str15.data() + str15.size(), 123456789)};
    if (result.ec == std::errc{}) {
        std::print("Transformed Complete!: {}\n", str15);
    }
    std::string str16(BufferSize, ' ');
    auto [ptr, error]{
        std::to_chars(str16.data(), str16.data() + str16.size(), 123456789)};
    if (error == std::errc{}) {
        std::print("Complete: {}\n", str16);
    }
    // 스트링 -> 숫자
    std::string str17{"12345678USD   "};
    size_t numOfOutput{};
    std::from_chars_result result2{std::from_chars(
        str17.data(), str17.data() + str17.size(), numOfOutput)};
    if (result2.ec == std::errc{}) {
        std::print("Num: {}\n", numOfOutput);
        std::print("First None Num: {}\n", *result2.ptr);
    }
    // 퍼펙트 라운드 트리핑
    double value1{0.314};
    std::string str18(BufferSize, ' ');
    std::to_chars_result result3{
        std::to_chars(str18.data(), str18.data() + str18.size(), value1)};
    if (result3.ec == std::errc{}) {
        std::print("Transformed Complete: {}\n", str18);
    }
    double value2{};
    std::from_chars_result result4{
        std::from_chars(str18.data(), str18.data() + str18.size(), value2)};
    if (result4.ec == std::errc{}) {
        if (value1 == value2)
            std::print("Perfect roundtrip\n");
        else
            std::print("No perfect roundtrip\n");
    }

    // std::string_view
    std::string filename1{R"(C:\temp\myFile.ext)"};
    std::print("C++ string: {}\n", extractExtension(filename1));

    char const *filename2{R"(C:\temp\myFile.ext)"};
    std::print("C String: {}\n", extractExtension(filename2));

    std::print("Literal: {}\n", extractExtension(R"(C:\temp\myFile.ext)"));

    // handleExtension(extractExtension("my file.ext"));
    //  오류 string_view -> char const* 로의 암시적 변환은 불가
    handleExtension(extractExtension("my file.ext").data());
    handleExtension(std::string{extractExtension("my file.ext")});

    using std::literals::string_view_literals::operator""sv;
    auto str19{"This is string_view type!"sv};
    std::string_view str20{"Type of string_view"};
    if constexpr (std::is_same_v<decltype(str19), decltype(str20)>) {
        std::print("same type\n");
    }
}

char *copyString(char const *str) {
    char *result{new char[strlen(str) + 1]};
    strcpy(result, str);
    return result;
}
char *appendString(char const *str1, char const *str2, char const *str3) {
    char *result{new char[strlen(str1) + strlen(str2) + strlen(str3) + 1]};
    strcpy(result, str1);
    strcat(result, str2);
    strcat(result, str3);
    return result;
}

std::string_view extractExtension(std::string_view filename) {
    return filename.substr(filename.rfind('.'));
}
