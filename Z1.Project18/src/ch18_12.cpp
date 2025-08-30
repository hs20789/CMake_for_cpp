// 정렬 연관 컨테이너를 살펴보기 전에 먼저 <utility>에 정의된 pair
// 클래스(std::pair 클래스 템플릿)를 알아보자.
// pair는 두 값을 그룹으로 묶는 클래스 템플릿이다. 두 값의 타입은 서로 다르게
// 지정할 수 있다. pair에 담긴 두 값으 각각 first와 second라는 public 데이터
// 멤버로 접근한다.
// first와 second 원소를 비교하는 데 모든 종류의 비교 연산자를 사용할 수 있다.

#include <format>
#include <iostream>
#include <string>
#include <utility>

int main()
{
    std::pair<std::string, int> myPair{"Ant", 50};
    std::pair<std::string, int> myOtherPair;

    myOtherPair.first = "Bear";
    myOtherPair.second = 6;

    std::pair<std::string, int> myThirdPair{myOtherPair};

    if (myPair < myOtherPair) {
        std::cout << "myPair is less than myOtherPair\n";
    } else {
        std::cout << "myPair is greater than myOtherPaie\n";
    }

    if (myPair == myOtherPair) {
        std::cout << "myOtherPair is equal to myThirdPair\n";
    } else {
        std::cout << "myOtherPair is not equal to myTHirdPair\n";
    }
}