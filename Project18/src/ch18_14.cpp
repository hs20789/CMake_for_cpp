#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <utility>

class Data final
{
  public:
    explicit Data(int value = 0) : m_value{value} {}
    int getValue() const { return m_value; }
    void setValue(int value) { m_value = value; }

  private:
    int m_value{};
};

int main()
{
    std::map<std::string, int> m{
        {"Marc G.", 123}, {"Warren B.", 456}, {"Peter V.W.", 789}};

    std::map<int, Data> dataMap;
    dataMap[44] = Data{44};
    auto ret{dataMap.insert(
        {1, Data{4}})}; // std::pair<iterator, bool> insert {...};
    if (ret.second) {
        std::cout << "Insert succeeded!\n";
    } else {
        std::cout << "Insert failed!\n";
    }

    if (ret = dataMap.insert({1, Data{6}}); ret.second) {
        std::cout << "Insert succeeded!\n";
    } else {
        std::cout << "Insert failed!\n";
    }

    if (auto [iter, success]{dataMap.insert({2, Data{6}})}; success) {
        std::cout << "Insert succeeded!\n";
    } else {
        std::cout << "Insert failed!\n";
    }
    std::cout << dataMap.at(1).getValue() << std::endl;
    if (auto [iter, success]{dataMap.insert_or_assign(1, Data{7})}; success) {
        std::cout << "Insert succeeded!\n";
    } else {
        std::cout << "Insert failed!\n";
    }
    std::cout << dataMap.at(1).getValue() << std::endl;
    dataMap[1] = Data{10};
    std::cout << dataMap[1].getValue() << '\n';

    dataMap.emplace(1, Data{11});
    std::cout << dataMap[1].getValue() << '\n';
    dataMap.try_emplace(1, Data{12});
    std::cout << dataMap[1].getValue() << '\n';

    for (auto iter{std::cbegin(dataMap)}; iter != std::cend(dataMap); ++iter) {
        std::cout << iter->second.getValue() << " | ";
    }
    std::cout << '\n';
    for (auto const &p : dataMap) {
        std::cout << p.second.getValue() << " @ ";
    }
    std::cout << '\n';
    dataMap[1].setValue(1111);
    for (auto const &[key, data] : dataMap) {
        std::cout << data.getValue() << " * ";
    }
    std::cout << std::endl;
    if (dataMap.contains(44)) {
        std::cout << "Contain Key(44)!\n";
    } else {
        std::cout << "Don't have key(44)!\n";
    }

    std::map<int, int> src{{1, 11}, {2, 22}};
    std::map<int, int> dst{{1, 12}, {3, 33}, {4, 44}};
    dst.merge(src);
    for (auto const &[key, value] : dst) {
        std::cout << value << " | ";
    }
    std::cout << std::endl;
}
