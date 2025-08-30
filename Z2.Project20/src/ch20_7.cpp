#include <format>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

//////////////////

class MyClass
{
  public:
    MyClass() = default;
    MyClass(MyClass const &src) = default;              // 1/5
    MyClass(std::string str) : m_str{std::move(str)} {} // 2/5
    virtual ~MyClass() = default;                       // 3/5
    MyClass &operator=(MyClass &&rhs) noexcept          // 4/5
    {
        if (this == &rhs)
            return *this;
        m_str = std::move(rhs.m_str);
        std::cout << std::format("Move operator= (m_str={})", m_str)
                  << std::endl;
        return *this;
    }
    MyClass &operator=(MyClass const &src)
    {
        if (this == &src)
            return *this;
        m_str = src.m_str;
        std::cout << std::format("Copy operator= (m_str={})", m_str)
                  << std::endl;
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &os, MyClass const &x)
    {
        return os << x.getString();
    }

    void setStirng(std::string str) { m_str = std::move(str); }
    std::string const &getString() const { return m_str; }

  private:
    std::string m_str;
};

int main()
{
    auto printCont{[](auto const &cont) {
        for (auto &v : cont) {
            std::cout << v << " || ";
        }
        std::cout << std::endl;
    }};

    std::vector<MyClass> vecSrc{MyClass{"a"}, MyClass{"b"}, MyClass{"c"}};
    std::vector<MyClass> vecDst(std::size(vecSrc));

    std::move(std::begin(vecSrc), std::end(vecSrc), std::begin(vecDst));
    std::cout << "vecDst:\n";
    printCont(vecDst);
    std::cout << "vecSrc:\n";
    printCont(vecSrc);

    std::vector<MyClass> vecDst2(std::size(vecDst));
    std::copy(std::cbegin(vecDst), std::cend(vecDst), std::begin(vecDst2));
    std::cout << "vecDst2:\n";
    printCont(vecDst2);
}