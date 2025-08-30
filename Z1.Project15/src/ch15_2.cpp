#include <iostream>
#include <format>

class FunctionObject
{
  public:
    int operator()(int param); // 함수 호출 연산자
    int doSquare(int param);   // 일반 메서드
};

int FunctionObject::operator()(int param) { return doSquare(param); }

int FunctionObject::doSquare(int param) { return param * param; }

int main()
{
    int x{3}, xSquared, xSquaredAgain;
    FunctionObject square;
    xSquared = square(x);
    xSquaredAgain = square.doSquare(xSquared);
    std::cout << std::format("{} {} {}", x, xSquared, xSquaredAgain)
              << std::endl;

}