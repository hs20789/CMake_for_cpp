#include <algorithm>
#include <execution>
#include <iostream>
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

int main()
{
    auto printCont{[](auto const &cont) {
        for (auto &v : cont) {
            std::cout << v << " || ";
        }
        std::cout << std::endl;
    }};
    std::vector<int> vec1, vecOdd, vecEven;
    populateContainer(vec1);
    vecOdd.resize(std::size(vec1));
    vecEven.resize(std::size(vec1));

    auto pairIters{std::partition_copy(std::cbegin(vec1), std::cend(vec1),
                                       std::begin(vecEven), std::begin(vecOdd),
                                       [](int i) { return i % 2 == 0; })};
    vecEven.erase(pairIters.first, std::end(vecEven));
    vecOdd.erase(pairIters.second, std::end(vecOdd));

    std::cout << "Even numbers:\n";
    printCont(vecEven);
    std::cout << "Odd numbers:\n";
    printCont(vecOdd);

    printCont(vec1);
    std::partition(std::begin(vec1), std::end(vec1),
                   [](int i) { return i % 2 == 0; });
    std::cout << "Partitioned result:\n";
    printCont(vec1);
}