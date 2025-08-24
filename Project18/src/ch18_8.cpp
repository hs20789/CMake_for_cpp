#include <array>
#include <iostream>
#include <iterator>
#include <span>
#include <vector>

void print(std::span<int> values)
{
    for (auto const &value : values) {
        std::cout << value << "  ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector v{11, 22, 33, 44, 55, 66};
    print(v);

    std::span mySpan{v};
    print(mySpan);

    std::span subspan{mySpan.subspan(2, 3)};
    print(subspan);

    print({v.data() + 2, 3});
    std::array<int, 5> arr{5, 4, 3, 2, 1};
    print(arr);
    print({arr.data() + 2, 3});

    int carr[]{9, 8, 7, 6, 5};
    print(carr);
    print({carr + 2, 3});
}