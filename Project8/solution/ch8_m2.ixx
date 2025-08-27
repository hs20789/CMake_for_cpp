// 생성자를 하나라도 생성하면 컴파일러는 기본 생성자(Default Constructor)를
// 생성해주지 않는다.

module;

#include <string>
#include <string_view>

export module Person2;


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

    // m_firstName 게터와 세터
    std::string getFirstName() const;
    void setFirstName(std::string_view firstName);
    // m_lastName 게터와 세터
    std::string getLastName() const;
    void setLastName(std::string_view lastName);
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
