#include <format>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

template <typename T> void printVector(std::vector<T> const &vec)
{
    for (auto &element : vec) {
        std::cout << std::format("|{0:<4}", element);
    }
    std::cout << std::endl;
}

int main()
{
    std::string str1{"Hello"};
    std::string str2{"World"};

    std::vector<std::reference_wrapper<std::string>> vec{std::ref(str1)};
    vec.push_back(std::ref(str2));

    vec[1].get() += "!";

    std::cout << str1 << "**" << str2 << std::endl;

    std::cout << "=============================\n";

    std::vector<int> vectorOne{1, 2, 3, 5};
    std::vector<int> vectorTwo;

    vectorOne.insert(std::cbegin(vectorOne) + 3, 4);

    for (int i{6}; i <= 10; i++) {
        vectorTwo.push_back(i);
    }
    printVector(vectorOne);
    printVector(vectorTwo);

    vectorOne.insert(std::cend(vectorOne), std::cbegin(vectorTwo),
                     std::cend(vectorTwo));
    printVector(vectorOne);

    vectorOne.erase(std::cbegin(vectorOne) + 1, std::cbegin(vectorOne) + 5);
    printVector(vectorOne);

    vectorTwo.clear();

    vectorTwo.insert(std::cbegin(vectorTwo), 10, 100);
    printVector(vectorTwo);

    vectorTwo.pop_back();
    printVector(vectorTwo);
}