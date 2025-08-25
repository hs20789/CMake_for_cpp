#include <format>
#include <iostream>
#include <iterator>
#include <vector>

void printVector(std::vector<int> vec)
{
    for (auto const &v : vec) {
        std::cout << v << " | ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector values{2, 5};
    printVector(values);
    int inputArr[]{3, 4};
    values.insert(std::cbegin(values) + 1, std::begin(inputArr),
                    std::end(inputArr));
    printVector(values);

    std::vector myVector{0, 1};
    values.insert(std::cbegin(values), std::begin(myVector),
                  std::end(myVector));
    printVector(values);

    std::vector<int> test;
    for (auto iter{std::crbegin(values)}; iter != std::crend(values); ++iter) {
        test.emplace_back(*iter);
    }
    printVector(test);
}