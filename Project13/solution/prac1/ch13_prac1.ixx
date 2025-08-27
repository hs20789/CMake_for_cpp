module;

#include <compare>
#include <format>
#include <iostream>
#include <string>
#include <string_view>
#include <utility>

export module ch13_m1;

// Person 클래스 정의
export class Person
{
    // 데이터 멤버
  private:
    std::string m_firstName{"Hong"};
    std::string m_lastName{"Gil-Dong"};
    std::string m_initials{"None"};

  public:
    // 생성자
    Person(std::string firstName, std::string lastName)
        : Person{std::move(firstName), std::move(lastName),
                 std::format("{}{}", firstName[0], lastName[0])}
    {}
    Person() = default;
    Person(std::string firstName, std::string lastName, std::string initials)
        : m_firstName{std::move(firstName)}, m_lastName{std::move(lastName)},
          m_initials{std::move(initials)}
    {}

    // 비교 연산자 오버로딩
    [[nodiscard]] auto operator<=>(const Person &) const = default;

    const std::string &getFirstName() const { return m_firstName; }
    void setFirstName(std::string firstName)
    {
        m_firstName = std::move(firstName);
    }

    const std::string &getLastName() const { return m_lastName; }
    void setLastName(std::string lastName) { m_lastName = std::move(lastName); }

    const std::string &getInitials() const { return m_initials; }
    void setInitials(std::string initials) { m_initials = std::move(initials); }

    void output() const
    {
        std::cout << std::format("{} {} - {}", m_firstName, m_lastName,
                                 m_initials)
                  << std::endl;
    }

    void output(std::ostream &output) const
    {
        output << std::format("{} {} ({})", getFirstName(), getLastName(),
                              getInitials())
               << std::endl;
    }
};
