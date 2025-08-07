#include <iostream>
#include <string>
#include <utility>
#include <print>

struct Logged
{
    Logged() { std::cout << "기본 생성자\n"; }
    Logged(const Logged &) { std::cout << "복사 생성자\n"; }
    ~Logged() { std::cout << "소멸자\n"; }
};

Logged create_logged_object()
{
    Logged local_obj;
    std::cout << "함수 내에서 객체 반환 직전\n";
    return local_obj;
}



void printStr(std::string &&str)
{
    str[0] = 'J';
    std::cout << str << '\n';
}

int main()
{
    std::cout << "함수 호출 시작\n";
    Logged main_obj = create_logged_object();
    std::cout << "함수 호출 완료\n";


    std::string str{"Hello~!"};
    printStr(std::move(str));
    std::cout << std::format("rvalue: {}\n", str);

    int var1{11};
    int var2{22};
    std::print("Before exchange(): a = {}, b= {}\n", var1, var2);
    int returnedValue{std::exchange(var1, var2)};
    std::print("After exchange(): a = {}, b = {}\n", var1, var2);
    std::print("exchange() returned: {}\n", returnedValue);

    return 0;
}