#include <iostream>

#include "func.h"

int main() {

    int *myIntegerPointer{nullptr};
    std::cout << "myIntegerPointer is nullptr?\nanswer: ";
    checkNullPointer(myIntegerPointer);
    // 포인터 변수에 메모리를 동적으로 할당
    myIntegerPointer = new int;
    *myIntegerPointer = 8;
    // delete 하고 나면 해제한 포인터를 다시 사용하지 않도록 nullptr로 초기화
    delete myIntegerPointer;
    myIntegerPointer = nullptr;

    // 포인터는 프리스토어뿐만 아니라 스택과 같은 다른 메모리 영역에서도 가능
    int i{10}, j{300};
    int *ptrForStack{&i};

    // 동적으로 배열 할당하기
    int arraysize{8};
    int *myVariableSizedArray{new int[arraysize]};
    myVariableSizedArray[3] = {2};

    delete[] myVariableSizedArray;
    myVariableSizedArray = nullptr;

    // 상수를 가리키는 포인터
    const int *constPointer1{}; // = int const* constPointer1{};
    constPointer1 = {&i};
    //*constPointer1 = 20; // 컴파일 에러 발생, const int*는 값 변경 불가

    // 상수 포인터
    int *const constPointer2{&i}; // int* const constPointer2{};
    *constPointer2 = {20};
    std::cout << std::format("i = {}\n", i);
    // constPointer2 = {&j}

    class Rect {
      public:
        constexpr Rect(size_t width, size_t height)
            : m_width{width}, m_height{height} {}
        constexpr size_t getArea() const { return m_width * m_height; }

      private:
        size_t m_width{};
        size_t m_height{};
    };

    constexpr Rect r{8, 2};
    int myArray[r.getArea()]; // 컴파일 타임에 크기가 결정됨

    // 레퍼런스
    int origin_num{12};
    int &ref_num1{origin_num}; // 레퍼런스 변수는 반드시 초기화해야 함
    std::cout << std::format(
        "address of origin_num: {}\naddress of ref_num1: {}\n",
        static_cast<void *>(&origin_num), static_cast<void *>(&ref_num1));

    int z{};
    int const &zRef{z};
    z = 100; // zRef는 z를 참조하므로 z의 값이 변경됨
    // zRef = 200; // zRef는 const이므로 z의 값을 변경할 수 없음

    // int &unnamedRef1{10};
    int const &unnamedRef2{20};
    int &&unnamedRef3{30}; // rvalue 레퍼런스

    int *intP{nullptr};
    int *&ptrRef{intP};
    ptrRef = new int(5);
    std::cout << *intP << '\n';
    std::cout << std::format(
        "address of intP: {:>15}\naddress of ptrRef: {:>12}\n",
        static_cast<void *>(intP), static_cast<void *>(ptrRef));

    std::pair<std::string, int> myPair{"hello", 5};
    auto &[theString, theInt]{myPair};           // 비 const 레퍼런스로 분해
    const auto &[constString, constInt]{myPair}; // const 레퍼런스로 분해

    // 포인터를 사용하여 홀수와 짝수를 분리하는 함수 호출
    int unSplit[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *oddNums{nullptr};
    int *evenNums{nullptr};
    size_t numOdds{}, numEvens{};

    separateOddsAndEvensPtr(unSplit, 10, &oddNums, &numOdds, &evenNums,
                            &numEvens);
    // 생성된 배열을 사용하는 코드
    // 사용 후 반드시 delete[]로 메모리 해제
    delete[] oddNums;
    oddNums = nullptr;
    delete[] evenNums;
    evenNums = nullptr;

    // 포인터를 사용하여 홀수와 짝수를 분리하는 함수 호출 - 레퍼런스 사용
    separateOddsAndEvensRef(unSplit, std::size(unSplit), oddNums, numOdds,
                            evenNums, numEvens);
    // 생성된 배열을 사용하는 코드
    // 사용 후 반드시 delete[]로 메모리 해제
    delete[] oddNums;
    oddNums = nullptr;
    delete[] evenNums;
    evenNums = nullptr;

    // 배열을 동적으로 할당하지 않는 코드
    std::vector<int> vecUnSplit{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> odds{}, evens{};
    separateOddsAndEvensRefVec(vecUnSplit, odds, evens);
    // 생성된 벡터를 사용하는 코드
    // 벡터는 자동으로 메모리를 관리하므로 delete[] 필요 없음

    auto oddsAndEvens{separateOddsAndEvensRefVecReturn(vecUnSplit)};
    std::cout << oddsAndEvens.odds.size() << " odd numbers and "
              << oddsAndEvens.evens.size() << " even numbers.\n";

    // 예외 테스트
    try {
        std::cout << divideNumbers(2.5, 0.5) << '\n';
        std::cout << divideNumbers(2.3, 0) << '\n'; // 예외 발생
        std::cout << divideNumbers(4.5, 2.5) << '\n';
    } catch (const std::invalid_argument &exception) {
        std::cout << std::format("Exception caught: {}\n", exception.what());
    }
    return 0;
}