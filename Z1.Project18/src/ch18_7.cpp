#include <array>
#include <iostream>
#include <iterator>
int main()
{
    std::array<int, 3> arr{9, 8, 7};
    std::cout << "Array size = " << arr.size() << std::endl;

    for (auto const &i : arr) {
        std::cout << i << std::endl;
    }
    std::cout << "Perfoming arr.fill(3)...\n";
    arr.fill(3);

    for (auto iter{std::cbegin(arr)}; iter != std::cend(arr); ++iter) {
        std::cout << *iter << "  ";
    }
    std::cout << '\n';

    std::array<int, 3> myArray{11, 22, 33};
    std::cout << std::get<1>(myArray) << "  " << myArray[1] << std::endl;

    auto arr1{std::to_array({111, 222, 333})};
    double carray[]{9, 8, 7, 6};
    auto arr2{std::to_array(carray)};
}