#include "namespace.h"
#include <cstddef>
#include <iostream>
#include <limits>
#include <compare>
#include <utility>
#include <optional>

import employee;



// 중첩 네임 스페이스
namespace global_namespace {
    static void f() { std::cout << "This is Globals namespace\n"; }
    namespace inner_namespace {
        static void g() { std::cout << "This is Inner Namespace\n"; }
    } // namespace inner_namespace
} // namespace global_namespace




// c++17 이후부터의 중첩 네임스페이스
namespace global_namespace::inner_namespace::deep_namespace {
    void h() { std::cout << "This is Inner's deep namespace\n"; }
} // namespace global_namespace::inner_namespace::deep_namespace



[[nodiscard("No Discard test")]] static auto nodiscard_func () {
    std::cout << "This function should not be ignored!" << std::endl;
    return 42;
    };

[[nodiscard]] std::optional<int> getData(bool giveIt) {
	if (giveIt) {
		std::cout << "Returning data...\n";
        return 42; // 값이 있는 경우
    } else {
		std::cout << "No data to return.\n";
        return std::nullopt; // 값이 없는 경우
	}
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    // std::endl과 '\n'
    std::cout << std::format("There are {} ways I love you", 219) << std::endl;
    std::cout << std::format("There are {} ways I love you\n", 219);

    // 입출력 연산은 반드시 명령문 단위로 처리: << 과 >> 을 한 명령어에 사용불가
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
    namespace alias = inner_namespace::deep_namespace;
    alias::h();

    // 리터럴
    int d_value = 123;
    int o_value = 0173;
    int h_value = 0x7B;
    int b_value = 0b1111011;
    std::cout << std::format("10진수: {}\n8진수: {}\n16진수: {}\n2진수: {}\n",
                             d_value, o_value, h_value, b_value);

    int value = 123'123'123;
    std::cout << value << '\n';

    // 균일 초기화 c++11 부터 도입 - 선언, 초기화시 안정적
    std::byte b{42}; // latedef 헤더 unsigned char 보다 명확

    // 숫자 경계값 <limits> 헤더
    std::cout << "int:\n";
    std::cout << std::format("Max int value: {:>15}\n",
                             std::numeric_limits<int>::max());
    std::cout << std::format("Min int value: {:>15}\n",
                             std::numeric_limits<int>::min());
    std::cout << std::format("Lowest int value: {:>12}\n",
                             std::numeric_limits<int>::lowest());

    std::cout << R"(double:
)";
    std::cout << std::format("Max double value: {:>27}\n",
                             std::numeric_limits<double>::max());
    std::cout << std::format("Min double value: {:>27}\n",
                             std::numeric_limits<double>::min());
    std::cout << std::format("Lowest double value: {:>12}\n",
                             std::numeric_limits<double>::lowest());

    // 캐스트
    float myFloat{ 3.14f };
	int i1{ (int)myFloat }; // C 스타일 캐스트
	int i2{ int (myFloat) }; // 함수형 스타일 캐스트
	int i3{ static_cast<int>(myFloat) }; // C++ 스타일 캐스트
    std::cout << typeid(i1).name () << '\n';
	std::cout << typeid(i2).name () << '\n';
	std::cout << typeid(i3).name () << '\n';

    
    // 열거 타입
    enum class PieceType {
	    King = 1,
        Queen,
        Rook = 10,
		Pawn
    };
    PieceType piece{ PieceType::King };
    // 열거 타입의 값이 내부적으로 정수로 표현된다고 해서 자동으로 정수로 변환되지 않음
	// if(piece == 1) { // 오류 발생
    if(piece == PieceType::King) {
        std::cout << "It's a King piece!\n";
    } else {
        std::cout << "It's not a King piece!\n";
	}

    enum class PieceType2 : unsigned long {
        King = 1,
        Queen,
        Rook = 10,
        Pawn
	};
	// c++20 부터는 using enum을 사용하여 열거형을 네임스페이스처럼 사용할 수 있음
	using enum PieceType2;
	PieceType2 piece2{ King };
    piece2 = Queen;
    if(piece2 == King) {
        std::cout << "It's a King piece!\n";
    } else {
        std::cout << "It's not a King piece!\n";
	}

    // employee 모듈 사용
	Employee anEmployee{ "Jeong", "HeonSu", 42, 80'000};
	std::cout << std::format("Employee: {} {}\n:"
						        "Number : {}\n"
						        "Salary : ${}\n",
	anEmployee.firstInitial, anEmployee.lastInitial, anEmployee.employeeNumber, anEmployee.salary);

    // 3방향 비교 연산자
    int i{ 11 };
    std::strong_ordering result{ i <=> 0 };
    if (result == std::strong_ordering::less) cout << "less\n";
	if (result == std::strong_ordering::greater) cout << "greater\n";
	if (result == std::strong_ordering::equal) cout << "equal\n";

	if (is_lt (result)) cout << "is_less\n";
	if (is_gt (result)) cout << "is_greater\n";
	if (is_eq (result)) cout << "is_equal\n";

    auto lambda_func = []()
    {
	    std::cout << "Hello, Lambda!" << std::endl;
		std::cout << "Entering Function" << __func__ << std::endl;
    };
    lambda_func ();

    
    nodiscard_func ();

    int myArray[]{ 1, 2, 3, 4 };
    std::cout << std::format ("Array size: {}\n", std::size (myArray));

    std::pair<double, int> myPair{ 1.23, 5 };
	std::cout << std::format ("{} {}", myPair.first, myPair.second) << std::endl;

    std::optional<int> data1{ getData (true) };
	std::optional<int> data2{ getData (false) };

    std::cout << std::format ("data1.has_value = {}\n", data1.has_value ());
    if (data2) {
        std::cout << std::format ("data2 has a value.\n");
    }

    std::cout << std::format ("data1.value = {}\n*data1 = {}\n",
                              data1.value(), *data1);

    std::cout << std::format ("data2.value_or(0) = {}\n",
                              data2.value_or(0));



	return 0;
}

namespace header_namespace {
    void f() { std::cout << "This is Header's namespace\n"; }
} // namespace header_namespace
