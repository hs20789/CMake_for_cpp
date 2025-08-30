#include <format>
#include <iostream>
#include <set>
#include <string>
#include <string_view>
#include <vector>

class AccesList final
{
  public:
    AccesList() = default;
    AccesList(std::initializer_list<std::string_view> users)
    {
        m_allowed.insert(std::begin(users), std::end(users));
    }
    void addUsers(std::string user) { m_allowed.emplace(std::move(user)); }
    void removeUser(std::string const &user) { m_allowed.erase(user); }
    bool isAllowed(std::string const &user)
    {
        return (m_allowed.contains(user));
    }
    std::vector<std::string> getAllUsers() const
    {
        return {std::begin(m_allowed), std::end(m_allowed)};
    }

  private:
    std::set<std::string> m_allowed;
};

int main()
{
    AccesList fileX{"mgregoire", "baduser"};
    fileX.addUsers("pvw");
    fileX.removeUser("baduser");

    if (fileX.isAllowed("mgregoire")) {
        std::cout << "mgregoire has permissions.\n";
    }
    if (fileX.isAllowed("baduser")) {
        std::cout << "baduser has permissions.\n";
    }

    auto users{fileX.getAllUsers()};
    for (auto const &user : users) {
        std::cout << user << " | ";
    }
    std::cout << std::endl;
}