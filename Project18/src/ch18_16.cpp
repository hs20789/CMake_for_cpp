#include <format>
#include <iostream>
#include <map>
#include <string>
#include <string_view>
#include <vector>

class BuddyList final
{
  public:
    // name으로 지정한 사람의 친구를 buddy로 추가한다.
    void addBuddy(std::string const &name, std::string const &buddy);
    // name으로 지정한 사람의 친구인 buddy를 제거한다.
    void removeBuddy(std::string const &name, std::string const &buddy);
    // buddy가 name으로 지정한 사람의 친구인지 확인
    bool isBuddy(std::string const &name, std::string const &buddy) const;
    // name으로 지정한 사람의 친구 목록을 가져온다.
    std::vector<std::string> getBuddies(std::string const &name) const;

  private:
    std::multimap<std::string, std::string> m_buddies;
};

int main()
{
    BuddyList buddies;
    buddies.addBuddy("Harry Potter", "Ron Weasley");
    buddies.addBuddy("Harry Potter", "Hermione Granger");
    buddies.addBuddy("Harry Potter", "Hagrid");
    buddies.addBuddy("Harry Potter", "Draco Malfoy");
    if (auto check{buddies.isBuddy("Harry Potter", "Draco Malfoy")}; check) {
        std::cout << "They are Friend!\n";
    } else {
        std::cout << "Ther are not Friend!\n";
    }
    buddies.removeBuddy("Harry Potter", "Draco Malfoy");

    buddies.addBuddy("Hagrid", "Harry Potter");
    buddies.addBuddy("Hagrid", "Ron Weasley");
    buddies.addBuddy("Hagrid", "Hermione Granger");

    auto harrysFriend{buddies.getBuddies("Harry Potter")};

    std::cout << "Harry's Friends: \n";
    for (auto const &v : harrysFriend) {
        std::cout << v << " | ";
    }
    std::cout << std::endl;

    if (auto check{buddies.isBuddy("Harry Potter", "Draco Malfoy")}; check) {
        std::cout << "They are Friend!\n";
    } else {
        std::cout << "Ther are not Friend!\n";
    }
}

void BuddyList::addBuddy(std::string const &name, std::string const &buddy)
{
    if (!isBuddy(name, buddy)) {
        m_buddies.insert({name, buddy});
    }
}

void BuddyList::removeBuddy(std::string const &name, std::string const &buddy)
{
    auto [begin, end]{m_buddies.equal_range(name)};
    for (auto iter{begin}; iter != end; ++iter) {
        if (iter->second == buddy) {
            m_buddies.erase(iter);
            break;
        }
    }
}

bool BuddyList::isBuddy(std::string const &name, std::string const &buddy) const
{
    auto [begin, end]{m_buddies.equal_range(name)};

    for (auto iter{begin}; iter != end; ++iter) {
        if (iter->second == buddy) {
            return true;
        }
    }
    return false;
}

std::vector<std::string> BuddyList::getBuddies(std::string const &name) const
{
    auto [begin, end]{m_buddies.equal_range(name)};

    std::vector<std::string> buddies;
    for (auto iter{begin}; iter != end; ++iter) {
        buddies.emplace_back(iter->second);
    }
    return buddies;
}