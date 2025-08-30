module;

#include <filesystem>
#include <format>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

export module ch15_m2;

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

    void output(std::ostream &output) const
    {
        output << std::format("{} {} ({})", getFirstName(), getLastName(),
                              getInitials())
               << std::endl;
    }
};

export std::ostream &operator<<(std::ostream &os, const Person &person)
{
    os << std::quoted(person.getFirstName())
       << std::quoted(person.getLastName())
       << std::quoted(person.getInitials());

    return os;
}

export std::istream &operator>>(std::istream &is, Person &person)
{
    std::string firstName, lastName, initials;
    is >> std::quoted(firstName) >> std::quoted(lastName) >>
        std::quoted(initials);

    person.setFirstName(std::move(firstName));
    person.setLastName(std::move(lastName));
    person.setInitials(std::move(initials));

    return is;
}
