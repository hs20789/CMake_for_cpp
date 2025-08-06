#include <iostream>
#include <string>

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

int main()
{
    std::cout << "함수 호출 시작\n";
    Logged main_obj = create_logged_object();
    std::cout << "함수 호출 완료\n";
    return 0;
}