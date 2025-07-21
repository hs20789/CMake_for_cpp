#include <iostream>

#include "namespace.h"

namespace global_namespace {
void f() { std::cout << "This is Global's namespace\n"; }
}  // namespace global_namespace

int main() {
    std::cout << "Hello, World!" << std::endl;

    // std::endl
    std::cout << std::format("There are {} ways I love you", 219) << std::endl;
    std::cout << std::format("There are {} ways I love you\n", 219);

    // 입출력 연산은 반드시 명령문 단위로 처리
    int value;
    std::cout << "Enter Value: ";
    std::cin >> value;

    header_namespace::f();
    global_namespace::f();

    return 0;
}

namespace header_namespace {
void f() { std::cout << "This is Header's namespace\n"; }
}  // namespace header_namespace
