module;

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <string_view>

export module PhoneBook;
export import ch18_m2;

export class PhoneBook
{
  public:
    // 생성자는 기본값 사용
    void addPhoneNum(Person const &person, std::string_view phoneNum);
    void removePhoneNum(Person const &person, std::string phoneNum);

    std::vector<std::string> getAllPhoneNum(Person const &person) const;

  private:
    std::multimap<Person, std::string> m_dataList;
};

void PhoneBook::addPhoneNum(Person const &person, std::string_view phoneNum)
{
    m_dataList.emplace(std::pair{person, phoneNum});
}

void PhoneBook::removePhoneNum(Person const &person, std::string phoneNum)
{
    auto [begin, end]{m_dataList.equal_range(person)};
    for (auto iter{begin}; iter != end; ++iter) {
        if (iter->second == phoneNum) {
            m_dataList.erase(iter);
            break;
        }
    }
}

std::vector<std::string> PhoneBook::getAllPhoneNum(Person const &person) const
{
    std::vector<std::string> phonebook;
    auto [begin, end]{m_dataList.equal_range(person)};
    for (auto iter{begin}; iter != end; ++iter) {
        phonebook.emplace_back(iter->second);
    }
    return phonebook;
}
