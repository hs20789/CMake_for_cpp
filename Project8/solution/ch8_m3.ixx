// 복제 생성자, 대입 연산자, 소멸자를 구현

module;

#include <iostream>
#include <print>
#include <string>
#include <string_view>

export module Person3;

// Person 클래스 정의
export class Person
{
    // 데이터 멤버
  private:
    std::string m_firstName{"Default FirstName"};
    std::string m_lastName{"Default LastName"};

  public:
    // 생성자
    Person(std::string_view first, std::string_view last)
        : m_firstName{first}, m_lastName{last}
    {}
    Person() = default;
    // 복제 생성자
    Person(const Person &src)
        : m_firstName{src.m_firstName}, m_lastName{src.m_lastName}
    {
        std::cout << "Person copy constructor called." << std::endl;
    }
    // 대입 연산자
    Person &operator=(Person const &rhs);

    // 소멸자
    ~Person() { std::cout << "Destructor Called!\n"; }

    // m_firstName 게터와 세터
    std::string getFirstName() const;
    void setFirstName(std::string_view firstName);
    // m_lastName 게터와 세터
    std::string getLastName() const;
    void setLastName(std::string_view lastName);
};

// 대입 연산자
Person &Person::operator=(Person const &rhs)
{
    std::cout << "Person assignment operator called." << std::endl;

    if (this == &rhs) {
        return *this;
    }
    this->m_firstName = rhs.m_firstName;
    this->m_lastName = rhs.m_lastName;
    return *this;
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
