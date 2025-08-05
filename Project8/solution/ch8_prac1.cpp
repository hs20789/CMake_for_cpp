// 성과 이름을 데이터 멤버로 저장하는 Person 클래스를 구현해보자.
// 1. 성과 이름에 대한 매개변수 두 개를 갖는 생성자도 하나 추가한다.
// 2. 게터와 세터도 정의한다.
// 3. 테스트용으로 스택과 프리스토어에 생성해보아라.

#include <format>
#include <iostream>
#include <memory>
#include <print>
#include <string>
#include <string_view>

// Person 클래스 정의
class Person
{
    // 데이터 멤버
  private:
    std::string m_firstName;
    std::string m_lastName;

  public:
    // 생성자
    Person(std::string_view first, std::string_view last)
        : m_firstName{first}, m_lastName{last}
    {}
    Person() = default;

    // m_firstName 게터와 세터
    std::string getFirstName() const;
    void setFirstName(std::string_view firstName);
    // m_lastName 게터와 세터
    std::string getLastName() const;
    void setLastName(std::string_view lastName);
};

int main()
{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// 스택에 생성
    ///
    // 1. 기본 초기화
    Person stackVar1;
    stackVar1.setFirstName("Jeong");
    stackVar1.setLastName("HeonSu");
    std::cout << std::format("stackVar1: {} {}\n\n", stackVar1.getFirstName(),
                             stackVar1.getLastName());

    // 2. 값초기화
    Person stackVar2{};
    stackVar2.setFirstName("Jeong");
    stackVar2.setLastName("HeonSu");
    std::cout << std::format("stackVar2: {} {}\n\n", stackVar2.getFirstName(),
                             stackVar2.getLastName());

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// 프리스토어에 생성
    ///
    // 1. new 사용
    Person *heapVar1{new Person{}};
    heapVar1->setFirstName("Jeong");
    heapVar1->setLastName("HeonSu");
    std::cout << std::format("heapVar1: {} {}\n\n", heapVar1->getFirstName(),
                             heapVar1->getLastName());

    // 2. 스마트 포인터 사용
    auto heapVar2{std::unique_ptr<Person>{new Person{}}};
    heapVar2->setFirstName("Jeong");
    heapVar2->setLastName("HeonSu");
    std::cout << std::format("heapVar2: {} {}\n\n", heapVar2->getFirstName(),
                             heapVar2->getLastName());

    auto heapVar3{std::make_unique<Person>()};
    heapVar3->setFirstName("Jeong");
    heapVar3->setLastName("HeonSu");
    std::cout << std::format("heapVar3: {} {}\n\n", heapVar3->getFirstName(),
                             heapVar3->getLastName());

    auto heapVar4{std::make_unique<Person>("John", "Smith")};
    std::cout << std::format("heapVar4: {} {}\n\n", heapVar4->getFirstName(),
                             heapVar4->getLastName());
    std::print("HIHIHIHIHIH\n");
}

std::string Person::getFirstName() const { return m_firstName; }
void Person::setFirstName(std::string_view firstName)
{
    this->m_firstName = firstName;
}
std::string Person::getLastName() const { return m_lastName; }
void Person::setLastName(std::string_view lastName)
{
    this->m_lastName = lastName;
}
