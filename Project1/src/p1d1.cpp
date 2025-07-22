#include "namespace.h"
#include <cstddef>
#include <iostream>
#include <limits>

// 중첩 네임 스페이스
namespace global_namespace {
    void f() { std::cout << "This is Global's namespace\n"; }
    namespace inner_namespace {
        void g() { std::cout << "This is Inner Namespace\n"; }
    } // namespace inner_namespace
} // namespace global_namespace

// c++17 이후부터의 중첩 네임스페이스
namespace global_namespace::inner_namespace::deep_namespace {
    void h() { std::cout << "This is Inner's deep namespace\n"; }
} // namespace global_namespace::inner_namespace::deep_namespace

int main() {
    std::cout << "Hello, World!" << std::endl;

    // std::endl과 '\n'
    std::cout << std::format("There are {} ways I love you", 219) << std::endl;
    std::cout << std::format("There are {} ways I love you\n", 219);

    // 입출력 연산은 반드시 명령문 단위로 처리: << 과 >> 을 한 명령어에 사용불가
    int value;
    // std::cout << "Enter Value: ";
    // std::cin >> value;

    header_namespace::f();
    global_namespace::f();
    global_namespace::inner_namespace::g();

    using namespace global_namespace;
    // using namespace header_namespace;  <- 오류 발생 같은 애매함을 불러일으킬
    // 수 있기에 사용 불가
    f();
    inner_namespace::g();

    using std::cout;
    cout << "Skip\n";

    // 네임스페이스 앨리어스
    namespace Alias = inner_namespace::deep_namespace;
    Alias::h();

    // 리터럴
    int d_value = 123;
    int o_value = 0173;
    int h_value = 0x7B;
    int b_value = 0b1111011;
    std::cout << std::format("10진수: {}\n8진수: {}\n16진수: {}\n2진수: {}\n",
                             d_value, o_value, h_value, b_value);

    value = 123'123'123;
    std::cout << value << std::endl;

    // 균일 초기화 c++11 부터 도입 - 선언, 초기화시 안정적
    std::byte b{42}; // cstddef 헤더 unsigned char 보다 명확

    // 숫자 경계값 <limits> 헤더
    std::cout << "int:\n";
    std::cout << std::format("Max int value: {:>15}\n",
                             std::numeric_limits<int>::max());
    std::cout << std::format("Min int value: {:>15}\n",
                             std::numeric_limits<int>::min());
    std::cout << std::format("Lowest int value: {:>12}\n",
                             std::numeric_limits<int>::lowest());

    std::cout << "\ndouble:\n";
    std::cout << std::format("Max double value: {:>27}\n",
                             std::numeric_limits<double>::max());
    std::cout << std::format("Min double value: {:>27}\n",
                             std::numeric_limits<double>::min());
    std::cout << std::format("Lowest double value: {:>12}\n",
                             std::numeric_limits<double>::lowest());

    return 0;
}

namespace header_namespace {
    void f() { std::cout << "This is Header's namespace\n"; }
} // namespace header_namespace
