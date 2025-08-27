// 복제 생성자, 대입 연산자, 소멸자를 구현

module;

#include <format>
#include <string>
#include <string_view>
#include <utility>

export module Person_ch10_prac;

export namespace HR
{

    // Person 클래스 정의
    class Person
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

        virtual ~Person() = default;                    // 소멸자 1/5
        Person(Person const &src) = default;            // 복사 생성자 2/5
        Person &operator=(Person const &src) = default; // 복사 대입 연산자 3/5
        Person(Person &&src) = default;                 // 이동 생성자 4/5
        Person &operator=(Person &&src) = default;      // 이동 대입 연산자 5/5

        // m_firstName 게터와 세터
        virtual std::string const &getFirstName() const { return m_firstName; }
        virtual void setFirstName(std::string_view sv) { m_firstName = sv; }
        virtual void setFirstName(std::string &&s) noexcept
        {
            m_firstName = std::move(s);
        }

        // m_lastName 게터와 세터
        virtual std::string const &getLastName() const { return m_lastName; }
        virtual void setLastName(std::string_view lastName)
        {
            m_lastName = lastName;
        }
        virtual void setLastName(std::string &&s) noexcept
        {
            m_lastName = std::move(s);
        }

        // m_initial 게터와 세터
        virtual std::string const &getInitials() const { return m_initials; }
        virtual void setInitial(std::string_view initial)
        {
            m_initials = initial;
        }
        virtual void setInitial(std::string s) { m_initials = std::move(s); }

        // 사람을 표현하는 스트링을 반환하는 함수
        virtual std::string toString() const
        {
            return std::format("{} {}", getFirstName(), getLastName());
        }
    };
} // namespace HR