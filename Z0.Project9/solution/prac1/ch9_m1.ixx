// 1. 스트링을 전달하도록 수정
// 2. 이동 생성/대입연산자 추가
// 3. 코드 중복 최소화

module;

#include <iostream>
#include <string>
#include <string_view>
#include <utility>

export module ch9_m1;

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
    {
        std::cout << "Person parameterde constructor called." << std::endl;
    }
    Person() : m_firstName{"Default FirstName"}, m_lastName{"Default LastName"}
    {
        std::cout << "Person default constructor called." << std::endl;
    }
    // 복제 생성자 1/5
    Person(Person const &src)
        : m_firstName{src.m_firstName}, m_lastName{src.m_lastName}
    {
        std::cout << "Person copy constructor called." << std::endl;
    }
    // 대입 연산자 2/5
    Person &operator=(Person const &rhs)
    {
        std::cout << "Person assignment operator called." << std::endl;

        auto temp{rhs};
        swap(temp);
        return *this;
    }

    // 이동 생성자 3/5
    Person(Person &&src) noexcept
        : m_firstName{std::move(src.m_firstName)},
          m_lastName{std::move(src.m_lastName)}
    {
        std::cout << "Person move constructor called." << std::endl;
    }
    // 이동 대입 연산자 4/5
    Person &operator=(Person &&rhs) noexcept
    {
        std::cout << "Person move assignment operator called." << std::endl;
        swap(rhs);
        return *this;
    }

    // 소멸자 5/5
    ~Person() { std::cout << "Person destructor Called!" << std::endl; }

    // m_firstName 게터와 세터
    std::string const &getFirstName() const { return m_firstName; }
    void setFirstName(std::string firstName)
    {
        this->m_firstName = std::move(firstName);
    }
    // m_lastName 게터와 세터
    std::string const &getLastName() const { return m_lastName; }
    void setLastName(std::string lastName)
    {
        this->m_lastName = std::move(lastName);
    }
    // swap method.
    //// Added to avoid code duplication
    void swap(Person &other) noexcept
    {
        std::swap(m_firstName, other.m_firstName);
        std::swap(m_lastName, other.m_lastName);
    }
};
