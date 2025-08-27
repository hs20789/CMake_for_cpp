// 복제 생성자, 대입 연산자, 소멸자를 구현

module;

#include <format>
#include <string>
#include <string_view>
#include <utility>

export module ch9_m3;

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

    // 레거시 비교연산자 오버로딩
    [[nodiscard]] bool operator<(Person const &other) const
    {
        return (getFirstName() < other.getFirstName()) ||
               (getFirstName() == other.getFirstName() &&
                getLastName() < other.getLastName()) ||
               (getFirstName() == other.getFirstName() &&
                getLastName() == other.getLastName() &&
                getInitials() < other.getInitials());
    }
    [[nodiscard]] bool operator==(const Person &other) const
    {
        return getFirstName() == other.getFirstName() &&
               getLastName() == other.getLastName() &&
               getInitials() == other.getInitials();
    }
    [[nodiscard]] bool operator<=(Person const &other) const
    {
        return !(other < *this);
    }
    [[nodiscard]] bool operator>=(Person const &other) const
    {
        return !(*this < other);
    }
    [[nodiscard]] bool operator>(Person const &other) const
    {
        return other < *this;
    }
    [[nodiscard]] bool operator!=(Person const &other) const
    {
        return !(*this == other);
    }

    // m_firstName 게터와 세터
    std::string const &getFirstName() const { return m_firstName; }
    void setFirstName(std::string_view sv) { m_firstName = sv; }
    void setFirstName(std::string &&s) noexcept { m_firstName = std::move(s); }
    // m_lastName 게터와 세터
    std::string const &getLastName() const { return m_lastName; }
    void setLastName(std::string_view lastName) { m_lastName = lastName; }
    void setLastName(std::string &&s) noexcept { m_lastName = std::move(s); }
    // m_initial 게터와 세터
    std::string const &getInitials() const { return m_initials; }
    void setInitial(std::string_view initial) { m_initials = initial; }
    void setInitial(std::string s) { m_initials = std::move(s); }
};
