#include <functional>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

void findMatches(std::span<int const> values1, std::span<int const> values2,
                 auto matcher, auto handler);

bool intEqual(int item1, int item2) { return item1 == item2; }
void printMatch(size_t position, int value1, int value2)
{
    std::cout << std::format("Match found at position {} ({}, {}).\n", position,
                             value1, value2);
}

void func(int num, std::string_view str)
{
    std::cout << std::format("func ({}, {})\n", num, str);
}

class IsLargerThan
{
  public:
    explicit IsLargerThan(int value) : m_value{value} {}
    bool operator()(int value1, int value2) const
    {
        return value1 > m_value && value2 > m_value;
    }

  private:
    int m_value{};
};

int main()
{
    std::function<void(int, std::string_view)> f1{func};
    f1(1, "test"); // <- std::function
    auto f2{func};
    f2(2, "Set"); // <- 함수 포인터

    std::vector values1{2, 500, 6, 9, 10, 101, 1};
    std::vector values2{4, 4, 2, 9, 0, 300, 1};

    findMatches(values1, values2, IsLargerThan{100}, printMatch);
}

void findMatches(std::span<int const> values1, std::span<int const> values2,
                 auto matcher, auto handler)
{
    if (values1.size() != values2.size()) {
        std::cout << "They must have same len!\n";
        return;
    }
    for (size_t i{}; i < values1.size(); ++i) {
        if (matcher(values1[i], values2[i])) {
            handler(i, values1[i], values2[i]);
        }
    }
}
