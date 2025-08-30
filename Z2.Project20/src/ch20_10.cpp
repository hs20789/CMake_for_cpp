#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

void populateContainer(auto &cont)
    requires requires(decltype(cont) c, int v) {
        { c.push_back(v) } -> std::same_as<void>;
    }
{
    while (true) {
        std::cout << "Enter a number (0 to quit): ";
        int value;
        std::cin >> value;
        if (value == 0) {
            break;
        }
        cont.push_back(value);
    }
}

class SumAndProduct
{
  public:
    void operator()(int value)
    {
        m_sum += value;
        m_product *= value;
    }
    int getSum() const { return m_sum; }
    int getProduct() const { return m_product; }

  private:
    int m_sum{};
    int m_product{1};
};

int main()
{
    std::map<int, int> myMap{{4, 40}, {5, 50}, {6, 60}};
    std::for_each(std::cbegin(myMap), std::cend(myMap), [](auto const &p) {
        std::cout << p.first << "->" << p.second << std::endl;
    });

    std::vector<int> myVector;

    populateContainer(myVector);
    int sum{}, product{1};
    std::for_each(std::cbegin(myVector), std::cend(myVector), [&](int i) {
        sum += i;
        product *= i;
    });
    std::cout << "The sum is " << sum << std::endl;
    std::cout << "The product is " << product << std::endl;

    SumAndProduct calculator;
    calculator =
        std::for_each(std::cbegin(myVector), std::cend(myVector), calculator);
    std::cout << "The sum is " << calculator.getSum() << std::endl;
    std::cout << "The product is " << calculator.getProduct() << std::endl;
}