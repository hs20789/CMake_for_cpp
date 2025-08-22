#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <utility>

class Person
{
  public:
    Person(std::string first, std::string last)
        : m_firstName{std::move(first)}, m_lastName{std::move(last)}
    {}
    std::string const &getFirstName() const { return m_firstName; }
    std::string const &getLastName() const { return m_lastName; }

  private:
    std::string m_firstName;
    std::string m_lastName;
};

int main()
{
    //
    //
}