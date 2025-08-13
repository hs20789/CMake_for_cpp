module;

#include <format>
#include <string>

export module Employee_ch10_prac;
import Person_ch10_prac;

export namespace HR
{
    class Employee : public Person
    {
      private:
        int m_ID{};

      public:
        Employee() = default; // 기본 생성자
        Employee(int ID, std::string firstName, std::string lastName,
                 std::string initials)
            : Person(std::move(firstName), std::move(lastName),
                     std::move(initials)),
              m_ID{ID}
        {}
        Employee(int ID, std::string firstName, std::string lastName)
            : Person(std::move(firstName), std::move(lastName)), m_ID{ID}
        {}
        // ID 전용 게터와 세터
        virtual void setID(int id) { m_ID = id; }
        virtual int getID() const { return m_ID; }

        // to String 오버라이드
        std::string toString() const override
        {
            return std::format("Employee with ID = {} is {}", getID(),
                               Person::toString());
        }
    };
} // namespace HR