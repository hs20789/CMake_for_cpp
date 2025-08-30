#include <format>
#include <iostream>
#include <iterator>
#include <vector>

template <typename InputIter, typename OutputIter>
void myCopy(InputIter begin, InputIter end, OutputIter target)
{
    for (auto iter{begin}; iter != end; ++iter, ++target) {
        *target = *iter;
    }
}

template <typename InputIter> auto sum(InputIter begin, InputIter end)
{
    auto sum{*begin};
    for (auto iter{++begin}; iter != end; ++iter) {
        sum += *iter;
    }
    return sum;
}

int main()
{
    std::vector myVector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    std::vector<int> vectorCopy(myVector.size());
    myCopy(std::cbegin(myVector), std::cend(myVector), std::begin(vectorCopy));

    myCopy(std::cbegin(myVector), std::cend(myVector),
           std::ostream_iterator<int>{std::cout, "  "});
    std::cout << std::endl;

    myCopy(std::cbegin(vectorCopy), std::cend(vectorCopy),
           std::ostream_iterator<int>{std::cout, "//"});
    std::cout << std::endl;

    std::cout << "Enter numbers separated by white space." << std::endl;
    std::cout << "Press Ctrl+D followed by Enter to stop.\n";
    std::istream_iterator<int> numbersIter{std::cin};
    std::istream_iterator<int> endIter;
    int result{sum(numbersIter, endIter)};
    std::cout << std::format("Sum: {}\n", result);
}