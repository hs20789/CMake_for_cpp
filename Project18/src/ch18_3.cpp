#include <format>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

template <typename T> void printVec(std::vector<T> const &vec)
{
    for (auto &v : vec) {
        std::cout << v << "  ";
    }
    std::cout << '\n';
}

template <typename T> void printVecIter(std::vector<T> const &vec)
{
    for (typename std::vector<T>::const_iterator it{std::cbegin(vec)};
         it != std::end(vec); ++it) {
        std::cout << *it << " || ";
    }
    std::cout << '\n';
}

int main()
{
    std::vector<std::string> stringVector(10, "HeonSu");
    for (auto const &vec : stringVector) {
        std::cout << vec << "  ";
    }
    std::cout << '\n';

    std::vector<int> intVector(10);
    intVector.assign(5, 100);
    printVec(intVector);

    std::vector<int> vectorOne(10);
    std::vector<int> vectorTwo(10);

    if (vectorOne == vectorTwo) {
        std::cout << "Equal!\n";
    } else {
        std::cout << "Not Equal!\n";
    }
    vectorOne[3] = 50;
    if (vectorOne < vectorTwo) {
        std::cout << "vectorOne is less than vectorTwo.\n";
    } else {
        std::cout << "vectorOne is not less than vectorTwo.\n";
    }
    printVecIter(vectorOne);

    for (auto it{std::begin(stringVector)}; it != std::end(stringVector);
         ++it) {
        it->append(" Jeong");
    }
    for (auto &str : stringVector) {
        str.append(" God");
    }
    printVecIter(stringVector);
}