// 복제 생성자, 대입 연산자, 소멸자를 구현

module;

#include <format>
#include <iostream>
#include <string>
#include <string_view>

export module Person4;

// Person 클래스 정의
export class Person
{
    // 데이터 멤버
  private:
    std::string m_firstName{"Default FirstName"};
    std::string m_lastName{"Default LastName"};
    std::string m_initials{"None"};

  public:
    // 생성자
    Person(std::string_view firstName, std::string_view lastName,
           std::string_view initial)
        : m_firstName{firstName}, m_lastName{lastName}, m_initials{initial}
    {}
    Person(std::string_view firstName, std::string_view lastName)
        : Person{firstName, lastName,
                 std::format("{}{}", firstName[0], lastName[0])}
    {}
    Person() = default;

    // 소멸자
    ~Person() { std::cout << "Destructor Called!\n"; }

    // m_firstName 게터와 세터
    std::string getFirstName() const;
    void setFirstName(std::string_view firstName);
    // m_lastName 게터와 세터
    std::string getLastName() const;
    void setLastName(std::string_view lastName);
    // m_initial 게터와 세터
    std::string getInitial() const;
    void setInitial(std::string_view initial);
};

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

std::string Person::getInitial() const { return m_initials; }
void Person::setInitial(std::string_view initial)
{
    this->m_initials = initial;
}
