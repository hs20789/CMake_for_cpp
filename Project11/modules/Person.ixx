module;

export module Person_ch11;
#include <string>

export class Person
{
  private:
    std::string m_firstName;
    std::string m_lastName;

  public:
    Person(std::string firstName, std::string lastName)
        : m_firstName{std::move(firstName)}, m_lastName{std::move(lastName)}
    {}
    std::string const &getFirstName() const { return m_firstName; }
    std::string const &getLastName() const { return m_lastName; }
};