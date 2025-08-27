#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values(10);
    int value{1};

    std::generate(std::begin(values), std::end(values), [&value] {
        value *= 2;
        return value;
    });
    for (auto const &i : values) {
        std::cout << i << " | ";
    }
    std::cout << std::endl;
    std::cout << "value : " << value << '\n';
}