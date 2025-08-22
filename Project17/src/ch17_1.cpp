#include <format>
#include <iostream>
#include <iterator>
#include <vector>

template <typename IteratorType> void iteratorTraitsTest(IteratorType it)
{
    typename std::iterator_traits<IteratorType>::value_type temp;
    temp = *it;
    std::cout << temp << std::endl;
}

// begint과 end 반복자로 주어진 원소 범위를 받아서 그 안에 있는 원소를 모두
// 화면에 출력하는 헬퍼 메서드
template <typename Iter> void myPrint(Iter begin, Iter end)
{
    for (auto iter{begin}; iter != end; ++iter) {
        std::cout << *iter << "  ";
    }
    std::cout << std::endl;
}

// 주어진 범위에서 원하는 값을 찾는 템플릿 함수
template <typename Iter>
auto myFind(Iter begin, Iter end,
            typename std::iterator_traits<Iter>::value_type const &value)
{
    for (auto iter{begin}; iter != end; ++iter) {
        if (*iter == value) {
            return iter;
        }
    }
    return end;
}

int main()
{
    std::vector values{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto iter{std::cbegin(values)}; iter != std::cend(values); ++iter) {
        std::cout << *iter << "  ";
    }
    iteratorTraitsTest(values.begin());
    std::cout << '\n';

    // 비권장 iter != std::end(...) 방식이 더 권장된다.
    // != 연산자가 모든 타입의 반복자에 대해 적용할 수 있는 반면 < 연산자는
    // 정/양방향 반복자에는 적용할 수 없기 때문이다.
    for (auto iter{std::cbegin(values)}; iter < std::cend(values); ++iter) {
        std::cout << *iter << "  ";
    }
    std::cout << '\n';

    myPrint(std::cbegin(values), std::cend(values));

    std::vector<int> values2{11, 22, 33, 44};
    auto result{myFind(std::cbegin(values2), std::cend(values2), 44)};
    if (result == std::cend(values2)) {
        std::cout << "Not Find\n";
    } else {
        std::cout << "Found value at position "
                  << std::distance(std::cbegin(values2), result) << std::endl;
    }

    auto it1{myFind(std::begin(values2), std::end(values2), 22)};
    auto it2{myFind(std::rbegin(values2), std::rend(values2), 22)};
    if (it1 != std::end(values2) && it2 != std::rend(values2)) {
        std::cout << std::format("Found at position {} going forward.\n",
                                 std::distance(std::begin(values2), it1));
        std::cout << std::format(
            "Found at position {} going backward.\n",
            std::distance(std::begin(values2), --it2.base()));
    }
}